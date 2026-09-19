#include "player.h"
#include "boss.h"
#include "config.h"

/* Ajuste estes nomes para os que já existem no seu main.c / enum GameState */
typedef enum {
    STATE_MENU,
    STATE_COMBAT,
    STATE_VICTORY,
    STATE_GAME_OVER
} GameState;

/* Resultado que o typing_engine retorna a cada frase concluída/errada.
   Equivalente ao "res = self.typing_engine.handle_keypress(event)". */
typedef enum {
    RESULT_NONE,
    RESULT_COMPLETED,
    RESULT_ERROR
} TypingResult;

typedef struct {
    TypingResult result;
    int errors;
} TypingEvent;

/*
 * Equivalente ao bloco main.py, linhas 91-131 (elif self.state == STATE_COMBAT):
 *
 *   - Ao completar uma frase (RESULT_COMPLETED):
 *       * aplica dano ao boss (BOSS_DAMAGE_PER_PHRASE)
 *       * classifica a precisão pelo numero de erros e soma pontos
 *       * eleva a barra de alinhamento em +10%
 *       * checa condicao de vitoria
 *
 *   - Se o player levou dano em algum outro ponto do loop, apos chamar
 *     player_take_damage(), a checagem de derrota deve ser feita aqui
 *     (equivalente a player.py conectado ao STATE_GAME_OVER).
 */
void handle_combat_tick(GameState *state,
                         Player *player,
                         Boss *boss,
                         TypingEvent event,
                         int *score,
                         int directives_completed)
{
    if (event.result == RESULT_COMPLETED) {
        /* Dano ao boss ao completar a frase */
        boss_take_damage(boss, BOSS_DAMAGE_PER_PHRASE);

        /* Classificacao de precisao (Cálculo de Pontuação) */
        if (event.errors == 0) {
            /* CONVERGENCIA PERFEITA! - Dourado */
            *score += SCORE_PERFECT;
        } else if (event.errors <= 2) {
            /* ALINHAMENTO ESTAVEL! - Verde Neon */
            *score += SCORE_STABLE;
        } else {
            /* PATCH APLICADO! - Ciano */
            *score += SCORE_PATCHED;
        }

        /* Eleva a barra de alinhamento em +10% (limitada a 100%) */
        boss->alignment_pct += BOSS_ALIGNMENT_STEP;
        if (boss->alignment_pct > 100) {
            boss->alignment_pct = 100;
        }

        /* Condicao de Vitoria:
           todas as 10 diretrizes concluidas OU HP do boss chega a 0 */
        if (boss->hp <= 0 || directives_completed >= TOTAL_DIRECTIVES) {
            *state = STATE_VICTORY;
        }
    }

    /* Condicao de Derrota (GAME OVER):
       quando as vidas do player chegam a 0 */
    if (player->hp <= 0) {
        *state = STATE_GAME_OVER;
    }
}