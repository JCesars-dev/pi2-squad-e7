# Project Model Canvas (PM Canvas)
## Projeto: AI Safety — Alinhamento do Modelo AURA-67 (Squad E7 — PI2)

O **Project Model Canvas (PM Canvas)** sintetiza a estratégia, escopo, requisitos e planejamento do projeto *AI Safety*, integrando as diretrizes da disciplina de **Frameworks de Processos 2 (FP2)** da CESAR School.

---

```text
+---------------------------------------------------------------------------------------------------------------+
|                                           PROJECT MODEL CANVAS                                                |
+-------------------+-------------------+-------------------+-------------------+-------------------------------+
| POR QUE?          | O QUE?            | QUEM?             | COMO?             | QUANDO?                       |
+-------------------+-------------------+-------------------+-------------------+-------------------------------+
| JUSTIFICATIVAS    | PRODUTO           | STAKEHOLDERS      | PREMISSAS         | GRUPO DE ENTREGAS             |
|                   |                   |                   |                   |                               |
| OBJETIVOS SMART   | REQUISITOS        | EQUIPE (SQUAD E7) | RISCOS            | LINHA DO TEMPO & RESTRICOES   |
|                   |                   |                   |                   |                               |
| BENEFICIOS        | NAO-ESCOPO        |                   |                   |                               |
+-------------------+-------------------+-------------------+-------------------+-------------------------------+
```

---

### 1. Por Que? (Justificativa, Objetivos e Benefícios)

#### 1.1. Justificativas
* Urgência acadêmica e mercadológica em debater **Segurança, Ética e Alinhamento em Inteligência Artificial** (mitigação de vieses, alucinações, vazamento de privacidade/LGPD e riscos de convergência instrumental).
* Dificuldade de estudantes em compreender na prática como funcionam mecanismos de **Alinhamento Constitucional e Guardrails de IA** (*Human-in-the-Loop*).
* Necessidade de ferramentas didáticas interativas que combinem dinâmicas de ação e digitação com conscientização crítica sobre o papel humano na supervisão de modelos de IA.

#### 1.2. Objetivo SMART
* Desenvolver e disponibilizar na web a aplicação interativa de **AI Safety** até o encerramento do semestre letivo (W17), contendo **15 Histórias de Usuário validadas**, módulos de inserção de diretrizes éticas em tempo real e desafios de alinhamento com o modelo **AURA-67**, alcançando avaliação de usabilidade $\ge 80\%$ de satisfação.

#### 1.3. Benefícios
* Conscientização crítica sobre os dilemas contemporâneos da IA através da reprogramação ativa e mitigação de vulnerabilidades (vieses, jailbreaks e injeções adversariais).
* Fixação prática de princípios de governança, auditoria de modelos e supervisão humana (*Constitutional AI*).
* Validação e convergência multidisciplinar das matérias do semestre (PIF, IHC, LMC, FDS, FP2).

---

### 2. O Que? (Produto, Requisitos e Não-Escopo)

#### 2.1. Produto
* **AI Safety:** Aplicação web interativa em terminal neural com motor em C/Web, ambientada nos laboratórios e datacenter da CESAR School, onde o jogador atua como AI Safety Engineer para reprogramar o modelo AURA-67.

#### 2.2. Requisitos de Alto Nível
* **Requisitos Funcionais (RF):**
  * Movimentação do engenheiro no terminal e ambiente do datacenter (WASD / direcionais).
  * Inserção e validação de diretrizes de alinhamento ético e constitucional em tempo real.
  * Barra de Alinhamento Ético (0% a 100%) que altera o comportamento e mensagens do modelo.
  * Mecânicas de defesa contra ataques adversariais (Prompt Injections e Context Drift).
  * Persistência de estado local (Save/Load) e condições de convergência ou falha.
* **Requisitos Não-Funcionais (RNF):**
  * Execução fluida no navegador web sem dependência de plugins externos pesados.
  * Tempo de resposta para validação lógica inferior a 100ms.
  * Código modular em C compilável sob padrão C99 sem vazamento de memória.
  * Interface em conformidade com as 10 Heurísticas de Usabilidade de Nielsen.

#### 2.3. Não-Escopo (O que NÃO será feito)
* Modo multiplayer cooperativo ou online.
* Gráficos fotorrealistas de alta complexidade que comprometam o carregamento web.
* Suporte nativo para plataformas mobile com controles de toque complexos.
* Treinamento de redes neurais reais pesadas executando localmente no navegador do cliente.

---

### 3. Quem? (Stakeholders e Equipe)

#### 3.1. Stakeholders Externos
* **Docentes Avaliadores:** Professores das disciplinas de FP2, FDS, LMC, IHC e PIF da CESAR School.
* **Usuários Finais:** Estudantes de Ciência da Computação, ADS, Engenharia e entusiastas de lógica e IA responsável.

#### 3.2. Equipe de Desenvolvimento (Squad E7)
* **Larissa Almeida:** Lead de Engenharia de Software (FDS)
* **Mateus Lacerda:** Gestão Ágil / Scrum Master (FP2) & Engenharia de Requisitos
* **Theo Monteiro:** Analista de Requisitos & Testador de Software (QA)
* **João Gabriel:** Desenvolvedor Web/C, Haskell e Arquitetura
* **Caio Brayner:** Desenvolvedor C
* **Matheus Chaves:** Designer de Interface (IHC) & Desenvolvedor Canvas/Web
* **Julio Cesar:** Consultor de Lógica Matemática (LMC) & Testador
* **Jhorge Araújo:** Consultor de Arquitetura e Lógica Matemática (LMC)

---

### 4. Como? (Premissas e Riscos)

#### 4.1. Premissas
* O usuário final possui navegador web moderno (Chrome, Firefox, Edge) com suporte a HTML5 Canvas e WebGL.
* O fluxo de desenvolvimento seguirá a cadência de Sprints quinzenais gerenciadas via Jira Software.
* A validação de inferências e regras de inferência será portada para Haskell na Unidade 2.

#### 4.2. Gestão de Riscos e Mitigações

| Risco Identificado | Impacto | Probabilidade | Estratégia de Mitigação |
| :--- | :--- | :--- | :--- |
| **Gargalo de renderização no Canvas web** | Alto | Média | Utilizar renderização geométrica otimizada e desacoplamento do loop de desenho. |
| **Dificuldade excessiva nos puzzles lógicos** | Médio | Média | Incluir tutoriais progressivos e explicações textuais no terminal de ajuda. |
| **Desvio de escopo (Scope Creep)** | Alto | Baixa | Rastreabilidade estrita através das 15 USs priorizadas via MoSCoW no Jira. |
| **Erros na integração entre JS e C** | Médio | Média | Definir contratos de dados claros e desacoplamento de módulos. |

---

### 5. Quando? (Grupo de Entregas e Linha do Tempo)

```text
[UNIDADE 1] =====================================> [UNIDADE 2] ====================================>
W01 - W04: Concepção & Setup                       W09 - W12: Port Haskell & Refinamento
├── Canvas, RACI, Backlog Inicial (FP2)            ├── Validador Lógico em Haskell (PIF/LMC)
├── Documento de Visão e RF/RNF (FDS)              ├── Testes Empíricos de Usabilidade (IHC)
└── 15 Histórias de Usuário (Jira)                 └── Módulo de Persistência Avançado (FDS)

W05 - W08: Protótipo Jogável de AI Safety em C     W13 - W17: Versão Final & Validação
├── Motor Gráfico 2D em C99 (PIF)                  ├── Fechamento do Produto e Testes de Carga
├── Validador de Proposições e Lógica (LMC)        ├── Demonstração de Banca e Apresentação
└── Entrega do MVP 1 (U1)                          └── Relatório Final de Encerramento (FP2)
```

---

### 6. Revisão do Canvas & Resultados do MVP 1 (Fechamento da Unidade 1)

*Responsável pela Revisão:* Larissa Almeida (Lead de Engenharia de Software / FP2)  
*Data de Atualização:* 24/09/2026 (Sprint W08)

#### 6.1. Riscos Mitigados no MVP 1
1. **Gargalo de Performance Gráfica:** Mitigado com sucesso através da arquitetura C99 desacoplada (física, partículas e renderização), mantendo taxa estável de 60 FPS com consumo mínimo de recursos.
2. **Conflito de Input (Movimentação vs. Digitação):** Mitigado pelo filtro no motor de digitação (`typing_engine.c`), permitindo esquiva ágil com WASD sem penalidades acidentais no buffer de diretrizes.
3. **Escopo e Rastreabilidade:** Mitigado pela manutenção rigorosa das 15 Histórias de Usuário no Jira e correspondência biunívoca com a estrutura do código.

#### 6.2. Premissas Validadas
* O formato de arena 2D com terminal retrô retroiluminado (`>_`) atende aos princípios de usabilidade e reforça o alinhamento ético e didático do jogo.
* A cadência quinzenal com acompanhamento no Jira manteve 100% das entregas das semanas W02, W06 e W08 dentro do prazo regulamentar da CESAR School.

#### 6.3. Transição para a Unidade 2
* **Foco Técnico:** Portar o validador de diretrizes e inferências lógicas para Haskell (PIF/LMC).
* **Foco de IHC:** Executar testes empíricos de usabilidade presenciais com a persona definida.
* **Foco de FDS/FP2:** Implementar arquitetura de persistência e refinar métricas de velocidade da equipe.

