#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

// Definição dos pinos
#define LED_R 13        //Pino do LED vermelho
#define LED_G 11        //Pino do LED verde
#define LED_B 12        //Pino do LED azul
#define BUTTON_A 5      //Pino do botão A
#define BUTTON_B 6      //Pino do botão B
#define BUZZER 21       // Pino conectado ao transistor que controla o buzzer

// Frequências dos sons correspondentes às cores do LED RGB
#define FREQ_VERMELHO 262  // Frequência do som para o LED Vermelho (Dó)
#define FREQ_VERDE    294  // Frequência do som para o LED Verde (Ré)
#define FREQ_AZUL     330  // Frequência do som para o LED Azul (Mi)
#define FREQ_AMARELO  349  // Frequência do som para o LED Amarelo (Fá)
#define FREQ_CIANO    392  // Frequência do som para o LED Ciano (Sol)
#define FREQ_MAGENTA  440  // Frequência do som para o LED Magenta (Lá)
#define FREQ_BRANCO   494  // Frequência do som para o LED Branco (Si)

uint8_t contador = 0;  // Variável de controle para as cores e sons, vai de 0 a 7

    // Inicializa os LEDs RGB
void leds_init() {
    // Inicializa e configura os pinos dos LEDs como saída
    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_init(LED_G);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_init(LED_B);
    gpio_set_dir(LED_B, GPIO_OUT);
}

// Função para gerar o som correspondente à frequência
void gerar_som(int frequencia) {
    // Calcula o intervalo entre os pulsos (em microssegundos)
    uint32_t intervalo = 1000000 / frequencia; // 1 segundo dividido pela frequência

    // Gera um ciclo de onda quadrada (liga/desliga o buzzer)
    for (int i = 0; i < 100; i++) {  // 100 ciclos para manter o som perceptível
        gpio_put(BUZZER, 1);  // Ligando o buzzer (sinal alto)
        sleep_us(intervalo / 2);  // Meio período (ligado)

        gpio_put(BUZZER, 0);  // Desligando o buzzer (sinal baixo)
        sleep_us(intervalo / 2);  // Meio período (desligado)
    }
}

// Associa as cores do LED a um som e toca o mesmo correspondente
void atualizar_leds_e_som() {
    int freq_som = 0; // Variável para armazenar a frequência do som
    // Verifica o valor de 'contador' e altera os LEDs e a frequência do som
    switch (contador) {
        case 0: gpio_put(LED_R, 0); gpio_put(LED_G, 0); gpio_put(LED_B, 0); freq_som = 0; break;
        case 1: gpio_put(LED_R, 1); gpio_put(LED_G, 0); gpio_put(LED_B, 0); freq_som = FREQ_VERMELHO; break;
        case 2: gpio_put(LED_R, 0); gpio_put(LED_G, 1); gpio_put(LED_B, 0); freq_som = FREQ_VERDE; break;
        case 3: gpio_put(LED_R, 0); gpio_put(LED_G, 0); gpio_put(LED_B, 1); freq_som = FREQ_AZUL; break;
        case 4: gpio_put(LED_R, 1); gpio_put(LED_G, 1); gpio_put(LED_B, 0); freq_som = FREQ_AMARELO; break;
        case 5: gpio_put(LED_R, 0); gpio_put(LED_G, 1); gpio_put(LED_B, 1); freq_som = FREQ_CIANO; break;
        case 6: gpio_put(LED_R, 1); gpio_put(LED_G, 0); gpio_put(LED_B, 1); freq_som = FREQ_MAGENTA; break;
        case 7: gpio_put(LED_R, 1); gpio_put(LED_G, 1); gpio_put(LED_B, 1); freq_som = FREQ_BRANCO; break;
    }

    // Toca o som correspondente à cor do LED
    if (freq_som > 0) {
        gerar_som(freq_som); // Chama a função para gerar o som
    }
}

// Configura os botões
void buttons_init() {
    // Inicializa o botão A
    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A); // Habilita o pull-up interno para o botão A
    // Inicializa o botão B
    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    gpio_pull_up(BUTTON_B); // Habilita o pull-up interno para o botão B
}

// Loop principal
int main() {
    stdio_init_all(); // Inicializa o sistema de E/S padrão
    leds_init();    // Inicializa os LEDs RGB
    gpio_init(BUZZER); // Inicializa o pino do buzzer
    gpio_set_dir(BUZZER, GPIO_OUT);  // Configura o pino do buzzer como saída
    buttons_init();

    atualizar_leds_e_som(); // Atualiza LEDs e toca o som inicialmente

    // Loop principal
    while (1) {
        // Se o botão A for pressionado, avança para a próxima cor e som
        if (!gpio_get(BUTTON_A)) {
            contador = (contador + 1) % 8;  // Avança até 7, depois volta para 0
            atualizar_leds_e_som(); // Atualiza LEDs e som
            sleep_ms(300);  // Delay para evitar múltiplos cliques
        }
        if (!gpio_get(BUTTON_B)) {  // Se o botão B for pressionado, retrocede para a cor e som anterior
            contador = (contador - 1) % 8;  // Retrocede até 0
            atualizar_leds_e_som(); // Atualiza LEDs e som
            sleep_ms(300); // Delay para evitar múltiplos cliques
        }
    }
}
