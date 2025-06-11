# Compilation Basics in embedded software design

This page summarizes key concepts an embedded software designer should know about the compilation process, toolchains, and build systems when writing firmware in C or C++.

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
Final Executable (.elf / .bin / .hex)
```
# GCC Toolchain Essentials

| Tool  | Use |
| ------------- | ------------- |
|arm-none-eabi-gcc |	Compile C files for ARM Cortex-M
|arm-none-eabi-g++  | Compile C++ files for ARM
|ld	| Link object files using a script
|objcopy	| Convert .elf → .bin / .hex
|nm, size, objdump	| Inspect symbols, memory size

 # GCC Flags You Must Know
 
|Flag |	Description |
| ------------- | ------------- |
|-mcpu=cortex-m4	|Target specific CPU core
|-mthumb |	Generate Thumb instructions
|-O0 → -O3	|Optimization level
|-g	|Include debug symbols
|-Wall	|Enable all warnings
|-T link.ld	|Use custom linker script
|-c	|Compile only, no linking
|-o	| Output file name

