# Zephyr I2C Loopback Application 🔄

## Overview 📝
This application demonstrates the use of the I2C peripheral on an STM32 board running Zephyr RTOS by performing a loopback test. The objective was to configure the I2C interface, send data, and verify correct reception-either by using a physical loopback (connecting SDA/SCL to a compatible device or self-addressed slave mode) or by communicating with a known slave device that echoes data. This validates the I2C driver configuration and hardware wiring.

## Environment & Requirements 💻
- **Hardware:** STM32 development board (e.g., STM32F4 series)
- **Connections:** For loopback, either connect the I2C bus to a slave device that echoes data or configure the MCU as both master and slave if supported. (Direct SDA/SCL loopback is not typical for I2C, as it is a multi-device bus.)
- **Software/OS:** Zephyr RTOS (version as used in the project)
- **Toolchain:** `arm-none-eabi-gcc`, `west`
- **Dependencies:** Zephyr I2C driver, correct device tree configuration for I2C peripheral

## Implementation Details 🛠️
- Configured the I2C peripheral in the device tree, enabling the appropriate I2C instance and assigning correct pins for SDA and SCL[2][4][8].
- Application code:
  - Obtained the I2C device binding using Zephyr’s device API.
  - Set up I2C configuration structure specifying parameters such as bitrate (e.g., 100 kHz, 400 kHz)[2][3].
  - Prepared a transmit buffer with a known data pattern (e.g., `{0xA5, 0x5A, 0xFF}`).
  - Used Zephyr’s `i2c_write_read()` or `i2c_transfer()` API to send and receive data[2][3].
  - Compared the received buffer to the transmitted data to verify correct loopback or echo operation.
  - Provided UART or console output to display test results.
- Device tree overlay was used to ensure the correct I2C controller and pins were enabled for the board[2][4][8].

## Build & Flash Instructions ⚙️
1. Ensure the I2C peripheral and pins are correctly configured in the device tree overlay (see Zephyr documentation for STM32 I2C binding)[2][4].
2. Connect the I2C bus to a compatible slave device or set up the board for self-addressed testing if supported.
3. Build the application:
``` bash
west build -b your_board
```
4. Flash the firmware to the board:
``` bash
west flash
```
5. Open a serial terminal to view test output.

## Test Procedure 🧪
- Connected the I2C bus to a slave device programmed to echo received data (or configured the MCU for self-addressed master-slave communication if hardware supports it).
- Flashed the application using `west flash`.
- On boot, the application sent a known data pattern over I2C and attempted to read the response.
- Compared the received data buffer to the transmitted buffer.
- Repeated the test with different data patterns and I2C configurations (e.g., bitrate).
- Observed results via UART/console output.

## Test Results 📊
- When the I2C bus was connected to an echo-capable slave, the received data matched the transmitted data exactly for all tested patterns and configurations.
- Changing the transmit data resulted in corresponding changes in the received data, confirming proper loopback/echo.
- No errors or mismatches were observed in the test cases.
- The I2C peripheral and Zephyr driver operated reliably in the tested configurations.

## Lessons Learned / Next Steps 🎯
- Learned how to configure and use Zephyr’s I2C API and device tree for STM32.
- Validated I2C functionality and hardware wiring through loopback/echo testing.
- Next steps: Communicate with actual I2C sensors or EEPROMs, explore multi-master scenarios, and implement interrupt-driven or DMA-based I2C transfers.

## References 📚
- [Zephyr STM32 I2C V2 Binding Documentation][2]
- [Zephyr STM32 I2C V1 Binding Documentation][4]
- [Zephyr I2C Driver Source (STM32)][1][3]
- [ST Wiki: I2C Device Tree Configuration][8]

[1]: https://github.com/zephyrproject-rtos/zephyr/blob/main/drivers/i2c/i2c_ll_stm32.c  
[2]: https://docs.zephyrproject.org/latest/build/dts/api/bindings/i2c/st,stm32-i2c-v2.html  
[3]: https://github.com/zephyrproject-rtos/zephyr/blob/master/drivers/i2c/i2c_ll_stm32_v2.c  
[4]: https://docs.zephyrproject.org/latest/build/dts/api/bindings/i2c/st,stm32-i2c-v1.html  
[8]: https://wiki.st.com/stm32mpu/wiki/I2C_device_tree_configuration  
