#include <stdio.h>

// Funcao de delay manual para o boot nao ser instantaneo
void wait(int count) {
    for(volatile int i = 0; i < count; i++);
}

int main() {
    // --- TELA 1: LOG DE BOOT (DEBUG) ---
    printf("\n\nLUMEN-OS KERNEL LOADING...\n");
    printf("---------------------------\n");
    
    printf("[*] Identificando CPU PowerPC Xenon... OK\n");
    wait(2000000);
    
    printf("[*] Inicializando barramento USB... OK\n");
    wait(2000000);
    
    printf("[*] Checando Conexao de Rede...\n");
    printf("[!] Erro: Cabo desconectado ou IP nao atribuido.\n");
    wait(2000000);

    printf("\n[!] AGUARDANDO MOUSE E TECLADO NAS PORTAS FRONTAIS...\n");
    printf("[*] Identificado: Mouse Standard USB\n");
    wait(3000000);

    // --- TELA 2: INTERFACE DISCORD (SIMULADA) ---
    // Limpa a tela visualmente
    for(int i=0; i<40; i++) printf("\n");

    printf("##################################################\n");
    printf("#   DISCORD XBOX 360  |  Status: Localhost       #\n");
    printf("##################################################\n");
    printf("#                                                #\n");
    printf("#  [ CANAIS ]          [ MENSAGENS ]             #\n");
    printf("#  # geral             Lumen: Finalmente compilou!#\n");
    printf("#  # dev-xbox          Console: Hardware Ativo   #\n");
    printf("#  # hardware          Sistema: Pronto para uso  #\n");
    printf("#                                                #\n");
    printf("##################################################\n");
    printf("Pressione o botao central para sair.\n");

    while(1) {
        // Loop infinito para manter o console ligado
    }

    return 0;
}
