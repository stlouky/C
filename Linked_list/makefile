CC = gcc
CFLAGS = -Wall -g
LDFLAGS =
TARGET = program
TEST_TARGET = test
SRC_DIR = src
TEST_DIR = test
SRC = $(wildcard $(SRC_DIR)/*.c)
TEST_SRC = $(wildcard $(TEST_DIR)/*.c)
OBJS = $(SRC:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)
TEST_OBJS = $(TEST_SRC:$(TEST_DIR)/%.c=$(TEST_DIR)/%.o)

.PHONY: all clean run test

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(OBJS)
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

$(TEST_TARGET): $(OBJS) $(TEST_OBJS)
	@$(CC) $(CFLAGS) -o $(TEST_TARGET) $(OBJS) $(TEST_OBJS) $(LDFLAGS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	@./$(TARGET)

test_run: $(TEST_TARGET)
	@./$(TEST_TARGET)

clean:
	@rm -f $(TARGET) $(OBJS) $(TEST_OBJS)
	@rm -rf $(TEST_TARGET)
	@echo "Vyčištění bylo úspěšné."