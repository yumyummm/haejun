#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/gpio.h>
#include <asm/uaccess.h>
#include <asm/io.h>

#define HIGH 1
#define LOW 0

int led[4]={23,24,25,1};

static int led_module_init(void)
{
    int ret, i;
    printk(KERN_INFO "led module init\n");
    for(int i=0;i<4;++i){
        ret = gpio_request(led[i], "LED");
        if(ret<0)
            printk(KERN_INFO "led module gpio request failed\n");
    }
    for(int i=0;i<4;++i){
        ret = gpio_direction_output(led[i], HIGH);
    }
    return 0;
    
}

static void led_module_exit(void)
{
    int i;
    printk(KERN_INFO "led_module exit\n");
    for(int i=0;i<4;++i)
    {
        gpio_free(led[i]);
    }
 
}

module_init(led_module_init);
module_exit(led_module_exit);
MODULE_LICENSE("GPL");