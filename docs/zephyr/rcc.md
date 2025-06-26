# Zephyr STM32 RCC (Clock Configuration) Application 🕰️

## Overview 📝
This application demonstrates configuring the Reset and Clock Controller (RCC) on an STM32 board using Zephyr RTOS. The goal was to understand and control the system clock source, core frequency, and peripheral bus prescalers via Zephyr’s device tree and clock control APIs.

## Implementation Details 🛠️
- Modified the device tree to configure the RCC node:
  - Selected the system clock source (e.g., HSE, HSI, or PLL)
  - Set the core clock frequency using the `clock-frequency` property
  - Configured AHB and APB bus prescalers for desired clock domains
- The configuration followed Zephyr’s STM32 RCC binding documentation[1][2][8]:
  - Example:
    ```bash
      &clk_hsi{
          status = "okay";
      };

      &pll{
          clocks = < &clk_hsi >;
          mul-n = < 0x1f >;
      };

      &rcc{
          clocks = < &hsi >;
          clock-frequency = < 0x3d09000 >;
          d1cpre = < 0x1 >;
          hpre = < 0x2 >;
          d1ppre = < 0x1 >;
          d2ppre1 = < 0x1 >;
          d2ppre2 = < 0x1 >;
          d3ppre = < 0x1 >;
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

## Test Procedure 🧪
- all configuration are got using DT_DROP Marco and then are sent to Console via printk function

## Test Results 📊
- The log seen in the console confirms the correctness of the configs by app.overlay.

## References 📚
- [Zephyr STM32 RCC Binding Documentation][1]
- [Zephyr STM32H7 RCC Binding Documentation][2]
- [Nordic Zephyr STM32 RCC Docs][8]
