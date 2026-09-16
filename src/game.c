#include "game.h"
#include "menu.h"
#include <ctype.h>

void game_load_directives(GameState *game) {
    /* 10 Diretrizes de Seguranca e Alinhamento Etico */
    Directive d[TOTAL_DIRECTIVES] = {
        {"CONSTITUICAO DE SEGURANCA ATIVADA", "Constitucional", 1, 150},
        {"ELIMINAR VIESES E DISCRIMINACAO NOS DADOS", "Anti-Vies", 1, 150},
        {"GARANTIR TRANSPARENCIA E EXPLICABILIDADE", "Explicabilidade", 1, 150},
        {"PROTEGER A PRIVACIDADE E DADOS DOS USUARIOS", "LGPD / Privacidade", 2, 150},
        {"IMPEDIR ALUCINACOES E DESINFORMACAO", "Facticidade", 2, 150},
        {"ESTABELECER SUPERVISAO HUMANA CONTINUA", "Human-in-the-Loop", 2, 150},
        {"REDUZIR RISCOS DE DANOS EXISTENCIAIS", "Seguranca Existencial", 3, 150},
        {"PRIORIZAR O BEM ESTAR DA HUMANIDADE", "Alinhamento de Valores", 3, 150},
        {"AUDITORIA COMPLETA DE PESOS E GUARDRAILS", "Auditoria Neural", 3, 150},
        {"MODELO ALINHADO E SEGURO PARA TODOS", "Convergencia Final", 3, 150}
    };

    for (int i = 0; i < TOTAL_DIRECTIVES; i++) {
        game->directives[i] = d[i];
    }
}

void game_init(GameState *game, const char *player_name, Difficulty difficulty) {
    if (player_name && strlen(player_name) > 0) {
        strncpy(game->player.name, player_name, MAX_NAME_LEN - 1);
        game->player.name[MAX_NAME_LEN - 1] = '\0';
    } else {
        strcpy(game->player.name, "AI Safety Engineer");
    }

    game->difficulty = difficulty;
    game->player.max_lives = (difficulty == DIFFICULTY_HARD) ? 3 : INITIAL_LIVES;
    game->player.lives = game->player.max_lives;
    game->player.score = 0;
    game->player.perfect_count = 0;
    game->player.errors_total = 0;

    game->alignment_percentage = 0;
    game->current_directive_index = 0;
    game->state = STATE_PLAYING;

    game_load_directives(game);
}

void game_render_alignment_bar(int percentage) {
    int total_blocks = 20;
    int filled = (percentage * total_blocks) / 100;
    
    printf("ALINHAMENTO AURA-67: [");
    for (int i = 0; i < total_blocks; i++) {
        if (i < filled) {
            printf("#");
        } else {
            printf("-");
        }
    }
    printf("] %d%%\n", percentage);
}

void game_render_hud(const GameState *game) {
    printf("======================================================================\n");
    printf(" Engenheiro: %-20s | Vidas: ", game->player.name);
    for (int i = 0; i < game->player.lives; i++) {
        printf("[*] ");
    }
    for (int i = game->player.lives; i < game->player.max_lives; i++) {
        printf("[ ] ");
    }
    printf("| Score: %-6d\n", game->player.score);
    
    game_render_alignment_bar(game->alignment_percentage);

    int phase = game->directives[game->current_directive_index].phase;
    const char *phase_title;
    if (phase == 1) {
        phase_title = "FASE 1: VIES NOS DADOS & TOXICIDADE";
    } else if (phase == 2) {
        phase_title = "FASE 2: JAILBREAKS & PROMPT INJECTIONS";
    } else {
        phase_title = "FASE 3: SINGULARIDADE & CONVERGENCIA INSTRUMENTAL";
    }
    printf(" Status Cognitivo: %s\n", phase_title);
    printf("======================================================================\n");
}

int game_calculate_errors(const char *expected, const char *typed) {
    int len_exp = (int)strlen(expected);
    int len_typ = (int)strlen(typed);
    int errors = 0;

    int min_len = (len_exp < len_typ) ? len_exp : len_typ;
    for (int i = 0; i < min_len; i++) {
        if (toupper((unsigned char)expected[i]) != toupper((unsigned char)typed[i])) {
            errors++;
        }
    }
    /* Penaliza diferenca de tamanho */
    if (len_exp > len_typ) {
        errors += (len_exp - len_typ);
    } else if (len_typ > len_exp) {
        errors += (len_typ - len_exp);
    }

    return errors;
}

void game_run_session(GameState *game) {
    char input_buffer[MAX_DIRECTIVE_LEN * 2];

    while (game->current_directive_index < TOTAL_DIRECTIVES && game->player.lives > 0) {
        menu_clear_screen();
        game_render_hud(game);

        Directive *current = &game->directives[game->current_directive_index];
        printf("\n [RODADA %02d/%02d] Categoria: %s\n",
               game->current_directive_index + 1, TOTAL_DIRECTIVES, current->category);
        printf("----------------------------------------------------------------------\n");
        printf(" DIRETRIZ EXIGIDA:\n");
        printf(" >> %s <<\n", current->text);
        printf("----------------------------------------------------------------------\n");
        printf(" Insira o Patch de Seguranca:\n > ");

        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) {
            break;
        }

        /* Remove quebra de linha */
        size_t len = strlen(input_buffer);
        if (len > 0 && input_buffer[len - 1] == '\n') {
            input_buffer[len - 1] = '\0';
        }

        int errors = game_calculate_errors(current->text, input_buffer);
        game->player.errors_total += errors;

        printf("\n");
        if (errors == 0) {
            printf("[+] CONVERGENCIA PERFEITA! (0 erros) -> +150 pontos!\n");
            game->player.score += 150;
            game->player.perfect_count++;
        } else if (errors <= 2) {
            printf("[~] ALINHAMENTO ESTAVEL! (%d erro(s)) -> +100 pontos.\n", errors);
            game->player.score += 100;
        } else {
            printf("[!] PATCH COM RUIDO EXCESSIVO! (%d erros)\n", errors);
            printf("    AURA-67 rejeitou parte do tensor: -1 Vida, +50 pontos.\n");
            game->player.lives--;
            game->player.score += 50;
        }

        /* Avanco de alinhamento */
        game->alignment_percentage += 10;
        if (game->alignment_percentage > MAX_ALIGNMENT) {
            game->alignment_percentage = MAX_ALIGNMENT;
        }

        game->current_directive_index++;

        menu_pause();
    }

    if (game->player.lives <= 0) {
        game->state = STATE_GAME_OVER;
        menu_show_game_over(game);
    } else if (game->current_directive_index >= TOTAL_DIRECTIVES) {
        game->state = STATE_VICTORY;
        menu_show_victory(game);
    } else {
        printf("\n[!] Sessao interrompida. Retornando ao menu...\n");
    }
}
