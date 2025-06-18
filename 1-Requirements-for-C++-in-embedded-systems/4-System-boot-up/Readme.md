# System Boot-up
This section provides the description of the boot-up process in embedded systems.

## What Happens When an Embedded System Starts?
When power is applied or a reset is triggered:
 
 - Reset Vector is triggered:
   -   CPU starts execution from a fixed address (reset vector).
   -   On ARM Cortex-M, this is usually at 0x00000000 or 0x08000000 (depending on Flash).
 - Startup Code (CRT0 or startup.s) runs:
   - Written in assembly (provided by toolchain or written manually).
   - It:
     - Sets up the **stack pointer** (the starting address of the stack memory holding local functions and variables, ...)
     - Initializes the BSS section (clears uninitialized globals)
     - Initializes the data section (copies initialized data from Flash to RAM)
     - Optionally initializes SystemInit() if present
     - Jumps to main()
 - C++-specific behavior (important!):
   - Calls constructors for global and static C++ objects before main() is run.
   - Destructors may not be called unless you explicitly handle shutdown.

## Key Sections in Memory:
|Section | Purpose|
---------|------
|.text	|Executable code (e.g., functions, main) stored in Flash|
|.data	|Initialized global/static variables (copied from Flash to RAM)|
|.bss	  |Uninitialized globals/statics (zero-initialized in RAM)|
|.heap	|Dynamically allocated memory (new/malloc)|
|.stack	|Used for local variables, function calls, etc.|

These are defined in the linker script (e.g. STM32F4.ld)

The following figure shows the order of these sections in memory:

<p align="center">
  <img src="https://github.com/Amir-Mansoori/Embedded-Cpp-Course/blob/main/Images/memory.png" alt="Figure 1: Memory sections" />
</p>
