# Zephyr UART Loopback Application 🔄

## Overview 📝
This application demonstrates the use of the UART peripheral on an STM32 board running Zephyr RTOS by performing a hardware loopback test. The goal was to configure UART, send data, and verify correct reception by physically connecting the TX and RX pins, allowing transmitted data to be immediately received back. This validates both the UART driver configuration and the hardware wiring.

## Environment & Requirements 💻
- **Hardware:** STM32 development board (e.g., STM32F4 series)
- **Connections:** TX and RX pins physically connected for loopback
- **Software/OS:** Zephyr RTOS (version as used in the project)
- **Toolchain:** `arm-none-eabi-gcc`, `west`
- **Dependencies:** Zephyr UART driver, correct device tree configuration for UART peripheral

## Implementation Details 🛠️
- Configured the UART peripheral in the device tree, enabling the appropriate UART instance and assigning correct pins for TX and RX[1][7].
- Application code:
  - Obtained the UART device binding using Zephyr’s device API.
  - Set UART parameters (baud rate, stop bits, data bits) as needed in the device tree or Kconfig[1].
  - Prepared a transmit buffer with a known data pattern (e.g., "Hello, UART!" or a fixed byte sequence).
  - Used Zephyr’s UART API to send data (`uart_poll_out` or `uart_fifo_fill`) and receive data (`uart_poll_in` or `uart_fifo_read`)[2][5][8].
  - Compared the received buffer to the transmitted data to verify correct loopback operation.
  - Provided UART or console output to display test results.

## Build & Flash Instructions ⚙️
1. Ensure the UART peripheral and pins are correctly configured in the device tree overlay (see Zephyr documentation for STM32 UART binding)[1].
2. Connect TX and RX pins on the board for hardware loopback.
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
- Connected TX and RX pins on the STM32 board.
- Flashed the application using `west flash`.
- On boot, the application sent a known data pattern over UART and attempted to read the response.
- Compared the received data buffer to the transmitted buffer.
- Repeated the test with different data patterns and UART configurations (e.g., baud rate, stop bits).
- Observed results via UART/console output.

## Test Results 📊
- When TX and RX were connected, the received data matched the transmitted data exactly for all tested patterns and configurations.
- Changing the transmit data resulted in corresponding changes in the received data, confirming proper loopback.
- No errors or mismatches were observed in the test cases.
- When the loopback connection was removed, the received data did not match, as expected.
- The UART peripheral and Zephyr driver operated reliably in loopback mode.

## Lessons Learned / Next Steps 🎯
- Learned how to configure and use Zephyr’s UART API and device tree for STM32.
- Validated UART functionality and hardware wiring through loopback testing.
- Next steps: Communicate with actual UART peripherals (modems, sensors), explore interrupt-driven and DMA UART transfers, and test single-wire/half-duplex UART modes[4].

## References 📚
- [Zephyr STM32 UART Binding Documentation][1]
- [Example: UART communication with LTE modem in Zephyr][2]
- [Zephyr UART circular DMA sample][3]
- [Zephyr STM32 single-wire UART sample][4]
- [Zephyr UART polling/interrupt code example][5]
- [Zephyr UART bring-up on STM32][7]
- [UART loopback test example][8]

[1]: https://docs.zephyrproject.org/latest/build/dts/api/bindings/serial/st,stm32-uart.html  
[2]: https://lists.zephyrproject.org/g/users/topic/example_of_how_use_uart_to/28504691  
[3]: https://github.com/zephyrproject-rtos/zephyr/blob/main/samples/boards/st/uart/circular_dma/README.rst  
[4]: https://docs.zephyrproject.org/3.7.0/samples/boards/stm32/uart/single_wire/README.html  
[5]: https://community.st.com/t5/stm32-mcus-embedded-software/not-receiving-uart-messages-with-zephyr-on-stm32l496/td-p/735375  
[7]: https://yairgadelov.me/zephyr-rtos-bringup-on-stm32/  
[8]: https://devzone.nordicsemi.com/f/nordic-q-a/108733/uart-loopback-test  
