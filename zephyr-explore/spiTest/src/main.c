#include <zephyr/kernel.h>

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/spi.h>
#define SPI_CS_NODE DT_NODELABEL(myspidev)

int main(){

	const struct device *const dev = DEVICE_DT_GET(DT_NODELABEL(spi1));
    
    
	if (!device_is_ready(dev)) {
		printk("%s: device not ready.\n", dev->name);
		return 0;
	}


	const struct spi_cs_control cs_ctrl = (struct spi_cs_control){
		.gpio = GPIO_DT_SPEC_GET(DT_NODELABEL(spi1), cs_gpios),
		.delay = 0u,
	};

  // REMOVE cs config entirely
    struct spi_config config = {
    .frequency = 1000000,
    .operation = SPI_OP_MODE_MASTER | SPI_WORD_SET(8),
    .slave = 0,
    .cs = NULL,  // <-- key change
};

    
    while(1){

        enum { datacount = 5 };
        uint8_t buff[datacount] = { 'D', 'A', 'N', 'K', 'E'};
        uint8_t rxdata[datacount]={0};

        struct spi_buf tx_buf[1] = {
            {.buf = buff, .len = datacount},
        };
        struct spi_buf rx_buf[1] = {
            {.buf = rxdata, .len = datacount},
        };

        
        struct spi_buf_set tx_set = { .buffers = tx_buf, .count = 1 };
        struct spi_buf_set rx_set = { .buffers = rx_buf, .count = 1 };

        int ret = spi_transceive(dev, &config, &tx_set, &rx_set);
   
        printk("rx: %c %c %c %c %c\n", rxdata[0], rxdata[1], rxdata[2], rxdata[3], rxdata[4]);

    }
}
