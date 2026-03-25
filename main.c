#include <stdio.h>

// Definicoes basicas para o compilador nao reclamar da falta de bibliotecas
typedef unsigned int uint32_t;

void delay(int cycles) {
    for(volatile int i = 0; i < cycles; i++);
}

int main() {
    // TELA 1: BOOT E DIAGNOSTICO
    printf("\n\n");
    printf("LUMEN-OS KERNEL v1.0\n");
    printf("----------------------------------\n");
    printf("[*] Iniciando Threads do PowerPC...\n");
    delay(1000000);
    
    printf("[*] Checando barramento USB...\n");
    // Aqui no futuro entra o driver real
    printf("[OK] Controlador USB pronto.\n");
    
    printf("[*] Inicializando Rede Ethernet...\n");
    printf("[ERR] DHCP nao respondeu. Verifique o cabo.\n");
    
    printf("\n[!] AGUARDANDO MOUSE E TECLADO...\n");
    printf("Pressione qualquer tecla ou espere o timeout.\n");
    delay(3000000);

    // TELA 2: INTERFACE DISCORD (SIMULADA NO TERMINAL)
    // Limpa a tela com varias quebras de linha
    for(int i=0; i<40; i++) printf("\n");

    printf("==================================================\n");
    printf("  DISCORD XBOX 360 | Status: Offline (Sem IP)    \n");
    printf("==================================================\n");
    printf("  # GERAL         |  SISTEMA: Hardware detectado\n");
    printf("  # DEV-LUMEN     |  MOUSE: Porta 01 (Ativo)    \n");
    printf("  # AJUDA         |  TECLADO: Porta 02 (Ativo)  \n");
    printf("--------------------------------------------------\n");
    printf("  [Lumen]: O projeto de terminal esta ganhando vida!\n");
    printf("==================================================\n");

    while(1) {
        // Loop infinito para o Xbox nao reiniciar
    }

    return 0;
}
