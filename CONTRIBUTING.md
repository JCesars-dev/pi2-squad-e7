# Guia de Contribuição — Squad E7

Bem-vindo ao repositório do **AI Safety: Alinhamento da AURA-67** (Projeto Integrador 2 — CESAR School). Este documento estabelece os padrões técnicos de versionamento e fluxo de trabalho para todos os membros da Squad E7.

---

## 1. Fluxo de Trabalho Git (Feature Branch Workflow)

Para garantir que a branch `main` permaneça sempre estável e pronta para entrega, utilize branches específicas para cada card do Jira:

1. **Atualize sua branch local:**
   ```bash
   git checkout main
   git pull origin main
   ```
2. **Crie uma branch com o prefixo da atividade:**
   ```bash
   git checkout -b feature/PI2-XXX-nome-da-tarefa
   ```
3. **Faça seus commits e envie para o GitHub:**
   ```bash
   git push -u origin feature/PI2-XXX-nome-da-tarefa
   ```
4. **Abra um Pull Request (PR) no GitHub**, preenchendo o template e solicitando a revisão de pelo menos um colega antes do merge.

---

## 2. Padrão de Mensagens de Commit (Conventional Commits)

Utilizamos a convenção do *Conventional Commits*:

* `feat(escopo):` Adição de nova funcionalidade (ex: `feat(pif): implementar modulo save.c`).
* `fix(escopo):` Correção de bug (ex: `fix(bullet): corrigir colisao de projeteis`).
* `docs(escopo):` Alterações em documentação (ex: `docs(lmc): atualizar relatorio formal da AV1`).
* `style(escopo):` Ajustes visuais, formatação de código ou CSS/HTML.
* `refactor(escopo):` Refatoração de código sem alteração de funcionalidade.
* `test(escopo):` Adição ou ajuste de testes.

---

## 3. Padrões de Código C (C99)

* **Linguagem:** C99 (`-std=c99`).
* **Compilação Limpa:** O código deve compilar sem nenhum aviso com as flags `-Wall -Wextra -std=c99 -pedantic`.
* **Nomenclatura:**
  * Nomes de variáveis e funções em minúsculas com *snake_case* (ex: `alignment_pct`, `player_take_damage`).
  * Constantes e macros em maiúsculas (ex: `MAX_PHRASES`, `SCREEN_WIDTH`).
  * Evite nomes genéricos (`x`, `a`, `aux`).
* **Documentação:** Toda função e struct deve possuir comentários explicativos sucintos sobre seus parâmetros e finalidade.

---

## 4. Como Executar Localmente

Consulte a **Seção 8 do [README.md](./README.md)** para instruções completas de execução no Linux, WSL e Windows via [`jogar.bat`](./jogar.bat).
