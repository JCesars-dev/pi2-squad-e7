#ifndef MENU_H
#define MENU_H

#include "game.h"

void menu_clear_screen(void);
void menu_clear_buffer(void);
int menu_read_int(int min_val, int max_val);
void menu_read_string(char *buffer, int max_len);

void menu_show_header(void);
void menu_show_main(void);
void menu_show_instructions(void);
void menu_show_credits(void);
void menu_show_victory(const GameState *game);
void menu_show_game_over(const GameState *game);
void menu_pause(void);

#endif /* MENU_H */
