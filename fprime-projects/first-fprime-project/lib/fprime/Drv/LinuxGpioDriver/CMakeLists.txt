####
# F prime CMakeLists.txt:
#
# SOURCE_FILES: combined list of source and autocoding files
# MOD_DEPS: (optional) module dependencies
#
####
if (NOT FPRIME_USE_STUBBED_DRIVERS)
    restrict_platforms(Linux)
endif()

if(FPRIME_USE_STUBBED_DRIVERS)
    set(SOURCE_FILES
        "${CMAKE_CURRENT_LIST_DIR}/LinuxGpioDriver.fpp"
        "${CMAKE_CURRENT_LIST_DIR}/LinuxGpioDriverCommon.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/LinuxGpioDriverStub.cpp"
    )
    register_fprime_module()
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(SOURCE_FILES
        "${CMAKE_CURRENT_LIST_DIR}/LinuxGpioDriver.fpp"
        "${CMAKE_CURRENT_LIST_DIR}/LinuxGpioDriverCommon.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/LinuxGpioDriver.cpp"
    )
    register_fprime_module()
endif()


