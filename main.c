
#include <stdio.h>
#include <string.h>
#include <usb/usbmain.h>
#include <input/input.h>
#include <network/network.h>
#include <console/console_init.h>
#include <xenon_smc/smc.h>

// Definicao de estados do sistema
#define BOOT_LOG 0
#define WAITING_INPUT 1
#define DISCORD_UI 2

int current_state = BOOT_LOG;

void get_temps(float *cpu, float *gpu) {
    unsigned char msg[16] = {0x07};
    unsigned char resp[16];
    smc_send_message(msg);
    smc_get_response(resp);
    *cpu = (float)((resp[9] << 8) | resp[10]) / 256.0;
    *gpu = (float)((resp[11] << 8) | resp[12]) / 256.0;
}

int main() {
    xenos_init(VIDEO_MODE_AUTO);
    console_init();
    usb_init();

    float c_temp, g_temp;
    char* ip_addr = "Nao identificado";

    // --- SEQUENCIA DE BOOT ---
    printf("LUMEN-OS KERNEL BOOTING...\n");
    printf("---------------------------\n");
    
    get_temps(&c_temp, &g_temp);
    printf("[ SYSTEM ] CPU: %.1f C | GPU: %.1f C\n", c_temp, g_temp);

    printf("[ NETWORK ] Inicializando DHCP via Ethernet...\n");
    if (network_init() == 0) {
        ip_addr = network_get_ip();
        printf("[ NETWORK ] Conectado! IP: %s\n", ip_addr);
    } else {
        printf("[ NETWORK ] Erro de rede. Continuando em modo offline.\n");
    }

    printf("\n[ INPUT ] Aguardando Mouse ou Teclado USB...\n");
    current_state = WAITING_INPUT;

    int mouse_ready = 0;
    while (current_state == WAITING_INPUT) {
        usb_do_poll();
        
        struct mouse_data_s mouse;
        if (get_mouse_data(&mouse, 0)) {
            mouse_ready = 1;
            printf("[ INPUT ] Mouse detectado! Pressione [A] no controle para iniciar UI.\n");
        }

        struct controller_data_s ctrl;
        if (get_controller_data(&ctrl, 0)) {
            if (ctrl.a) current_state = DISCORD_UI;
            if (ctrl.logo) return 0;
        }
    }

    // --- INTERFACE DISCORD (TELA 2) ---
    console_init(); 
    while(1) {
        usb_do_poll();
        
        printf("==================================================\n");
        printf("  DISCORD X360 | Server: Dev-Lumen | IP: %s  \n", ip_addr);
        printf("==================================================\n");
        printf(" [#] GERAL        | [ CHAT ]                       \n");
        printf(" [#] HARDWARE     |  Lumen: O terminal esta on!   \n");
        printf(" [#] CODIGO       |  Sistema: Mouse %s         \n", mouse_ready ? "OK" : "OFF");
        printf("--------------------------------------------------\n");
        printf(" [!] CPU: %.1f C | [!] GPU: %.1f C \n", c_temp, g_temp);
        printf("==================================================\n");
        printf(" Segure [LOGO] para sair para a Dashboard.        \n");

        // Atualiza temps a cada ciclo longo
        get_temps(&c_temp, &g_temp);

        struct controller_data_s ctrl;
        if (get_controller_data(&ctrl, 0) && ctrl.logo) break;

        // Delay para evitar flickering (piscar a tela)
        for(int i=0; i<8000000; i++) { __asm__("nop"); }
        console_init(); 
    }

    return 0;
}
