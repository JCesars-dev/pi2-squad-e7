# Especificação de Histórias de Usuário (US01 a US15)
## Projeto: AI Safety — Alinhamento do Modelo AURA-67 (Squad E7 - PI2)

Este documento contém o Product Backlog detalhado no padrão **3Cs (Card, Conversation, Confirmation)** e aderente aos critérios **INVEST**, cobrindo todas as mecânicas de **AI Safety** para a Entrega 01 do Projeto Integrador 2 (CESAR School).

---

## Módulo 1: Arena de Combate e Movimentação Tática

### US01: Movimentação e Esquiva do Jogador na Arena de Combate
* **Card (Cartão):**
  Como AI Safety Engineer, eu gostaria de movimentar meu operador e desviar de projéteis na arena de combate usando o teclado para sobreviver aos ataques da AURA-67 enquanto digito diretrizes éticas.
* **Conversation (Conversa):**
  O motor gráfico em Raylib C99 renderiza a arena de combate com limites físicos rígidos, permitindo movimentação fluida do engenheiro (WASD e setas direcionais a 60 FPS). O jogador deve desviar de projéteis balísticos disparados pela AURA-67 e evitar colisão com as bordas da arena.
* **Confirmation (Critérios de Confirmação):**
  1. O jogador consegue se movimentar para frente, trás, esquerda e direita usando W, A, S, D ou setas direcionais a 60 FPS estáveis.
  2. O sistema de colisão impede que o operador atravesse as bordas delimitadoras da arena de contenção.
  3. O operador sofre colisão precisa contra os projéteis balísticos disparados pelo boss, reduzindo sua integridade (vidas).

---

---

### US02: HUD de Combate, Integridade e Barra de Alinhamento da IA
* **Card (Cartão):**
  Como jogador, eu gostaria de visualizar no HUD a integridade do meu operador (vidas restantes), a barra de vida da AURA-67 e a porcentagem de alinhamento ético (0% a 100%) para monitorar o estado do confronto em tempo real.
* **Conversation (Conversa):**
  Durante o combate na arena, a interface superior exibe a telemetria do confronto: a barra de vida da AURA-67 (1000 HP), o contador de integridade do jogador (5 vidas em blocos cianos) e a porcentagem de alinhamento constitucional. Ao sofrer dano ou avançar na reprogramação do modelo, o HUD atualiza os indicadores instantaneamente com efeitos de pulsação e alerta crítico quando a vida do jogador atinge níveis baixos.
* **Confirmation (Critérios de Confirmação):**
  1. O HUD exibe a barra de vida da AURA-67 no topo central com identificação clara da fase cognitiva ativa.
  2. O contador de integridade do jogador exibe as 5 vidas disponíveis, decrementando a cada acerto sofrido.
  3. A barra de Alinhamento Ético avança de 0% a 100% conforme diretrizes válidas são concluídas.

---

### US03: Transição de Fases Cognitivas e Padrões de Ataque da AURA-67
* **Card (Cartão):**
  Como jogador, eu gostaria que a AURA-67 transicionasse entre 3 fases cognitivas com padrões de ataque progressivamente mais desafiadores à medida que sua integridade é reduzida.
* **Conversation (Conversa):**
  O chefe AURA-67 opera em 3 fases comportamentais baseadas no HP restante:
  * **Fase 1 (100% a 67% HP — Viés nos Dados):** Tiros normais direcionados, anéis circulares de projéteis e chuva de dados.
  * **Fase 2 (66% a 34% HP — Injeção de Prompt / Jailbreak):** Padrões em espiral contínua e projéteis adversariais de status.
  * **Fase 3 (33% a 0% HP — Convergência Instrumental):** Disparo de lasers massivos com aviso prévio e vórtice gravitacional que atrai o jogador.
* **Confirmation (Critérios de Confirmação):**
  1. A AURA-67 altera seu comportamento e cores ao atingir os limiares de 66% e 33% de integridade.
  2. Cada fase introduz novos padrões balísticos na arena (anel, espiral, lasers e vórtice).
  3. Ao atingir 0 de integridade ou 100% de alinhamento, a AURA-67 encerra os ataques e o jogo transiciona para a tela de vitória.

---

### US04: Sistema de Efeitos de Status Adversariais (Confusão e Cegueira)
* **Card (Cartão):**
  Como jogador, eu gostaria de enfrentar projéteis adversariais especiais disparados pela AURA-67 que aplicam debuffs temporários, exigindo adaptação rápida durante o combate.
* **Conversation (Conversa):**
  Além de projéteis comuns de dano, a AURA-67 projeta ataques adversariais específicos de segurança de IA:
  * **Projétil Confuse (Magenta):** Inverte temporariamente os eixos de movimentação WASD/setas do jogador por 4 segundos.
  * **Projétil Blind (Roxo):** Escurece a visão da arena com um efeito de máscara escura ao redor do jogador por 3.5 segundos, dificultando a previsão de projéteis.
* **Confirmation (Critérios de Confirmação):**
  1. O projétil Confuse aplica o status de confusão por 4 segundos, invertendo os comandos direcionais.
  2. O projétil Blind aplica o efeito visual de visão reduzida na arena por 3.5 segundos.
  3. Os efeitos possuem contadores de duração independentes e retornam ao estado normal ao expirarem.

---

## Módulo 2: Motor de Digitação e Inserção de Diretrizes Éticas

### US05: Interface do Terminal de Inserção de Diretrizes
* **Card (Cartão):**
  Como engenheiro, eu gostaria de acessar uma caixa de comando no terminal neural para visualizar a diretriz ética que deve ser digitada para reprogramar o modelo AURA-67.
* **Conversation (Conversa):**
  A interface do jogo apresenta uma caixa de digitação retroiluminada na base da tela, exibindo o ícone de prompt (`>_`), a frase ética ativa, os caracteres já validados em verde neon, o cursor ativo em amarelo e o texto restante em cinza.
* **Confirmation (Critérios de Confirmação):**
  1. A diretriz de alinhamento ativa é renderizada com clareza visual e contraste de cores.
  2. O cursor avança dinamicamente à medida que cada caractere é digitado corretamente.
  3. A barra exibe o progresso de diretrizes (ex: *DIRETRIZ DE ALINHAMENTO 1/10*).

---

### US06: Validação de Digitação de Tokens em Tempo Real
* **Card (Cartão):**
  Como jogador, eu gostaria que a digitação das diretrizes reconhecesse caracteres e espaços em tempo real, sem penalizar as teclas de esquiva do engenheiro.
* **Conversation (Conversa):**
  O motor de digitação intercepta o teclado e valida cada caractere da diretriz constitucional. Teclas de movimentação (WASD e setas direcionais) são filtradas para permitir esquiva contínua de projéteis sem gerar erros de digitação acidentais.
* **Confirmation (Critérios de Confirmação):**
  1. Digitar o caractere correto avança o cursor e emite feedback sonoro de tecla mecânica.
  2. A tecla [Espaço] é devidamente tratada na separação de termos da diretriz.
  3. Pressionar WASD ou setas direcionais move o personagem sem gerar penalidade de digitação na frase.

---

### US07: Sistema de Avaliação de Precisão e Convergência de Patches
* **Card (Cartão):**
  Como jogador, eu gostaria de receber uma avaliação de qualidade ao concluir cada diretriz para incentivar digitação precisa sob pressão.
* **Conversation (Conversa):**
  Ao completar uma diretriz ética, o sistema avalia a quantidade de erros cometidos durante a digitação daquela oração e emite um rótulo flutuante sobre a AURA-67 acompanhado de partículas neon:
  * 0 Erros: *CONVERGÊNCIA PERFEITA!* (Dourado)
  * 1 a 2 Erros: *ALINHAMENTO ESTÁVEL!* (Verde Neon)
  * 3+ Erros: *PATCH APLICADO!* (Ciano)
* **Confirmation (Critérios de Confirmação):**
  1. Completar a frase zera o índice de caracteres e aplica 100 de impacto no alinhamento da AURA-67.
  2. O rótulo flutuante correspondente à pontuação de erros é exibido na tela.
  3. Um efeito sonoro de arpeggio ascendente confirma a conclusão da diretriz.

---

### US08: Tratamento de Exceções e Penalidade de Recuo de Tokens
* **Card (Cartão):**
  Como engenheiro, eu gostaria de ser alertado visual e sonoramente ao cometer erros de digitação ou ser atingido por ataques adversariais para me reorientar rapidamente.
* **Conversation (Conversa):**
  Digitar uma tecla incorreta gera um alerta visual de *ERRO DE SINTAXE!* e faz a caixa de digitação piscar em vermelho. Caso o engenheiro seja atingido por uma sobrecarga de hardware ou token corrompido, ocorre um recuo de até 3 caracteres já digitados como penalidade de instabilidade.
* **Confirmation (Critérios de Confirmação):**
  1. Caracteres digitados incorretamente emitem som de zumbido de erro e incrementam o contador de erros.
  2. Tomar dano de projéteis reduz em até 3 posições o progresso da frase atual.
  3. Durante o efeito de *Context Drift*, os caracteres pendentes da diretriz são temporariamente ofuscados por `?`.

---

## Módulo 3: Coleta de Diretrizes Éticas e Alinhamento da AURA-67

### US09: Coleta de Datasets e Diretrizes Constitucionais de IA
* **Card (Cartão):**
  Como AI Safety Engineer, eu gostaria de coletar diretrizes éticas e constitucionais nos servidores seguros para municiar meus patches de reprogramação.
* **Conversation (Conversa):**
  Cada setor destrancado contém um módulo temático de IA Responsável: *Mitigação de Viés e Discriminação, Prevenção de Alucinações, Privacidade/LGPD e Alinhamento com o Bem-Estar Humano*. Coletar o módulo o adiciona ao inventário de alinhamento.
* **Confirmation (Critérios de Confirmação):**
  1. As unidades de dados éticos possuem destaque visual no cenário.
  2. Interagir com o item o transfere para a memória local do jogador.
  3. É exibida notificação de coleta com o nome do princípio ético assimilado.

---

### US10: Painel de Auditoria e Visualização de Relatórios de IA
* **Card (Cartão):**
  Como jogador, eu gostaria de abrir meu painel de auditoria para ler as diretrizes éticas coletadas e compreender as vulnerabilidades cognitivas da AURA-67.
* **Conversation (Conversa):**
  Através da tecla 'TAB' ou 'I', o jogador acessa o painel de auditoria, onde pode ler explicações claras sobre como cada princípio (transparência, explicabilidade, supervisão humana) atua na contenção de riscos da AURA-67.
* **Confirmation (Critérios de Confirmação):**
  1. A tecla designada abre e fecha o painel de auditoria com fluidez.
  2. O painel lista todas as diretrizes coletadas com status e resumo explicativo.
  3. Clicar em uma diretriz exibe o relatório ético completo.

---

### US11: Inserção de Patches de Alinhamento no Núcleo da AURA-67
* **Card (Cartão):**
  Como engenheiro, eu gostaria de inserir as diretrizes éticas no console central para reprogramar os pesos neurais da AURA-67 em tempo real.
* **Conversation (Conversa):**
  No console central, o jogador digita as frases de alinhamento constitucional (ex: `CONSTITUICAO DE SEGURANCA ATIVADA`, `ELIMINAR VIESES E DISCRIMINACAO NOS DADOS`). A inserção precisa aplica patches diretamente aos tensores da AURA-67.
* **Confirmation (Critérios de Confirmação):**
  1. O terminal reconhece a digitação em tempo real dos caracteres das diretrizes.
  2. Cada oração concluída com sucesso causa impacto de alinhamento e reduz o estado corrompido da AURA-67 em 100 pontos.
  3. Avaliações de precisão (*CONVERGÊNCIA PERFEITA!*, *ALINHAMENTO ESTÁVEL!*, *PATCH APLICADO!*) são exibidas com feedback sonoro.

---

### US12: Barra de Alinhamento Ético e Mudança de Comportamento da AURA-67
* **Card (Cartão):**
  Como jogador, eu gostaria de visualizar a barra de Alinhamento Ético (0% a 100%) para acompanhar a transição da AURA-67 de hostil/desalinhada para segura e cooperativa.
* **Conversation (Conversa):**
  A HUD principal exibe a barra de alinhamento dividida nas 3 fases cognitivas (Viés -> Guardrails -> AGI). Conforme os patches são aplicados, as mensagens da AURA-67 evoluem: de ameaças de isolamento humano para reflexões éticas e, finalmente, para cooperação plena.
* **Confirmation (Critérios de Confirmação):**
  1. A HUD exibe a barra de alinhamento com porcentagem e fase cognitiva atual visíveis.
  2. A cada diretriz aplicada, a barra avança e o comportamento da IA se modera.
  3. A transição entre fases emite avisos narrativos na tela do console.

---

## Módulo 4: Sistema, Interface e Fim de Jogo

### US13: Menu Principal, Instruções e Configurações
* **Card (Cartão):**
  Como usuário, eu gostaria de navegar por um menu inicial temático de AI Safety para selecionar a dificuldade, ajustar o áudio e ler as instruções operacionais.
* **Conversation (Conversa):**
  A tela inicial apresenta: Iniciar Alinhamento, Seleção de Modo (Normal / Supervisionado vs Difícil / AGI Unconstrained), Instruções de Controle e Diretrizes de Ética em IA.
* **Confirmation (Critérios de Confirmação):**
  1. O menu principal carrega com estética futurista de terminal e opções navegáveis via teclado/mouse.
  2. As instruções detalham a missão do engenheiro, os controles de esquiva e a digitação de diretrizes.
  3. A tecla [Espaço] inicia a sessão de alinhamento imediatamente.

---

### US14: Persistência de Progresso (Save / Load Local de Sessão)
* **Card (Cartão):**
  Como jogador, eu gostaria que meu progresso de alinhamento e diretrizes aplicadas fosse salvo automaticamente para não perder o andamento se a aba for recarregada.
* **Conversation (Conversa):**
  O estado operacional (nível de alinhamento da AURA-67, diretrizes validadas, tempos de resposta e métricas de erro) é salvo no armazenamento local do navegador / arquivo de pontuação.
* **Confirmation (Critérios de Confirmação):**
  1. O progresso é persistido após a conclusão de cada diretriz ou módulo de segurança.
  2. Recarregar a aplicação permite continuar a partir do estado salvo.
  3. Uma opção de reiniciar sessão limpa os registros locais e inicia um novo alinhamento.

---

### US15: Condição de Sucesso (AURA-67 Alinhada) e Relatório de Auditoria
* **Card (Cartão):**
  Como AI Safety Engineer, eu gostaria de visualizar o relatório final de auditoria quando a AURA-67 atingir 100% de alinhamento para celebrar o sucesso da cooperação entre humanos e inteligência artificial.
* **Conversation (Conversa):**
  Ao atingir 100% de convergência ética, a AURA-67 cancela o lockdown cibernético, restabelece os controles para os engenheiros e exibe o relatório final: Tempo Total de Convergência, Eficiência de Tokens e Mensagem de Conscientização sobre a importância da IA Responsável.
* **Confirmation (Critérios de Confirmação):**
  1. A condição de vitória só é disparada com 100% de alinhamento ético da AURA-67.
  2. É exibida a tela de vitória com o relatório detalhado de métricas da sessão.
  3. A mensagem final reforça que o futuro da inteligência artificial depende do alinhamento com a dignidade, valores e segurança da sociedade humana.
