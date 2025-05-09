	/**
	 * @file
	 * @brief blink an LED by toggeling a gpio 
	 * 
	 * 
     * There are different ways to get access to a component like GPIO or SPI or UART or anything else. 
	 * One way is getting the related device directly from the devicetree. 
	 * This way is somehow uncommon and it is rarely used in the most examples which i found on Internet, mostly due to these resaons:
	 *	1. Lack of Bundled Configuration Data
	 *			Direct device retrieval gives you only the device pointer, without any associated configuration such as pins, flags, or other properties defined in devicetree.
	 *			This forces you to manually fetch and manage related parameters separately, increasing boilerplate and risk of errors.
	 *	2. Less Type Safety and Code Clarity
	 *			Using just a device pointer can lead to scattered code where device configuration is handled separately from device access.
	 *			dt_spec bundles device and configuration into a single, strongly typed structure (e.g., gpio_dt_spec), improving readability and reducing mistakes.
	 *	3. More Error-Prone for Complex Bindings
	 *			For devices that require multiple devicetree properties (e.g., GPIO pins plus flags), direct device retrieval does not help manage these cohesively.
	 *			dt_spec macros initialize all relevant fields at compile time, preventing runtime misconfiguration.
	 *	4. Manual Handling of Phandles and Indices	
     *			When devices are referenced via phandles or arrays in devicetree, direct device retrieval requires manual indexing and property extraction.
	 *			dt_spec macros abstract this complexity, making code simpler and less error-prone.
	 *
	 *  A device can be taken directly using <device_get_binding> function or <DEVICE_DT_GET> MACRO (using MACRO is recommended). 
	 * 
	 * 	Note: 
	 * 	* There are definitely other functions or MACROs to get directly a device 
	 *  * <device_get_binding> function looks for property of label with matched value (not node label),
	 * 	  So you should add label property to the node in the devicetree by using an overlay. as you can see in app.overlay file.
	 * 	*
	 * @authors Roham Kaveie - Farzane Majd
	 * @date 2025-04-24
	 */





#include <zephyr/kernel.h>
#include <zephyr/device.h>

#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>


#define SLEEP_TIME_MS 500 


const struct device *dev = DEVICE_DT_GET(DT_NODELABEL(gpioe)); 

int main(){
	
	// const struct device *dev = device_get_binding("mygpioe"); // looks for property of label with matched value (not node label)
	// const struct device *dev = device_get_by_dt_nodelabel("gpioe");
	// if(!dev)
	// 	return 0;
	gpio_pin_configure(dev, 1, GPIO_OUTPUT ); // configure as output 
	
	while(1) {
		gpio_pin_toggle(dev, 1); // toggles the pin
		if(gpio_pin_get(dev,1))
			printk("LED on \n");
		else
			printk("LED off \n");
		printk("LED blinking... \n");
		k_msleep(SLEEP_TIME_MS);
	}

}


