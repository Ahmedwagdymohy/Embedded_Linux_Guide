# Kernel memory stack
**in this tutorial we suppose that the board has a `memory management unit` (MMU) and we have 1G of ram**

## How the CPU access the memoy?
- **The Cpu access an *virtual* address to the `MMU` and then the `MMU` remaps the address to the *physical* address and access the real RAM**
- **The MMU checks also for the privilages of the process that's trying to access the memory, if it's not accessible it will show segmentation fault**