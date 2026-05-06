CC = gcc
CFLAGS = -Wall -Wextra -g -I./include
SRC_DIR = source
TEST_DIR = tests
BIN_DIR = bin
INC_DIR = include

# Arquivos fonte
SRC = $(SRC_DIR)/shell_Sort.c
TEST_SRC = $(TEST_DIR)/test_shell.c
OBJ = $(BIN_DIR)/shell_Sort.o
TEST_OBJ = $(BIN_DIR)/test_shell.o

# Executável
EXEC = $(BIN_DIR)/test_shell

.PHONY: all clean run debug

all: $(EXEC)

# Compila o executável do teste
$(EXEC): $(OBJ) $(TEST_OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Compila os objetos
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Roda o programa
run: $(EXEC)
	./$(EXEC)

# Roda no GDB
debug: $(EXEC)
	gdb ./$(EXEC)

# Limpa os binários
clean:
	rm -rf $(BIN_DIR)/*
