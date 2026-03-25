CC = powerpc-linux-gnu-gcc
CFLAGS = -march=powerpc -m32 -nostdlib

all:
	powerpc-linux-gnu-gcc -mcpu=powerpc -m32 -nostdlib main.c -o xenon.elf
