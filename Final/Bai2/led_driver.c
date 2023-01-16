#include <linux/module.h>   
#include <linux/string.h>    
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/io.h>
#include <linux/sched.h>
#include <linux/interrupt.h>
#include <linux/list.h>
#include <linux/irq.h>
#include <linux/slab.h>
#include <linux/gpio.h>
#include <linux/time.h>
#include <linux/delay.h>
#include <linux/timer.h>

#define LED0 22
#define LED1 27
#define MY_DEVICE_NAME    "myLED_timer"

MODULE_LICENSE("GPL")
MODULE_AUTHOR("Tran Ngoc Nguyen-123180031")
MODULE_DESCRIPTION("LED_DRIVER MODULE")


struct timer_list my_timer;
int my_flag = 0;

//TIMER FUNCTION
static void timer_function(unsigned long data){
	gpio_set_value(LED0, my_flag == 1);
	gpio_set_value(LED1, my_flag == 0);
	my_flag = my_flag ? (0):(1);
	// modify the timer for next time
	mod_timer(&my_timer, jiffies + HZ / 2);
}


//INIT MODULE
int init_module(void)
{

	printk("moudle: LED blinking ...\n");
	printk("*****LED GPIO Init ******************\n");
	if(gpio_request(LED0,"LED0") ) return -1;
	if(gpio_request(LED1,"LED1") ) return -1;
	gpio_direction_output(LED0, 0);
	gpio_direction_output(LED1, 0);

	//  -- initialize the timer 
	init_timer(&my_timer);
	my_timer.expires = jiffies + HZ ;
	my_timer.function = timer_function;
	my_timer.data = NULL;

	// -- TIMER START 
	add_timer(&my_timer);

	return 0;
}

//CLEANUP MODULE
void cleanup_module(void)
{
	del_timer(&my_timer);

	printk("module : LED blinking END\n");
	gpio_set_value(LED0, 0);
	gpio_set_value(LED1, 0);
	gpio_free(LED0);
	gpio_free(LED1);
}
