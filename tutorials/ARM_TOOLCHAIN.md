# How To Install ARM Toolchain

1. go to the [official download page](https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads) for ARM Toolchain
2. checkout version **6-2017-q2-update** and download the pre-built files according to your operating system.
3. decompress it to your `~` (home) directory and find an absolute path to the `bin/` directory.

	In my case: `/Users/alvin/gcc-arm-none-eabi-6-2017-q2-update/bin`.
	
4. Add the following line (replace `<path>` with the path your found in step 3) to `~/.bashrc` for bash users or `~/.zshrc` for zsh users.

```
export PATH=<path>:$PATH
```