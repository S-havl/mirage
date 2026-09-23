CC := gcc
CFLAGS := -O2 -Wall -Wextra -Iinclude

SRC := src/main.c src/app/app.c src/convert/convert.c
BUILD_DIR := build
RESOBJ := $(BUILD_DIR)/icon.o

FORMAT_FILES := $(shell find . -type d -name '$(BUILD)' -prune -false -o -type f \( -name '*.c' -o -name '*.h' \))

ifeq ($(OS),Windows_NT)
	TARGET := mirage.exe
	WINDRES := windres
	RC := icon/icon.rc
	EXTRA_OBJS := $(RESOBJ)
else
	TARGET := mirage
	EXTRA_OBJS := 
endif

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(RESOBJ): $(RC) | $(BUILD_DIR)
	$(WINDRES) $< -O coff -o $@

$(TARGET): $(SRC) $(EXTRA_OBJS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

format:
	@echo "Formatting the Mirage source code..."
	@clang-format -i $(FORMAT_FILES)

clean:
	rm -rf $(BUILD_DIR) mirage mirage.exe

rebuild: clean all

.PHONY: all format clean rebuild
