# Booting sequence of the embedded linux systems:
> Interview Questions
1. What's the first thing that runs when the device is powered on?
2. What's the first bootloader?
3. What's the second bootloader?
4. What's the third bootloader?
5. What's SOC? -> it's the system on chip , it's the processor and the peripherals on the same chip, it can be used for multiple purposes like the raspberry pi.


> Answer:
1. **Bios**               : is the first thing that runs when the device is powered on , it's also usde to make hardware check like if there's a RAM problem the device will make beeeb sound and stop booting   
2. **firts bootloader**   : is used to make hardware cheks on the device 
3. **second bootloader(SPL)**  : used for safety checks if th efist bootloader is corrupted and also used for debugging, it also init the DRAM(Dynamic ram) & Dram controller , then copies the U-boot(which's the third bootloader) to the RAM and then jumps to the U-boot code.
4. **Third bootloader**   : this one is optional in the devices not in all , but in our case it's called u-boot and for windows it's called GRUB
                        the third bootloader gives me the capability to choose the mode I'm booting to like )the safe-mode or the normal mode recovery mode, can also choose which kernel to start for example if we have a dual booth on the device and we want to choose which device to boot from the third bootloadr will give us this capability.

4. **kernel**             
5. **initramfs**
6. **root file system**



![alt text](Assets/image.png)




[!NOTE]
the bootloader is a bare metal thing that's written in C and assembly , it's target dependant , it's the thing which calles the kernel 





# Customizing the bootloader:
**After creating the toolchain we are going to use , Now it's the time to make our bootloader**
1. download the U-boot repo
    - ```bash
        git clone git://git.denx.de/u-boot.git
        ```
2. Go to u-boot directory
    - ```bash
        cd u-boot
        ```
3. To see the available configs based on the board or the soc you are using 
    - ```bash
        cd configs
        ls #this will list all the available configurations
        ```       
3. Make the U-boot configurations
    - ```bash
        #Note that you should have added the bin path of the tool chain , we discussed this in the previous README
        make rpi_4_defconfig
        ```
4. This will create a configuration file in the `u-boot` directory

5. Now we are going to build the U-boot
    - ```bash
        make -j8 -s 
        # Thiswillgenerate a u-boot binfile.
        ```
**Now we are done with the bootloader we will take this binfile and it on the Raspi4 board , and the next step is to create A kernel and we will make the bootloader boot it**