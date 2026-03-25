CC = powerpc-linux-gnu-gcc
OBJCOPY = powerpc-linux-gnu-objcopy

# Corrigido de -march para -mcpu conforme o log de erro do seu print
CFLAGS = -mcpu=powerpc -m32 -nostdlib -I. -O2

all:
	$(CC) $(CFLAGS) -c main.c -o main.o
	$(CC) $(CFLAGS) main.o -o xenon.elf
