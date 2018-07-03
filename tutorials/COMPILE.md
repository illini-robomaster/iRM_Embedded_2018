# How To Compile This Project

### Prerequisites
* see [How to install ARM Toolchain](https://github.com/illini-robomaster/iRM_Embedded_2018/blob/master/tutorials/ARM_TOOLCHAIN.md) first
* make sure you have **CMake 3.11.10 or later** installed

## Compile Method 1 - Makefile
1. Go to your project root directory `<path to your iRM_Embedded_2018/>` in your terminal
2. run `make <target>` and replace `<target>` with the robot type to compile codes for a specific type of robot  
	e.g. run `make infantry1` or `make engineering`
3. you can add flags for debug or testing purposes  
	e.g. `make infantry1 DEBUG=1 RUNTEST=1`
4. if you see a `.elf` file (e.g. `infantry1.elf` or `engineering.elf`) generated under project root directory, than it means the compilation is successful and the binary file is ready to be flashed onto the MCU.
5. for a more detailed documentation, run `make how` to see all available make options.

## Compile Method 2 - CMake - For Advanced Users
1. Go to your project root directory in your terminal
2. run the following command to build for infantry robot
	
	```
	mkdir build && cd build
	cmake -DCMAKE_TOOLCHAIN_FILE=STM32F427xx.cmake -DINFANTRY1=ON -DDEBUG=OFF -DRUNTEST=OFF ..
	make -j
	```
	
3. you should see a `iRM2018.elf` generated under your `build/` directory if the compilation is successful.
4. to see a full list of cmake options, run `cmake -L ..`

Note: before switching to building a different robot, your should clean up your build directory by `rm -rf build/`

## What's Next?
[How To Flash These Compiled Binaries](https://github.com/illini-robomaster/iRM_Embedded_2018/blob/master/tutorials/COMPILE.md)