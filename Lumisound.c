#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <stdbool.h>

// Definição dos pinos (Pins definition)
#define LED_R 13        // Pino do LED vermelho
#define LED_G 11        // Pino do LED verde
#define LED_B 12        // Pino do LED azul
#define BUTTON_A 5      // Pino do botão A
#define BUTTON_B 6      // Pino do botão B
#define BUZZER 21       // Pino conectado ao transistor que controla o buzzer

// Frequências dos sons correspondentes às cores do LED RGB (Frequencies for LED colors)
#define FREQ_RED     262  // Frequência do som para o LED Vermelho (Dó)
#define FREQ_GREEN   294  // Frequência do som para o LED Verde (Ré)
#define FREQ_BLUE    330  // Frequência do som para o LED Azul (Mi)
#define FREQ_YELLOW  349  // Frequência do som para o LED Amarelo (Fá)
#define FREQ_CYAN    392  // Frequência do som para o LED Ciano (Sol)
#define FREQ_MAGENTA 440 // Frequência do som para o LED Magenta (Lá)
#define FREQ_WHITE   494  // Frequência do som para o LED Branco (Si)

// === Conjunto definição de notas para melodia (A) Super Mario Bros. === //
#define NOTE_E5   659
#define NOTE_G5   784
#define NOTE_C5   523
#define NOTE_G4   392
#define NOTE_E4   330
#define NOTE_A4   440
#define NOTE_B4   494
#define NOTE_AS4  466
#define NOTE_GS4  415
#define NOTE_F5   698
#define NOTE_D5   587
#define NOTE_FS5  740
#define NOTE_GS5  831
#define NOTE_E3   165
#define NOTE_A3   220
#define NOTE_B3   247
#define NOTE_C4   262
#define NOTE_G3   196
#define NOTE_A5   880
#define NOTE_DS5  622
#define REST        0

// === Conjunto definição de notas para melodia (B) Game Of Thrones - Thema === //
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_GS5 831
#define NOTE_AS3 233
#define REST        0

// Struct para armazenamento das sequências de nota de cada melodia, seguido de seu respectivo tempo de emissão 
// (Struct for storing the note sequences of each melody along with their duration)
typedef struct {
    int frequency;
    int duration_ms;
} Note;

// Array de notas para a melodia A (Super Mario Bros)
Note melody_A[] = {
    {NOTE_E5, 125}, {NOTE_E5, 125}, {REST, 125}, {NOTE_E5, 125}, {REST, 125}, {NOTE_C5, 125}, {NOTE_E5, 125}, 
    {NOTE_G5, 250}, {REST, 250}, {NOTE_G4, 125}, {REST, 250}, {NOTE_C5, 250}, {NOTE_G4, 125}, {REST, 250}, {NOTE_E4, 250}, 
    {NOTE_A4, 250}, {NOTE_B4, 250}, {NOTE_AS4, 125}, {NOTE_A4, 250}, {NOTE_G4, 125}, {NOTE_E5, 125}, {NOTE_G5, 125}, {NOTE_A5, 250}, 
    {NOTE_F5, 125}, {NOTE_G5, 125}, {REST, 125}, {NOTE_E5, 250}, {NOTE_C5, 125}, {NOTE_D5, 125}, {NOTE_B4, 250},

    {REST, 250}, {NOTE_G5, 125}, {NOTE_F5, 125}, {NOTE_D5, 125}, {NOTE_E5, 250}, {REST, 125}, {NOTE_GS4, 125}, 
    {NOTE_A4, 125}, {NOTE_C4, 125}, {REST, 125}, {NOTE_A4, 125}, {NOTE_C5, 125}, {NOTE_D5, 125}, {REST, 250}, {NOTE_DS5, 250}, 
    {REST, 125}, {NOTE_D5, 250}, {NOTE_C5, 500}, {REST, 500}
};

// Array de notas para a melodia B (Game Of Thrones - Thema)
Note melody_B[] = {
    {NOTE_G4, 300}, {NOTE_C4, 300}, {NOTE_DS4, 150}, {NOTE_F4, 150}, {NOTE_G4, 300}, {NOTE_C4, 300}, {NOTE_DS4, 150}, {NOTE_F4, 150}, 
    {NOTE_G4, 300}, {NOTE_C4, 300}, {NOTE_DS4, 150}, {NOTE_F4, 150}, {NOTE_G4, 300}, {NOTE_C4, 300}, {NOTE_DS4, 150}, {NOTE_F4, 150}, 
    {NOTE_G4, 300}, {NOTE_C4, 300}, {NOTE_E4, 150}, {NOTE_F4, 150}, {NOTE_G4, 300}, {NOTE_C4, 300}, {NOTE_E4, 150}, {NOTE_F4, 150}, 
    {NOTE_G4, 300}, {NOTE_C4, 300}, {NOTE_E4, 150}, {NOTE_F4, 150}, {NOTE_G4, 300}, {NOTE_C4, 300}, {NOTE_E4, 150}, {NOTE_F4, 150}, 
    {NOTE_G4, 600}, {NOTE_C4, 600},

    {NOTE_DS4, 150}, {NOTE_F4, 150}, {NOTE_G4, 300}, {NOTE_C4, 300}, {NOTE_DS4, 150}, {NOTE_F4, 150},
    {NOTE_D4, 600}, {REST, 300}, {NOTE_F4, 300}, {NOTE_AS3, 300}, 
    {NOTE_DS4, 150}, {NOTE_D4, 150}, {NOTE_F4, 300}, {NOTE_AS3, 300},
    {NOTE_DS4, 150}, {NOTE_D4, 150}, {NOTE_C4, 900}, {REST, 600},

    {NOTE_G4, 300}, {NOTE_C4, 300}, {NOTE_DS4, 150}, {NOTE_F4, 150}, {NOTE_G4, 300}, {NOTE_C4, 300}, {NOTE_DS4, 150}, {NOTE_F4, 150}, 
    {NOTE_G4, 300}, {NOTE_C4, 300}, {NOTE_DS4, 150}, {NOTE_F4, 150}, {NOTE_G4, 300}, {NOTE_C4, 300}, {NOTE_DS4, 150}, {NOTE_F4, 150}, 
    {NOTE_G4, 600}, {NOTE_C4, 600},

    {NOTE_D4, 1200}, {NOTE_F4, 300}, {NOTE_AS3, 300}, {NOTE_D4, 300}, {NOTE_DS4, 300}, {NOTE_D4, 300}, {NOTE_AS3, 300}, {NOTE_C4, 1200}
};

uint8_t counter = 0;  // Variável de controle para as cores e sons, vai de 0 a 7 (Counter para alternar estados)

// Inicializa os LEDs RGB
// (Inicializa e configura os pinos dos LEDs como saída)
void init_leds() {
    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_init(LED_G);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_init(LED_B);
    gpio_set_dir(LED_B, GPIO_OUT);
}

// Função para gerar o som correspondente à frequência
// (Gera um sinal de onda quadrada no buzzer para reproduzir o som)
void generate_sound(int frequency, int duration) {
    if(frequency == 0){
        sleep_ms(duration);
        return;
    }
    // Calcula o intervalo entre os pulsos (em microssegundos)
    uint32_t interval = 1000000 / frequency; // 1 segundo dividido pela frequência
    int cycles = (duration * 1000) / interval;

    // Gera um ciclo de onda quadrada (liga/desliga o buzzer)
    for (int i = 0; i < 100; i++) {  // 100 ciclos para manter o som perceptível
        gpio_put(BUZZER, 1);      // Liga o buzzer (sinal alto)
        sleep_us(interval / 2);   // Meio período (ligado)

        gpio_put(BUZZER, 0);      // Desliga o buzzer (sinal baixo)
        sleep_us(interval / 2);   // Meio período (desligado)
    }
}

// Associa as cores do LED a um som e toca o mesmo correspondente
// (Atualiza os LEDs de acordo com o estado e reproduz o som associado)
void update_leds_and_sound(uint8_t state) {
    int sound_freq = 0; // Variável para armazenar a frequência do som
    // Verifica o valor de 'state' e altera os LEDs e a frequência do som
    switch (state) {
        case 0: 
            gpio_put(LED_R, 0); 
            gpio_put(LED_G, 0); 
            gpio_put(LED_B, 0); 
            sound_freq = 0; 
            break;
        case 1: 
            gpio_put(LED_R, 1); 
            gpio_put(LED_G, 0); 
            gpio_put(LED_B, 0); 
            sound_freq = FREQ_RED; 
            break;
        case 2: 
            gpio_put(LED_R, 0); 
            gpio_put(LED_G, 1); 
            gpio_put(LED_B, 0); 
            sound_freq = FREQ_GREEN; 
            break;
        case 3: 
            gpio_put(LED_R, 0); 
            gpio_put(LED_G, 0); 
            gpio_put(LED_B, 1); 
            sound_freq = FREQ_BLUE; 
            break;
        case 4: 
            gpio_put(LED_R, 1); 
            gpio_put(LED_G, 1); 
            gpio_put(LED_B, 0); 
            sound_freq = FREQ_YELLOW; 
            break;
        case 5: 
            gpio_put(LED_R, 0); 
            gpio_put(LED_G, 1); 
            gpio_put(LED_B, 1); 
            sound_freq = FREQ_CYAN; 
            break;
        case 6: 
            gpio_put(LED_R, 1); 
            gpio_put(LED_G, 0); 
            gpio_put(LED_B, 1); 
            sound_freq = FREQ_MAGENTA; 
            break;
        case 7: 
            gpio_put(LED_R, 1); 
            gpio_put(LED_G, 1); 
            gpio_put(LED_B, 1); 
            sound_freq = FREQ_WHITE; 
            break;
    }
    // Toca o som correspondente à cor do LED
    if (sound_freq > 0) {
        generate_sound(sound_freq, 100); // Chama a função para gerar o som
    }
}

// Configura os botões (Inicializa e configura os botões com pull-up interno)
void init_buttons() {
    // Inicializa o botão A
    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A); // Habilita o pull-up interno para o botão A
    // Inicializa o botão B
    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    gpio_pull_up(BUTTON_B); // Habilita o pull-up interno para o botão B
}

// Função para reproduzir uma melodia
// (Percorre o array de notas e reproduz cada nota com o tempo especificado)
void play_melody(Note melody[], int size) {
    for(int i = 0; i < size; i++){
        generate_sound(melody[i].frequency, melody[i].duration_ms);
        sleep_ms(50);
    }
}

// Função para detectar pressionamento prolongado (mais de 1 segundo)
// (Retorna true se o botão estiver pressionado por mais de 1 segundo)
bool detect_long_press(uint pin) {
    if(!gpio_get(pin)) {
        absolute_time_t start = get_absolute_time();
        while(!gpio_get(pin)) {
            if(absolute_time_diff_us(start, get_absolute_time()) > 1000000) {
                return true;
            }
        }
    }
    return false;
}

// Define o LED para vermelho (utilizado no modo melódico para o botão A)
void set_led_red() {
    gpio_put(LED_R, 1);
    gpio_put(LED_G, 0);
    gpio_put(LED_B, 0);
}

// Define o LED para amarelo (utilizado no modo melódico para o botão B)
void set_led_yellow() {
    gpio_put(LED_R, 1);
    gpio_put(LED_G, 1);
    gpio_put(LED_B, 0);
}

// Desliga os LEDs
void set_led_off() {
    gpio_put(LED_R, 0);
    gpio_put(LED_G, 0);
    gpio_put(LED_B, 0);
}

// Loop principal do programa
int main() {
    stdio_init_all(); // Inicializa a comunicação serial
    
    init_leds(); // Inicializa os LEDs RGB
    gpio_init(BUZZER); // Inicializa o pino do buzzer
    gpio_set_dir(BUZZER, GPIO_OUT); // Define o pino do buzzer como saída
    init_buttons(); // Inicializa os botões
    
    // Variáveis para detectar a duração do pressionamento dos botões
    absolute_time_t press_start_A;
    absolute_time_t press_start_B;
    bool was_pressed_A = false;
    bool was_pressed_B = false;
    const uint32_t LONG_PRESS_THRESHOLD = 1000000; // 1 segundo em microsegundos
    
    while (1) {
        // Verifica o estado do Botão A
        if (!gpio_get(BUTTON_A)) {  // Botão A pressionado (nível 0 com pull-up)
            if (!was_pressed_A) {
                press_start_A = get_absolute_time();
                was_pressed_A = true;
            }
        } else {
            if (was_pressed_A) {  // Botão A foi liberado
                uint32_t diff = absolute_time_diff_us(press_start_A, get_absolute_time());
                if (diff >= LONG_PRESS_THRESHOLD) {
                    // Pressionamento prolongado: Toca a melodia (Super Mario Bros) com LED vermelho
                    set_led_red();
                    play_melody(melody_A, sizeof(melody_A) / sizeof(Note));
                    set_led_off();
                    sleep_ms(500);
                } else {
                    // Pressionamento curto: Incrementa o contador e atualiza os LEDs e som
                    counter = (counter + 1) % 8;
                    update_leds_and_sound(counter);
                    sleep_ms(300);
                }
                was_pressed_A = false;
            }
        }
        
        // Verifica o estado do Botão B
        if (!gpio_get(BUTTON_B)) {  // Botão B pressionado
            if (!was_pressed_B) {
                press_start_B = get_absolute_time();
                was_pressed_B = true;
            }
        } else {
            if (was_pressed_B) {  // Botão B foi liberado
                uint32_t diff = absolute_time_diff_us(press_start_B, get_absolute_time());
                if (diff >= LONG_PRESS_THRESHOLD) {
                    // Pressionamento prolongado: Toca a melodia (Game Of Thrones - Thema) com LED amarelo
                    set_led_yellow();
                    play_melody(melody_B, sizeof(melody_B) / sizeof(Note));
                    set_led_off();
                    sleep_ms(500);
                } else {
                    // Pressionamento curto: Decrementa o contador e atualiza os LEDs e som
                    if (counter == 0)
                        counter = 7;
                    else
                        counter--;
                    update_leds_and_sound(counter);
                    sleep_ms(300);
                }
                was_pressed_B = false;
            }
        }
        
        sleep_ms(50); // Pequeno delay para debouncing
    }
}
