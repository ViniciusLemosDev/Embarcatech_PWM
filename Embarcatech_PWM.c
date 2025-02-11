#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22
#define LED_PIN 12
#define PWM_FREQ 50  // 50Hz -> Período de 20ms

#define DUTY_0 500    // 0 graus - 500µs
#define DUTY_90 1470  // 90 graus - 1470µs
#define DUTY_180 2400 // 180 graus - 2400µs

void set_servo_angle(uint slice, uint16_t duty) {
    pwm_set_gpio_level(SERVO_PIN, duty);
}

int main() {
    stdio_init_all();
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);
    
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
    pwm_set_wrap(slice_num, 20000);  // 20ms
    pwm_set_clkdiv(slice_num, 125.0f);
    pwm_set_enabled(slice_num, true);


    set_servo_angle(slice_num, DUTY_180);  // 180 graus
    sleep_ms(5000);
    set_servo_angle(slice_num, DUTY_90);  // 90 graus
    sleep_ms(5000);
    set_servo_angle(slice_num, DUTY_0);   // 0 graus
    sleep_ms(5000);

    uint duty_cycle = DUTY_0;
    uint passo = 5;

    while (1)
  {
    // Mudar o Duty Cycle para atualizar a posição do servo motor
    pwm_set_gpio_level(SERVO_PIN, duty_cycle);
    sleep_ms(10);

    // Incrementa ou decrementa o valor do Duty Cycle dependendo da direção
    duty_cycle += passo;

    // Se atingir os limites, inverte a direção
    if (duty_cycle >= DUTY_180 || duty_cycle <= DUTY_0) {
        passo = -passo;
    }
    
}
}
