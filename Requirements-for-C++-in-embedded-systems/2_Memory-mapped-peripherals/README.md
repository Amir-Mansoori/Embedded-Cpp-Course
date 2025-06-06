# What Are Memory-Mapped Peripherals?
In many embedded systems (ARM Cortex, AVR, RISC-V, etc.), peripheral devices (GPIOs, UART, timers, etc.) are accessed not via special CPU instructions, but by mapping hardware registers into the system's main memory space.
You can then read/write hardware just like a variable in RAM.

Therefore, the peripherals are mapped into the memory address space. This means you can access hardware registers as if they were normal memory locations using pointers in C or C++.

Using direct register access lets your software read from and write to specific memory addresses tied to hardware functionality.

![Example of Memory Mapping](https://github.com/Amir-Mansoori/Embedded-Cpp-Course/blob/main/Images/Memory_mapped.png)

