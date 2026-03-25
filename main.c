#include <xetypes.h>
#include <console/console.h>
#include <usb/usbmain.h>
#include <network/network.h>
#include <xenon_soc/xenon_power.h>
#include <input/input.h>

int main() {
    // Inicializa o hardware real do Xbox 360
    xenos_init(VIDEO_MODE_AUTO);
    console_init();
    usb_init();
    network_init();

    printf("==========================================\n");
    printf("       LUMEN-OS HARDWARE BOOT             \n");
    printf("==========================================\n");

    // Checagem Real de Rede
    char *ip = network_get_ip();
    if (ip) {
        printf("[ OK ] Rede Ativa: %s\n", ip);
    } else {
        printf("[ !! ] Cabo de rede nao detectado.\n");
    }

    printf("\n[*] Aguardando Mouse/Teclado nas portas USB...\n");

    while(1) {
        usb_do_poll(); // Varre o hardware USB real

        // Tenta ler um mouse real
        struct mouse_data_s mouse;
        if (get_mouse_data(&mouse, 0)) {
            printf("\r[ MOUSE ] Detectado! Pos: %d, %d", mouse.x, mouse.y);
            // Aqui entrariamos na fase 2 (Interface)
        }

        // Se apertar o botao central, volta pro Aurora
        struct controller_data_s ctrl;
        if (get_controller_data(&ctrl, 0)) {
            if (ctrl.logo) break;
        }
    }

    return 0;
}
