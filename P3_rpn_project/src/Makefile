CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic

BUILD_DIR = ../build
SRC_DIR = .
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))
TARGET = $(BUILD_DIR)/graph

default: purge format analyze all run clean
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

leaks: all
	leaks -atExit -- $(BUILD_DIR)/graph

run: all
	$(TARGET)

purge:
	rm -f $(BUILD_DIR)/graph $(BUILD_DIR)/*.o

clean:
	rm -f $(BUILD_DIR)/*.o

format:
	find . -name "*.c" -o -name "*.h" | xargs clang-format -i
	find . -name "*.c" -o -name "*.h" | xargs clang-format -n

analyze:
	find . -name "*.c" -o -name "*.h" | xargs cppcheck --enable=all --suppress=missingIncludeSystem

.PHONY: purge default all leaks run clean format analyze

