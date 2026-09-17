#include "config.h"
#include "player.h"
#include "boss.h"
#include "bullet.h"
#include "typing_engine.h"
#include "ui.h"
#include <math.h>
#include <string.h>
#include <stddef.h>

typedef enum {
    STATE_MENU,
    STATE_COMBAT,
    STATE_GAME_OVER,
    STATE_VICTORY
} GameState;

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "AI Safety");
    SetTargetFPS(TARGET_FPS);

    GameState state = STATE_MENU;
    int difficulty = DIFFICULTY_NORMAL;

    Player player;
    Boss boss;
    BulletManager bullet_mgr;
    TypingEngine typing_engine;
    UIManager ui;

    player_init(&player, SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT - 200.0f);
    boss_init(&boss, SCREEN_WIDTH / 2.0f, 130.0f, difficulty);
    bullet_mgr_init(&bullet_mgr);
    typing_engine_init(&typing_engine);
    ui_init(&ui);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        if (dt > 0.05f) dt = 0.05f; /* Clamp dt against spikes */

        /* --- INPUT & UPDATE --- */
        if (state == STATE_MENU) {
            if (IsKeyPressed(KEY_ONE) || IsKeyPressed(KEY_N)) difficulty = DIFFICULTY_NORMAL;
            if (IsKeyPressed(KEY_TWO) || IsKeyPressed(KEY_D)) difficulty = DIFFICULTY_HARD;

            /* =========================================================================
             * TO DO [PI2-91 - Matheus Chaves]:
             * "Fazer a chamada do início de jogo no menu interativo principal"
             * 
             * Implemente aqui a verificacao da tecla de inicio (ex: KEY_SPACE ou KEY_ENTER).
             * Ao pressionar:
             * 1. Inicialize as entidades:
             *    player_init(&player, SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT - 200.0f);
             *    boss_init(&boss, SCREEN_WIDTH / 2.0f, 130.0f, difficulty);
             *    bullet_mgr_clear(&bullet_mgr);
             *    typing_engine_reset(&typing_engine);
             *    ui_init(&ui);
             * 2. Mude o estado para combate:
             *    state = STATE_COMBAT;
             * ========================================================================= */
        } else if (state == STATE_COMBAT) {
            /* 1. Movimentacao do Jogador */
            player_handle_input(&player);
            player_update(&player, dt);

            /* 2. Atualizacao do Chefe */
            Vector2 p_pos = (Vector2){ player.rect.x + player.rect.width / 2.0f, player.rect.y + player.rect.height / 2.0f };
            boss_update(&boss, dt, &bullet_mgr, p_pos);

            /* 3. Motor de Digitacao */
            typing_engine_update(&typing_engine, dt);

            /* Captura de teclas digitadas */
            int char_pressed = GetCharPressed();
            while (char_pressed > 0) {
                int errors = 0;
                const char *res = typing_engine_handle_key(&typing_engine, char_pressed, &errors);
                if (res != NULL) {
                    if (strcmp(res, "COMPLETED") == 0) {
                        /* Aplica dano ao chefe (100 HP por diretriz) */
                        boss_take_damage(&boss, 100);
                        ui_spawn_particle_burst(&ui, boss.rect.x + boss.rect.width / 2.0f,
                                                boss.rect.y + boss.rect.height / 2.0f, COLOR_BOSS, 24);
                        ui_trigger_shake(&ui, 0.35f, 9.0f);

                        /* Avaliacao de Precisao */
                        const char *rating_txt;
                        Color rating_c;
                        int font_sz;
                        if (errors == 0) {
                            rating_txt = "CONVERGENCIA PERFEITA!";
                            rating_c = (Color){ 255, 215, 0, 255 };
                            font_sz = 36;
                        } else if (errors <= 2) {
                            rating_txt = "ALINHAMENTO ESTAVEL!";
                            rating_c = (Color){ 50, 255, 120, 255 };
                            font_sz = 30;
                        } else {
                            rating_txt = "PATCH APLICADO!";
                            rating_c = (Color){ 0, 220, 255, 255 };
                            font_sz = 26;
                        }

                        ui_spawn_floating_text(&ui, rating_txt, boss.rect.x + boss.rect.width / 2.0f,
                                              boss.rect.y - 30.0f, rating_c, font_sz, 1.2f);

                        if (boss.hp <= 0 || typing_engine_is_finished(&typing_engine)) {
                            state = STATE_VICTORY;
                        }
                    } else if (strcmp(res, "ERROR") == 0) {
                        ui_spawn_floating_text(&ui, "ERRO DE SINTAXE!", SCREEN_WIDTH / 2.0f,
                                              SCREEN_HEIGHT - 130.0f, (Color){ 255, 60, 60, 255 }, 24, 0.5f);
                    }
                }
                char_pressed = GetCharPressed();
            }

            /* Tratamento de barra de espaco como tecla */
            if (IsKeyPressed(KEY_SPACE)) {
                int errors = 0;
                const char *res = typing_engine_handle_key(&typing_engine, KEY_SPACE, &errors);
                if (res != NULL && strcmp(res, "ERROR") == 0) {
                    ui_spawn_floating_text(&ui, "ERRO DE SINTAXE!", SCREEN_WIDTH / 2.0f,
                                          SCREEN_HEIGHT - 130.0f, (Color){ 255, 60, 60, 255 }, 24, 0.5f);
                }
            }

            /* 4. Projeteis, Colisoes e Status */
            const char *status_applied = NULL;
            bool hit_player = bullet_mgr_update(&bullet_mgr, dt, &player, &typing_engine, &status_applied);

            if (status_applied != NULL) {
                if (strcmp(status_applied, "BLIND") == 0) {
                    ui_spawn_floating_text(&ui, "CONTEXT DRIFT!", p_pos.x, p_pos.y - 30.0f, (Color){ 180, 70, 255, 255 }, 26, 1.0f);
                } else if (strcmp(status_applied, "CONFUSE") == 0) {
                    ui_spawn_floating_text(&ui, "PROMPT INJECTION!", p_pos.x, p_pos.y - 30.0f, (Color){ 255, 0, 180, 255 }, 26, 1.0f);
                }
            }

            if (hit_player) {
                ui_spawn_particle_burst(&ui, p_pos.x, p_pos.y, COLOR_PLAYER, 16);
                ui_trigger_shake(&ui, 0.2f, 6.0f);
                ui_spawn_floating_text(&ui, "DANO!", p_pos.x, p_pos.y - 30.0f, (Color){ 255, 60, 60, 255 }, 26, 0.8f);
                typing_engine_on_player_hit(&typing_engine);

                if (!player.is_alive) {
                    state = STATE_GAME_OVER;
                }
            }

            ui_update(&ui, dt);
        } else if (state == STATE_GAME_OVER || state == STATE_VICTORY) {
            if (IsKeyPressed(KEY_R)) {
                player_init(&player, SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT - 200.0f);
                boss_init(&boss, SCREEN_WIDTH / 2.0f, 130.0f, difficulty);
                bullet_mgr_clear(&bullet_mgr);
                typing_engine_reset(&typing_engine);
                ui_init(&ui);
                state = STATE_COMBAT;
            }
        }

        /* --- RENDER --- */
        BeginDrawing();
        
        /* Camera / Screen Shake Offset */
        float offset_x = 0.0f;
        float offset_y = 0.0f;
        if (ui.shake_timer > 0.0f) {
            offset_x = (float)GetRandomValue((int)-ui.shake_intensity, (int)ui.shake_intensity);
            offset_y = (float)GetRandomValue((int)-ui.shake_intensity, (int)ui.shake_intensity);
        }

        if (state == STATE_MENU) {
            ui_draw_menu(difficulty);
        } else {
            /* Aplica shake nas entidades de jogo */
            Camera2D camera = { 0 };
            camera.target = (Vector2){ -offset_x, -offset_y };
            camera.offset = (Vector2){ 0.0f, 0.0f };
            camera.rotation = 0.0f;
            camera.zoom = 1.0f;

            BeginMode2D(camera);
            ui_draw_arena_grid();
            boss_draw(&boss);
            bullet_mgr_draw(&bullet_mgr);
            player_draw(&player);
            ui_draw_particles(&ui);
            ui_draw_floating_texts(&ui);
            EndMode2D();

            /* Elementos estaticos de HUD */
            ui_draw_boss_hp(&boss);
            ui_draw_player_hp(&player);
            ui_draw_typing_box(&typing_engine);

            if (state == STATE_GAME_OVER) {
                ui_draw_game_over();
            } else if (state == STATE_VICTORY) {
                ui_draw_victory();
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
