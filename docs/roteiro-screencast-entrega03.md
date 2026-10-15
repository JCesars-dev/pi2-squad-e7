## Roteiro de Gravação e Falas do Screencast — Entrega 03 (FDS)

### Entrega 03: Implementação e Testes de Sistema (US01–US15)

#### Projeto: AI Safety — Alinhamento do Modelo AURA-67 (Squad E7 — CESAR School)

- **Ticket no Jira:** [PI2-211](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-211) (screencast das novas histórias no README) e [PI2-204](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-204) (screencast dos testes, anexado aos cards)
- **Responsável e Apresentadora:** Larissa Vitória Silva de Almeida (Lead de Engenharia de Software)
- **Artefato Demonstrado:** Vídeo de demonstração do MVP 1 já gravado: jogo AI Safety rodando em C99 + Raylib 5.0, build via Makefile
- **Escopo das Histórias Cobertas:** US01 a US15 (US09, US10 e US14 não aparecem no vídeo)
- **Duração Total Estimada:** 02 minutos e 45 segundos, a duração do vídeo já gravado. Fica na faixa de 1 a 3 minutos usada na Entrega 02.

### 1. Visão Geral da Minutagem e Ações na Tela

O vídeo já gravado tem 2 minutos e 45 segundos, dividido em 5 blocos que o painel lateral marca na tela. Cada cena abaixo segue um desses blocos, com os horários em que as coisas acontecem no vídeo.

| Bloco | Minutagem | Foco / Histórias | Ação Visual na Tela (horários do vídeo) |
| :-: | :-: | :-- | :-- |
| **Cena 1** | `00:00 – 00:35` | Abertura e build (C99 + Raylib 5.0) | `00:00` slide "AURA-67 AI Safety". `00:05` Makefile no editor. `00:15` terminal compilando e executando o jogo. `00:30` slide "Build validada". |
| **Cena 2** | `00:35 – 00:55` | **US13:** Menu principal, instruções e configurações | `00:35` menu "Terminal de Alinhamento: AURA-67" com a missão. `00:40` modos Normal e AGI sem limites. `00:50` controles `1/M` e `2/D`. |
| **Cena 3** | `00:55 – 01:30` | **US01:** Movimentação e esquiva. **US02:** HUD de combate | `00:55` início da partida na arena. `01:00` rótulo "Alinhamento estável! (+100)". `01:05 – 01:25` esquivas, vidas e ética subindo de 10% para 40%. |
| **Cena 4** | `01:30 – 02:15` | **US05, US06, US07, US08, US11, US12:** Motor de digitação | `01:30` caixa de comando `>_` com a diretriz ativa. `01:40` rótulo "Alinhamento estável! (+100)". `01:50` rótulo "Patch aplicado! (+50)" e caixa em vermelho. `02:00` novas diretrizes. |
| **Cena 5** | `02:15 – 02:45` | **US03:** Fases cognitivas. **US04:** Status adversariais. **US15:** Vitória | `02:15` painel "Fase 1 → Fase 2 → Fase 3". `02:25` Fase 3 com círculo de área na arena. `02:35` laser vertical. `02:40` tela "AURA-67 alinhada com sucesso!". |

#### Cobertura das 15 histórias

"No vídeo" diz se a funcionalidade aparece nas imagens gravadas. "Jira" é o status dos cards em 15/10/2026.

| História | Cena | No vídeo | Jira |
| :-- | :-: | :-- | :-- |
| US01: Movimentação e esquiva do jogador | 3 | Sim | Concluído |
| US02: HUD, integridade e barra de alinhamento | 3 | Sim | Concluído |
| US03: Fases cognitivas e padrões de ataque | 5 | Sim | Concluído |
| US04: Efeitos de status (Confusão e Cegueira) | 5 | Parcial: aparecem os projéteis coloridos, mas não os efeitos | Concluído |
| US05: Interface do terminal de diretrizes | 4 | Sim | Concluído |
| US06: Validação de digitação em tempo real | 4 | Sim | Concluído |
| US07: Avaliação de precisão dos patches | 4 | Sim | Concluído |
| US08: Exceções e penalidade de recuo | 4 | Parcial: aparece o alerta vermelho, mas não o recuo | Concluído |
| US09: Coleta de diretrizes constitucionais | — | Não | Concluído |
| US10: Painel de auditoria | — | Não | Concluído |
| US11: Inserção de patches de alinhamento | 4 | Sim | Tarefas pendentes |
| US12: Barra de alinhamento ético | 4 | Sim | Tarefas pendentes |
| US13: Menu principal e modos | 2 | Sim | Concluído |
| US14: Persistência de progresso (Save/Load) | — | Não | Tarefas pendentes (subtarefa em andamento) |
| US15: Condição de sucesso e relatório | 5 | Parcial: aparece a vitória e a pontuação, mas não o relatório de tempo e eficiência | Tarefas pendentes |

### 2. Roteiro de Falas para Narração (Teleprompter)

#### Cena 1: Abertura e Build (00:00 – 00:35)

- **Ação na Tela:** `00:00` slide de abertura "AURA-67 AI Safety". `00:05` Makefile no editor, com as flags `-Wall -Wextra -std=c99 -pedantic`. `00:15` terminal executando o jogo. `00:30` slide "Build validada: C99 + Raylib 5.0", com `make && make windows` e a execução por `./bin/jogo` ou `jogar.bat`.
- **Falas da Narração:**

  > "Olá a todos. Sou Larissa Almeida, Lead de Engenharia de Software da Squad E7, e este é o screencast da Entrega 03 de Fundamentos de Desenvolvimento de Software. Apresentamos o AI Safety, nosso jogo em C99 puro com Raylib 5.0.
  >
  > O projeto compila via Makefile com as flags Wall, Wextra, std c99 e pedantic, roda no terminal e a build foi concluída sem warnings."

#### Cena 2: US13 — Menu Principal, Instruções e Configurações (00:35 – 00:55)

- **Ação na Tela:** `00:35` menu "Terminal de Alinhamento: AURA-67", com o quadro "Missão: reprogramar AURA-67 antes do colapso cognitivo". `00:40` modos de operação: Normal (supervisão) e AGI sem limites. `00:50` quadro de controles: `1/M` para Normal e `2/D` para Difícil.
- **Falas da Narração:**

  > "Na US13, o menu nos coloca na pele de um engenheiro de IA, com a missão de reprogramar a AURA-67 antes do colapso cognitivo.
  >
  > O jogador escolhe o modo Normal ou o Difícil, confere os controles e as ameaças e inicia com a tecla Espaço."

#### Cena 3: US01 e US02 — Esquiva, Combate e HUD (00:55 – 01:30)

- **Ação na Tela:** `00:55` início da partida: arena com o engenheiro (quadrado ciano) na base e a AURA-67 (losango vermelho) no topo. `01:00` rótulo "Alinhamento estável! (+100)". `01:05` a `01:25` esquivas dos projéteis rosa, com a ética subindo de 10% para 40%. Destacar no HUD:
  1. Barra superior "AURA-67 \[Desalinhada\] — Fase 1".
  2. Blocos de vida no canto inferior esquerdo.
  3. Pontuação e percentual de ética no canto inferior direito.
- **Falas da Narração:**

  > "Ao iniciar a partida, assumimos o controle do engenheiro. Na US01, o quadrado ciano se move com WASD ou setas, dentro dos limites da arena, e desvia dos projéteis da AURA-67, o quadrado vermelho no topo.
  >
  > Na US02, o HUD mostra a barra da AURA-67 com a fase ativa, as cinco vidas, a pontuação e o percentual de ética, que sobe a cada diretriz concluída."

#### Cena 4: US05, US06, US07, US08, US11 e US12 — Motor de Digitação (01:30 – 02:15)

- **Ação na Tela:** `01:30` caixa de comando `>_` na base da tela, com a diretriz ativa, os caracteres corretos em verde, o cursor em amarelo e o contador "Diretriz de alinhamento n/10". `01:40` rótulo "Alinhamento estável! (+100)". `01:50` rótulo "Patch aplicado! (+50)" e caixa de digitação em vermelho. `02:00` a `02:15` novas diretrizes sendo digitadas enquanto o engenheiro desvia.
- **Falas da Narração:**

  > "A US05 traz o terminal de diretrizes na base da tela: a frase ativa, os caracteres corretos em verde, o cursor em amarelo e o contador de diretrizes, de 1 a 10.
  >
  > Na US06, a digitação é validada em tempo real e as teclas de movimento não geram erro, então o jogador digita e desvia ao mesmo tempo.
  >
  > Na US07, cada diretriz concluída recebe uma avaliação, como Alinhamento Estável ou Patch Aplicado. Esse é o patch da US11, que reprograma a AURA-67 e faz a barra de alinhamento da US12 subir. Na US08, um erro de digitação faz a caixa piscar em vermelho."

#### Cena 5: US03, US04 e US15 — Fases Cognitivas e Vitória (02:15 – 02:45)

- **Ação na Tela:** `02:15` painel lateral "Fase 1 → Fase 2 → Fase 3" e barra superior da AURA-67 mudando de fase. `02:25` Fase 3, com o círculo de área na arena. `02:35` laser vertical na lateral esquerda. `02:40` tela "AURA-67 alinhada com sucesso!" com a "Pontuação constitucional: 800 pontos".
- **Falas da Narração:**

  > "Na US03, a AURA-67 avança por três fases cognitivas: na primeira, os primeiros ataques; na segunda, padrões de projéteis mais intensos, incluindo os projéteis coloridos de status da US04; na terceira, lasers e evasão de alto risco.
  >
  > Ao completar as dez diretrizes, o alinhamento chega a cem por cento e a US15 exibe a tela de vitória, com a pontuação constitucional da sessão."

### 3. Diretrizes Técnicas para a Gravação do Vídeo

1. **Ritmo de Leitura:**
   - Falar de forma clara e cadenciada, sem pressa. As falas foram dimensionadas para 130 a 140 palavras por minuto, cena a cena, para caber em cada bloco do vídeo.
2. **Sincronia com o Vídeo:**
   - O vídeo já tem narração e legendas automáticas. Se for regravar o áudio, usar as falas acima, cronometradas para os mesmos 5 blocos do painel lateral (Bloco 01 a 05), que marcam onde cada cena começa.
3. **Qualidade do Áudio:**
   - Gravar em ambiente silencioso, com microfone próximo e sem ruídos de fundo ou eco.
4. **Legendas (Requisito FDS):**
   - A rubrica pede áudio e/ou legendas. Usar o texto das falas acima como base para as legendas (YouTube, Clipchamp ou CapCut).
5. **Resolução de Tela:**
   - O vídeo enviado está em 1024×576. Exportar ou regravar em 1080p (Full HD, 16:9) para os textos do jogo e do terminal ficarem legíveis.
6. **Onde Anexar:**
   - Anexar o screencast aos cards das histórias no Jira (PI2-204 e PI2-205) e publicar o link ou o vídeo no README (PI2-211).
