#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

#define LED_BLUE 11
#define LED_RED 12
#define LED_GREEN 13
#define BUTTON 5

volatile bool led_sequence_active = false;

// Callback para desligar o LED verde
int64_t turn_off_green_callback(alarm_id_t id, void *user_data) {
    gpio_put(LED_GREEN, 0);
    led_sequence_active = false; // Permite novo acionamento
    return 0;
}

// Callback para desligar o LED vermelho
int64_t turn_off_red_callback(alarm_id_t id, void *user_data) {
    gpio_put(LED_RED, 0);
    add_alarm_in_ms(3000, turn_off_green_callback, NULL, false);
    return 0;
}

// Callback para desligar o LED azul
int64_t turn_off_blue_callback(alarm_id_t id, void *user_data) {
    gpio_put(LED_BLUE, 0);
    add_alarm_in_ms(3000, turn_off_red_callback, NULL, false);
    return 0;
}

// Callback para acender todos os LEDs
void button_callback(uint gpio, uint32_t events) {
    if (!led_sequence_active) {
        led_sequence_active = true;
        gpio_put(LED_BLUE, 1);
        gpio_put(LED_RED, 1);
        gpio_put(LED_GREEN, 1);
        add_alarm_in_ms(3000, turn_off_blue_callback, NULL, false);
    }
}

// Função para debounce do botão
bool debounce_button() {
    sleep_ms(50);
    return gpio_get(BUTTON) == 0;
}

int main() {
    stdio_init_all();

    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);

    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_FALL, true, &button_callback);

    while (1) {
        sleep_ms(100);
    }
}
