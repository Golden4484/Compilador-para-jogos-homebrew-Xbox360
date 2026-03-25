# Nome do compilador para PowerPC
CC = powerpc-linux-gnu-gcc

# Configurações de arquitetura do Xbox 360
CFLAGS = -march=powerpc -m32 -nostdlib

# O que o comando 'make' deve fazer
all:
	$(CC) $(CFLAGS) main.c -o xenon.elf
