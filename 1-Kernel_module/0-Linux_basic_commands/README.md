# All the basic commands you need to deal with Linux 
#### In this guide we are using Ubuntu , but whatever the Distrpo you are using it doesn't really matter



## 1. `ls`
Lists directory contents.

```sh
ls -l
```

## 2. `cd`
Changes the current directory.

```sh
cd /path/to/directory
```

## 3. `pwd`
Prints the current working directory.

```sh
pwd
```

## 4. `cp`
Copies files or directories.

```sh
cp source_file destination_file
```

## 5. `mv`
Moves or renames files or directories.

```sh
mv old_name new_name
```

## 6. `rm`
Removes files or directories.

```sh
rm file_name
```

## 7. `chmod`
Changes file permissions.

```sh
chmod 755 script.sh
```

## 8. `chown`
Changes file owner and group.

```sh
chown user:group file_name
```

## 9. `find`
Searches for files in a directory hierarchy.

```sh
find /path -name "file_name"
```

## 10. `grep`
Searches for a specified pattern in files.

```sh
grep "search_term" file_name
```

## 11. `echo`
Displays a line of text or string.

```sh
echo "Hello, World!"
```

## 12. `cat`
Concatenates and displays the content of files.

```sh
cat file_name
```

## 13. `more`
Views file content one screen at a time.

```sh
more file_name
```

## 14. `less`
Views file content with backward and forward navigation.

```sh
less file_name
```

## 15. `head`
Displays the first few lines of a file.

```sh
head -n 10 file_name
```

## 16. `tail`
Displays the last few lines of a file.

```sh
tail -n 10 file_name
```

## 17. `ps`
Displays currently running processes.

```sh
ps aux
```

## 18. `kill`
Terminates processes by PID.

```sh
kill 1234
```

## 19. `top`
Displays real-time system processes.

```sh
top
```

## 20. `df`
Displays disk space usage.

```sh
df -h
```

## 21. `du`
Displays disk usage of files and directories.

```sh
du -sh /path/to/directory
```

## 22. `tar`
Archives files using tar.

```sh
tar -czvf archive.tar.gz /path/to/directory
```

## 23. `gzip`
Compresses files using gzip.

```sh
gzip file_name
```

## 24. `unzip`
Extracts zip archives.

```sh
unzip archive.zip
```

## 25. `scp`
Securely copies files between hosts.

```sh
scp source_file user@remote_host:/path/to/destination
```

## 26. `ssh`
Connects to a remote host securely.

```sh
ssh user@remote_host
```

## 27. `wget`
Downloads files from the internet.

```sh
wget http://example.com/file
```

## 28. `curl`
Transfers data from or to a server.

```sh
curl http://example.com
```

## 29. `sudo`
Executes a command as another user, typically the superuser.

```sh
sudo command
```

## 30. `apt-get`
Package handling utility in Debian-based distributions.

```sh
sudo apt-get update
```

## 31. `yum`
Package manager for RPM-based distributions.

```sh
sudo yum update
```

## 32. `systemctl`
Controls the systemd system and service manager.

```sh
systemctl start service_name
```

## 33. `journalctl`
Views systemd, kernel, and journal logs.

```sh
journalctl -xe
```

## 34. `df`
Displays file system disk space usage.

```sh
df -h
```

## 35. `fdisk`
Manipulates disk partition tables.

```sh
sudo fdisk /dev/sda
```

## 36. `mount`
Mounts a file system.

```sh
sudo mount /dev/sda1 /mnt
```

## 37. `umount`
Unmounts a file system.

```sh
sudo umount /mnt
```

## 38. `reboot`
Reboots the system.

```sh
sudo reboot
```

## 39. `shutdown`
Shuts down or reboots the system.

```sh
sudo shutdown -h now
```

## 40. `uname`
Displays system information.

```sh
uname -a
```





----------------------------------------------------------------------------------
# Mind Maps
## apt get
![alt text](image.png)


## Cat
![alt text](image-1.png)

## systemctl
![alt text](image-3.png)

## snap
![alt text](image-4.png)

## grep
![alt text](image-5.png)

## Fine 
![alt text](image-6.png)

## Error Handling
![alt text](image-7.png)

## Git & Github
![alt text](image-8.png)

![alt text](image-9.png)