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
## GCC Essentials
Stands for GNU Compiler for C/C++ (GCC). gcc and g++ both compile C codes into the assembly/object files. If we use `-c` flag, the output will be the object file, otherwise the output will be the executable:
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

