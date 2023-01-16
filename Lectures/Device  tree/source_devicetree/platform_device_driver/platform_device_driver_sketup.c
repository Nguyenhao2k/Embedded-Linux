#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/device.h>
#include <linux/delay.h>
#include <linux/slab.h>

#define DEVICE_NAME "my_dev"

static struct platform_device my_device = {
        .name               = DEVICE_NAME,
        .id                 = PLATFORM_DEVID_NONE,
};

void __init my_device_init_pdata(void)
{
        printk(KERN_ALERT " %s\n", __FUNCTION__);

        /* Register "my-platform-device" with the OS. */
        platform_device_register(&my_device);
}


/* Probe driver function called by the OS when the device with the name
 * "my-platform-device" is found in the system. */
static int my_driver_probe(struct platform_device *pdev)
{

        printk(KERN_ALERT " %s\n", __FUNCTION__);

        return 0;
}

static int my_driver_remove(struct platform_device *pdev)
{
        printk(KERN_ALERT " %s\n", __FUNCTION__);

        /* do something with the driver */

        return 0;
}


static struct platform_driver my_driver = {
        .probe      = my_driver_probe,
        .remove     = my_driver_remove,
        .driver     = {
                .name   = DEVICE_NAME,
                .owner  = THIS_MODULE,
        },
};

/* Entry point for loading this module */
static int __init my_driver_init_module(void)
{
        int ret;
        pr_info(" %s\n", __FUNCTION__);

        /* Add the device to the platform.
           This has to be done by the platform specific code.
           */
        my_device_init_pdata();

        /* We will use this when we know for sure that this device is not
           hot-pluggable and is sure to be present in the system.
           */
        ret = platform_driver_probe(&my_driver, my_driver_probe);
        // return driver_register(&my_driver);

        /* We will use this when we are not sure if this device is present in the
           system. The driver probe will be called by the OS if the device is
           present in the system.
           */
        //return platform_driver_register(&my_driver);
        return ret;
}

/* entry point for unloading the module */
static void __exit my_driver_cleanup_module(void)
{
        pr_info(" %s\n", __FUNCTION__);
        platform_driver_unregister(&my_driver);
        // driver_unregister(&my_driver);
}

module_init(my_driver_init_module);
module_exit(my_driver_cleanup_module);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("KienLT9");