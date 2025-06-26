#include <zephyr/kernel.h>

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>

/* size of stack area used by each thread */
#define STACKSIZE 1024

/* scheduling priority used by each thread */
#define PRIORITY 7

/* delay between greetings (in ms) */
#define SLEEPTIME 500
K_THREAD_STACK_DEFINE(threadA_stack_area, STACKSIZE);
static struct k_thread threadA_data;

K_THREAD_STACK_DEFINE(threadB_stack_area, STACKSIZE);
static struct k_thread threadB_data;

/* threadA is a static thread that is spawned automatically */

void threadA(void *dummy1, void *dummy2, void *dummy3)
{
	ARG_UNUSED(dummy1);
	ARG_UNUSED(dummy2);
	ARG_UNUSED(dummy3);

	printk("thread_a: thread started \n");

	while (1)
	{
		printk("thread_a: Hello in the loop \n");
		k_msleep(1000);
	}

}

void threadB(void *dummy1, void *dummy2, void *dummy3)
{
	ARG_UNUSED(dummy1);
	ARG_UNUSED(dummy2);
	ARG_UNUSED(dummy3);

	printk("thread_b: thread started \n");

	
	const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(DT_ALIAS(led0),gpios);

	gpio_pin_configure_dt(&led,GPIO_OUTPUT_ACTIVE);

	while (1)
	{
		gpio_pin_toggle_dt(&led);
		printk("thread_b: blinking green led \n");
		k_msleep(200);
	}

}

void main(void)
{
	k_thread_create(&threadA_data, threadA_stack_area,
			K_THREAD_STACK_SIZEOF(threadA_stack_area),
			threadA, NULL, NULL, NULL,
			PRIORITY, 0, K_FOREVER);
	k_thread_name_set(&threadA_data, "thread_a");

	k_thread_create(&threadB_data, threadB_stack_area,
        K_THREAD_STACK_SIZEOF(threadB_stack_area),
        threadB, NULL, NULL, NULL,
        PRIORITY, 0, K_FOREVER);
    k_thread_name_set(&threadB_data, "thread_b");

    k_thread_start(&threadB_data);
	k_thread_start(&threadA_data);
    
}
