#include <stdio.h>
#include <string.h>

// Simulando as chamadas da Libxenon para o seu terminal
// Nota: Em um ambiente real, voce precisaria das libs do Libxenon no repo
void sys_check_hardware() {
    printf("[ SYSTEM ] Verificando processador Xenon... OK\n");
    printf("[ SYSTEM ] Verificando GPU Xenos... OK\n");
    printf("[ SYSTEM ] Memoria RAM GDDR3: 512MB detectada.\n");
}

int main() {
    // TELA 1: MODO DEBUG / BOOT
    printf("==========================================\n");
    printf("       LUMEN-OS KERNEL V1.0 - BOOT        \n");
    printf("==========================================\n");
    
    sys_check_hardware();

    printf("[ NETWORK ] Tentando obter IP via DHCP...\n");
    // Aqui ele tentaria a rede. Se falhar, mostra o erro:
    printf("[ ERROR ] DHCP Timeout. Verifique o cabo de rede.\n");
    printf("[ INFO ] Continuando em modo Offline...\n");

    printf("\n[ INPUT ] AGUARDANDO PERIFERICOS USB...\n");
    printf("[ WAIT ] Por favor, conecte o Mouse e o Teclado agora.\n");

    // Simulacao de identificacao
    // Na Libxenon real, aqui teria um loop 'while(!usb_detected)'
    printf("[ OK ] Mouse detectado na porta USB 0!\n");
    printf("[ OK ] Teclado detectado na porta USB 1!\n");

    printf("\n[ BOOT ] Tudo pronto. Iniciando interface em 3s...\n");
    
    // Pequena pausa (loop de delay)
    for(int i=0; i<20000000; i++) { __asm__("nop"); }

    // TELA 2: INTERFACE DISCORD (Limpamos a tela visualmente com espacos)
    for(int i=0; i<50; i++) printf("\n");

    printf("##################################################\n");
    printf("#   DISCORD XBOX 360  |  Usuario: Lumen#2026     #\n");
    printf("##################################################\n");
    printf("#                                                #\n");
    printf("#  [ CANAIS ]          [ MENSAGENS ]             #\n");
    printf("#  # geral             Lumen: Rodando no 360!    #\n");
    printf("#  # dev-lumen         Console: Hardware OK      #\n");
    printf("#  # bugs              Sistema: Mouse Ativo      #\n");
    printf("#                                                #\n");
    printf("##################################################\n");
    printf("Pressione o botao LOGO para sair.\n");

    while(1) {
        // Loop infinito para manter o app aberto no Xbox
    }

    return 0;
}
