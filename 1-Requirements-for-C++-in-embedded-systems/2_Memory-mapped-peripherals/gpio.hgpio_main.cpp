#include "gpio.h"

int main() {
    // Configure PA5 as output
    GPIOA->MODER &= ~(0b11 << (5 * 2));
    GPIOA->MODER |=  (0b01 << (5 * 2));

    while (true) {
        GPIOA->ODR |=  (1 << 5);  // Turn on LED
        for (volatile int i = 0; i < 100000; ++i);

        GPIOA->ODR &= ~(1 << 5);  // Turn off LED
        for (volatile int i = 0; i < 100000; ++i);
    }
}
