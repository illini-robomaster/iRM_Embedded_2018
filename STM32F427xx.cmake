########################################################################
#  Copyright (C) 2018
#  Illini RoboMaster @ University of Illinois at Urbana-Champaign.
#
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program. If not, see <http://www.gnu.org/licenses/>.
########################################################################

include(CMakeForceCompiler)

set(MCU_LINKER_SCRIPT STM32F427IIHx_FLASH.ld)
set(MCU_ARCH cortex-m4)
set(MCU_FLOAT_ABI hard)
set(MCU_FPU fpv4-sp-d16)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)

SET(CMAKE_C_COMPILER_WORKS 1)
SET(CMAKE_C_COMPILER arm-none-eabi-gcc)
SET(CMAKE_CXX_COMPILER arm-none-eabi-g++)

set(COMMON_FLAGS "-mcpu=${MCU_ARCH} -mthumb -mthumb-interwork -mfloat-abi=${MCU_FLOAT_ABI} -ffunction-sections -fdata-sections -g -fno-common -fmessage-length=0 -specs=nano.specs -specs=nosys.specs")

if (MCU_FLOAT_ABI STREQUAL hard)
    set(COMMON_FLAGS "${COMMON_FLAGS} -mfpu=${MCU_FPU} -u _printf_float")
endif ()

set(CMAKE_CXX_FLAGS "${COMMON_FLAGS} -std=c++11")
set(CMAKE_C_FLAGS "${COMMON_FLAGS} -std=gnu99")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,-gc-sections -T ${CMAKE_SOURCE_DIR}/${MCU_LINKER_SCRIPT}")
