# Compilation Basics in embedded software design

This page summarizes key concepts an embedded software designer should know about the compilation process, toolchains, and build systems when writing firmware in C or C++. Two examples are provided to learn how to use make and CMake tools (make_demo and cmake_demo).

Compilation Pipeline:

```
Source (.c / .cpp)
   ↓  [Preprocessor: #includes, #defines]   
Preprocessed (.i)
   ↓  [Compiler: C++ → Assembly]
Assembly (.s)
   ↓  [Assembler: ASM → Machine code]
Object file (.o)
   ↓  [Linker: combines .o + startup + script]
Final Executable (.exe / .elf / .bin)
```
### Preprocessor
The preprocessor takes the C code and generates the .i file. The following command can be used:

`g++ -E main.cpp -o main.i`

The Preprocessor:
- Expands macros (#define), so it replaces all the macros in the code with their actual values
- Replaces #include with actual file content
- Removes comments
- Handles conditionals like #ifdef, #ifndef
### Compiler
The compiler takes that .i file and translates it into low-level assembly instructions specific to your CPU architecture that is the .s file. The following command can be used:

`g++ -S main.cpp -o main.s`

The .s file contains **human-readable assembly code**, for example (x86-64):
```
.file   "main.cpp"
    .text
    .globl  main
    .type   main, @function
main:
    pushq   %rbp
    movq    %rsp, %rbp
    movl    $0, %eax
    popq    %rbp
    ret
```
if you use the compiler on:
```
int main() {
    return 0;
}
```

### Assembler
The assembler takes the human-readable assembly code **(.s)** to binary machine code stored in an object file **(.o)**.


The following gcc command can be used:

`g++ -c main.s -o main.o`

At the end, we will have the object file main.o which is a binary file. 
### Linker
The linker takes one or more object files (.o) and combines them into a final executable (like main.exe)
It also resolves symbol references between files and arranges the final memory layout (especially important in embedded systems).

This is a simple example to show how Linking works. Let’s say you have:

**main.cpp**
```
#include "utils.h"
int main() {
    printMessage();
    return 0;
}
```

**utils.cpp**
```
#include <iostream>
void printMessage() {
    std::cout << "Hello from utils!" << std::endl;
}
```
This is the step-by-step compilation and linking process:
```
g++ -c main.cpp     # → main.o
g++ -c utils.cpp    # → utils.o
g++ main.o utils.o -o app   # linking step!
```
During Linking the following steps are executed:

- **Symbol Resolution**

	**main.o** uses printMessage(), but doesn’t define it

	**utils.o** defines printMessage()

	The linker matches them and connects the call

- **Memory Layout**
Code sections (.text), data (.data), BSS (.bss) are placed in memory.
In embedded systems, the linker uses a linker script to define where Flash and RAM begin/end

- **Relocation**
Relative and absolute addresses inside .o files are patched to correct values

- **Library Linking**
If your code uses functions from the C++ standard library (like std::cout), the linker pulls in pieces from libstdc++.a, libc.a, etc.


## GCC common flags
GCC stands for GNU Compiler for C/C++ (GCC). **gcc** and **g++** both compile C codes into the assembly/object files. If we use `-c` flag, the output will be the object file, otherwise the output will be the executable:
```
gcc main.c -o main
g++ main.cpp -o main
```

common flags used in gcc:
	
|Flag |	Description |
| ------------- | ------------- |
|-c	|Compile only, no linking
|-o	| Output file name
|-I   |  Include path for headers
|-L   | Library path
|-l<lib>   | Link with a library (e.g. -lm for math)
|-mcpu=cortex-m4	|Target specific CPU core
|-O0 → -O3	|Optimization level
|-g	|Include debug symbols
|-Wall	|Enable all warnings
|-T link.ld	|Use custom linker script

## make
make is a **build automation** tool that helps you compile large C/C++ projects. Instead of manually typing `g++ main.cpp utils.cpp -o app` every time you make a change, you write rules in a file called a Makefile.

We meed to define rules in a Makefile like:
```
target: dependencies
    commands to build target
```
**make** reads this file and only rebuilds what changed (based on file timestamps).
It is extremely fast, but low-level and manual.

 ### Why Use make?
 - Useful for small to medium projects
 - Great control over the build process
 - Works with any compiler (e.g. gcc, g++, arm-none-eabi-gcc)
## CMake
CMake is a **build system generator**. It generates Makefiles (or project files for other build systems like Visual Studio or Ninja) from a more readable and modular input file called **CMakeLists.txt**.

We need to write build configuration in CMakeLists.txt

CMake outputs a native build system (like a Makefile), then you run make or another build command

### Why Use CMake?
- Supports multi-platform and cross-compilation
- Works well with IDEs and toolchains
- Makes it easier to manage complex or modular projects
- Standard for many open-source and embedded C++ projects
