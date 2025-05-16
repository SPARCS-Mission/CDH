#include <zephyr/kernel.h>

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/spi.h>

int main(){

	const struct device *const dev = DEVICE_DT_GET(DT_NODELABEL(spi1));
    
	if (!device_is_ready(dev)) {
		printk("%s: device not ready.\n", dev->name);
		// return 0;
	}

    struct spi_config config = {
    .frequency = 8000000,
    .operation = SPI_OP_MODE_MASTER | SPI_WORD_SET(8),
    .slave = 0,
    .cs = NULL,  // <-- key change
    };

    uint16_t rx_cnt = 0;

    while(1){
        
        enum { datacount = 5 };

        uint8_t buff[datacount] = { 'D', 'A', 'N', 'K', 'E'};
        // uint8_t buff[datacount] = { 1, 1, 1, 1, 1};
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
        
        printk("rx %d : %c %c %c %c %c\n",++rx_cnt, rxdata[0], rxdata[1], rxdata[2], rxdata[3], rxdata[4]);

    }
}
