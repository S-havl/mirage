CC := gcc
WINDRES := windres

TARGET := ttoBinary

SRC := src/ttoBinary.c
RC := icon/icon.rc

BUILD_DIR := build
RESOBJ := $(BUILD_DIR)/icon.o

CFLAGS := -O2 -Wall -Wextra

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(RESOBJ): $(RC) | $(BUILD_DIR)
	$(WINDRES) $< -O coff -o $@

$(TARGET): $(SRC) $(RESOBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(TARGET) $(BUILD_DIR)

rebuild: clean all

.PHONY: all clean rebuild
