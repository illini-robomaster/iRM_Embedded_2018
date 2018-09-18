# How To Debug This Project

## Debug Print
simply by enabling the debug flag when compiling the code - `make infantry1 DEBUG=1` - you can see all the debug message printed to a serial monitor if you wire up UART6 correctly to your computer

## ARM GDB

### Dependency
* [ARM Toolchain](https://github.com/illini-robomaster/iRM_Embedded_2018/blob/master/tutorials/ARM_TOOLCHAIN.md)
* [openocd](http://openocd.org/)

### Debug Steps
1. run `openocd -f iRM_Embedded_2018/<st-link-version>.cfg` in your terminal, where `<st-link-version>` can be choosen from `[st-link-v2.cfg, st-link-v2-1.cfg]` depending on the version of your st-link program uploader.
2. in a new terminal window run `arm-none-eabi-gdb <your bin file>`
3. inside gdb run `target extended-remote :3333` or `tar ext :3333` in short, to connect to your `openocd` server
4. run `load` inside arm-gdb will flash the program onto the chip
5. just like regular `gdb` debugger, commands like `continue`, `run`, `break`, `watch`, `next`, `step` all works the same way.