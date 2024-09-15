# Building Root file System :
After we customized and build the kernel we are going to create a filesystem for the kernel 
the filesystem contains the `(initprocess systemd or systemv - binaries - applications)`



## types of the filesystems:
1. **init-ram-FS** : it's a temporary filesystem that's loaded into the memory , it's used to load the kernel modules and the drivers that are needed to boot the system , it's a compressed filesystem that's loaded into the memory

2. **Storage-Based-FS** : it's a nonvolatile memory like the SD-card

3. **Network-FS** : it's a nonvolatile but it's in a different board and mounted and accessed through any network protocol


# Operations we are going to do:
1. **Create a standard hierarichy** 
2. **Create directories**
3. **Put the commands in /usr/bin**
4. **Put Libraries like (glibc)**
5. **Applications**


We are going to use the `busyBox` to create the filesystem, it contains a lot of commands and utilities that are used in the linux system

#### Steps:
1. Download the busyBox 
```bash
git clone https://github.com/mirror/busybox.git
```
2. Configure the busyBox
```bash
make ARCH=arm64 CROSS_COMPILE=aarch64-rpi4-linux-gnu- deconfig # to clean the old configurations
make ARCH=arm64 CROSS_COMPILE=aarch64-rpi4-linux-gnu- menuconfig # to configure the busyBox
```
3. Build the busyBox
```bash 
make ARCH=arm64 CROSS_COMPILE=aarch64-rpi4-linux-gnu-
```
4. Install the busyBox
```bash
make ARCH=arm CROSS_COMPILE=aarch64-rpi4-linux-gnu- install CONFIG_PREFIX=/home/wagdy/Desktop/Embedded_linux/rootfs
```

5. Go to the rootfs directory and create the following directories:
```bash
cd /home/wagdy/Desktop/Embedded_linux/rootfs
mkdir  proc sys 
```

6. After all we need to have a file called `initramfs.cpio` with `.cpio` extension , it's a compressed file that contains the filesystem
```bash
# make sure to execute this command inside the rootfs directory
cd /home/wagdy/Desktop/Embedded_linux/rootfs
find . -print0 | cpio --null -ov --format=newc > initramfs.cpio
```



7. Now we can boot qemu using the `Image` kernel we have and the `Initramfs.cpio` we created
```bash
qemu-system-aarch64 -M virt -cpu cortex-a53 -m 1G -kernel <Image Path> -append "console=ttyAMA0 rdinit=/bin/sh" -initrd <initramfs file> -nographic 
```