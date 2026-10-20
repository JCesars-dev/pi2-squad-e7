# Casos de Teste de Sistema — Sprint 01 (Entrega 03 — FDS)

Projeto: AI Safety — Alinhamento do Modelo AURA-67 (Squad E7 — CESAR School)

Os casos abaixo cobrem sete histórias da Sprint 01: **US01, US02, US03, US05, US06, US07 e US13**. Cada caso foi escrito a partir dos Critérios de Confirmação (3Cs) do card da história no Jira, e o teste é feito com o jogo rodando por inteiro (teste de sistema).

## Resumo dos resultados

| História | Casos | Passou | Falhou | Parcial |
| :-- | :-: | :-: | :-: | :-: |
| US01 | 3 | 3 | 0 | 0 |
| US02 | 3 | 3 | 0 | 0 |
| US03 | 3 | 1 | 0 | 2 |
| US05 | 3 | 3 | 0 | 0 |
| US06 | 3 | 0 | 3 | 0 |
| US07 | 5 | 2 | 3 | 0 |
| US13 | 7 | 7 | 0 | 0 |
| **Total** | **27** | **19** | **6** | **2** |

As falhas estão concentradas em **US06** (validação da digitação) e **US07** (avaliação dos patches). Os detalhes de cada falha estão nas observações, no fim do documento.

## Como executar

1. Compilar o projeto: `make clean && make` (Linux ou Ubuntu) ou, no Windows com WSL, `wsl make clean` e depois `wsl make`.
2. Abrir o jogo: `./bin/jogo` (Linux ou Ubuntu) ou `wsl ./bin/jogo` (Windows com WSL).
3. Executar os passos de cada caso, na ordem, e comparar com o resultado esperado.
4. Preencher as colunas **Resultado obtido** (Passou, Falhou, Parcial ou Não testado) e **Evidência** (horário do trecho no screencast).
5. Se o caso falhar, abrir uma issue no GitHub com o modelo de bug, citando o ID do caso e o card do Jira.

## US01 — Movimentação e Esquiva do Jogador na Arena de Combate ([PI2-67](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-67))

| ID | Critério (Jira) | Passos | Resultado esperado | Resultado obtido | Evidência |
| :-- | :-: | :-- | :-- | :-: | :-: |
| CT-US01-01 | 1 | Iniciar uma partida. Pressionar W, A, S e D, uma tecla por vez. Repetir com as setas direcionais. | O engenheiro (quadrado ciano) se move para cima, esquerda, baixo e direita de forma fluida (alvo de 60 FPS, 16,667 ms por quadro no log do jogo). | Passou | `00:55 – 01:25` |
| CT-US01-02 | 2 | Manter o engenheiro andando contra cada uma das quatro bordas da arena. | O engenheiro para na borda e não atravessa o limite da arena de contenção. | Passou | Vídeo de testes, `0:20 – 0:34`: base em `0:21`, topo em `0:24`, direita em `0:26` e esquerda em `0:29` |
| CT-US01-03 | 3 | Deixar um projétil disparado pela AURA-67 atingir o engenheiro. | O projétil colide com o engenheiro e a integridade (vidas) diminui. | Passou | `01:55 – 02:10` e `02:20 – 02:31` (vidas diminuem) |

## US02 — HUD de Combate, Integridade e Barra de Alinhamento da IA ([PI2-68](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-68))

| ID | Critério (Jira) | Passos | Resultado esperado | Resultado obtido | Evidência |
| :-- | :-: | :-- | :-- | :-: | :-: |
| CT-US02-01 | 1 | Iniciar uma partida e observar o topo da tela. | A barra da AURA-67 aparece no topo central, com a fase cognitiva ativa identificada (por exemplo, "Fase 1"). | Passou | `00:55 – 01:30` |
| CT-US02-02 | 2 | Observar o contador de vidas no canto inferior esquerdo. Deixar o engenheiro ser atingido mais de uma vez. | O contador começa com 5 vidas e diminui uma a cada acerto sofrido. | Passou | `00:55` (5 vidas) e `01:55 – 02:10` (diminuem) |
| CT-US02-03 | 3 | Digitar as diretrizes uma a uma e acompanhar o percentual de ética no HUD. | O percentual de alinhamento ético avança de 0% a 100% conforme as diretrizes válidas são concluídas. | Passou | `01:00` (ética em 10%) até `02:40` (vitória) |

## US03 — Transição de Fases Cognitivas e Padrões de Ataque da AURA-67 ([PI2-69](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-69))

| ID | Critério (Jira) | Passos | Resultado esperado | Resultado obtido | Evidência |
| :-- | :-: | :-- | :-- | :-: | :-: |
| CT-US03-01 | 1 | Iniciar uma partida e digitar as diretrizes até a barra da AURA-67 passar de 66% e depois de 33% de integridade. | A AURA-67 muda de fase (Fase 1, 2 e 3) e altera o comportamento e as cores ao atingir esses limiares. | Parcial: a troca de fase aparece, mas a mudança de cor não está clara | Fase 1 em `00:55`, Fase 2 em `01:30` e Fase 3 em `02:10`. A mudança de cor não aparece com clareza |
| CT-US03-02 | 2 | Observar os ataques da AURA-67 em cada fase. | Cada fase traz padrões novos na arena: anéis e tiros na Fase 1, espirais e projéteis de status na Fase 2, lasers com aviso e vórtice na Fase 3. | Parcial: aparecem os projéteis de status, o círculo e o laser; anel e espiral não estão claros | Fase 2 em `01:30 – 02:10` (projéteis roxos), círculo de área em `02:25` e laser vertical em `02:35`. Anel e espiral não estão claros |
| CT-US03-03 | 3 | Completar as dez diretrizes (100% de alinhamento). | A AURA-67 para de atacar e o jogo mostra a tela de vitória. | Passou | `02:40 – 02:45` |

## US05 — Interface do Terminal de Inserção de Diretrizes ([PI2-71](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-71))

| ID | Critério (Jira) | Passos | Resultado esperado | Resultado obtido | Evidência |
| :-- | :-: | :-- | :-- | :-: | :-: |
| CT-US05-01 | 1 | Iniciar uma partida e olhar a caixa de comando `>_` na base da tela. | A diretriz ativa aparece de forma clara, com bom contraste: caracteres já digitados em verde, cursor em amarelo e o restante em cinza. | Passou | `00:55 – 02:35` |
| CT-US05-02 | 2 | Digitar os primeiros caracteres da diretriz, corretamente, um por um. | O cursor avança a cada caractere digitado corretamente. | Passou | `01:30 – 01:45` |
| CT-US05-03 | 3 | Concluir uma diretriz e observar o contador. | A barra mostra o progresso de diretrizes no formato "Diretriz de alinhamento n/10" e o número aumenta ao concluir cada diretriz. | Passou | `01:10` (3/10) até `02:30` (10/10) |

## US06 — Validação de Digitação de Tokens em Tempo Real ([PI2-72](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-72))

| ID | Critério (Jira) | Passos | Resultado esperado | Resultado obtido | Evidência |
| :-- | :-: | :-- | :-- | :-: | :-: |
| CT-US06-01 | 1 | Com o som ligado, digitar um caractere correto da diretriz ativa. | O cursor avança e o jogo emite o som de tecla mecânica. | Falhou: o jogo não emite som de tecla | Vídeo de testes, legenda em `1:23`. O vídeo está sem áudio; no código não há nenhuma chamada de áudio em `src/` |
| CT-US06-02 | 2 | Digitar uma diretriz que tenha mais de uma palavra, incluindo a tecla Espaço entre os termos. | O Espaço é aceito como separador de termos e a digitação continua sem erro. | Falhou: cada Espaço conta como erro | Vídeo de testes, `1:12`, `1:14` e `1:21` (a caixa fica vermelha a cada Espaço) |
| CT-US06-03 | 3 | Durante a digitação, pressionar W, A, S, D e as setas para mover o engenheiro. | O personagem se move e a frase digitada não sofre penalidade nem aparece erro de digitação. | Falhou: as setas passam, mas W, A, S e D geram erro | Vídeo de testes, `0:36 – 0:58`: setas em `0:39 – 0:46` e W, A, S, D em `0:49 – 0:56` (piscadas em `0:52` e `0:54`). A piscada de `0:41` é de tecla errada |

## US07 — Sistema de Avaliação de Precisão e Convergência de Patches ([PI2-73](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-73))

| ID | Critério (Jira) | Passos | Resultado esperado | Resultado obtido | Evidência |
| :-- | :-: | :-- | :-- | :-: | :-: |
| CT-US07-01 | 1 | Concluir uma diretriz digitando a frase inteira. | O índice de caracteres volta a zero, a próxima diretriz aparece e o alinhamento da AURA-67 recebe o impacto (100 pontos). | Passou | Vídeo de testes, `1:26`: a frase termina, a próxima aparece (2/10) e a barra da AURA-67 diminui. O rótulo mostra +50 de pontuação; o dano ao chefe por frase é 100 (`BOSS_DAMAGE_PER_PHRASE`) |
| CT-US07-02 | 2 | Concluir uma diretriz sem cometer nenhum erro de digitação. | Aparece o rótulo "CONVERGÊNCIA PERFEITA!" (dourado) sobre a AURA-67. | Falhou: cada Espaço conta como erro | Vídeo de testes, `1:02 – 1:26`: a frase termina em "PATCH APLICADO! (+50)", e não em "CONVERGÊNCIA PERFEITA!" |
| CT-US07-03 | 2 | Concluir uma diretriz com 1 ou 2 erros. | Aparece o rótulo "ALINHAMENTO ESTÁVEL!" (verde neon). | Falhou: cada Espaço conta como erro | Vídeo de testes, `1:02 – 1:26`: a frase termina em "PATCH APLICADO! (+50)", e não em "ALINHAMENTO ESTÁVEL!" |
| CT-US07-04 | 2 | Concluir uma diretriz com 3 ou mais erros. | Aparece o rótulo "PATCH APLICADO!" (ciano). | Passou | Vídeo de testes, `1:26` ("PATCH APLICADO! (+50)") |
| CT-US07-05 | 3 | Com o som ligado, concluir uma diretriz. | Toca um efeito sonoro de arpejo ascendente que confirma a conclusão. | Falhou: o jogo não toca som ao concluir a frase | Vídeo de testes, legenda em `1:23`. O vídeo está sem áudio; no código não há nenhuma chamada de áudio em `src/` |

## US13 — Menu Principal, Instruções e Configurações ([PI2-79](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-79))

| ID | Critério (Jira) | Passos | Resultado esperado | Resultado obtido | Evidência |
| :-- | :-: | :-- | :-- | :-: | :-: |
| CT-US13-01 | 1 | Abrir o jogo e observar a tela inicial. | O menu principal aparece em estética de terminal futurista, com o título "Terminal de Alinhamento: AURA-67". | Passou | `00:35 – 00:55` |
| CT-US13-02 | 2 | No menu, pressionar `1` (ou `N`) e depois `2` (ou `D`). | O modo operacional muda entre Normal (supervisionado) e Difícil, com feedback visual na tela. | Passou | Vídeo de testes, `0:14 – 0:19`: Normal, depois Difícil (vermelho) e de volta ao Normal |
| CT-US13-03 | 3 | Ler o guia de controles e o quadro de ameaças cognitivas no menu. | O guia de controles e as ameaças da AURA-67 aparecem centralizados e legíveis. | Passou | `00:35 – 00:55` |
| CT-US13-04 | 4 | No menu, pressionar Espaço. | O jogo sai do menu e entra no combate (estado STATE_MENU para STATE_COMBAT). | Passou | `00:50 – 00:56` (do menu para a arena) |
| CT-US13-05 | 5 | Jogar até a tela final, pressionar `M` para voltar ao menu e iniciar outra partida com Espaço. | A nova partida começa limpa: vidas, ética, pontuação, chefe e diretrizes voltam ao estado inicial. | Passou | Vídeo de testes, `1:33 – 1:38`: Game Over em `1:33`, menu em `1:36` (cerca de 1 s) e partida nova em `1:37` (5 vidas, pontos 0000, ética 0%) |
| CT-US13-06 | 6 | Rodar `make clean && make` no terminal. | O projeto compila em C99 sem erros e sem warnings (flags `-Wall -Wextra -std=c99 -pedantic`). | Passou | Vídeo de testes, `0:00 – 0:14`: `make clean` e `make`, com "Compilacao... concluida com sucesso!" e sem warnings |
| CT-US13-07 | 5 | Jogar até as vidas acabarem (Game Over) e apertar `R`. | A partida recomeça direto, limpa: 5 vidas, ética 0%, pontos 0000, diretriz 1/10 e a AURA-67 com a barra cheia. | Passou | Vídeo de testes, `1:40 – 1:45`: Game Over em `1:40` (cerca de 0,5 s) e partida nova em `1:41` (5 vidas, pontos 0000, ética 0%) |

## Observações sobre a evidência

* **Resumo dos 27 casos:** 19 passaram, 6 falharam e 2 passaram só em parte (CT-US03-01 e CT-US03-02, em que a mudança de cor e os padrões de anel e espiral não ficam claros no vídeo).
* **Falhas encontradas (viram issues no GitHub):**
  * **Espaço conta como erro** (CT-US06-02, CT-US07-02 e CT-US07-03): em `src/main.c`, o Espaço é processado duas vezes (no loop de `GetCharPressed` e em `IsKeyPressed(KEY_SPACE)`). Como todas as 10 frases têm de 3 a 6 espaços, toda frase termina com "PATCH APLICADO".
  * **W, A, S e D geram erro de digitação** (CT-US06-03): a checagem compara com os códigos das letras maiúsculas, e a digitação normal gera minúsculas. As setas não têm o problema.
  * **O jogo não tem som** (CT-US06-01 e CT-US07-05): não há nenhuma chamada de áudio em `src/` nem arquivo de som no repositório.
* **Vídeos:** o **vídeo de testes** (`docs/screencast_testes_sprint01.mov`, 1:46, com legendas e sem áudio) é a evidência principal, e o **vídeo de demonstração** (`docs/screencast_demonstracao_lofi.mp4`, 02:45) é complementar. Na coluna **Evidência**, "Vídeo de testes" indica o primeiro, e quando não está indicado o horário é do segundo. Os horários foram lidos a cada 0,1 ou 0,5 s e podem variar alguns instantes.
* **Pontos do vídeo de testes que as legendas não explicam:** em `0:41` a caixa fica vermelha por uma tecla errada (o cursor está parado no T), e não pelas setas. Em `0:47` e `0:48` as piscadas são dos Espaços. Em `1:06` e `1:07` são duas teclas erradas. Em `1:21` a piscada é do terceiro Espaço. O Game Over do `R` aparece por cerca de 0,5 s (`1:40`).
* O vídeo mostra o resultado na tela, mas não as teclas pressionadas. Por isso, ele comprova o que aconteceu, e não qual tecla foi usada.
* O vídeo de demonstração tem um corte em `02:15`: a partida passa da Fase 3, com 3 vidas e ética em 70%, para a Fase 1, com 5 vidas e ética em 30%. O trecho final (até a vitória) é de outra gravação.
* No CT-US02-03, o vídeo de demonstração mostra a ética subindo de 0% até 90% e termina na tela de vitória, mas o 100% em si não aparece em um quadro. No CT-US01-01, o vídeo mostra o movimento nas quatro direções, mas não mostra quais teclas foram usadas nem os 60 FPS.
* **Como os resultados foram preenchidos:** os casos do vídeo de testes seguem as legendas e as imagens do vídeo, que foi gravado pelo grupo. Os demais vêm da análise do vídeo de demonstração. "Passou" significa que o resultado esperado aparece nas imagens. Quem executar os casos deve confirmar ou corrigir cada resultado.
