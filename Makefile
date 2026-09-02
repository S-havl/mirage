CC := gcc
CFLAGS := -O2 -Wall -Wextra -Iinclude

SRC := src/main.c src/app/app.c src/input/input.c src/output/output.c src/file/file.c
BUILD_DIR := build
RESOBJ := $(BUILD_DIR)/icon.o

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

clean:
	rm -rf $(BUILD_DIR) mirage mirage.exe

rebuild: clean all

.PHONY: all clean rebuild
