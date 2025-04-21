#include <zephyr/kernel.h>
#include <zephyr/device.h>

#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/uart.h>



#define SLEEP_TIME_MS 500 

//#define LED0_NODE DT_ALIAS(myled)

#define LED0_NODE DT_NODELABEL(led4)
#define LED_GPIO DT_GPIO_LABEL(LED0_NODE, gpios)
#define LED_PIN DT_GPIO_PIN(LED0_NODE, gpios)
#define LED_FLAGS DT_GPIO_FLAGS(LED0_NODE, gpios)

int main(){

    struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
    gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
    
	while(1) {

		gpio_pin_toggle_dt(&led);
		printk("LED blinking... \n");
		k_msleep(SLEEP_TIME_MS);
	}

}

