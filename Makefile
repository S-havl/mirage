CC := gcc
CFLAGS := -O2 -Wall -Wextra

SRC := src/ttoBinary.c
BUILD_DIR := build
RESOBJ := $(BUILD_DIR)/icon.o

ifeq ($(OS),Windows_NT)
	TARGET := ttoBinary.exe
	WINDRES := windres
	RC := icon/icon.rc
	EXTRA_OBJS := $(RESOBJ)
else
	TARGET := ttoBinary
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
	rm -rf $(BUILD_DIR) ttoBinary ttoBinary.exe

rebuild: clean all

.PHONY: all clean rebuild
