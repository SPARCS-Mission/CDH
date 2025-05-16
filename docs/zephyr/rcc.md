# Zephyr STM32 RCC (Clock Configuration) Application 🕰️

## Overview 📝
This application demonstrates configuring the Reset and Clock Controller (RCC) on an STM32 board using Zephyr RTOS. The goal was to understand and control the system clock source, core frequency, and peripheral bus prescalers via Zephyr’s device tree and clock control APIs.

## Environment & Requirements 💻
- **Hardware:** STM32 development board (e.g., STM32F4 Discovery)
- **Software/OS:** Zephyr RTOS (version as used in the project)
- **Toolchain:** `arm-none-eabi-gcc`, `west`
- **Dependencies:** Zephyr STM32 RCC driver, correct device tree configuration

## Implementation Details 🛠️
- Modified the device tree to configure the RCC node:
  - Selected the system clock source (e.g., HSE, HSI, or PLL)
  - Set the core clock frequency using the `clock-frequency` property
  - Configured AHB and APB bus prescalers for desired clock domains
- The configuration followed Zephyr’s STM32 RCC binding documentation[1][2][8]:
  - Example:
    ```
    &rcc {
      clocks = <&pll>;              /* Use PLL as SYSCLK source */
      ahb-prescaler = <2>;
      clock-frequency = <DT_FREQ_M(40)>; /* 40 MHz core clock */
      apb1-prescaler = <1>;
      apb2-prescaler = <1>;
    };
    ```
- Application code optionally uses Zephyr’s clock control API to verify or display the configured clock frequencies at runtime.

## Build & Flash Instructions ⚙️
1. Ensure the device tree is properly configured for your board and desired clock settings.
2. Build the project:
``` bash
west build -b your_board
```
3. Flash the firmware to the board:
``` bash
west flash
```
4. (Optional) Connect a serial terminal to observe any runtime clock information output.

## Test Procedure 🧪
- Built and flashed the application with initial RCC settings.
- Observed system behavior, ensuring the board booted and peripherals functioned as expected.
- Changed clock source and prescaler values in the device tree to test different configurations (e.g., switching from HSI to PLL, adjusting core frequency).
- Used Zephyr’s logging or UART output to print the effective system clock and peripheral clock rates after boot.
- Verified that the board remained stable and that peripherals (e.g., UART, timers) operated at expected speeds after each configuration change.

## Test Results 📊
- The board successfully booted and operated with different clock sources and frequencies as set in the device tree.
- UART baud rate and timer intervals matched expected values for each clock configuration.
- No instability or errors were observed after changing clock sources or prescalers.
- The application confirmed correct clock settings using Zephyr’s clock control API.
- All test cases passed, confirming the ability to configure and verify RCC settings through Zephyr.

## Lessons Learned / Next Steps 🎯
- Gained hands-on experience with STM32 RCC configuration in Zephyr via device tree.
- Understood the relationship between system clock source, prescalers, and peripheral operation.
- Next steps: Experiment with dynamic clock switching at runtime and explore low-power clock modes.

## References 📚
- [Zephyr STM32 RCC Binding Documentation][1]
- [Zephyr STM32H7 RCC Binding Documentation][2]
- [Nordic Zephyr STM32 RCC Docs][8]
