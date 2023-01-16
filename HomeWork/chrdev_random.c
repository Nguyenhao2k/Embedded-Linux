
/*Cac buoc de complie va install 
1. make
2. insmod chrdev_random.ko 
3. kiem tra xem file da duoc tao o duong dan /dev/ 
4. rmmod chardev_random
*/


#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/random.h>
#include <asm/uaccess.h>

#define DEVICE_NAME "chrdev_random"
#define BUF_SIZE 10

static int buf_size = BUF_SIZE;
module_param(buf_size, int, S_IRUGO);
MODULE_PARM_DESC(buf_size, "Size of the buffer for the random characters");

static int major;
static struct cdev cdev;

static ssize_t chrdev_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	char random_buf[buf_size];

	get_random_bytes(random_buf, buf_size);

	if (copy_to_user(buf, random_buf, buf_size))
		return -EFAULT;

	return buf_size;
}

static const struct file_operations chrdev_fops = {
	.owner = THIS_MODULE,
	.read = chrdev_read,
};

static int __init chrdev_init(void)
{
	dev_t dev;
	int ret;

	ret = alloc_chrdev_region(&dev, 0, 1, DEVICE_NAME);
	if (ret)
		return ret;

	major = MAJOR(dev);

	cdev_init(&cdev, &chrdev_fops);
	cdev.owner = THIS_MODULE;

	ret = cdev_add(&cdev, dev, 1);
	if (ret) {
		unregister_chrdev_region(dev, 1);
		return ret;
	}

	return 0;
}

static void __exit chrdev_exit(void)
{
	dev_t dev = MKDEV(major, 0);

	cdev_del(&cdev);
	unregister_chrdev_region(dev, 1);
}

module_init(chrdev_init);
module_exit(chrdev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("TranNgocNguyen-19ES");
MODULE_DESCRIPTION("Character driver exercise");

