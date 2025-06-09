#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

// Memory address for GPIOA (based on STM32F4)
#define GPIOA_BASE 0x40020000U

struct GPIO_Registers {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFR[2];
};

#define GPIOA ((GPIO_Registers*) GPIOA_BASE)

#endif // GPIO_H
