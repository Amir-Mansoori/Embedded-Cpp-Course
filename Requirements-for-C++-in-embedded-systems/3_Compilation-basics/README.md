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
