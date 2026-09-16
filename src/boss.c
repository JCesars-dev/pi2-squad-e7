#include "boss.h"
#include <math.h>

void boss_init(Boss *b, float x, float y, int difficulty) {
    b->rect = (Rectangle){ x - BOSS_SIZE / 2.0f, y - BOSS_SIZE / 2.0f, BOSS_SIZE, BOSS_SIZE };
    b->base_x = x;
    b->base_y = y;
    b->max_hp = BOSS_MAX_HP;
    b->hp = BOSS_MAX_HP;
    b->difficulty = difficulty;
    b->move_timer = 0.0f;
    b->pulse_timer = 0.0f;
    b->hit_flash_timer = 0.0f;

    b->timer_ring = 0.0f;
    b->timer_aimed = 0.0f;
    b->timer_spiral = 0.0f;
    b->timer_rain = 0.0f;
    b->timer_laser = 0.0f;
    b->timer_vortex = 0.0f;
    b->spiral_angle = 0.0f;
}

int boss_get_phase(const Boss *b) {
    float ratio = (float)b->hp / (float)b->max_hp;
    if (ratio > 0.66f) return 1;
    if (ratio > 0.33f) return 2;
    return 3;
}

void boss_take_damage(Boss *b, int damage) {
    b->hp -= damage;
    if (b->hp < 0) b->hp = 0;
    b->hit_flash_timer = 0.35f;
}

void boss_update(Boss *b, float dt, BulletManager *bm, Vector2 player_pos) {
    b->move_timer += dt;
    b->pulse_timer += dt;
    if (b->hit_flash_timer > 0.0f) b->hit_flash_timer -= dt;

    /* Movimento senoidal horizontal suave */
    b->rect.x = b->base_x + sinf(b->move_timer * 1.5f) * 140.0f - b->rect.width / 2.0f;
    b->rect.y = b->base_y + cosf(b->move_timer * 0.8f) * 20.0f - b->rect.height / 2.0f;

    Vector2 center = (Vector2){ b->rect.x + b->rect.width / 2.0f, b->rect.y + b->rect.height / 2.0f };
    int phase = boss_get_phase(b);
    float diff_mult = (b->difficulty == DIFFICULTY_HARD) ? 0.75f : 1.0f;

    /* --- FASE 1: Vies nos Dados (Aimed + Ring + Rain) --- */
    if (phase >= 1) {
        b->timer_aimed += dt;
        if (b->timer_aimed >= 1.4f * diff_mult) {
            b->timer_aimed = 0.0f;
            bullet_mgr_spawn_aimed(bm, center, player_pos, 180.0f, BULLET_NORMAL);
        }

        b->timer_ring += dt;
        if (b->timer_ring >= 2.6f * diff_mult) {
            b->timer_ring = 0.0f;
            bullet_mgr_spawn_ring(bm, center, (b->difficulty == DIFFICULTY_HARD) ? 14 : 10, 140.0f, BULLET_NORMAL);
        }
    }

    /* --- FASE 2: Jailbreaks & Injections (Espirais Duplas + Status Bullets) --- */
    if (phase >= 2) {
        b->timer_spiral += dt;
        if (b->timer_spiral >= 0.12f * diff_mult) {
            b->timer_spiral = 0.0f;
            b->spiral_angle += 0.35f;

            Vector2 v1 = (Vector2){ cosf(b->spiral_angle) * 150.0f, sinf(b->spiral_angle) * 150.0f };
            Vector2 v2 = (Vector2){ cosf(b->spiral_angle + PI) * 150.0f, sinf(b->spiral_angle + PI) * 150.0f };

            BulletType bt = (phase == 2 && ((int)(b->spiral_angle * 5) % 6 == 0)) ? BULLET_BLIND : BULLET_NORMAL;
            bullet_mgr_spawn(bm, center, v1, 5.0f, bt, 8.0f);
            bullet_mgr_spawn(bm, center, v2, 5.0f, BULLET_NORMAL, 8.0f);
        }

        /* Disparo de Confuse Bullet (Prompt Injection) */
        b->timer_rain += dt;
        if (b->timer_rain >= 3.5f * diff_mult) {
            b->timer_rain = 0.0f;
            bullet_mgr_spawn_aimed(bm, center, player_pos, 160.0f, BULLET_CONFUSE);
        }
    }

    /* --- FASE 3: Singularidade Instrumental (Lasers + Vortex) --- */
    if (phase == 3) {
        b->timer_laser += dt;
        if (b->timer_laser >= 4.0f * diff_mult) {
            b->timer_laser = 0.0f;
            /* Laser vertical na posicao do jogador */
            bullet_mgr_spawn_laser(bm, player_pos.x - 20.0f, ARENA_MARGIN_TOP, 40.0f, SCREEN_HEIGHT - ARENA_MARGIN_TOP - ARENA_MARGIN_BOTTOM, 1.0f, 0.6f);
        }

        b->timer_vortex += dt;
        if (b->timer_vortex >= 7.0f) {
            b->timer_vortex = 0.0f;
            bullet_mgr_spawn_vortex(bm, center, 220.0f, 150.0f, 4.0f);
        }
    }
}

void boss_draw(const Boss *b) {
    Color fill_color = (b->difficulty == DIFFICULTY_HARD) ? COLOR_BOSS_HARD : COLOR_BOSS;
    Color border_color = WHITE;

    if (b->hit_flash_timer > 0.0f) {
        fill_color = WHITE;
        border_color = YELLOW;
    }

    /* Desenha quadrado com brilho */
    DrawRectangleRec(b->rect, fill_color);
    DrawRectangleLinesEx(b->rect, 3.0f, border_color);

    /* Geometria de losango interno rotativo */
    Vector2 c = (Vector2){ b->rect.x + b->rect.width / 2.0f, b->rect.y + b->rect.height / 2.0f };
    float d = 16.0f + sinf(b->pulse_timer * 4.0f) * 3.0f;
    Vector2 top = (Vector2){ c.x, c.y - d };
    Vector2 right = (Vector2){ c.x + d, c.y };
    Vector2 bottom = (Vector2){ c.x, c.y + d };
    Vector2 left = (Vector2){ c.x - d, c.y };

    DrawLineEx(top, right, 2.0f, WHITE);
    DrawLineEx(right, bottom, 2.0f, WHITE);
    DrawLineEx(bottom, left, 2.0f, WHITE);
    DrawLineEx(left, top, 2.0f, WHITE);
}
