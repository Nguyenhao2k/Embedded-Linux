obj-m   += platform_device_driver_bind_dtb.o

# Option build for KIT
# export ARCH=arm64
# export export CROSS_COMPILE=aarch64-linux-gnu-

# KERNELDIR ?= /data/workspace/kienlt9/linux

KERNELDIR ?= /lib/modules/$(shell uname -r)/build

PWD       := $(shell pwd)

all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean