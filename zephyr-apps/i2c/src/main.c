#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/i2c.h>


int main(void)
{


	while(1){
		printk("this one gonna be painfull... (good luck)");
		k_msleep(1000);
	}
	return 0;
}
