# Zephyr Threading Demonstration Application 🧵

## Overview 📝
This application demonstrates the use of threading (multitasking) in Zephyr RTOS on an STM32 board. The goal was to create multiple threads, assign them different priorities, and observe their concurrent execution using simple tasks such as toggling LEDs or printing messages over UART. This exercise helps understand Zephyr’s thread API, scheduling, and synchronization primitives.

## Environment & Requirements 💻
- **Hardware:** STM32 development board (e.g., STM32F4 series)
- **Software/OS:** Zephyr RTOS (version as used in the project)
- **Toolchain:** `arm-none-eabi-gcc`, `west`
- **Dependencies:** Zephyr kernel, device tree configuration for required peripherals (e.g., GPIO, UART)

## Implementation Details 🛠️
- Defined two or more threads using Zephyr’s `K_THREAD_DEFINE()` macro or by manually creating thread stacks and calling `k_thread_create()`[1][2].
- Assigned different priorities to each thread to observe the effects of Zephyr’s priority-based preemptive scheduler.
- Each thread performed a simple task, such as:
  - Thread 1: Toggled an LED at a fixed interval.
  - Thread 2: Printed a message over UART at a different interval.
- Used `k_sleep()` to control timing within each thread.
- Optionally demonstrated synchronization using kernel objects like semaphores or mutexes.
- Main code organized in `src/main.c`, with thread entry functions defined as static functions.

## Build & Flash Instructions ⚙️
1. Ensure the device tree is properly configured for any peripherals used (e.g., LED, UART).
2. Build the project:
``` bash
west build -b your_board
```
3. Flash the firmware to the board:
``` bash
west flash
```
4. Open a serial terminal to observe UART output (if used).

## Test Procedure 🧪
- Flashed the application using `west flash`.
- Observed the behavior of the LEDs and/or UART output.
- Verified that each thread performed its task at the expected interval.
- Changed thread priorities to observe any changes in execution order or timing.
- (Optional) Introduced synchronization primitives (e.g., semaphore) and verified correct inter-thread communication or resource sharing.
- Monitored for any unexpected blocking or starvation.

## Test Results 📊
- Multiple threads executed concurrently as expected.
- LED toggling and UART message printing occurred at their respective intervals.
- Changing thread priorities affected which thread preempted the other, as expected for Zephyr’s scheduler.
- When synchronization primitives were used, threads coordinated access to shared resources correctly.
- No deadlocks, starvation, or crashes observed during testing.

## Lessons Learned / Next Steps 🎯
- Learned how to create, configure, and manage threads in Zephyr.
- Gained understanding of Zephyr’s preemptive scheduling and thread priorities.
- Next steps: Explore thread synchronization in more depth (e.g., message queues, events), experiment with dynamic thread creation and termination, and test real-time response with hardware interrupts.

## References 📚
- [Zephyr Kernel Thread API Documentation][1]
- [Zephyr Threading Example (Official Sample)][2]
- [Zephyr Synchronization Primitives][3]
- [Zephyr RTOS Concepts Guide][4]

[1]: https://docs.zephyrproject.org/latest/kernel/threads/index.html  
[2]: https://github.com/zephyrproject-rtos/zephyr/tree/main/samples/basic/threads  
[3]: https://docs.zephyrproject.org/latest/kernel/synchronization/index.html  
[4]: https://docs.zephyrproject.org/latest/kernel/index.html  
