/**
 * @file 
 * @brief blink an LED by toggeling a gpio 
 * 
 * 	Continuing the previous topic (get access to a component like GPIO or ...)
 * 	Another way is using <_dt_spec>
 * 	The word spec stands for specification and it refers to a struct that encapsulates 
 *  all the necessary information about a device or peripheral (like device pointers and configuration)
 *  in one place. you can use <*_DT_SPEC_GET> functions to get _dt_spec structure and First 
 *  we need a devicetree node identifier. A lot of MACROS could make that possible such as:
 * 	1. DT_ALIAS(alias)
 *  2. DT_NODELABEL(label)
 *  3. DT_CHOSEN(chosen)
 *  4. DT_PATH(soc, pin-controller@58020000, gpio@58020000) // example path
 * 	
 * 
 * @authors Roham Kaveie - Farzane Majd
 * @date 2025-04-25
 */


#include <zephyr/kernel.h>
#include <zephyr/device.h>

#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/spi.h>


#define SLEEP_TIME_MS 500 

#define LED0_NODE DT_ALIAS(led0)

// if these information (NODELABEL of PORT,PIN number, and configuration flags) needed: 
// #define LED_GPIO DT_GPIO_LABEL(LED0_NODE, gpios)
// #define LED_PIN DT_GPIO_PIN(LED0_NODE, gpios)
// #define LED_FLAGS DT_GPIO_FLAGS(LED0_NODE, gpios)

int main(){
	
    struct gpio_dt_spec led = GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios);
	struct spi_dt_spec my_spi;
	gpio_pin_configure_dt(&led,GPIO_OUTPUT_ACTIVE);
	my_spi.config.cs
	spi_write_dt();
	while(1) {
		gpio_pin_toggle_dt(&led);
		if(gpio_pin_get_dt(&led))
			printk("LED on \n");
		else
			printk("LED off \n");
		printk("LED blinking... \n");
		k_msleep(SLEEP_TIME_MS);
	}

}


