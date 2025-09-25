#
# Copyright (c) 2021 Nordic Semiconductor ASA
#
# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
#
cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(Beluga)

# NORDIC SDK APP START
file(GLOB SOURCE "src/*.c")
set(SERIAL_SRC
        src/serial/comms.c
        src/serial/comms_uart.c)
file(GLOB DECAWAVE_SRC "DecaDriver/src/*.c")
# Added for debugging why the debugger wont work
# add_compile_options(-g -O0)


add_compile_options(-g -ggdb -fno-omit-frame-pointer -fno-inline -fno-optimize-sibling-calls)

include_directories(include DecaDriver/include)

target_sources(app PRIVATE
    ${SOURCE}
    ${SERIAL_SRC}
    ${DECAWAVE_SRC}
)
target_sources_ifdef(CONFIG_MCUMGR_TRANSPORT_COMMS app PRIVATE
        src/serial/smp_comms.c
        src/serial/serial_util.c
)
# NORDIC SDK APP END
