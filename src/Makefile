CC := gcc
WINDRES := windres

TARGET := ttoBinary
SRC := ttoBinary.c
RC := icon.rc
RESOBJ := icon.o

CFLAGS := -O2 -Wall -Wextra

all: $(TARGET)

$(RESOBJ): $(RC)
	$(WINDRES) $< -O coff -o $@

$(TARGET): $(SRC) $(RESOBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET) $(RESOBJ)

rebuild: clean all

.PHONY: all clean rebuild
