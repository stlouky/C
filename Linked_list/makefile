# Kompilátor a volby kompilace
CC = gcc
CFLAGS = -Wall -g -Isrc  # -Wall: zobrazit všechna varování, -g: přidat ladicí informace, -Isrc: zahrnout hlavičkové soubory ze složky src
TEST_CFLAGS = -DTESTING  # Při kompilaci testů definovat makro TESTING

# Výstupní cíle
TARGET = program  # Název hlavního programu
TEST_TARGET = test_executable  # Název testovacího spustitelného souboru

# Složky se zdrojovými kódy
SRC_DIR = src  # Složka se zdrojovými soubory programu
TEST_DIR = test  # Složka s testovacími soubory

# Zdroje a objektové soubory
SRC = $(filter-out $(SRC_DIR)/link_list.c, $(wildcard $(SRC_DIR)/*.c))  # Všechny zdrojové soubory kromě link_list.c
TEST_SRC = $(wildcard $(TEST_DIR)/*.c)  # Všechny testovací zdrojové soubory
OBJS = $(SRC:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)  # Vytvoření seznamu objektových souborů z hlavních zdrojových souborů
TEST_OBJS = $(TEST_SRC:$(TEST_DIR)/%.c=$(TEST_DIR)/%.o) $(OBJS)  # Vytvoření seznamu objektových souborů pro testy a zahrnutí hlavních objektů

.PHONY: all clean run run_tests  # Cíle, které nejsou skutečnými soubory

# Hlavní cíl pro kompilaci celého programu
all: $(TARGET)

# Kompilace hlavního programu
$(TARGET): $(OBJS) src/link_list.o
	@echo "Kompiluji hlavní program..."
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) src/link_list.o

# Kompilace testovacího spustitelného souboru
$(TEST_TARGET): $(TEST_OBJS)
	@echo "Kompiluji testy..."
	$(CC) $(CFLAGS) $(TEST_CFLAGS) -o $(TEST_TARGET) $(TEST_OBJS)

# Spuštění hlavního programu
run: $(TARGET)
	@echo "Spouštím program..."
	@./$(TARGET)

# Spuštění testovacího spustitelného souboru
run_tests: $(TEST_TARGET)
	@echo "Spouštím testy..."
	@./$(TEST_TARGET)

# Vyčištění všech binárních a objektových souborů
clean:
	@echo "Čistím binární soubory a objektové soubory..."
	find $(SRC_DIR) -name "*.o" -type f -delete
	find $(TEST_DIR) -name "*.o" -type f -delete
	rm -f $(TARGET)
	rm -f $(TEST_TARGET)
	@echo "Vyčištění bylo úspěšné."
