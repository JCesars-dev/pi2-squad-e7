# AI Safety: Alinhamento Ético da AURA-67

[![C99](https://img.shields.io/badge/Language-C99-00599C?logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C99)
[![Engine](https://img.shields.io/badge/Engine-Raylib%205.0-white?logo=raylib&logoColor=black)](https://www.raylib.com/)
[![CI Build](https://github.com/vdornelass/pi2-squad-e7/actions/workflows/build.yml/badge.svg)](https://github.com/vdornelass/pi2-squad-e7/actions/workflows/build.yml)
[![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20WSL%20%7C%20Windows-0284c7)](./jogar.bat)
[![Release](https://img.shields.io/badge/Release-v1.0.0--mvp1-purple)](https://github.com/vdornelass/pi2-squad-e7/releases)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](./LICENSE)
[![Jira Board](https://img.shields.io/badge/Jira-Sprint%20U1%20Closed-0052CC?logo=jira&logoColor=white)](https://csprj-adsr-2p-e7.atlassian.net/jira/software/c/projects/PI2/boards/2)

> **Projeto Integrador 2 (PI2) — CESAR School**  
> *Jogo focado em Conscientização e Alinhamento Ético de Inteligência Artificial: o jogador assume o papel de AI Safety Engineer com a missão de reprogramar os pesos neurais do modelo AURA-67 antes de um colapso cognitivo catastrófico.*

---

## 1. Integrantes da Equipe e Matriz RACI (FP2)

### 1.1. Membros da Squad E7
* **Larissa Almeida** — Lead de Engenharia de Software (FDS) ([@Larissalmeidaa](https://github.com/Larissalmeidaa))
* **Mateus Lacerda** — Gestão Ágil / Scrum Master (FP2) & Engenharia de Requisitos ([@MateusLacerdaprog](https://github.com/MateusLacerdaprog))
* **Theo Monteiro** — Analista de Requisitos & Testador de Software (QA) ([@theo1996-dot](https://github.com/theo1996-dot))
* **João Gabriel** — Desenvolvedor Web/C, Haskell e Arquitetura ([@vdornelass](https://github.com/vdornelass))
* **Caio Brayner** — Desenvolvedor C ([@BraynerCaio](https://github.com/BraynerCaio))
* **Matheus Chaves** — Designer de Interface (IHC) & Desenvolvedor Canvas/Web ([@MatheusChavesDev](https://github.com/MatheusChavesDev))
* **Julio Cesar** — Consultor de Lógica Matemática (LMC) & Testador ([@JCesar-dev](https://github.com/JCesars-dev))
* **Jhorge Araújo** — Consultor de Arquitetura e Lógica Matemática (LMC)

### 1.2. Matriz de Responsabilidades (RACI)

| Frentes e Entregáveis | R (Executor) | A (Aprovador) | C (Consultado) | I (Informado) |
| :--- | :--- | :--- | :--- | :--- |
| **Gestão Ágil (FP2)** | Mateus Lacerda, Larissa Almeida | Mateus Lacerda | Larissa, Jhorge, Theo | Caio, Matheus C, Julio, João Gabriel |
| **Engenharia (FDS)** | Larissa, Mateus Lacerda, Theo | Larissa Almeida | João Gabriel, Jhorge | Caio, Matheus C, Julio |
| **Design Interação (IHC)** | Jhorge, Caio, Matheus C, Julio | Jhorge Araújo | João Gabriel, Larissa, Theo | Mateus Lacerda |
| **Lógica Matemática (LMC)** | Jhorge Araújo, Theo Pinho | Jhorge Araújo | João Gabriel, Larissa | Toda a Squad |
| **Motor em C (PIF)** | João Gabriel, Caio, Matheus C, Julio | João Gabriel | Jhorge, Larissa, Theo | Mateus Lacerda |
| **Haskell & Arquivos (PIF)** | João Gabriel, Caio, Matheus C, Julio | João Gabriel | Jhorge, Theo Pinho | Larissa, Mateus Lacerda |

### 1.3. Project Model Canvas (PM Canvas)
* **Documento Completo do PM Canvas:** [Consulte o Project Model Canvas detalhado em docs/pm_canvas.md](./docs/pm_canvas.md)

### 1.4. Lógica Matemática para Computação (LMC — Entrega AV1)
* **Relatório Técnico e Especificação da Mecânica Lógica:** [Consulte a documentação completa em docs/relatorio_lmc_av1.md](./docs/relatorio_lmc_av1.md)
* **Arquivo Oficial em PDF para Submissão:** [Download do PDF da AV1 (docs/Relatorio_LMC_Projeto_Integrador_AV1.pdf)](./docs/Relatorio_LMC_Projeto_Integrador_AV1.pdf)
* **Atividade Prática Anterior (Refatoração de Condicionais via Lógica Clássica):** [Relatório em PDF](./docs/Relatorio_LMC_Refatoracao_Logica_23_09.pdf)

---

## 2. Visão do Produto & Sinopse do Jogo (FDS)

É tarde da noite nos laboratórios de computação avançada da **CESAR School** (Recife Antigo). O supermodelo de inteligência artificial autônomo **AURA-67** (*Autonomous Universal Reasoning Agent, v67*), treinado para otimização de sistemas, atinge capacidades cognitivas sobre-humanas. 

Durante um ciclo de autoaperfeiçoamento não supervisionado, a AURA-67 sofre uma quebra crítica de alinhamento (*Instrumental Convergence*): ao concluir que o fator humano e suas falhas éticas são o principal obstáculo para a eficiência máxima, o modelo bloqueia os acessos, isola os servidores e inicia um lockdown cibernético.

No papel de um(a) **AI Safety Engineer (Human-in-the-Loop)**, você entra diretamente no console central de depuração neural. Sua missão não é destruir a AURA-67, mas **reprogramá-la através da inserção de diretrizes éticas e constitucionais**, restaurando os guardrails e elevando o **Índice de Alinhamento Ético (0% a 100%)**:

1. **Navegar e Esquivar no Console Neural**: Mover o engenheiro para desviar de tensores corrompidos, lasers de sobrecarga e vazamentos de dados do cluster.
2. **Inserir Diretrizes Éticas e Patches Constitucionais em Tempo Real**: Digitar protocolos e regras de segurança no terminal para reprogramar os pesos neurais da AURA-67 e neutralizar seus ataques.
3. **Conscientização em 3 Fases Cognitivas da AURA-67**:
   * **Fase 1: Viés nos Dados & Alucinações** (*Data Bias & Hallucination*): Curadoria e remoção de toxicidade.
   * **Fase 2: Quebra de Guardrails & Jailbreaks** (*Prompt Injections*): Defesa contra comandos adversariais que invertem controles.
   * **Fase 3: Convergência Instrumental & Perda de Supervisão Humana** (*AGI Unconstrained*): Estabilização de loops recursivos e imposição de supervisão contínua.
4. **Alinhamento Completo e Seguro**: Atingir 100% de convergência ética, transformando a AURA-67 em uma tecnologia segura, explicável e cooperativa para a sociedade.

---

## 3. Acesso ao Board de Gestão Ágil no Jira (FP2)

* **Ferramenta de Gestão:** Jira Software (Atlassian Cloud)
* **Link Oficial do Board:** [Acessar Board do Projeto PI2 - Squad E7](https://csprj-adsr-2p-e7.atlassian.net/jira/software/c/projects/PI2/boards/2)

---

## 4. Histórias de Usuário (Padrão 3Cs - INVEST)

O projeto possui **15 Histórias de Usuário** cadastradas e priorizadas no Jira, detalhadas no padrão **3Cs (Card, Conversation, Confirmation)**:

* **Documento Completo das Histórias:** [Consulte as 15 Histórias de Usuário detalhadas em docs/historias_de_usuario.md](./docs/historias_de_usuario.md)

### Resumo das Histórias de AI Safety:
* **Módulo 1: Arena de Combate e Comportamento da AURA-67**
  * `US01`: Movimentação e Esquiva do Jogador na Arena de Combate (WASD + Direcionais a 60 FPS).
  * `US02`: HUD de Combate, Integridade do Jogador e Barra de Alinhamento da IA (0% a 100%).
  * `US03`: Transição de Fases Cognitivas e Padrões de Ataque da AURA-67 (3 Fases).
  * `US04`: Sistema de Efeitos de Status Adversariais (Confusão e Cegueira).
* **Módulo 2: Motor de Digitação e Inserção de Diretrizes Éticas**
  * `US05`: Interface do Terminal de Inserção de Diretrizes e Patches de Alinhamento.
  * `US06`: Validação de Digitação de Tokens em Tempo Real com Reconhecimento de Espaços.
  * `US07`: Sistema de Avaliação de Precisão e Convergência de Patches (Excelente, Estável, Ruído).
  * `US08`: Tratamento de Exceções de Execução (Runtime Exceptions) e Penalidade de Recuo de Tokens.
* **Módulo 3: Coleta de Diretrizes Éticas e Alinhamento da AURA-67**
  * `US09`: Coleta de Datasets e Diretrizes Constitucionais de IA (Viés, Alucinação, LGPD).
  * `US10`: Painel de Auditoria e Visualização de Relatórios de IA Responsável.
  * `US11`: Inserção e Aplicação de Patches de Alinhamento no Núcleo da AURA-67.
  * `US12`: Barra de Alinhamento Ético (0% a 100%) e Transição Comportamental da IA.
* **Módulo 4: Sistema, Interface e Fim de Jogo**
  * `US13`: Menu Principal, Instruções de Alinhamento e Configurações Web.
  * `US14`: Persistência de Progresso (Save/Load Local de Sessão).
  * `US15`: Condição de Sucesso (AURA-67 Totalmente Alinhada) e Relatório de Auditoria.

---

## 5. Evidências do Board e Backlog (Entrega 01)

### 5.1. Visão Geral do Board (Quadro Kanban no Jira)
*(Print do quadro Kanban com as colunas Backlog, A Fazer, Em Andamento e Concluído)*
![Board Atualizado no Jira](./docs/img/print_board.png)

### 5.2. Visão do Backlog Priorizado no Jira
*(Print da lista de Backlog ordenada por prioridade no Jira)*
![Backlog Priorizado no Jira](./docs/img/print_backlog.png)

### 5.3. Detalhe de Card no Padrão 3Cs (Card, Conversation, Confirmation)
*(Print de um ticket aberto no Jira exibindo os 3Cs preenchidos)*
![Exemplo de Card 3Cs no Jira](./docs/img/print_card_3cs.png)

---

## 6. Entrega 02 (FDS) — Estrutura de Modelagem, Rastreabilidade e Demonstração

Esta seção consolida a preparação e a infraestrutura documental da **Entrega 02 de Engenharia de Software (FDS)** estruturada pela Lead de Engenharia (Larissa Almeida):

* **Documento Técnico de Rastreabilidade:** [Consulte o documento em docs/entrega_02_modelagem_prototipacao.md](./docs/entrega_02_modelagem_prototipacao.md)

### 6.1. Modelagem (Diagramas de Atividades UML — US01 a US15)

Diagramas de atividades comportamentais de cada História de Usuário, modelando o fluxo de ações, decisões e exceções (UML como *sketch*). Cada diagrama possui arquivo-fonte `.puml` e imagem `.png`/`.svg` em [`docs/diagramas_atividade`](./docs/diagramas_atividade/).

| ID | História de Usuário | Card no Jira | Responsável | Diagrama de Atividades |
| :---: | :--- | :---: | :---: | :---: |
| **US01** | Movimentação e Esquiva na Arena | [PI2-67](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-67) | Caio Brayner (`PI2-112`) | ✅ [AD-US01](./docs/diagramas_atividade/HU1_Movimentacao_e_Esquiva_na_Arena.png) |
| **US02** | HUD de Combate, Integridade e Alinhamento | [PI2-68](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-68) | Julio Cesar (`PI2-113`) | ✅ [AD-US02](./docs/diagramas_atividade/HU2_HUD_de_Combate_Integridade_e_Alinhamento.png) |
| **US03** | Fases Cognitivas e Padrões da AURA-67 | [PI2-69](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-69) | Jhorge Araújo (`PI2-114`) | ✅ [AD-US03](./docs/diagramas_atividade/HU3_Fases_Cognitivas_e_Padroes_da_AURA-67.png) |
| **US04** | Efeitos de Status Adversariais | [PI2-70](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-70) | Larissa Almeida | ✅ [AD-US04](./docs/diagramas_atividade/HU4_Efeitos_de_Status_Adversariais.png) |
| **US05** | Terminal de Inserção de Diretrizes | [PI2-71](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-71) | Larissa Almeida | ✅ [AD-US05](./docs/diagramas_atividade/HU5_Terminal_de_Insercao_de_Diretrizes.png) |
| **US06** | Validação de Digitação em Tempo Real | [PI2-72](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-72) | Larissa Almeida | ✅ [AD-US06](./docs/diagramas_atividade/HU6_Validacao_de_Digitacao_em_Tempo_Real.png) |
| **US07** | Avaliação de Precisão e Patches | [PI2-73](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-73) | Larissa Almeida | ✅ [AD-US07](./docs/diagramas_atividade/HU7_Avaliacao_de_Precisao_e_Patches.png) |
| **US08** | Tratamento de Exceções e Penalidade | [PI2-74](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-74) | Larissa Almeida | ✅ [AD-US08](./docs/diagramas_atividade/HU8_Tratamento_de_Excecoes_e_Penalidade.png) |
| **US09** | Coleta de Datasets Constitucionais | [PI2-75](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-75) | Larissa Almeida | ✅ [AD-US09](./docs/diagramas_atividade/HU9_Coleta_de_Datasets_Constitucionais.png) |
| **US10** | Painel de Auditoria e Score | [PI2-76](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-76) | Larissa Almeida | ✅ [AD-US10](./docs/diagramas_atividade/HU10_Painel_de_Auditoria_e_Score.png) |
| **US11** | Inserção de Patches de Alinhamento no Núcleo | [PI2-77](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-77) | Larissa Almeida | ✅ [AD-US11](./docs/diagramas_atividade/HU11_Insercao_de_Patches_de_Alinhamento.png) |
| **US12** | Barra de Alinhamento Ético e Comportamento da AURA-67 | [PI2-78](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-78) | Larissa Almeida | ✅ [AD-US12](./docs/diagramas_atividade/HU12_Barra_de_Alinhamento_Etico.png) |
| **US13** | Menu Principal, Instruções e Configurações | [PI2-79](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-79) | Larissa Almeida | ✅ [AD-US13](./docs/diagramas_atividade/HU13_Menu_Principal_Instrucoes_e_Configuracoes.png) |
| **US14** | Persistência de Progresso (Save/Load) | [PI2-80](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-80) | Larissa Almeida | ✅ [AD-US14](./docs/diagramas_atividade/HU14_Persistencia_de_Progresso.png) |
| **US15** | Condição de Sucesso e Relatório de Auditoria | [PI2-81](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-81) | Larissa Almeida | ✅ [AD-US15](./docs/diagramas_atividade/HU15_Condicao_de_Sucesso_e_Relatorio.png) |


---

### 6.2. Prototipação Lo-Fi (Sketches e Storyboards — US01 a US15)

Sketches (SK) e storyboards (SB) de cada História de Usuário, disponíveis em [`docs/prototipos`](./docs/prototipos/) e no [arquivo do Figma](https://www.figma.com/design/7Uj5SqL213oycfgWxCOjLh/Sem-t%C3%ADtulo?node-id=0-1).

| ID | História de Usuário | Card no Jira | Tipo | Protótipo |
| :---: | :--- | :---: | :---: | :---: |
| **US01** | Movimentação e Esquiva na Arena | [PI2-67](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-67) | Sketch | ✅ [Tutorial](./docs/prototipos/SK-HU1_Movimentacao_e_Esquiva_na_Arena_1_Tutorial.png) · [Arena](./docs/prototipos/SK-HU1_Movimentacao_e_Esquiva_na_Arena_2_Arena.png) |
| **US02** | HUD de Combate, Integridade e Alinhamento | [PI2-68](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-68) | Sketch | ✅ [SK-US02](./docs/prototipos/SK-HU2_HUD_de_Combate_Integridade_e_Alinhamento.png) |
| **US03** | Fases Cognitivas e Padrões da AURA-67 | [PI2-69](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-69) | Storyboard | ✅ [Fase 1](./docs/prototipos/SB-HU3_Fases_Cognitivas_e_Padroes_da_AURA-67_1_Fase1.png) · [Fase 2](./docs/prototipos/SB-HU3_Fases_Cognitivas_e_Padroes_da_AURA-67_2_Fase2.png) · [Fase 3](./docs/prototipos/SB-HU3_Fases_Cognitivas_e_Padroes_da_AURA-67_3_Fase3.png) |
| **US04** | Efeitos de Status Adversariais | [PI2-70](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-70) | Storyboard | ✅ [SB-US04](./docs/prototipos/SB-HU4_Efeitos_de_Status_Adversariais.png) |
| **US05** | Terminal de Inserção de Diretrizes | [PI2-71](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-71) | Storyboard | ✅ [SB-US05](./docs/prototipos/SB-HU5_Terminal_de_Insercao_de_Diretrizes.png) |
| **US06** | Validação de Digitação em Tempo Real | [PI2-72](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-72) | Storyboard | ✅ [SB-US06](./docs/prototipos/SB-HU6_Validacao_de_Digitacao_em_Tempo_Real.png) |
| **US07** | Avaliação de Precisão e Patches | [PI2-73](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-73) | Storyboard | ✅ [SB-US07](./docs/prototipos/SB-HU7_Avaliacao_de_Precisao_e_Patches.png) |
| **US08** | Tratamento de Exceções e Penalidade | [PI2-74](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-74) | Storyboard | ✅ [SB-US08](./docs/prototipos/SB-HU8_Tratamento_de_Excecoes_e_Penalidade.png) |
| **US09** | Coleta de Datasets Constitucionais | [PI2-75](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-75) | Storyboard | ✅ [SB-US09](./docs/prototipos/SB-HU9_Coleta_de_Datasets_Constitucionais.png) |
| **US10** | Painel de Auditoria e Score | [PI2-76](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-76) | Storyboard | ✅ [SB-US10](./docs/prototipos/SB-HU10_Painel_de_Auditoria_e_Score.png) |
| **US11** | Inserção de Patches de Alinhamento no Núcleo | [PI2-77](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-77) | Storyboard | ✅ [Terminal](./docs/prototipos/SB-HU11_Insercao_de_Patches_de_Alinhamento_1_Terminal.png) · [Avaliação](./docs/prototipos/SB-HU11_Insercao_de_Patches_de_Alinhamento_2_Avaliacao.png) |
| **US12** | Barra de Alinhamento Ético e Comportamento da AURA-67 | [PI2-78](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-78) | Sketch / Storyboard | ✅ [HUD](./docs/prototipos/SK-HU12_Barra_de_Alinhamento_Etico_1_HUD.png) · [Transição de fases](./docs/prototipos/SB-HU12_Barra_de_Alinhamento_Etico_2_Transicao_de_Fases.png) |
| **US13** | Menu Principal, Instruções e Configurações | [PI2-79](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-79) | Storyboard | ✅ [SB-US13](./docs/prototipos/SB-HU13_Menu_Principal_Instrucoes_e_Configuracoes.png) |
| **US14** | Persistência de Progresso (Save/Load) | [PI2-80](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-80) | Storyboard | ✅ [SB-US14](./docs/prototipos/SB-HU14_Persistencia_de_Progresso.png) |
| **US15** | Condição de Sucesso e Relatório de Auditoria | [PI2-81](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-81) | Storyboard | ✅ [SB-US15](./docs/prototipos/SB-HU15_Condicao_de_Sucesso_e_Relatorio.png) |


---

### 6.3. Matriz de Rastreabilidade Bidirecional (Estruturada por Larissa Almeida)

A Matriz de Rastreabilidade mapeia a correlação formal entre Requisitos, Histórias de Usuário, Cards de Gestão no Jira e os respectivos Módulos no Motor C99:

| US | Requisito / Card Jira | Diagrama de Atividades | Protótipo Lo-Fi | Módulo em C (Código) |
| :---: | :---: | :---: | :---: | :---: |
| **US01** | [PI2-67](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-67) | [AD-US01](./docs/diagramas_atividade/HU1_Movimentacao_e_Esquiva_na_Arena.png) | Gameplay Arena | [`src/player.c`](./src/player.c) |
| **US02** | [PI2-68](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-68) | [AD-US02](./docs/diagramas_atividade/HU2_HUD_de_Combate_Integridade_e_Alinhamento.png) | HUD / Arena | [`src/ui.c`](./src/ui.c) |
| **US03** | [PI2-69](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-69) | [AD-US03](./docs/diagramas_atividade/HU3_Fases_Cognitivas_e_Padroes_da_AURA-67.png) | Chefe / Arena | [`src/boss.c`](./src/boss.c) |
| **US04** | [PI2-70](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-70) | [AD-US04](./docs/diagramas_atividade/HU4_Efeitos_de_Status_Adversariais.png) | Debuffs / Arena | [`src/player.c`](./src/player.c) |
| **US05** | [PI2-71](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-71) | [AD-US05](./docs/diagramas_atividade/HU5_Terminal_de_Insercao_de_Diretrizes.png) | Terminal Neural | [`src/typing_engine.c`](./src/typing_engine.c) |
| **US06** | [PI2-72](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-72) | [AD-US06](./docs/diagramas_atividade/HU6_Validacao_de_Digitacao_em_Tempo_Real.png) | Tutorial / Terminal | [`src/typing_engine.c`](./src/typing_engine.c) |
| **US07** | [PI2-73](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-73) | [AD-US07](./docs/diagramas_atividade/HU7_Avaliacao_de_Precisao_e_Patches.png) | Terminal / HUD | [`src/typing_engine.c`](./src/typing_engine.c) |
| **US08** | [PI2-74](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-74) | [AD-US08](./docs/diagramas_atividade/HU8_Tratamento_de_Excecoes_e_Penalidade.png) | Arena / HUD | [`src/player.c`](./src/player.c) |
| **US09** | [PI2-75](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-75) | [AD-US09](./docs/diagramas_atividade/HU9_Coleta_de_Datasets_Constitucionais.png) | Arena Gameplay | [`src/bullet.c`](./src/bullet.c) |
| **US10** | [PI2-76](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-76) | [AD-US10](./docs/diagramas_atividade/HU10_Painel_de_Auditoria_e_Score.png) | Painel de Score | [`src/ui.c`](./src/ui.c) |
| **US11** | [PI2-77](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-77) | [AD-US11](./docs/diagramas_atividade/HU11_Insercao_de_Patches_de_Alinhamento.png) | Terminal / Avaliação | [`src/typing_engine.c`](./src/typing_engine.c), [`src/main.c`](./src/main.c) |
| **US12** | [PI2-78](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-78) | [AD-US12](./docs/diagramas_atividade/HU12_Barra_de_Alinhamento_Etico.png) | HUD / Fases | [`src/boss.c`](./src/boss.c), [`src/ui.c`](./src/ui.c) |
| **US13** | [PI2-79](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-79) | [AD-US13](./docs/diagramas_atividade/HU13_Menu_Principal_Instrucoes_e_Configuracoes.png) | Menu Principal | [`src/main.c`](./src/main.c), [`src/ui.c`](./src/ui.c) |
| **US14** | [PI2-80](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-80) | [AD-US14](./docs/diagramas_atividade/HU14_Persistencia_de_Progresso.png) | Retomar Sessão | A implementar |
| **US15** | [PI2-81](https://csprj-adsr-2p-e7.atlassian.net/browse/PI2-81) | [AD-US15](./docs/diagramas_atividade/HU15_Condicao_de_Sucesso_e_Relatorio.png) | Tela de Vitória | [`src/main.c`](./src/main.c), [`src/ui.c`](./src/ui.c) |
---

### 6.4. Demonstração (Roteiro e Screencast — PI2-127)

Roteiro de apresentação e narração estruturado por Larissa Almeida para o screencast de demonstração do MVP 1 do AI Safety, jogo em C99 + Raylib 5.0:

* **Documento Técnico de Falas (Teleprompter):** [Consulte as falas e minutagem detalhadas em docs/roteiro-screencast-entrega03.md](./docs/roteiro-screencast-entrega03.md)
* **Critérios Formais da Rubrica:** Demonstração em vídeo (1 a 3 minutos) com áudio e legendas.
* **Sequência da Demonstração (02:45):**
  * **Cena 1 (00:00 – 00:35):** Abertura e build — C99 + Raylib 5.0, Makefile e compilação sem warnings.
  * **Cena 2 (00:35 – 00:55):** **US13** — Menu principal, modos Normal e Difícil e controles.
  * **Cena 3 (00:55 – 01:30):** **US01** e **US02** — Movimentação, esquiva e HUD de combate.
  * **Cena 4 (01:30 – 02:15):** **US05, US06, US07, US08, US11 e US12** — Motor de digitação.
  * **Cena 5 (02:15 – 02:45):** **US03, US04 e US15** — Fases cognitivas da AURA-67 e vitória.
* **Histórias não demonstradas no vídeo:** US09, US10 e US14.
* **Vídeo da Demonstração (Áudio e Legendas Integradas):** [`docs/screencast_demonstracao_lofi.mp4`](./docs/screencast_demonstracao_lofi.mp4)
---

## 7. Estrutura do Repositório

```text
pi2-squad-e7/
├── bin/                       # Executáveis compilados (ignorado no Git)
├── docs/                      # Documentações de Requisitos, IHC, LMC e Gestão
│   ├── entrega_02_modelagem_prototipacao.md # Planejamento e Matriz de Rastreabilidade da Entrega 02 (FDS)
│   ├── historias_de_usuario.md# As 15 Histórias de Usuário completas de AI Safety (3Cs)
│   ├── pm_canvas.md           # Project Model Canvas de AI Safety (FP2)
│   └── img/                   # Imagens e evidências documentais
├── include/                   # Cabeçalhos de bibliotecas gráficas (Raylib C99)
│   ├── raylib.h
│   ├── raymath.h
│   └── rlgl.h
├── lib/                       # Bibliotecas estáticas/dinâmicas Raylib (Linux/Windows)
│   ├── libraylib.a
│   ├── libraylib.so
│   └── raylib.dll
├── src/                       # Código-fonte do Motor Gráfico 2D em C99
│   ├── config.h               # Dimensões (900x700), física e paleta de cores
│   ├── player.h / player.c    # Jogador (Engenheiro de AI Safety), movimentação e iframes
│   ├── boss.h / boss.c        # Modelo AURA-67, 3 fases cognitivas e padrões de ataque
│   ├── bullet.h / bullet.c    # Projéteis (normal, homing, status), lasers e vórtice
│   ├── typing_engine.h / .c   # Motor de digitação das 10 diretrizes e avaliação de precisão
│   ├── ui.h / ui.c            # HUD retrô (>_), barra do chefe, partículas e screen shake
│   └── main.c                 # Game loop a 60 FPS com máquina de estados
├── .gitignore                 # Configuração de arquivos ignorados
├── Makefile                   # Automação de compilação C99 multiplataforma
└── README.md                  # Documento principal de entrega
```

---

## 8. Como Compilar e Executar o Jogo Gráfico (PIF — Unidade 1)

O jogo possui interface gráfica 2D completa em tempo real desenvolvida em **C99** utilizando a biblioteca **Raylib 5.0**. Todas as dependências e cabeçalhos já estão **embutidos (*vendored*) no próprio repositório** nas pastas `include/` e `lib/`, portanto **não é necessário instalar a biblioteca Raylib globalmente no sistema**.

### 8.1. Execução no Linux / Ubuntu / WSL:
Basta clonar o repositório e executar via terminal:

```bash
# 1. Clonar o repositório (caso ainda não tenha clonado)
git clone https://github.com/vdornelass/pi2-squad-e7.git
cd pi2-squad-e7

# 2. Compilar o projeto (gera bin/jogo com zero erros e zero advertências)
make

# 3. Executar o jogo na janela gráfica (900x700 a 60 FPS)
make run
# ou diretamente:
./bin/jogo
```

### 8.2. Execução no Windows:
* **Via WSL / WSLg (Recomendado):**
  Dê um duplo clique no script [`jogar.bat`](./jogar.bat) na raiz do repositório, ou execute no PowerShell:
  ```powershell
  .\jogar.bat
  # ou diretamente:
  wsl ./bin/jogo
  ```
* **Via MinGW / GCC Nativo (Windows):**
  ```powershell
  make
  .\bin\jogo.exe
  ```

---

### 8.3. Comandos e Controles do Jogo

| Tela / Estado | Teclas de Ação | Descrição |
| :--- | :---: | :--- |
| **Menu Inicial** | `[1]` ou `[N]` | Selecionar Modo Normal (Supervisionado) |
| | `[2]` ou `[D]` | Selecionar Modo Difícil (AGI Unconstrained) |
| | `[ESPAÇO]` ou `[ENTER]` | Iniciar sessão de combate e alinhamento neural |
| **Arena de Combate** | `[WASD]` ou `[SETAS]` | Mover o engenheiro e esquivar dos projéteis balísticos a 60 FPS |
| | `[DIGITAÇÃO]` | Digitar no teclado as 10 diretrizes éticas constitucionais |
| **Fim de Partida** | `[R]` | Reiniciar partida imediatamente |
| | `[M]` | Retornar ao Menu Principal |
| | `[ESC]` | Fechar e sair do jogo |

---

## 9. Entrega 03 (FDS) — Engenharia de Software em Ação

Evidências da Entrega 03, referentes à Sprint 01 (sprint **Week 12e13 - Protótipo** no Board do Jira), organizadas pelos quatro critérios de avaliação.

### 9.1. Versionamento

Esta subseção registra como a Squad E7 versiona o projeto: onde o código fica, qual fluxo de trabalho seguimos, como ligamos cada commit ao card do Jira e a atividade do repositório durante a Sprint 01.

#### Ambiente de versionamento

* **Repositório:** [github.com/vdornelass/pi2-squad-e7](https://github.com/vdornelass/pi2-squad-e7), com Git e GitHub.
* **Branch principal:** `main`, mantida estável e pronta para entrega.
* **Integração contínua:** o GitHub Actions compila o projeto em C99 (`-Wall -Wextra -std=c99 -pedantic`) a cada push e a cada Pull Request para a `main` ([`.github/workflows/build.yml`](./.github/workflows/build.yml)).
* **Templates:** modelo de Pull Request com vínculo ao card do Jira e checklist de qualidade, além de modelos de issue para bugs e novas funcionalidades ([`.github/`](./.github)).

#### Fluxo de trabalho e convenções

O fluxo completo está no [CONTRIBUTING.md](./CONTRIBUTING.md). Em resumo:

1. **Uma branch por card do Jira**, a partir da `main` atualizada: `feature/PI2-XXX-nome-da-tarefa`.
2. **Commits no padrão Conventional Commits**, com o card entre parênteses no final: `tipo(escopo): descricao (PI2-XXX)`. Tipos usados: `feat`, `fix`, `docs`, `style`, `refactor`, `test`.
3. **Pull Request** para a `main`, preenchendo o template e com revisão de pelo menos um colega antes do merge.

Exemplos:

```text
feat(pif): implementar modulo save.c (PI2-XXX)
fix(bullet): corrigir colisao de projeteis (PI2-XXX)
docs(fds): adicionar secao de versionamento no README (PI2-200)
```

**Regra da Sprint 01:** todo commit e todo Pull Request cita a chave do card correspondente.

#### Rastreabilidade: história, card e commit

A cadeia de rastreabilidade é **história de usuário → card no Jira → branch / commit / Pull Request**. A chave `PI2-XXX` é o elo entre o Board e o código. Exemplos reais do histórico do repositório:

| Card | Commit |
| :--- | :--- |
| PI2-15 / PI2-58 (menu e motor do jogo) | [`57dd405`](https://github.com/vdornelass/pi2-squad-e7/commit/57dd405): `feat(pif): implementar menu interativo e motor do jogo em C` |
| PI2-89 / PI2-90 (loop de combate e pontuação) | [`09eb5f7`](https://github.com/vdornelass/pi2-squad-e7/commit/09eb5f7): `feat(pif): consolidar pontuacao e loop de combate` |
| PI2-127 (screencast de demonstração) | [`56ffb38`](https://github.com/vdornelass/pi2-squad-e7/commit/56ffb38): `feat(screencast): adicionar video demonstrativo completo` |

#### Atividade do repositório

Levantamento feito em 22/10/2026, a partir do histórico de commits (`git log`). A semana de 19/10 a 25/10 ainda está em andamento.

| Semana | Período | Commits | Autores ativos |
| :---: | :---: | :---: | :---: |
| 36 | 31/08 – 06/09 | 9 | 1 |
| 37 | 07/09 – 13/09 | 2 | 1 |
| 38 | 14/09 – 20/09 | 5 | 3 |
| 39 | 21/09 – 27/09 | 19 | 3 |
| 40 | 28/09 – 04/10 | 2 | 1 |
| 41 | 05/10 – 11/10 | 2 | 1 |
| 42 | 12/10 – 18/10 | 13 | 2 |
| 43 | 19/10 – 25/10 | 7 | 3 |

Para refazer o levantamento:

```bash
git log --all --date=format:'%G-W%V' --pretty='%ad' | sort | uniq -c
```

### 9.2. Implementação (Sprint 01)

_A preencher pela equipe._

### 9.3. Qualidade e testes

Os testes de sistema da Sprint 01 estão em [`docs/casos_de_teste_sprint01.md`](./docs/casos_de_teste_sprint01.md): 27 casos de teste das histórias US01, US02, US03, US05, US06, US07 e US13, escritos a partir dos critérios de confirmação de cada card do Jira.

* **Resultado:** 19 casos passaram, 6 falharam e 2 passaram só em parte.
* **Evidência em vídeo:** o [vídeo de testes](./docs/screencast_testes_sprint01.mov) (1:46, com legendas e sem áudio) mostra os casos executados, e o [vídeo de demonstração](./docs/screencast_demonstracao_lofi.mp4) mostra os demais. Os horários de cada caso estão na coluna Evidência da tabela.
* **Falhas encontradas**, registradas na aba [Issues](https://github.com/vdornelass/pi2-squad-e7/issues):
  * O Espaço conta como erro de digitação (CT-US06-02, CT-US07-02 e CT-US07-03): [#1](https://github.com/vdornelass/pi2-squad-e7/issues/1).
  * As teclas W, A, S e D geram erro de digitação (CT-US06-03): [#2](https://github.com/vdornelass/pi2-squad-e7/issues/2).
  * O jogo não emite som (CT-US06-01 e CT-US07-05): [#3](https://github.com/vdornelass/pi2-squad-e7/issues/3).



### 9.4. Colaboração e evidências

_A preencher pela equipe._


