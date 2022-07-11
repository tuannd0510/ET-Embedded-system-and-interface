obj-m += lcdi2c.o
KDIR = /home/tuannd/rpi-kernel/linux

all:
	make ARCH=arm CROSS_COMPILE=/bin/arm-linux-gnueabihf- -C $(KDIR) M=$(PWD) modules
clean:
	make -C $(KDIR) M=$(PWD) clean