#include "boss.h"
#include "config.h"

#define BOSS_FLASH_DURATION 0.15f

void boss_init(Boss *boss, int max_hp) {
    boss->max_hp = max_hp;
    boss->hp = max_hp;
    boss->flash_timer = 0.0f;
    boss->alignment_pct = 0;
}

void boss_take_damage(Boss *boss, int damage) {
    boss->hp -= damage;
    if (boss->hp < 0) {
        boss->hp = 0;
    }
    boss->flash_timer = BOSS_FLASH_DURATION;
}

void boss_update(Boss *boss, float dt) {
    if (boss->flash_timer > 0.0f) {
        boss->flash_timer -= dt;
    }
}