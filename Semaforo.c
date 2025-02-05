#include "pico/stdlib.h"
#include <stdio.h>

// Definição dos pinos dos LEDs
#define LED_RED 11
#define LED_YELLOW 12
#define LED_GREEN 13

// Variável para controlar o estado do semáforo
typedef enum {
    RED,
    YELLOW,
    GREEN
} TrafficLightState;

TrafficLightState current_state = RED;

// Função de callback para o temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    static int counter = 0;

    // Desliga todos os LEDs
    gpio_put(LED_RED, 0);
    gpio_put(LED_YELLOW, 0);
    gpio_put(LED_GREEN, 0);

    // Muda o estado do semáforo
    switch (current_state) {
        case RED:
            gpio_put(LED_RED, 1);
            current_state = YELLOW;
            break;
        case YELLOW:
            gpio_put(LED_YELLOW, 1);
            current_state = GREEN;
            break;
        case GREEN:
            gpio_put(LED_GREEN, 1);
            current_state = RED;
            break;
    }

    // Incrementa o contador e imprime a cada segundo
    counter++;
    if (counter % 3 == 0) {
        printf("Estado do semáforo alterado!\n");
    }

    return true;
}

int main() {
    // Inicializa a stdio para usar a porta serial
    stdio_init_all();

    // Configura os pinos dos LEDs como saída
    gpio_init(LED_RED);
    gpio_init(LED_YELLOW);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    // Inicializa o temporizador repetitivo
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop principal
    while (true) {
        // Imprime uma mensagem a cada segundo
        printf("Tempo decorrido: %d segundos\n", (int)(time_us_64() / 1000000));
        sleep_ms(1000);
    }

    return 0;
}