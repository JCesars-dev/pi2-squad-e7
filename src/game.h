#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LEN 64
#define MAX_DIRECTIVE_LEN 128
#define TOTAL_DIRECTIVES 10
#define INITIAL_LIVES 5
#define MAX_ALIGNMENT 100

typedef struct {
    char text[MAX_DIRECTIVE_LEN];
    char category[40];
    int phase;
    int points;
} Directive;

typedef struct {
    char name[MAX_NAME_LEN];
    int lives;
    int max_lives;
    int score;
    int perfect_count;
    int errors_total;
} Player;

typedef enum {
    DIFFICULTY_NORMAL = 1,
    DIFFICULTY_HARD = 2
} Difficulty;

typedef enum {
    STATE_MENU,
    STATE_PLAYING,
    STATE_GAME_OVER,
    STATE_VICTORY,
    STATE_EXIT
} GameStateEnum;

typedef struct {
    Player player;
    Difficulty difficulty;
    int alignment_percentage;
    int current_directive_index;
    Directive directives[TOTAL_DIRECTIVES];
    GameStateEnum state;
} GameState;

/* Prototipos do Motor de Jogo */
void game_init(GameState *game, const char *player_name, Difficulty difficulty);
void game_load_directives(GameState *game);
void game_run_session(GameState *game);
void game_render_hud(const GameState *game);
void game_render_alignment_bar(int percentage);
int game_calculate_errors(const char *expected, const char *typed);

#endif /* GAME_H */
