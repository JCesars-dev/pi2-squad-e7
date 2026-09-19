#ifndef BOSS_H
#define BOSS_H

#include <stdbool.h>

typedef struct {
    int   hp;
    int   max_hp;
    float flash_timer;   
    int   alignment_pct;  

} Boss;

void boss_init(Boss *boss, int max_hp);

void boss_take_damage(Boss *boss, int damage);

#endif 