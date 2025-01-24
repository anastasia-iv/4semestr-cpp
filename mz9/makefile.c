CC = gcc
CFLAGS += -m32 -Wall -g -o2 -W
AS = nasm
ASMFLAGS += -g -f elf32

all: integral

integral: project.c f.o
	$(CC) $(CFLAGS) $^ -lm -o $@
	
f.o: f.asm
	$(AS) $(ASMFLAGS) $< -o $@

.PHONY: clean test

clean:
	rm -rf *.o

test:
	$(AS) $(ASMFLAGS) f.asm -o f.o
	$(CC) -DTEST $(CFLAGS) project.c -lm f.o -o integral