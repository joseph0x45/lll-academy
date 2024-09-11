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
If we are compiling straight up assembly code, we use
```sh
arm-none-linux-gnueabihf-gcc -o test.o asm.s -nostdlib -static
```

Install GDB 
```sh
sudo pacman -S arm-none-eabi-gdb
```

Run qemu with the debugger
```sh
qemu-arm -g 4242 ./test
```

Run gdb multiarch
```sh
arm-none-eabi-gdb
```

Then inside GDB, run `file <file>` and then `target remote localhost:4242`
