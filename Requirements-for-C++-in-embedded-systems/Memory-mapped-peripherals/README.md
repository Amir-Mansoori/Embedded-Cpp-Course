# What Are Memory-Mapped Peripherals?
In embedded systems, peripherals (like GPIO, UART, timers, SPI, etc.) are mapped into the memory address space. This means you can access hardware registers as if they were normal memory locations using pointers in C or C++.

Using direct register access lets your software read from and write to specific memory addresses tied to hardware functionality.
