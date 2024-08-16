/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int LED_PIN = 13;
const int BT_PIN = 19;
const int IN1 = 7;
const int IN2 = 8;
const int IN3 = 10;
const int IN4 = 11;


int main() {
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(BT_PIN);
    gpio_set_dir(BT_PIN, GPIO_IN);
    gpio_pull_up(BT_PIN);

    gpio_init(IN1);
    gpio_set_dir(IN1, GPIO_OUT);
    gpio_init(IN2);
    gpio_set_dir(IN2, GPIO_OUT);
    gpio_init(IN3);
    gpio_set_dir(IN3, GPIO_OUT);
    gpio_init(IN4);
    gpio_set_dir(IN4, GPIO_OUT);

    while (true) {
        if(!gpio_get(BT_PIN)){
        for (int i = 0; i <= 500; i++){    
            gpio_put(LED_PIN, 1);
            gpio_put(IN1,1);
            sleep_ms(10);
            gpio_put(IN1, 0);
            gpio_put(IN2,1);
            sleep_ms(10);
            gpio_put(IN2, 0);
            gpio_put(IN3,1);
            sleep_ms(10);
            gpio_put(IN3, 0);
            gpio_put(IN4,1);
            sleep_ms(10);
            gpio_put(IN4, 0);
        }
        gpio_put(LED_PIN, 0);
        }
    }
}
