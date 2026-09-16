#ifndef UI_H
#define UI_H

#include "config.h"
#include "player.h"
#include "boss.h"
#include "typing_engine.h"

#define MAX_FLOATING_TEXTS 32
#define MAX_PARTICLES 128

typedef struct {
    char text[64];
    float x, y;
    Color color;
    int font_size;
    float life;
    float max_life;
    bool active;
} FloatingText;

typedef struct {
    Vector2 pos;
    Vector2 vel;
    Color color;
    float size;
    float life;
    bool active;
} Particle;

typedef struct {
    FloatingText texts[MAX_FLOATING_TEXTS];
    Particle particles[MAX_PARTICLES];
    float shake_timer;
    float shake_intensity;
} UIManager;

void ui_init(UIManager *ui);
void ui_trigger_shake(UIManager *ui, float duration, float intensity);
void ui_spawn_floating_text(UIManager *ui, const char *txt, float x, float y, Color color, int font_size, float lifetime);
void ui_spawn_particle_burst(UIManager *ui, float x, float y, Color color, int count);
void ui_update(UIManager *ui, float dt);

void ui_draw_arena_grid(void);
void ui_draw_boss_hp(const Boss *boss);
void ui_draw_player_hp(const Player *player);
void ui_draw_typing_box(const TypingEngine *te);
void ui_draw_floating_texts(const UIManager *ui);
void ui_draw_particles(const UIManager *ui);
void ui_draw_menu(int difficulty);
void ui_draw_game_over(void);
void ui_draw_victory(void);

#endif /* UI_H */
