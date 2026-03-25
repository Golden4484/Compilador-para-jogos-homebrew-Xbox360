CC = powerpc-linux-gnu-gcc
OBJCOPY = powerpc-linux-gnu-objcopy

# Corrigido para -mcpu=powerpc conforme sugerido pelo erro anterior
CFLAGS = -mcpu=powerpc -m32 -nostdlib -I. -O2
LIBS = -lgcc

all:
	$(CC) $(CFLAGS) -c main.c -o main.o
	$(CC) $(CFLAGS) main.o -o xenon.elf $(LIBS)
