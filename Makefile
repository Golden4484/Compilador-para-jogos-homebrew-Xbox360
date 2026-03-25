# Compilador para arquitetura PowerPC do Xbox 360
CC = powerpc-linux-gnu-gcc
LD = powerpc-linux-gnu-ld
OBJCOPY = powerpc-linux-gnu-objcopy

# Parametros de compilacao (mcpu correto para o Xenon)
CFLAGS = -mcpu=powerpc -m32 -nostdlib -I. -O2 -Wall
LDFLAGS = -T xenon.lds -nostdlib

# Bibliotecas Libxenon (Rede, USB, Input)
LIBS = -lxenon -lgcc -lc

all:
	$(CC) $(CFLAGS) -c main.c -o main.o
	$(CC) $(CFLAGS) main.o -o xenon.elf $(LIBS)
