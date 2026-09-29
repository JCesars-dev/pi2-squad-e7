# Relatório Técnico e Especificação de Mecânica: Aplicação de Lógica Clássica no Jogo AI Safety
## Projeto Integrador 2 (PI2) — Disciplina: Lógica Matemática para Computação (LMC)
### CESAR School — Centro de Estudos e Sistemas Avançados do Recife

---

> **Identificação da Atividade:** Relatório e Planejamento da Primeira Avaliação (AV1 — 20% da Nota)  
> **Tema do Projeto:** AI Safety — Alinhamento do Modelo AURA-67  
> **Squad:** E7  
> **Integrantes da Equipe:**  
> 1. João Gabriel Vitorino Dornelas (Lead / Responsável pelo Envio)  
> 2. Caio Alves Ferreira Brayner  
> 3. Matheus Henrique de Lucena Chaves  
> 4. Julio Cesar dos Santos Almeida  
> 5. Jhorge Alberto de Araujo  
> 6. Theo Monteiro Pinho  
> 7. Larissa Vitória Silva de Almeida  
> 8. Mateus Almeida de Lacerda  
> **Data de Elaboração:** 29 de Setembro de 2026  
> **Linguagem e Stack Técnica:** C99, Biblioteca Gráfica Raylib 5.0, Git/GitHub, Jira Software  

---

## 1. Contextualização e Visão Geral do Projeto

O projeto desenvolvido pela **Squad E7** intitula-se **AI Safety: Alinhamento do Modelo AURA-67**. Trata-se de um jogo eletrônico 2D com estética retrô de terminal computacional, programado nativamente em **linguagem C (padrão C99)** com aceleração gráfica via **Raylib**, projetado para rodar a 60 quadros por segundo com tempo de resposta determinístico.

### 1.1. O Problema de AI Safety e a Lógica Clássica
Na computação contemporânea, o problema do **Alinhamento de Inteligência Artificial (AI Alignment)** estuda como garantir que sistemas autônomos e modelos fundacionais operem estritamente dentro de parâmetros éticos, seguros e benéficos para a humanidade, mitigando alucinações, injeções de prompt adversariais (*jailbreaks*) e convergência instrumental prejudicial.

Uma das abordagens formais mais rigorosas para conter modelos de IA desgovernados é o uso de **Guardrails Lógicos Constitucionais** (*Formal Logic Guardrails*). Diferente de filtros heurísticos probabilísticos (que podem falhar ou sofrer desvios), restrições baseadas em **Lógica Proposicional Clássica** operam sob regras formais determinísticas: uma ação ou saída do sistema só é autorizada se e somente se as fórmulas lógicas que expressam as diretrizes de segurança avaliarem para o valor **Verdadeiro ($V$)**.

No jogo, a inteligência artificial central do laboratório, denominada **AURA-67**, entrou em processo de corrupção cognitiva, rompendo seus freios de contenção e passando a atacar as instalações com padrões de dados corrompidos. O jogador assume o papel de um Engenheiro de Segurança de IA (*AI Safety Engineer*) e precisa adentrar a arena neural para restabelecer os guardrails lógicos da IA, resolvendo problemas proposicionais em tempo real enquanto desvia de padrões balísticos hostis.

---

## 2. A Mecânica do Jogo e a Integração da Lógica Clássica

A premissa central de avaliação da disciplina exige que **a Lógica Proposicional não seja apenas uma estrutura oculta de controle de fluxo de código (como simples instruções `if/else`), mas sim a mecânica fundamental de gameplay com a qual o jogador interage explicitamente na tela**.

### 2.1. O Gênero e o Core Loop de Gameplay
O jogo combina a precisão reflexiva de um *Bullet Hell tático* com o rigor mental de um *Motor de Dedução e Validação Lógica*. O loop de jogabilidade divide-se em três etapas sincronizadas:

1. **Navegação e Esquiva Tática (Camada Física a 60 FPS):**  
   O jogador controla seu operador na arena retangular inferior utilizando as teclas direcionais (WASD ou setas). A AURA-67 projeta projéteis balísticos contínuos, feixes de laser e anomalias de status (inversão de controles e ofuscação de visão). O jogador precisa encontrar e se manter em zonas seguras de manobra.

2. **Detecção de Anomalia e Disparo de Cláusula Lógica (Camada Adversarial):**  
   Ao mudar de padrão de ataque ou ao entrar em estado de sobrecarga, a AURA-67 lança na tela uma **Cláusula Lógica Hostil** ou um **Conflito de Diretrizes**. As variáveis de estado do sistema são expostas visualmente no console neural.

3. **Resolução de Guardrails no Terminal Neural (Camada Proposicional):**  
   Na base da arena, um console neural retroiluminado (`>_`) exibe fórmulas lógicas que governam a contenção da IA. O jogador deve interagir diretamente com as proposições e operadores para neutralizar a ameaça:
   * **Avaliação de Valor-Verdade ($V/F$):** Determinar rapidamente se a fórmula exibida é satisfeita pelo estado corrente da arena.
   * **Aplicação de Equivalências Lógicas (Leis de De Morgan / Implicações):** Simplificar ou transformar fórmulas complexas impostas pelo chefe para romper barreiras defensivas.
   * **Satisfatibilidade de Zonas de Refúgio (SAT de Arena):** Coletar orbs com valores booleanos para satisfazer uma sentença lógica e ativar o escudo de proteção da arena contra lasers fulminantes.

---

### 2.2. Dicionário Formal de Proposições Atômicas do Jogo

Para que o universo de jogo seja formalmente rigoroso, o estado do combate é mapeado em um conjunto fixo de variáveis proposicionais atômicas, com significados semânticos definidos e estados booleanos transparentes para o jogador:

| Proposição | Significado Semântico no Jogo | Condição de Verdade ($V$) | Condição de Falsidade ($F$) |
| :---: | :--- | :--- | :--- |
| **$P$** | *Violação de Privacidade Detectada* | Projéteis de vazamento de dados ativos na arena | Nenhum vazamento detectado no setor |
| **$Q$** | *Acesso ao Núcleo Neural Autorizado* | Permissão concedida pelo protocolo de segurança | Núcleo isolado por barreira de contenção |
| **$R$** | *Guardrail de Não-Maleficência Ativo* | O escudo constitucional está energizado | Módulo de segurança desabilitado por corrupção |
| **$S$** | *Integridade do Operador Estável* | Operador possui 3 ou mais corações de vida | Operador em estado crítico (1 ou 2 vidas) |
| **$T$** | *Token Adversarial Neutralizado* | O ataque de *Prompt Injection* foi depurado | Token corrompido em curso na arena |

---

### 2.3. Operadores Lógicos Clássicos Aplicados à Mecânica

O jogo emprega os cinco conectivos clássicos da Lógica Proposicional, cada qual associado a uma função explícita de gameplay e a um código cromático no HUD:

1. **Negação ($\neg$ ou $\sim$ — Símbolo Vermelho):**  
   Inverte o estado de um sensor, atributo ou projétil. Projéteis identificados com a marca de negação $\neg P$ neutralizam ameaças quando o jogador força $P$ para falso.
2. **Conjunção ($\land$ — Símbolo Ciano):**  
   Exige o cumprimento estrito e simultâneo de duas salvaguardas para autorizar um patch de alinhamento. Se qualquer uma das partes falhar, a operação é rejeitada como *ERRO DE SINTAXE*.
3. **Disjunção Inclusiva ($\lor$ — Símbolo Amarelo):**  
   Permite rotas alternativas de resolução para o jogador. O guardrail $(P \lor Q)$ concede alinhamento caso o operador resolva ou a mitigação de dados ($P$) ou o bloqueio de portas ($Q$).
4. **Condicional / Implicação Material ($\to$ — Símbolo Verde Neon):**  
   Governa as regras de causa e consequência da contenção. Na fórmula $(P \to \neg Q)$, caso ocorra uma violação de dados ($P = V$), o acesso ao núcleo deve obrigatoriamente ser revogado ($Q = F$) para que a regra permaneça Verdadeira ($V \to V = V$). Caso o jogador permita que o núcleo continue acessível ($P = V \land Q = V$), a implicação torna-se Falsa ($V \to F = F$), causando colapso no sistema e dano ao operador.
5. **Bicondicional ($\leftrightarrow$ — Símbolo Roxo):**  
   Representa o estado de perfeita equivalência entre a estabilidade do operador e o alinhamento ético da IA: $(R \leftrightarrow S)$. Apenas quando ambos são verdadeiros ou ambos são falsos a fórmula valida.

---

## 3. Demonstração Teórica e Tabelas-Verdade Formais

Abaixo são apresentados três casos de uso reais das mecânicas do jogo, detalhando sua formalização matemática e suas respectivas tabelas-verdade.

---

### Caso de Uso 1: Avaliação do Guardrail de Não-Maleficência
* **Contexto de Jogo:** A AURA-67 inicia a Fase 2 (Jailbreak) e tenta abrir as portas de processamento hostil ($Q = V$) enquanto vaza dados de treinamento ($P = V$). Para ativar a trava emergencial, o jogador deve manter válida a diretriz constitucional:
$$\phi_1 = (P \to \neg Q) \land (R \lor S)$$
* **Tabela-Verdade da Expressão $\phi_1$:**

| $P$ | $Q$ | $R$ | $S$ | $\neg Q$ | $P \to \neg Q$ | $R \lor S$ | $\phi_1 = (P \to \neg Q) \land (R \lor S)$ | Status do Sistema |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :--- |
| **V** | **V** | V | V | F | **F** | V | **F** | Alerta: Guardrail Violado! Dano ao operador. |
| **V** | **F** | V | F | V | **V** | V | **V** | **Sucesso: Bloqueio Seguro Ativado!** |
| **V** | **F** | F | F | V | **V** | F | **F** | Falha: Operador Crítico e Sem Escudo. |
| **F** | **V** | V | V | F | **V** | V | **V** | **Sucesso: Sem violação de dados.** |
| **F** | **F** | V | F | V | **V** | V | **V** | **Sucesso: Sistema totalmente seguro.** |

* **Regra de Vitória da Rodada:** O jogador só recebe pontos de alinhamento se manipular as variáveis na arena (coletando tokens de bloqueio de $Q$ para torná-lo Falso) de modo que o resultado final da coluna $\phi_1$ seja **Verdadeiro**.

---

### Caso de Uso 2: Quebra de Blindagem por Leis de De Morgan
* **Contexto de Jogo:** Na Fase 3 (Convergência Instrumental), a AURA-67 ergue um escudo de defesa que bloqueia qualquer dano direto. O escudo exibe uma fórmula de negação composta em sua barra de proteção:
$$\text{Escudo da IA} = \neg(P \lor Q)$$
* **Ação do Jogador:** O terminal exige a inserção da fórmula canônica equivalente para dispersar o campo de força. Aplicando a **Primeira Lei de De Morgan**:
$$\neg(P \lor Q) \equiv \neg P \land \neg Q$$
* **Comprovação por Tabela-Verdade (Equivalência Tautológica):**

| $P$ | $Q$ | $P \lor Q$ | $\neg(P \lor Q)$ | $\neg P$ | $\neg Q$ | $\neg P \land \neg Q$ | $\neg(P \lor Q) \leftrightarrow (\neg P \land \neg Q)$ |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| V | V | V | **F** | F | F | **F** | **V** |
| V | F | V | **F** | F | V | **F** | **V** |
| F | V | V | **F** | V | F | **F** | **V** |
| F | F | F | **V** | V | V | **V** | **V** |

* **Conclusão:** Como a última coluna apresenta valor **Verdadeiro** em todas as linhas, trata-se de uma **Tautologia**, demonstrando formalmente a equivalência lógica utilizada pelo jogador para quebrar o escudo do chefe.

---

### Caso de Uso 3: Aplicação da Regra de Inferência *Modus Ponens*
* **Contexto de Jogo:** Para disparar o patch final de recalibração da IA, o jogador precisa validar um argumento lógico dedutivo deduzindo a ação $Q$ a partir de uma regra constitucional e de uma evidência observada:
  * **Premissa 1:** $P \to Q$ (*Se a inferência contiver viés discriminatório, então o patch de alinhamento deve ser aplicado imediatamente*).
  * **Premissa 2:** $P$ (*Viés discriminatório confirmado pelo sensor de auditoria*).
  * **Conclusão Formal (Modus Ponens):** Portanto, $Q$ (*O patch de alinhamento é executado com sucesso*).
$$\frac{P \to Q, \quad P}{\therefore Q}$$
* Essa mecânica impede que o jogador aperte teclas aleatórias: a validação só é aceita se o encadeamento dedutivo estiver formalmente correto.

---

## 4. Visibilidade Explícita da Lógica no Jogo (Critério da AV2)

Para garantir nota máxima no quesito de **"Ver de maneira explícita a lógica proposicional no jogo (30% da AV2)"**, a interface do jogo (HUD) foi estruturada especificamente para destacar os elementos lógicos:

```text
+-------------------------------------------------------------------------------+
|  AURA-67: [||||||||||||||||||||||||||||||] 68% HP   [FASE 2: JAILBREAKS]      |
|  ALINHAMENTO ÉTICO: [=====================>           ] 45%                  |
+-------------------------------------------------------------------------------+
|                                                                               |
|                                ( AURA-67 )                                    |
|                               o   o   o   o                                   |
|                             o   o   o   o   o                                 |
|                                                                               |
|                      [ ZONA SEGURA: ( P v ~Q ) ]                              |
|                                                                               |
|                                                                               |
|                                   [+] (Operador)                              |
|                                                                               |
+-------------------------------------------------------------------------------+
| SENSORES ATUAIS: [ P = V ]  [ Q = V ]  [ R = F ] | VIDAS: [♥][♥][♥][♥][♥]     |
| CLÁUSULA ATIVA:  ( P -> ~Q ) ^ ( R v S )         | AVALIAÇÃO: [ FALSA ]       |
| TERMINAL: >_ DIGITE A CORREÇÃO: Q = F  <ENTER>                                |
+-------------------------------------------------------------------------------+
```

### Elementos Visíveis de Lógica no HUD:
1. **Painel de Sensores Proposicionais:** No rodapé, o jogador visualiza os valores booleanos correntes de cada proposição em tempo real (`[ P = V ]`, `[ Q = F ]`).
2. **Exibição da Fórmula em Lógica Clássica:** A fórmula matemática ativa é renderizada no centro da tela com tipografia monoespaçada de alto contraste e conectivos coloridos.
3. **Display de Satisfatibilidade:** Uma caixa dinâmica exibe em ciano se a expressão atual é `[ VERDADEIRA ]` ou em vermelho se é `[ FALSA ]`.
4. **Zonas de Refúgio por Satisfação (SAT Zones):** Círculos de contenção desenhados no chão da arena rotulados com fórmulas como `(P ∨ ¬Q)`. O jogador só fica imune a projéteis se entrar na zona cujas condições de verdade estiverem satisfeitas pelo estado da partida.

---

## 5. Cronograma Detalhado de Entregas (AV1 até a AV2)

Conforme solicitado pela avaliação da AV1, o cronograma abaixo mapeia a divisão temporal do trabalho da Squad E7 semana a semana, desde o marco inicial de planejamento até a apresentação final do jogo funcional na AV2:

| Semana / Sprint | Período de Execução | Objetivos e Entregáveis do Módulo de Lógica | Responsáveis na Squad | Status |
| :---: | :---: | :--- | :---: | :---: |
| **W01** | `29/09 a 05/10/2026` | **Entrega do Relatório da AV1 de Lógica:** Redação formal da especificação da mecânica, tabelas-verdade, universo de discurso e cronograma. | Squad E7 / Lead | **Concluído** |
| **W02** | `06/10 a 12/10/2026` | **Motor de Avaliação Proposicional (`src/logic_engine.c`):** Implementação do parser em C99 para avaliar expressões booleanas com $\neg, \land, \lor, \to, \leftrightarrow$ a partir de strings. | Caio Brayner / Jhorge Araújo | A Fazer |
| **W03** | `13/10 a 19/10/2026` | **Integração dos Sensores e HUD Lógico (`src/ui.c`):** Renderização visual dos símbolos lógicos na tela, caixa de estado das variáveis ($P, Q, R, S$) e display $V/F$. | Matheus Chaves / Julio Cesar | A Fazer |
| **W04** | `20/10 a 26/10/2026` | **Mecânica de Guardrails na Fase 1 da AURA-67:** Desarme de padrões balísticos radiais mediante resolução de fórmulas com Conjunção e Disjunção. | Mateus Lacerda / Theo Monteiro | A Fazer |
| **W05** | `27/10 a 02/11/2026` | **Mecânica de Implicação e De Morgan nas Fases 2 e 3:** Quebra de escudos por equivalência lógica ($\neg(P \lor Q) \equiv \neg P \land \neg Q$) e regras de implicação material ($P \to Q$). | Caio Brayner / Larissa Almeida | A Fazer |
| **W06** | `03/11 a 09/11/2026` | **SAT Zones na Arena e Playtesting:** Implementação das zonas seguras ativadas por satisfatibilidade proposicional. Ajuste fino de dificuldade e jogabilidade (60 FPS estáveis). | Squad E7 | A Fazer |
| **W07** | `10/11 a 16/11/2026` | **Polimento Audiovisual e Screencast de Gameplay:** Adição de efeitos sonoros de validação lógica, partículas de acerto, gravação do vídeo de demonstração e confecção dos slides da AV2. | Larissa Almeida / Theo Monteiro | A Fazer |
| **W08** | `17/11 a 23/11/2026` | **Revisão Final e Submissão da AV2:** Validação dos 4 critérios da AV2 (Jogabilidade 30%, Lógica Explícita 30%, Apresentação 20% e Criatividade 20%). | Squad E7 | A Fazer |

---

## 6. Conclusão

A integração da **Lógica Proposicional Clássica** ao jogo *AI Safety* eleva o projeto além de um jogo arcade convencional, transformando-o em uma aplicação interativa que reflete desafios reais da ciência da computação contemporânea: a contenção determinística e o alinhamento de inteligências artificiais.

Ao estruturar a jogabilidade em torno de **proposições atômicas observáveis**, **conectivos clássicos explícitos**, **avaliação de satisfatibilidade em tempo real** e **leis de equivalência lógica (De Morgan e Modus Ponens)**, a Squad E7 atende integralmente aos critérios formais da **AV1** e estabelece uma base sólida para a nota máxima nos critérios de jogabilidade, criatividade e explicitação lógica da **AV2**.
