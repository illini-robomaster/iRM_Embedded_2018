# How To Flash Binaries On To the MCU
see [How to compile this project](https://github.com/illini-robomaster/iRM_Embedded_2018/blob/master/tutorials/COMPILE.md) before trying to flash

## Dependency
* [st-link](https://github.com/texane/stlink) - just follow their tutorial to install this tool

## Flash Commands
1. After compiling the project, you should see a `.bin` file generated under either `iRM_Embedded_2018` or `iRM_Embedded_2018/build`
2. run `st-flash write <path to your binary> 0x8000000`
	
	e.g. `st-flash write infantry1.bin 0x8000000`
	
3. **important**: unplug your st-link before starting up the robot, or your code may not be excuted.