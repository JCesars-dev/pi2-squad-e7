#include "config.h"
#include "player.h"
#include "boss.h"
#include "bullet.h"
#include "typing_engine.h"
#include "ui.h"
#include "game_state.h"
#include <math.h>
#include <string.h>
#include <stddef.h>

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "AI Safety");
    SetTargetFPS(TARGET_FPS);

    GameContext ctx;
    game_state_init(&ctx);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        if (dt > 0.05f) dt = 0.05f; /* Clamp dt against spikes */

        /* --- INPUT & UPDATE --- */
        if (ctx.state == STATE_MENU) {
            if (IsKeyPressed(KEY_ONE) || IsKeyPressed(KEY_N)) ctx.difficulty = DIFFICULTY_NORMAL;
            if (IsKeyPressed(KEY_TWO) || IsKeyPressed(KEY_D)) ctx.difficulty = DIFFICULTY_HARD;

            /* Inicio de jogo no menu interativo principal */
            if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) {
                game_state_reset_combat(&ctx);
            }
        } else if (ctx.state == STATE_COMBAT) {
            /* 1. Movimentacao do Jogador */
            player_handle_input(&ctx.player);
            player_update(&ctx.player, dt);

            /* 2. Atualizacao do Chefe */
            Vector2 p_pos = (Vector2){ ctx.player.rect.x + ctx.player.rect.width / 2.0f,
                                       ctx.player.rect.y + ctx.player.rect.height / 2.0f };
            boss_update(&ctx.boss, dt, &ctx.bullet_mgr, p_pos);

            /* 3. Motor de Digitacao */
            typing_engine_update(&ctx.typing_engine, dt);

            /* Captura de teclas digitadas (o espaco tambem chega por aqui) */
            int char_pressed = GetCharPressed();
            while (char_pressed > 0) {
                int errors = 0;
                const char *res = typing_engine_handle_key(&ctx.typing_engine, char_pressed, &errors);
                if (res != NULL) {
                    if (strcmp(res, "COMPLETED") == 0) {
                        /* Aplica dano ao chefe (100 HP por diretriz) */
                        boss_take_damage(&ctx.boss, 100);
                        ui_spawn_particle_burst(&ctx.ui, ctx.boss.rect.x + ctx.boss.rect.width / 2.0f,
                                                ctx.boss.rect.y + ctx.boss.rect.height / 2.0f, COLOR_BOSS, 24);
                        ui_trigger_shake(&ctx.ui, 0.35f, 9.0f);

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

                        ui_spawn_floating_text(&ctx.ui, rating_txt, ctx.boss.rect.x + ctx.boss.rect.width / 2.0f,
                                               ctx.boss.rect.y - 30.0f, rating_c, font_sz, 1.2f);

                        if (ctx.boss.hp <= 0 || typing_engine_is_finished(&ctx.typing_engine)) {
                            ctx.state = STATE_VICTORY;
                        }
                    } else if (strcmp(res, "ERROR") == 0) {
                        ui_spawn_floating_text(&ctx.ui, "ERRO DE SINTAXE!", SCREEN_WIDTH / 2.0f,
                                               SCREEN_HEIGHT - 130.0f, (Color){ 255, 60, 60, 255 }, 24, 0.5f);
                    }
                }
                char_pressed = GetCharPressed();
            }

            /* 4. Projeteis, Colisoes e Status */
            const char *status_applied = NULL;
            bool hit_player = bullet_mgr_update(&ctx.bullet_mgr, dt, &ctx.player, &ctx.typing_engine, &status_applied);

            if (status_applied != NULL) {
                if (strcmp(status_applied, "BLIND") == 0) {
                    ui_spawn_floating_text(&ctx.ui, "CONTEXT DRIFT!", p_pos.x, p_pos.y - 30.0f,
                                           (Color){ 180, 70, 255, 255 }, 26, 1.0f);
                } else if (strcmp(status_applied, "CONFUSE") == 0) {
                    ui_spawn_floating_text(&ctx.ui, "PROMPT INJECTION!", p_pos.x, p_pos.y - 30.0f,
                                           (Color){ 255, 0, 180, 255 }, 26, 1.0f);
                }
            }

            if (hit_player) {
                ui_spawn_particle_burst(&ctx.ui, p_pos.x, p_pos.y, COLOR_PLAYER, 16);
                ui_trigger_shake(&ctx.ui, 0.2f, 6.0f);
                ui_spawn_floating_text(&ctx.ui, "DANO!", p_pos.x, p_pos.y - 30.0f,
                                       (Color){ 255, 60, 60, 255 }, 26, 0.8f);
                typing_engine_on_player_hit(&ctx.typing_engine);

                if (!ctx.player.is_alive) {
                    ctx.state = STATE_GAME_OVER;
                }
            }

            ui_update(&ctx.ui, dt);
        } else if (ctx.state == STATE_GAME_OVER || ctx.state == STATE_VICTORY) {
            if (IsKeyPressed(KEY_R)) {
                game_state_reset_combat(&ctx);
            }
        }

        /* --- RENDER --- */
        BeginDrawing();

        /* Camera / Screen Shake Offset */
        float offset_x = 0.0f;
        float offset_y = 0.0f;
        if (ctx.ui.shake_timer > 0.0f) {
            offset_x = (float)GetRandomValue((int)-ctx.ui.shake_intensity, (int)ctx.ui.shake_intensity);
            offset_y = (float)GetRandomValue((int)-ctx.ui.shake_intensity, (int)ctx.ui.shake_intensity);
        }

        if (ctx.state == STATE_MENU) {
            ui_draw_menu(ctx.difficulty);
        } else {
            /* Aplica shake nas entidades de jogo */
            Camera2D camera = { 0 };
            camera.target = (Vector2){ -offset_x, -offset_y };
            camera.offset = (Vector2){ 0.0f, 0.0f };
            camera.rotation = 0.0f;
            camera.zoom = 1.0f;

            BeginMode2D(camera);
            ui_draw_arena_grid();
            boss_draw(&ctx.boss);
            bullet_mgr_draw(&ctx.bullet_mgr);
            player_draw(&ctx.player);
            ui_draw_particles(&ctx.ui);
            ui_draw_floating_texts(&ctx.ui);
            EndMode2D();

            /* Elementos estaticos de HUD */
            ui_draw_boss_hp(&ctx.boss);
            ui_draw_player_hp(&ctx.player);
            ui_draw_typing_box(&ctx.typing_engine);

            if (ctx.state == STATE_GAME_OVER) {
                ui_draw_game_over();
            } else if (ctx.state == STATE_VICTORY) {
                ui_draw_victory();
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}