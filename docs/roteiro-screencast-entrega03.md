## Roteiro de Gravação e Falas do Screencast — Entrega 03 (FDS)

### Entrega 03: Implementação e Testes de Sistema (US01–US15)

#### Projeto: AI Safety — Alinhamento do Modelo AURA-67 (Squad E7 — CESAR School)

- **Ticket no Jira:** [PI2-211](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-211) (screencast das novas histórias no README) e [PI2-204](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-204) (screencast dos testes, anexado aos cards)
- **Responsável pelo Roteiro:** Larissa Vitória Silva de Almeida (Lead de Engenharia de Software)
- **Artefato Demonstrado:** Vídeo de demonstração do MVP 1 já gravado: jogo AI Safety rodando em C99 + Raylib 5.0, build via Makefile. A narração e as legendas já estão embutidas no vídeo e são transcritas na seção 2
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

### 2. Falas da Narração do Vídeo (Transcrição das Legendas)

As falas abaixo são a transcrição das legendas embutidas no vídeo, com o horário em que cada frase aparece. Os horários foram lidos do vídeo a cada meio segundo, então podem variar alguns instantes.

#### Cena 1: Abertura e Build (00:00 – 00:35)

- **Ação na Tela:** `00:00` slide de abertura "AURA-67 AI Safety". `00:05` Makefile no editor, com as flags `-Wall -Wextra -std=c99 -pedantic`. `00:15` terminal executando o jogo. `00:30` slide "Build validada: C99 + Raylib 5.0", com `make && make windows` e a execução por `./bin/jogo` ou `jogar.bat`.
- **Falas da Narração:**

  > `00:00` "Olá. Somos o squad sete e esse é o nosso jogo AI Safety."
  >
  > `00:09` "O AI Safety está sendo programado em C99 puro, utilizando a Raylib a cento e sessenta frames por segundo."
  >
  > `00:17` "Essa é uma demonstração do jogo rodando em terminal."
  >
  > Sem narração de `00:20` a `00:35`: o jogo executa no terminal e o slide da build aparece.

#### Cena 2: US13 — Menu Principal, Instruções e Configurações (00:35 – 00:55)

- **Ação na Tela:** `00:35` menu "Terminal de Alinhamento: AURA-67", com o quadro "Missão: reprogramar AURA-67 antes do colapso cognitivo". `00:40` modos de operação: Normal (supervisão) e AGI sem limites. `00:50` quadro de controles: `1/M` para Normal e `2/D` para Difícil.
- **Falas da Narração:**

  > `00:37` "No AI Safety entramos na pele de um engenheiro de IA"
  >
  > `00:40` "e temos a missão de reprogramar a IA hostil AURA-67,"
  >
  > `00:44` "inserindo comandos éticos"
  >
  > `00:46` "antes que ela entre em colapso cognitivo."
  >
  > `00:49` "E esse é o menu inicial do jogo."

#### Cena 3: US01 e US02 — Esquiva, Combate e HUD (00:55 – 01:30)

- **Ação na Tela:** `00:55` início da partida: arena com o engenheiro (quadrado ciano) na base e a AURA-67 (losango vermelho) no topo. `01:00` rótulo "Alinhamento estável! (+100)". `01:05` a `01:25` esquivas dos projéteis rosa, com a ética subindo de 10% para 40%. Destacar no HUD:
  1. Barra superior "AURA-67 \[Desalinhada\] — Fase 1".
  2. Blocos de vida no canto inferior esquerdo.
  3. Pontuação e percentual de ética no canto inferior direito.
- **Falas da Narração:**

  > `00:56` "Ao iniciar a partida, assumimos o controle do engenheiro de IA,"
  >
  > `01:00` "representado pelo quadrado azul"
  >
  > `01:02` "e temos que desviar dos projéteis hostis da IA"
  >
  > `01:04` "corrompida, representada pelo quadrado vermelho."
  >
  > `01:09` "Precisamos evitar tomar dano para vencer"
  >
  > `01:12` "e conseguir salvar a IA AURA-67."
  >
  > Sem narração de `01:15` a `01:30`: o jogador desvia dos projéteis e a ética sobe no HUD.

#### Cena 4: US05, US06, US07, US08, US11 e US12 — Motor de Digitação (01:30 – 02:15)

- **Ação na Tela:** `01:30` caixa de comando `>_` na base da tela, com a diretriz ativa, os caracteres corretos em verde, o cursor em amarelo e o contador "Diretriz de alinhamento n/10". `01:40` rótulo "Alinhamento estável! (+100)". `01:50` rótulo "Patch aplicado! (+50)" e caixa de digitação em vermelho. `02:00` a `02:15` novas diretrizes sendo digitadas enquanto o engenheiro desvia.
- **Falas da Narração:**

  > `01:32` "Cada diretriz ética digitada no campo inferior da tela reprograma"
  >
  > `01:36` "os pesos neurais da IA: sobe a barra de alinhamento de 0"
  >
  > `01:39` "a 100% e causa dano à IA hostil."
  >
  > Sem narração de `01:42` a `02:15`: o jogador continua digitando as diretrizes e desviando, com os rótulos "Alinhamento estável!" e "Patch aplicado!" na tela.

#### Cena 5: US03, US04 e US15 — Fases Cognitivas e Vitória (02:15 – 02:45)

- **Ação na Tela:** `02:15` painel lateral "Fase 1 → Fase 2 → Fase 3" e barra superior da AURA-67 mudando de fase. `02:25` Fase 3, com o círculo de área na arena. `02:35` laser vertical na lateral esquerda. `02:40` tela "AURA-67 alinhada com sucesso!" com a "Pontuação constitucional: 800 pontos".
- **Falas da Narração:**

  > `02:18` "A gameplay do jogo é frenética e viciante,"
  >
  > `02:21` "e o jogador precisa de muita destreza nos movimentos e habilidade"
  >
  > `02:24` "no teclado se quiser vencer esse desafio."
  >
  > `02:35` "Ao conseguir a vitória,"
  >
  > `02:36` "a IA é completamente restaurada e é exibida na tela"
  >
  > `02:39` "o relatório final da pontuação obtida na gameplay."

### 3. Diretrizes Técnicas para a Gravação do Vídeo

1. **Narração e Legendas (Requisito FDS):**
   - O vídeo já tem narração e legendas embutidas, que atendem ao "áudio e/ou legendas" da rubrica. A seção 2 é a transcrição delas.
2. **Trechos sem Narração:**
   - `00:20` a `00:37`, `01:15` a `01:32`, `01:42` a `02:18` e `02:27` a `02:35`. Nesses trechos o vídeo mostra só a tela, sem fala nem legenda.
3. **Resolução de Tela:**
   - O vídeo está em 1024×576. Se for exportar ou regravar de novo, usar 1080p (Full HD, 16:9) para os textos do jogo e do terminal ficarem legíveis.
4. **Onde Anexar:**
   - Anexar o screencast aos cards das histórias no Jira (PI2-204 e PI2-205) e publicar o link ou o vídeo no README (PI2-211).
