/**
 * @file
 * @brief blink an LED by toggeling a gpio 
 * 
 * 
 * @authors Roham Kaveie - Farzane Majd
 * @date 2025-04-24
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>

#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>


#define SLEEP_TIME_MS 500 


const struct device *dev = DEVICE_DT_GET(DT_NODELABEL(gpioa)); 

int main(){
	
	// const struct device *dev = device_get_binding("mygpioa"); // looks for property of label with matched value (not node label)
	// const struct device *dev = device_get_by_dt_nodelabel("gpioa");
	// if(!dev)
	// 	return 0;
	gpio_pin_configure(dev, 3, GPIO_OUTPUT ); // configure as output 
	
	while(1) {
		gpio_pin_toggle(dev, 3); // toggles the pin
		if(gpio_pin_get(dev,3))
			printk("LED on \n");
		else
			printk("LED off \n");
		printk("LED blinking... \n");
		k_msleep(SLEEP_TIME_MS);
	}

}


