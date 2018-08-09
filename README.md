# Illini RoboMaster Embedded Control 2018

This repository hosted codes for low level hardware protocol & control algrithms implemented on the **DJI RoboMaster 2018 Type A Control Board** with a STM32F427 chip as its main MCU.

**Note:** since this repository contains git submodules, you will have to clone this repo with `--recursive` tag to obtain all source codes:

```
git clone --recursive https://github.com/illini-robomaster/iRM_Embedded_2018.git
```

## Important File Structure

* [Applications](https://github.com/illini-robomaster/iRM_Embedded_Libraries) - User Level Generic Libraries (as a git submodule)

* [Configs](https://github.com/illini-robomaster/iRM_Embedded_2018/tree/master/Configs) - Board Specific / Robot Specific configuration headers

* [Tasks](https://github.com/illini-robomaster/iRM_Embedded_2018/tree/master/Tasks) - High level customized control logics built on top of our Generic Libraries

* [STM32F427xx.cmake](https://github.com/illini-robomaster/iRM_Embedded_2018/blob/master/STM32F427xx.cmake) - CMake Toolchain File

* iRM\_Embedded\_2018.ioc - Hardware Pin Definitions for STM32CubeMX to generate driver level source codes

* HAL / Driver Level Libs - Should NOT Be Modified By Hand
	* Inc / Src - Header & source files for HAL libraries
	* Middlewares - FreeRTOS, FatFS, and other 3rd party libraries
	* Drivers - Low Level Drivers

## IDE Choices
* CLion - recommanded for under experienced coder
	- [x] CMake Integration
	- [x] Auto Completion

* vim - recommended by Alvin. Mouse free editing experience helps achieve maximum productivity
	- [ ] CMake Integration
	- [x] Auto Completion

* atom / sublime text / VSCode / etc - suit yourself
	- [ ] CMake Integration
	- [ ] Auto Completion

## Dependency
* Unix Based Environment - MacOS / Linux

* Build Essentials
	* Cmake 3.11.0 or higher
	* ARM Toolchain

* [stlink](https://github.com/texane/stlink) - optional for single command flashing

* [OpenOCD]() - optional for debug purposes

## Tutorials
* [How to install ARM Toolchain](https://github.com/illini-robomaster/iRM_Embedded_2018/blob/master/tutorials/ARM_TOOLCHAIN.md)
* [How to compile the code](https://github.com/illini-robomaster/iRM_Embedded_2018/blob/master/tutorials/COMPILE.md)
* [How to flash binary files onto the micro controller](https://github.com/illini-robomaster/iRM_Embedded_2018/blob/master/tutorials/FLASH.md)
* [How to use gbd with on chip debugger](https://github.com/illini-robomaster/iRM_Embedded_2018/blob/master/tutorials/DEBUG.md)
