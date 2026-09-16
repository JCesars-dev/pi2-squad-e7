#include "bullet.h"
#include <math.h>
#include <stddef.h>

void bullet_mgr_init(BulletManager *bm) {
    bullet_mgr_clear(bm);
}

void bullet_mgr_clear(BulletManager *bm) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        bm->bullets[i].active = false;
    }
    for (int i = 0; i < MAX_LASERS; i++) {
        bm->lasers[i].active = false;
    }
    bm->vortex.active = false;
}

void bullet_mgr_spawn(BulletManager *bm, Vector2 pos, Vector2 vel, float radius, BulletType type, float life) {
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (!bm->bullets[i].active) {
            bm->bullets[i].pos = pos;
            bm->bullets[i].vel = vel;
            bm->bullets[i].radius = radius;
            bm->bullets[i].type = type;
            bm->bullets[i].life = life;
            bm->bullets[i].max_life = life;
            bm->bullets[i].active = true;
            return;
        }
    }
}

void bullet_mgr_spawn_ring(BulletManager *bm, Vector2 pos, int count, float speed, BulletType type) {
    float step = (2.0f * PI) / (float)count;
    for (int i = 0; i < count; i++) {
        float angle = i * step;
        Vector2 vel = (Vector2){ cosf(angle) * speed, sinf(angle) * speed };
        bullet_mgr_spawn(bm, pos, vel, 5.0f, type, 8.0f);
    }
}

void bullet_mgr_spawn_aimed(BulletManager *bm, Vector2 pos, Vector2 target, float speed, BulletType type) {
    float dx = target.x - pos.x;
    float dy = target.y - pos.y;
    float dist = sqrtf(dx * dx + dy * dy);
    if (dist > 0.001f) {
        Vector2 vel = (Vector2){ (dx / dist) * speed, (dy / dist) * speed };
        bullet_mgr_spawn(bm, pos, vel, 6.0f, type, 8.0f);
    }
}

void bullet_mgr_spawn_laser(BulletManager *bm, float x, float y, float w, float h, float warning_time, float active_time) {
    for (int i = 0; i < MAX_LASERS; i++) {
        if (!bm->lasers[i].active) {
            bm->lasers[i].rect = (Rectangle){ x, y, w, h };
            bm->lasers[i].warning_timer = warning_time;
            bm->lasers[i].active_timer = active_time;
            bm->lasers[i].is_firing = false;
            bm->lasers[i].active = true;
            return;
        }
    }
}

void bullet_mgr_spawn_vortex(BulletManager *bm, Vector2 pos, float radius, float strength, float duration) {
    bm->vortex.pos = pos;
    bm->vortex.radius = radius;
    bm->vortex.pull_strength = strength;
    bm->vortex.duration = duration;
    bm->vortex.active = true;
}

bool bullet_mgr_update(BulletManager *bm, float dt, Player *player, TypingEngine *te, const char **status_applied_out) {
    bool hit_player = false;
    if (status_applied_out) *status_applied_out = NULL;

    Vector2 p_center = (Vector2){ player->rect.x + player->rect.width / 2.0f, player->rect.y + player->rect.height / 2.0f };

    /* 1. Vortex Gravitacional */
    if (bm->vortex.active) {
        bm->vortex.duration -= dt;
        if (bm->vortex.duration <= 0.0f) {
            bm->vortex.active = false;
        } else {
            float vdx = bm->vortex.pos.x - p_center.x;
            float vdy = bm->vortex.pos.y - p_center.y;
            float dist = sqrtf(vdx * vdx + vdy * vdy);
            if (dist < bm->vortex.radius && dist > 1.0f) {
                float pull = (1.0f - (dist / bm->vortex.radius)) * bm->vortex.pull_strength * dt;
                player_apply_force(player, (vdx / dist) * pull, (vdy / dist) * pull);
            }
        }
    }

    /* 2. Atualiza Projeteis */
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (!bm->bullets[i].active) continue;

        Bullet *b = &bm->bullets[i];
        b->life -= dt;
        if (b->life <= 0.0f) {
            b->active = false;
            continue;
        }

        /* Homing curvature */
        if (b->type == BULLET_HOMING) {
            float hdx = p_center.x - b->pos.x;
            float hdy = p_center.y - b->pos.y;
            float hdist = sqrtf(hdx * hdx + hdy * hdy);
            if (hdist > 1.0f) {
                b->vel.x += (hdx / hdist) * 120.0f * dt;
                b->vel.y += (hdy / hdist) * 120.0f * dt;
            }
        }

        b->pos.x += b->vel.x * dt;
        b->pos.y += b->vel.y * dt;

        /* Arena Boundary Despawn */
        if (b->pos.x < 10 || b->pos.x > SCREEN_WIDTH - 10 ||
            b->pos.y < 10 || b->pos.y > SCREEN_HEIGHT - 10) {
            b->active = false;
            continue;
        }

        /* Colisao Circulo vs Retangulo do Player */
        if (CheckCollisionCircleRec(b->pos, b->radius, player->rect)) {
            b->active = false;

            if (b->type == BULLET_BLIND) {
                typing_engine_apply_blindness(te, DURATION_BLIND);
                if (status_applied_out) *status_applied_out = "BLIND";
            } else if (b->type == BULLET_CONFUSE) {
                player_apply_confuse(player, DURATION_CONFUSE);
                if (status_applied_out) *status_applied_out = "CONFUSE";
            } else {
                /* Dano real */
                if (player_take_damage(player, 1)) {
                    hit_player = true;
                }
            }
        }
    }

    /* 3. Atualiza Lasers */
    for (int i = 0; i < MAX_LASERS; i++) {
        if (!bm->lasers[i].active) continue;

        Laser *l = &bm->lasers[i];
        if (l->warning_timer > 0.0f) {
            l->warning_timer -= dt;
            if (l->warning_timer <= 0.0f) {
                l->is_firing = true;
            }
        } else if (l->active_timer > 0.0f) {
            l->active_timer -= dt;
            /* Dano do laser se colidir */
            if (CheckCollisionRecs(l->rect, player->rect)) {
                if (player_take_damage(player, 1)) {
                    hit_player = true;
                }
            }
            if (l->active_timer <= 0.0f) {
                l->active = false;
            }
        }
    }

    return hit_player;
}

void bullet_mgr_draw(const BulletManager *bm) {
    /* 1. Vortex */
    if (bm->vortex.active) {
        DrawCircleLines(bm->vortex.pos.x, bm->vortex.pos.y, bm->vortex.radius, COLOR_VORTEX);
        DrawCircle(bm->vortex.pos.x, bm->vortex.pos.y, 8.0f, COLOR_VORTEX);
    }

    /* 2. Lasers */
    for (int i = 0; i < MAX_LASERS; i++) {
        if (!bm->lasers[i].active) continue;
        const Laser *l = &bm->lasers[i];
        if (!l->is_firing) {
            /* Linha telegrafada de aviso */
            DrawRectangleLinesEx(l->rect, 1.5f, COLOR_LASER_WARNING);
        } else {
            /* Feixe ativo */
            DrawRectangleRec(l->rect, COLOR_LASER_BEAM);
            DrawRectangleLinesEx(l->rect, 2.0f, WHITE);
        }
    }

    /* 3. Bullets */
    for (int i = 0; i < MAX_BULLETS; i++) {
        if (!bm->bullets[i].active) continue;
        const Bullet *b = &bm->bullets[i];

        Color c = COLOR_BULLET_NORMAL;
        if (b->type == BULLET_HOMING) c = COLOR_BULLET_HOMING;
        else if (b->type == BULLET_BLIND) c = COLOR_BULLET_BLIND;
        else if (b->type == BULLET_CONFUSE) c = COLOR_BULLET_CONFUSE;

        DrawCircleV(b->pos, b->radius, c);
        DrawCircleLines(b->pos.x, b->pos.y, b->radius + 1.0f, WHITE);
    }
}
