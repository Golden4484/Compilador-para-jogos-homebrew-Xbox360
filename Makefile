CC = powerpc-linux-gnu-gcc
CFLAGS = -march=powerpc -m32 -nostdlib

all:
	$(CC) $(CFLAGS) main.c -o xenon.elf
