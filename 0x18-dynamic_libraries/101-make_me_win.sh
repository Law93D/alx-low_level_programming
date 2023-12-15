#!/bin/bash
wget -P .. https://raw.githubusercontent.com/Law93D/alx_low_level_programming/master/0x18-dynamic_libraries/libjackpot_win.so
export LD_PRELOAD="$PWD/../libjackpot_win.so"
