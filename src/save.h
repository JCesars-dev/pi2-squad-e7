#ifndef SAVE_H
#define SAVE_H

#include <stdbool.h>

/* Cabeçalho de validação de integridade */
#define SAVE_MAGIC_NUMBER 0x41555241 /* Representa 'AURA' em Hex */
#define SAVE_VERSION 1

/* Estrutura contendo o estado exato da partida */
typedef struct {
    int magic;               /* Validação do arquivo */
    int version;             /* Versão do formato do save */
    int score;               /* Pontuação atual */
    int player_hp;           /* Vidas/HP do jogador */
    int boss_hp;             /* Vida da AURA-67 */
    int boss_phase;          /* Fase atual da AURA-67 */
    int boss_alignment_pct;  /* Alinhamento ético (%) */
    int phrase_index;        /* Índice da diretriz (fase de digitação) */
} SaveData;

/* Protótipos das funções de persistência */
bool save_game(const SaveData *data);
bool load_game(SaveData *data);
bool save_exists(void);

/* Protótipo da função de exportação para o ranking (Haskell) */
void save_match_result(int score, int accuracy_pct, int victory);

#endif // SAVE_H