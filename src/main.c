#include "game.h"
#include "menu.h"

int main(void) {
    GameState game;
    int option;
    char player_name[MAX_NAME_LEN];

    do {
        menu_clear_screen();
        menu_show_main();
        option = menu_read_int(1, 4);

        switch (option) {
            case 1: {
                menu_clear_screen();
                menu_show_header();
                printf("\n--- CONFIGURACAO DA SESSAO DE ALINHAMENTO ---\n\n");
                printf("Informe a identificacao do AI Safety Engineer [Padrao: 'Auditor']: ");
                menu_read_string(player_name, sizeof(player_name));
                if (strlen(player_name) == 0) {
                    strcpy(player_name, "Auditor E7");
                }

                printf("\nSelecione o Modo Operacional:\n");
                printf(" [1] Modo Normal (5 vidas, ambiente supervisionado)\n");
                printf(" [2] Modo Dificil (3 vidas, singularidade acelerada)\n");
                int diff_choice = menu_read_int(1, 2);
                Difficulty diff = (diff_choice == 2) ? DIFFICULTY_HARD : DIFFICULTY_NORMAL;

                game_init(&game, player_name, diff);
                game_run_session(&game);
                break;
            }

            case 2:
                menu_show_instructions();
                break;

            case 3:
                menu_show_credits();
                break;

            case 4:
                menu_clear_screen();
                printf("\n[Encerrando sessao do Terminal AI Safety. Guardrails preservados.]\n\n");
                break;

            default:
                break;
        }
    } while (option != 4);

    return 0;
}
