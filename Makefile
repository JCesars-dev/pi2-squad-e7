CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic -Iinclude -Isrc
TARGET = bin/jogo
SRCS = src/main.c src/player.c src/boss.c src/bullet.c src/typing_engine.c src/ui.c

# Detecção de Sistema Operacional
UNAME_S := $(shell uname -s 2>/dev/null || echo Windows)

ifeq ($(UNAME_S), Linux)
    LDFLAGS = -Llib -Wl,-rpath,'$$ORIGIN/../lib' -lraylib -lm -lpthread -ldl
else
    # Windows MinGW
    LDFLAGS = -Llib -lraylib -lopengl32 -lgdi32 -lwinmm
endif

all: $(TARGET)

$(TARGET): $(SRCS)
	@mkdir -p bin
	$(CC) $(CFLAGS) $(SRCS) $(LDFLAGS) -o $(TARGET)
	@echo "Compilacao do AI Safety em C (Raylib) concluida com sucesso!"

run: all
ifeq ($(UNAME_S), Linux)
	LD_LIBRARY_PATH=lib:$$LD_LIBRARY_PATH ./$(TARGET)
else
	./$(TARGET)
endif

clean:
	rm -f bin/jogo bin/*.o bin/*.exe
	@echo "Limpeza concluida."

.PHONY: all run clean
