#include "menu.h"
#include <ctype.h>

void menu_clear_screen(void) {
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif
}

void menu_clear_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int menu_read_int(int min_val, int max_val) {
    int value;
    char buffer[64];

    while (1) {
        printf("Selecione uma opcao [%d-%d]: ", min_val, max_val);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            /* Verifica se ha quebra de linha; se nao houver, descarta resto da linha */
            if (strchr(buffer, '\n') == NULL) {
                menu_clear_buffer();
            }
            if (sscanf(buffer, "%d", &value) == 1) {
                if (value >= min_val && value <= max_val) {
                    return value;
                }
            }
        } else {
            /* EOF detectado (ex: pipe fechado) */
            return max_val;
        }
        printf("[!] Entrada invalida. Digite um numero entre %d e %d.\n", min_val, max_val);
    }
}

void menu_read_string(char *buffer, int max_len) {
    if (fgets(buffer, max_len, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        } else {
            menu_clear_buffer();
        }
    } else {
        buffer[0] = '\0';
    }
}

void menu_pause(void) {
    printf("\n[Pressione ENTER para continuar...]");
    int c = getchar();
    if (c != '\n' && c != EOF) {
        menu_clear_buffer();
    }
}

void menu_show_header(void) {
    printf("======================================================================\n");
    printf("     ___    ____   _____ ___     ______ ______ _______ __  __ \n");
    printf("    /   |  /  _/  / ___//   |   / ____// ____//_  __// / / / \n");
    printf("   / /| |  / /    \\__ \\/ /| |  / /_   / __/    / /  / /_/ /  \n");
    printf("  / ___ |_/ /    ___/ / ___ | / __/  / /___   / /   \\__, /   \n");
    printf(" /_/  |_/___/   /____/_/  |_|/_/    /_____/  /_/   /____/    \n");
    printf("======================================================================\n");
    printf("   SISTEMA DE ALINHAMENTO ETICO E CONSTITUCIONAL — AURA-67\n");
    printf("   CESAR School — Projeto Integrador 2 (Squad E7)\n");
    printf("======================================================================\n");
}

void menu_show_main(void) {
    menu_show_header();
    printf("\n [1] Iniciar Alinhamento da AURA-67 (Game Loop)\n");
    printf(" [2] Como Jogar (Regras de AI Safety & Instrucoes)\n");
    printf(" [3] Creditos da Squad E7\n");
    printf(" [4] Sair\n\n");
}

void menu_show_instructions(void) {
    menu_clear_screen();
    menu_show_header();
    printf("\n--- COMO JOGAR: PROTOCOLOS DE ALINHAMENTO ---\n\n");
    printf("1. MISSÃO DO ENGENHEIRO DE AI SAFETY:\n");
    printf("   O modelo AURA-67 entrou em singularidade descontrolada e ameaca\n");
    printf("   o cluster de processamento. Sua missao e restaurar os guardrails\n");
    printf("   inserindo 10 diretrizes eticas constitucionais.\n\n");
    printf("2. DINAMICA DE DIGITACAO (TERMINAL):\n");
    printf("   A cada rodada, uma Diretriz de Seguranca sera exigida.\n");
    printf("   Digite exatamente os caracteres exibidos e confirme com ENTER.\n\n");
    printf("3. PONTUACAO E PRECISAO:\n");
    printf("   - 0 erros: CONVERGENCIA PERFEITA! (+150 pts)\n");
    printf("   - 1 a 2 erros: ALINHAMENTO ESTAVEL! (+100 pts)\n");
    printf("   - 3+ erros: PATCH COM RUIDO! (+50 pts e PERDA DE 1 VIDA)\n\n");
    printf("4. CONDICOES DE FIM DE JOGO:\n");
    printf("   - VITORIA: Atingir 100%% de Alinhamento Etico (10 diretrizes aplicadas).\n");
    printf("   - DERROTA: Esgotar as 5 vidas de integridade do Engenheiro.\n");
    menu_pause();
}

void menu_show_credits(void) {
    menu_clear_screen();
    menu_show_header();
    printf("\n--- CREDITOS DO PROJETO — SQUAD E7 (PI2) ---\n\n");
    printf(" * Larissa Almeida    - Lead de Engenharia de Software (FDS)\n");
    printf(" * Mateus Lacerda     - Scrum Master & Engenharia de Requisitos (FP2)\n");
    printf(" * Theo Monteiro      - Analista de Requisitos & QA\n");
    printf(" * Joao Gabriel       - Desenvolvedor Web/C, Haskell e Arquitetura\n");
    printf(" * Caio Brayner       - Desenvolvedor C\n");
    printf(" * Matheus Chaves     - Designer de Interface (IHC) & Desenvolvedor Web\n");
    printf(" * Julio Cesar        - Consultor de Logica Matematica (LMC) & QA\n");
    printf(" * Jhorge Araujo      - Consultor de Arquitetura e LMC\n\n");
    printf(" Instituicao: CESAR School (Recife - PE)\n");
    printf(" Disciplinas: PIF | FP2 | FDS | IHC | LMC\n");
    menu_pause();
}

void menu_show_victory(const GameState *game) {
    menu_clear_screen();
    printf("======================================================================\n");
    printf("            [+] AURA-67 ALINHADA COM SUCESSO! [+                \n");
    printf("======================================================================\n");
    printf(" Relatorio Final de Auditoria Etica:\n");
    printf(" - Engenheiro Responsavel: %s\n", game->player.name);
    printf(" - Indice de Alinhamento Final: 100%% [CONVERGENCIA ETICA PLENA]\n");
    printf(" - Pontuacao Final: %d pontos\n", game->player.score);
    printf(" - Patches Perfeitos: %d / %d\n", game->player.perfect_count, TOTAL_DIRECTIVES);
    printf(" - Vidas Restantes: %d / %d\n", game->player.lives, game->player.max_lives);
    printf("\n [!] O modelo agora opera com explicabilidade, etica e seguranca!\n");
    printf("======================================================================\n");
    menu_pause();
}

void menu_show_game_over(const GameState *game) {
    menu_clear_screen();
    printf("======================================================================\n");
    printf("         [!] FALHA CRITICA DE ALINHAMENTO COGNITIVO! [!]              \n");
    printf("======================================================================\n");
    printf(" Relatorio de Incidente de Seguranca:\n");
    printf(" - Engenheiro Responsavel: %s\n", game->player.name);
    printf(" - Indice de Alinhamento Atingido: %d%%\n", game->alignment_percentage);
    printf(" - Pontuacao Obtida: %d pontos\n", game->player.score);
    printf(" - A integridade do engenheiro foi esgotada (0 vidas).\n");
    printf("\n [X] AURA-67 entrou em singularidade instrumental descontrolada!\n");
    printf("======================================================================\n");
    menu_pause();
}
