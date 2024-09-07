# Setting up env(Arch Linux)
Install the toolchain
```sh
yay -S arm-none-linux-gnueabihf-toolchain-bin
```

Then install qemu
```sh
yay -S qemu-user
```

Compile the C code into ARM assembly
```sh
arm-none-linux-gnueabihf-gcc -o test.o main.c -static
```

Install GDB 
```sh
sudo pacman -S arm-none-eabi-gdb
```

Run qemu with the debugger
```sh
qemu-arm -g 4242 ./test
```
