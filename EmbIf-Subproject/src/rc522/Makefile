obj-m :=RFID-RC522.o
RFID-RC522-objs:=rc522_driver.o rc522_api.o
KDIR = /home/tuannd/rpi-kernel/linux

all:
	make ARCH=arm CROSS_COMPILE=/bin/arm-linux-gnueabihf- -C $(KDIR) M=$(PWD) modules
clean:
	make -C $(KDIR) M=$(PWD) clean