# F´ (Fprime) Hello World Project 👋

## Overview 📝
This project is a simple "Hello World" application built using the F´ (Fprime) framework. It serves as an introduction to Fprime’s component-based architecture, build system, and deployment process. The application demonstrates basic component creation, event logging, and command handling within the Fprime environment.

## Environment & Requirements 💻
- **Hardware:** Development PC or supported embedded target (depending on build configuration)
- **Software/OS:** Fprime framework (version used in the project)
- **Toolchain:** Python 3.x, CMake, GCC toolchain appropriate for target platform
- **Dependencies:** Fprime core libraries and tools installed as per official instructions

## Implementation Details 🛠️
- Created a simple Fprime component that outputs "Hello World" on startup.
- Implemented a basic command handler to trigger the "Hello World" message.
- Used Fprime’s event logger to log the message to the console or telemetry output.
- Followed the official Fprime project structure with components, topology, and deployment files.
- Built using Fprime’s build system (`fprime-util` or CMake-based build).
- Source files include component implementation (`HelloWorldComponent.cpp`), header, and configuration files.

## Build & Flash Instructions ⚙️
1. Set up the Fprime environment and dependencies following the official guide.
2. Navigate to the project directory.
3. Build the project:
``` bash
fprime-util build
```
or, if using CMake directly:
``` bash
mkdir build && cd build
cmake ..
make
```

1. Deploy or run the application on your target platform or simulator as configured.

## Test Procedure 🧪
- Built the project successfully without errors.
- Ran the application on the target or simulator.
- Verified that the "Hello World" message was logged to the console or telemetry output on startup.
- Tested the command interface by sending the appropriate command and confirming the message output.
- Checked for any runtime errors or unexpected behavior.

## Test Results 📊
- The application started and logged "Hello World" as expected.
- Commands triggered the message output correctly.
- No build or runtime errors encountered.
- The component behaved as designed, confirming understanding of Fprime basics.

## Lessons Learned / Next Steps 🎯
- Gained initial hands-on experience with Fprime component creation and build process.
- Understood event logging and command handling in Fprime.
- Next steps: Develop more complex components, integrate with Zephyr or hardware targets, and explore Fprime’s telemetry and health monitoring features.

## References 📚
- [Fprime Official Documentation](https://fprime.io/)
- [Fprime Getting Started Guide](https://fprime.io/GettingStarted.html)
- [Fprime GitHub Repository](https://github.com/nasa/fprime)


