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


