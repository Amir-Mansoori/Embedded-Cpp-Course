# Memory types in embedded systems
We can divide memory types in embedded systems into **Volatile** and **Non-volatile** memories:

- Volatile: loses data when power is off
- Non-volatile: keeps data when power is off

In terms of how memory is accessed, sequential access (like in magnetic tapes) means the data has to be read one piece at a time in order. In contrast, **random access** (which evolved as an improvement over sequential access) lets the system go straight to any piece of data, which is much faster and more efficient.

In terms of Reading/Writing from/to memory, we can divide the memories into **ROM** (Read Only Memory) and **RAM** (Random Access Memory). We are able to read and write from/to RAM. However in ROM we usually write data only once and then we can only read data. Although the naming convention does not imply, **RAM is volatile** and **ROM is usually non-volatile**. ROM is originally designed to be written once and read many times. Today, types like EEPROM and Flash can be electrically re-written, though more slowly and less frequently than RAM. 

- Examples of **ROM**: **PROM**, **EPROM**, **EEPROM**, **FLASH**
  - Note that **SD cards** and **SSD** memories are two types of Flash memories.
- Examples of **RAM**: **SRAM**, **DRAM** (DDR memories)

| Memory type| storage | Examples| 
-------------|---------|-------------------------
| ROM | Non-Volatile (read) | PROM, EPROM, EEPROM, FLASH
| RAM | Volatile  | SRAM, DRAM (DDR memories)

|Memory type | examples | usage
-------------|----------|--------------
| FLASH (non-volatile)     | SD cards| Storing firmware, file systems, or OS images
| SRAM (volatile)  | Cache memories | storing small amount of memories that can be accessed very fast (Stack, heap, cache, runtime variables)
| DRAM (volatile)  | DDR memories | slower than SRAM, good for storing larger data like images or video frames

<p align="center">
  <img src="[https://github.com/Amir-Mansoori/Embedded-Cpp-Course/blob/main/Images/memory.png](https://github.com/Amir-Mansoori/Embedded-Cpp-Course/blob/main/Images/dram.png)" alt="DRAM cell structure with continuous refreshing of capacitors to retain data" />
</p>
