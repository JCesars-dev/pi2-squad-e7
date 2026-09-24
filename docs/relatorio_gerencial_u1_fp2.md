# Relatório Gerencial de Fechamento da Unidade 1 (FP2)
## Projeto: AI Safety — Alinhamento do Modelo AURA-67 (Squad E7 — PI2)

> **Documento de Gestão Ágil e Governança de Projetos (FP2)**  
> **Responsáveis:** Larissa Almeida (Lead de Engenharia de Software) e Mateus Lacerda (Scrum Master)  
> **Data:** 24/09/2026 (Ciclo W08 — Fechamento da U1)  
> **Status:** Minuta consolidada de fechamento da Unidade 1  

---

## 1. Sumário Executivo

Ao longo do ciclo da **Unidade 1 (Semanas W01 a W08)**, a **Squad E7** cumpriu integralmente os objetivos pedagógicos e técnicos das disciplinas integradas (FP2, FDS, IHC, LMC e PIF) da **CESAR School**.

O projeto convergiu para o desenvolvimento de uma aplicação interativa em tempo real centrada em **Conscientização e Segurança em Inteligência Artificial (AI Safety)**. O usuário atua no papel de um(a) *AI Safety Engineer* que deve reprogramar os pesos e guardrails do supermodelo autônomo **AURA-67**, combinando dinâmicas de esquiva tática com a validação ativa de diretrizes constitucionais e éticas digitadas no terminal neural.

---

## 2. Estrutura Organizacional e Matriz de Responsabilidades (RACI)

A Squad E7 estruturou sua governança ágil garantindo que cada disciplina contasse com uma liderança técnica e responsabilidades claras:

| Integrante | Papel Principal | Frentes de Atuação |
| :--- | :--- | :--- |
| **Larissa Almeida** | Lead de Engenharia (FDS) | Engenharia de Software, Rastreabilidade, PM Canvas e Governança |
| **Mateus Lacerda** | Scrum Master / Gestão Ágil (FP2) | Facilitação de Sprints, Backlog MoSCoW e Métricas |
| **João Gabriel** | Lead de Arquitetura e Motor C (PIF) | Game Loop a 60 FPS, Makefile, Física e Raylib C99 |
| **Theo Monteiro** | Analista de Requisitos & QA (FDS/FP2) | Testes de Sistema, Especificação de RF/RNF e Auditoria |
| **Caio Brayner** | Desenvolvedor C & Suporte IHC | Módulos de Jogador/Colisão e Prototipação Lo-Fi |
| **Matheus Chaves** | Designer de Interação & UI (IHC) | Design System, Paleta Retrô Neon e Telas do Figma |
| **Julio Cesar** | Consultor de Lógica Matemática (LMC) | Modelagem Proposicional, Equivalências e Testes |
| **Jhorge Araújo** | Consultor de Lógica e Arquitetura (LMC/PIF) | Validação Lógica, Refatoração e Arquitetura de Módulos |

---

## 3. Histórico de Entregas por Sprint (W01 a W08)

Durante a Unidade 1, a equipe realizou entregas contínuas em cadência quinzenal, 100% registradas e rastreadas via Jira Software:

```text
W01-W02 (Sprint 1) ───> W03-W04 (Sprint 2) ───> W05-W06 (Sprint 3) ───> W07-W08 (Sprint 4)
 ├── Visão do Produto    ├── Personas (IHC)      ├── RF01-RF08 (FDS)     ├── MVP 1 Jogável (C99)
 ├── 15 User Stories     ├── Lo-Fi Preliminar    ├── RNF01-RNF05 (FDS)   ├── Refatoração LMC
 └── PM Canvas V1        └── Regras LMC (V1)     └── MoSCoW Backlog      └── Entrega 02 FDS
```

### 3.1. Sprint W02 (Visão e Backlog Inicial)
* **Entregas FDS/FP2:** Documento de Visão e Engenharia de Requisitos (`PI2-14`), levantamento das 15 User Stories no padrão 3Cs (`PI2-41`) e Project Model Canvas inicial (`PI2-12`).
* **Resultado:** Aprovação da proposta temática de AI Safety e alinhamento pedagógico com a CESAR School.

### 3.2. Sprint W04 (Design de Interação e Setup de Desenvolvimento)
* **Entregas IHC/PIF/LMC:** Definição da Persona *Lucas Andrade* (`PI2-83`), protótipo de baixa fidelidade preliminar no Figma (`PI2-85`), repositório C configurado com Makefile multiplataforma (`PI2-15`) e formalização de regras de inferência em LMC (`PI2-16`).

### 3.3. Sprint W06 (Refinamento de Requisitos e Motor em C)
* **Entregas FDS/FP2/PIF:** Especificação formal de 8 Requisitos Funcionais e 5 Não-Funcionais (`PI2-19`), priorização MoSCoW do Backlog (`PI2-20`) e implementação do motor gráfico 2D em C99 com suporte a Raylib a 60 FPS (`PI2-17`).

### 3.4. Sprint W08 (MVP 1, Refatoração Lógica e Entrega 02 FDS)
* **Entregas FDS/LMC/PIF:** Jogo funcional compilável sem warnings (`make run`), relatório formal de refatoração de condicionais via Leis de De Morgan e Álgebra Booleana (`Relatorio_LMC_Refatoracao_Logica_23_09.pdf`), atualização do PM Canvas (`PI2-170`) e infraestrutura de rastreabilidade da Entrega 02 (`PI2-122`).

---

## 4. Indicadores de Produtividade e Métricas Ágeis

* **Total de Histórias e Subtarefas Cadastradas:** 172 tickets no projeto `PI2`.
* **Taxa de Conclusão da Squad na U1:** $\ge 85\%$ de itens concluídos dentro do prazo.
* **Qualidade de Código:** 0 warnings em compilação sob padrão `-Wall -Wextra -std=c99`.
* **Rastreabilidade de Requisitos:** 100% das 15 Histórias de Usuário mapeadas aos cards do Jira, módulos de código em C e artefatos de modelagem.

---

## 5. Retrospectiva da Squad (Lições Aprendidas)

### 5.1. O que funcionou bem (Pontos Fortes)
* **Engajamento e Distribuição de Papéis:** Cada integrante assumiu a responsabilidade por sua disciplina de especialização, reduzindo sobrecarga.
* **Governança via Jira:** O acompanhamento sistemático de cards e subtarefas permitiu identificar e desbloquear pendências antes dos prazos finais.
* **Qualidade da Documentação:** O `README.md` e a pasta `docs/` mantiveram documentação viva, com diagramas e matrizes sempre sincronizados com o código.

### 5.2. O que pode ser aprimorado (Plano de Ação para a U2)
* **Gerenciamento de Acessos Externos:** Garantir que links de ferramentas na nuvem (como Figma e Google Drive) sejam sempre configurados com permissão pública de visualização (*Anyone with the link can view*) logo no início da tarefa.
* **Antecipação de Gravações de Tela:** Realizar testes de gravação com 48h de antecedência para evitar gargalos na véspera de entregas.

---

## 6. Planejamento Estratégico para a Unidade 2 (W09 a W17)

1. **Port do Validador para Haskell (PIF & LMC):**
   - Transpor a lógica de verificação de diretrizes e inferências booleanas para tipos algébricos e funções puras em Haskell.
2. **Testes de Usabilidade Empíricos (IHC):**
   - Aplicar testes de usabilidade presenciais com usuários do perfil da persona, coletando métricas de satisfação (SUS $\ge 80$).
3. **Persistência de Sessão e Áudio (FDS & PIF):**
   - Implementar Save/Load binário de progresso (`US14`) e trilha sonora retrô dinâmica.
4. **Fechamento e Apresentação de Banca (FP2):**
   - Compilação dos relatórios gerenciais finais, ensaio de pitch e entrega do produto finalizado.
