CC = powerpc-linux-gnu-gcc
OBJCOPY = powerpc-linux-gnu-objcopy

# Trocamos -march por -mcpu para o processador Xenon
CFLAGS = -mcpu=powerpc -m32 -nostdlib -I. -O2

all:
	$(CC) $(CFLAGS) -c main.c -o main.o
	$(CC) $(CFLAGS) main.o -o xenon.elf
