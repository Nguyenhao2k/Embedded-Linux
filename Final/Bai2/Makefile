#Kiem tra bang cach  
#1) sudo make
#2) sudo insmod led_driver.ko 
obj-m += led_driver.o
 
KDIR = /lib/modules/$(shell uname -r)/build
 
 
all:
    make -C $(KDIR)  M=$(shell pwd) modules
 
clean:
    make -C $(KDIR)  M=$(shell pwd) clean
