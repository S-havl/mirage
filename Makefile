CC := gcc
CFLAGS := -O2 -Wall -Wextra -Iinclude
SRC := src/main.c
BUILD_DIR := build
TARGET := mirage

FORMAT_FILES := $(shell find . -path './$(BUILD_DIR)' -prune -o -type f \( -name '*.c' -o -name '*.h' \) -print)

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

format:
	@echo "Formatting the Mirage source code..."
	@clang-format -i $(FORMAT_FILES)

clean:
	rm -rf $(BUILD_DIR) $(TARGET) $(TARGET).exe

rebuild: clean all

.PHONY: all format clean rebuild
