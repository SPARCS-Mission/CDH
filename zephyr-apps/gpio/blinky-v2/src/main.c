/**
 * @file 
 * @brief blink an LED by toggeling a gpio 
 *
 * @authors Roham Kaveie - Farzane Majd
 * @date 2025-04-25
 */


#include <zephyr/kernel.h>
#include <zephyr/device.h>

#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/spi.h>


#define SLEEP_TIME_MS 100 

#define LED0_NODE DT_ALIAS(led3)
// #define LED0_NODE DT_NODELABEL(my_led)
// #define LED0_NODE DT_PATH(leds, led_3)

// if these information (NODELABEL of PORT,PIN number, and configuration flags) needed: 
// #define LED_GPIO DT_GPIO_LABEL(LED0_NODE, gpios)
// #define LED_PIN DT_GPIO_PIN(LED0_NODE, gpios)
// #define LED_FLAGS DT_GPIO_FLAGS(LED0_NODE, gpios)

int main(){
    struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
	gpio_pin_configure_dt(&led,GPIO_OUTPUT_ACTIVE);
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


