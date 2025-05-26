# Volatile Variables
volatile keyword in C++ is used to declare variables that can be modified by external factors outside the program's control.
 This qualifier informs the compiler that the variable's value may change anytime, preventing certain optimizations that could lead to unexpected behavior. 

 Volatile variables within a function is very useful when we deal with hardware registers or shared memory in a multithreaded environment and handle concurrent operations. 
 Volatile variables helps to maintain data consistency and also ensures that the compiler doesn't waste the computer power in optimizations for the variables as the value of the variable can change any time.

Volatile keyword tells the compiler that the variable can change outside of your control, so do not optimize read/writes.
It is important in embedded systems because registers, sensors, interrupts, or DMA might change the memory contents at any time.
Without volatile, the compiler may cache a variable in a register and never reload from memory, meaning that you could miss changes from hardware.

Example:



 Refer to [This page](https://www.geeksforgeeks.org/volatile-qualifier-in-cpp/) for more explanation.
