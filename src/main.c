#include "config.h"
#include "player.h"
#include "boss.h"
#include "bullet.h"
#include "typing_engine.h"
#include "ui.h"
#include "save.h"
#include "patch_feedback.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stddef.h>

#define RANKING_FILE "bin/ranking.txt"
#define MAX_RANKING_ENTRIES 10
#define MAX_NAME_LEN 16

typedef enum {
    STATE_MENU,
    STATE_COMBAT,
    STATE_GAME_OVER,
    STATE_VICTORY,
    STATE_NAME_INPUT,
    STATE_RANKING
} GameState;

typedef struct {
    char name[MAX_NAME_LEN];
    int score;
} RankingEntry;

/* Funcoes auxiliares para carregamento do Ranking gerado em Haskell */
static void save_ranking_entry(const char *player_name, int score) {
    FILE *f = fopen(RANKING_FILE, "a");
    if (f) {
        fprintf(f, "%s %d\n", player_name[0] == '\0' ? "ANONIMO" : player_name, score);
        fclose(f);
    }
}

static int load_ranking(RankingEntry entries[], int max_entries) {
    FILE *f = fopen(RANKING_FILE, "r");
    if (!f) return 0;

    int count = 0;
    while (count < max_entries && fscanf(f, "%15s %d", entries[count].name, &entries[count].score) == 2) {
        count++;
    }
    fclose(f);
    return count;
}

/* =========================================================================
 * Processamento de Rodadas e Game Loop (PI2-89 - Julio Cesar)
 * Integracao de Pontuacao e Alinhamento Etico (PI2-90 - Caio Brayner)
 * ========================================================================= */
static void combat_process_round(GameState *state,
                                 Player *player,
                                 Boss *boss,
                                 BulletManager *bullet_mgr,
                                 TypingEngine *typing_engine,
                                 UIManager *ui,
                                 int *score,
                                 float dt) {
    /* 1. Movimentacao do Jogador */
    player_handle_input(player);
    player_update(player, dt);

    /* 2. Atualizacao do Chefe */
    Vector2 p_pos = (Vector2){ player->rect.x + player->rect.width / 2.0f, player->rect.y + player->rect.height / 2.0f };
    boss_update(boss, dt, bullet_mgr, p_pos);

    /* 3. Motor de Digitacao */
    typing_engine_update(typing_engine, dt);

    /* Captura de caracteres digitados */
    int char_pressed = GetCharPressed();
    while (char_pressed > 0 && *state == STATE_COMBAT) {
        int errors = 0;
        const char *res = typing_engine_handle_key(typing_engine, char_pressed, &errors);
        if (res != NULL) {
            if (strcmp(res, "COMPLETED") == 0) {
                /* Dano ao chefe e incremento de alinhamento */
                boss_take_damage(boss, BOSS_DAMAGE_PER_PHRASE);
                boss->alignment_pct += BOSS_ALIGNMENT_STEP;
                if (boss->alignment_pct > 100) boss->alignment_pct = 100;

                ui_spawn_particle_burst(ui, boss->rect.x + boss->rect.width / 2.0f,
                                        boss->rect.y + boss->rect.height / 2.0f, COLOR_BOSS, 24);
                ui_trigger_shake(ui, 0.35f, 9.0f);

                /* Classificacao de precisao e pontuacao (Caio Brayner - PI2-90) */
                const char *rating_txt;
                Color rating_c;
                int font_sz;
                int feedback_grade;
                if (errors == 0) {
                    *score += SCORE_PERFECT;
                    rating_txt = "CONVERGENCIA PERFEITA! (+150)";
                    rating_c = (Color){ 255, 215, 0, 255 };
                    font_sz = 34;
                    feedback_grade = 0;
                } else if (errors <= 2) {
                    *score += SCORE_STABLE;
                    rating_txt = "ALINHAMENTO ESTAVEL! (+100)";
                    rating_c = (Color){ 50, 255, 120, 255 };
                    font_sz = 30;
                    feedback_grade = 1;
                } else {
                    *score += SCORE_PATCHED;
                    rating_txt = "PATCH APLICADO! (+50)";
                    rating_c = (Color){ 0, 220, 255, 255 };
                    font_sz = 26;
                    feedback_grade = 2;
                }

                patch_feedback_play_grade(feedback_grade);
                ui_spawn_floating_text(ui, rating_txt, boss->rect.x + boss->rect.width / 2.0f,
                                      boss->rect.y - 30.0f, rating_c, font_sz, 1.2f);

                if (boss->alignment_pct >= 100 && typing_engine_is_finished(typing_engine)) {
                    *state = STATE_VICTORY;
                    save_match_result(*score, 100, 1);
                }
            } else if (strcmp(res, "ERROR") == 0) {
                *score = (*score >= SCORE_ERROR_PENALTY) ? *score - SCORE_ERROR_PENALTY : 0;
                patch_feedback_play_error();
                ui_spawn_floating_text(ui, "ERRO DE SINTAXE! (-5)", SCREEN_WIDTH / 2.0f,
                                      SCREEN_HEIGHT - 130.0f, (Color){ 255, 60, 60, 255 }, 24, 0.5f);
            }
        }
        char_pressed = GetCharPressed();
    }

    /* Evita que um projetil converta vitoria em derrota no mesmo frame. */
    if (*state != STATE_COMBAT) {
        ui_update(ui, dt);
        return;
    }

    /* 4. Projeteis, Colisoes e Status */
    const char *status_applied = NULL;
    bool hit_player = bullet_mgr_update(bullet_mgr, dt, player, typing_engine, &status_applied);

    if (status_applied != NULL) {
        if (strcmp(status_applied, "BLIND") == 0) {
            ui_spawn_floating_text(ui, "CONTEXT DRIFT!", p_pos.x, p_pos.y - 30.0f, (Color){ 180, 70, 255, 255 }, 26, 1.0f);
        } else if (strcmp(status_applied, "CONFUSE") == 0) {
            ui_spawn_floating_text(ui, "PROMPT INJECTION!", p_pos.x, p_pos.y - 30.0f, (Color){ 255, 0, 180, 255 }, 26, 1.0f);
        }
    }

    if (hit_player) {
        ui_spawn_particle_burst(ui, p_pos.x, p_pos.y, COLOR_PLAYER, 16);
        ui_trigger_shake(ui, 0.2f, 6.0f);
        ui_spawn_floating_text(ui, "DANO!", p_pos.x, p_pos.y - 30.0f, (Color){ 255, 60, 60, 255 }, 26, 0.8f);
        typing_engine_on_player_hit(typing_engine);

        if (!player->is_alive) {
            *state = STATE_GAME_OVER;
            save_match_result(*score, 50, 0);
        }
    }

    /* Salvamento binario automatico durante o combate ativo */
    if (*state == STATE_COMBAT) {
        SaveData session_data = {
            .score = *score,
            .player_hp = player->hp,
            .boss_hp = boss->hp,
            .boss_phase = boss->difficulty,
            .boss_alignment_pct = (int)boss->alignment_pct,
            .phrase_index = typing_engine->phrase_index
        };
        save_game(&session_data);
    }

    ui_update(ui, dt);
}

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "AI Safety");
    patch_feedback_init();
    SetTargetFPS(TARGET_FPS);

    GameState state = STATE_MENU;
    int difficulty = DIFFICULTY_NORMAL;
    int score = 0;

    char player_name[MAX_NAME_LEN] = "\0";
    int letter_count = 0;

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
        if (dt > 0.05f) dt = 0.05f; /* Clamp dt contra picos de frametime */

        /* --- INPUT & UPDATE --- */
        if (state == STATE_MENU) {
            if (IsKeyPressed(KEY_ONE) || IsKeyPressed(KEY_N)) difficulty = DIFFICULTY_NORMAL;
            if (IsKeyPressed(KEY_TWO) || IsKeyPressed(KEY_D)) difficulty = DIFFICULTY_HARD;

            /* Inicio de jogo no menu interativo principal (Matheus Chaves - PI2-91) */
            if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER)) {
                /* Inicializa entidades e reseta o estado da sessao */
                player_init(&player, SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT - 200.0f);
                boss_init(&boss, SCREEN_WIDTH / 2.0f, 130.0f, difficulty);
                bullet_mgr_clear(&bullet_mgr);
                typing_engine_reset(&typing_engine);
                ui_init(&ui);
                score = 0;
                
                /* Transita para combate */
                state = STATE_COMBAT;
            } else if (save_exists() && IsKeyPressed(KEY_C)) {
                /* Carrega a sessao salva se existir o arquivo binario valido */
                SaveData saved_session;
                if (load_game(&saved_session)) {
                    difficulty = saved_session.boss_phase;
                    score = saved_session.score;
                    player_init(&player, SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT - 200.0f);
                    boss_init(&boss, SCREEN_WIDTH / 2.0f, 130.0f, difficulty);
                    bullet_mgr_clear(&bullet_mgr);
                    typing_engine_reset(&typing_engine);
                    ui_init(&ui);
                    if (saved_session.phrase_index >= 0 &&
                        saved_session.phrase_index < typing_engine.phrase_count) {
                        typing_engine.phrase_index = saved_session.phrase_index;
                        typing_engine.total_completed = saved_session.phrase_index;
                    }

                    player.hp = saved_session.player_hp;
                    boss.hp = saved_session.boss_hp;
                    boss.alignment_pct = (float)saved_session.boss_alignment_pct;
                    state = STATE_COMBAT;
                }
            } else if (IsKeyPressed(KEY_K)) {
                state = STATE_RANKING;
            }
        } else if (state == STATE_COMBAT) {
            /* Processamento da rodada ativa (Julio Cesar - PI2-89) */
            combat_process_round(&state, &player, &boss, &bullet_mgr, &typing_engine, &ui, &score, dt);
        } else if (state == STATE_GAME_OVER || state == STATE_VICTORY) {
            if (IsKeyPressed(KEY_ENTER)) {
                state = STATE_NAME_INPUT;
            } else if (IsKeyPressed(KEY_R)) {
                player_init(&player, SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT - 200.0f);
                boss_init(&boss, SCREEN_WIDTH / 2.0f, 130.0f, difficulty);
                bullet_mgr_clear(&bullet_mgr);
                typing_engine_reset(&typing_engine);
                ui_init(&ui);
                score = 0;
                state = STATE_COMBAT;
            } else if (IsKeyPressed(KEY_M)) {
                state = STATE_MENU;
            }
        } else if (state == STATE_NAME_INPUT) {
            int key = GetCharPressed();
            while (key > 0) {
                if ((key >= 32) && (key <= 125) && (letter_count < MAX_NAME_LEN - 1)) {
                    player_name[letter_count] = (char)key;
                    player_name[letter_count + 1] = '\0';
                    letter_count++;
                }
                key = GetCharPressed();
            }

            if (IsKeyPressed(KEY_BACKSPACE)) {
                letter_count--;
                if (letter_count < 0) letter_count = 0;
                player_name[letter_count] = '\0';
            }

            if (IsKeyPressed(KEY_ENTER)) {
                save_ranking_entry(player_name, score);
                player_name[0] = '\0';
                letter_count = 0;
                state = STATE_RANKING;
            }
        } else if (state == STATE_RANKING) {
            if (IsKeyPressed(KEY_M) || IsKeyPressed(KEY_ESCAPE)) {
                state = STATE_MENU;
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
            if (save_exists()) {
                DrawText("[C] CONTINUAR JOGO SALVO", SCREEN_WIDTH / 2 - 140, SCREEN_HEIGHT - 180, 20, GREEN);
            }
            DrawText("[K] VER RANKING", SCREEN_WIDTH / 2 - 90, SCREEN_HEIGHT - 140, 20, LIGHTGRAY);
        } else if (state == STATE_RANKING) {
            DrawText("=== RANKING DE JOGADORES ===", SCREEN_WIDTH / 2 - 180, 80, 26, GOLD);
            
            RankingEntry entries[MAX_RANKING_ENTRIES];
            int count = load_ranking(entries, MAX_RANKING_ENTRIES);

            for (int i = 0; i < count; i++) {
                DrawText(TextFormat("%d. %-15s - %06d PTS", i + 1, entries[i].name, entries[i].score),
                         SCREEN_WIDTH / 2 - 160, 150 + (i * 35), 20, RAYWHITE);
            }

            if (count == 0) {
                DrawText("NENHUMA PONTUACAO REGISTRADA", SCREEN_WIDTH / 2 - 160, 200, 20, GRAY);
            }

            DrawText("Pressione [M] para voltar ao menu", SCREEN_WIDTH / 2 - 160, SCREEN_HEIGHT - 100, 20, GRAY);
        } else if (state == STATE_NAME_INPUT) {
            DrawText("DIGITE SEU NOME PARA O RANKING:", SCREEN_WIDTH / 2 - 180, SCREEN_HEIGHT / 2 - 60, 20, RAYWHITE);
            DrawRectangleLines(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 - 20, 300, 40, RAYWHITE);
            DrawText(player_name, SCREEN_WIDTH / 2 - 140, SCREEN_HEIGHT / 2 - 10, 20, GREEN);
            DrawText("Pressione [ENTER] para confirmar", SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 + 40, 18, GRAY);
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
            ui_draw_hud_stats(score, boss.alignment_pct);
            ui_draw_typing_box(&typing_engine);

            if (state == STATE_GAME_OVER) {
                ui_draw_game_over(score);
                DrawText("Pressione [ENTER] para registrar pontuacao", SCREEN_WIDTH / 2 - 180, SCREEN_HEIGHT - 100, 20, YELLOW);
            } else if (state == STATE_VICTORY) {
                ui_draw_victory(score);
                DrawText("Pressione [ENTER] para registrar pontuacao", SCREEN_WIDTH / 2 - 180, SCREEN_HEIGHT - 100, 20, GREEN);
            }
        }

        EndDrawing();
    }

    patch_feedback_shutdown();
    CloseWindow();
    return 0;
}