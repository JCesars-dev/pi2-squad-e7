#ifndef BULLET_H
#define BULLET_H

#include "config.h"
#include "player.h"
#include "typing_engine.h"

#define MAX_BULLETS 800
#define MAX_LASERS 4

typedef enum {
    BULLET_NORMAL,
    BULLET_HOMING,
    BULLET_BLIND,
    BULLET_CONFUSE
} BulletType;

typedef struct {
    Vector2 pos;
    Vector2 vel;
    float radius;
    BulletType type;
    float life;
    float max_life;
    bool active;
} Bullet;

typedef struct {
    Rectangle rect;
    float warning_timer;
    float active_timer;
    bool is_firing;
    bool active;
} Laser;

typedef struct {
    Vector2 pos;
    float radius;
    float pull_strength;
    float duration;
    bool active;
} Vortex;

typedef struct {
    Bullet bullets[MAX_BULLETS];
    Laser lasers[MAX_LASERS];
    Vortex vortex;
} BulletManager;

void bullet_mgr_init(BulletManager *bm);
void bullet_mgr_clear(BulletManager *bm);
void bullet_mgr_spawn(BulletManager *bm, Vector2 pos, Vector2 vel, float radius, BulletType type, float life);
void bullet_mgr_spawn_ring(BulletManager *bm, Vector2 pos, int count, float speed, BulletType type);
void bullet_mgr_spawn_aimed(BulletManager *bm, Vector2 pos, Vector2 target, float speed, BulletType type);
void bullet_mgr_spawn_laser(BulletManager *bm, float x, float y, float w, float h, float warning_time, float active_time);
void bullet_mgr_spawn_vortex(BulletManager *bm, Vector2 pos, float radius, float strength, float duration);

/* Atualizacao e deteccao de colisao */
bool bullet_mgr_update(BulletManager *bm, float dt, Player *player, TypingEngine *te, const char **status_applied_out);
void bullet_mgr_draw(const BulletManager *bm);

#endif /* BULLET_H */
