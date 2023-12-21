#!/bin/bash
# Linux Shell Script
# ATprogISPUSB02A fash script
# Uses DAPA (Direct Parallel Access) Programmer
read -p "WARNING: This procedure enables external clock. Make sure if a 8MHz crystal is installed on MCU module with ATmega1284P and connect the MCU module to the programmer ATprogISPUSB02A" -n1 -s
avrdude -v -patmega1284p -cstk500 -B 50 -P $1 -e -Ulock:w:0xff:m -Uefuse:w:0xff:m -Uhfuse:w:0b11010110:m -Ulfuse:w:0xf7:m
avrdude -v -patmega1284p -cstk500 -B 50 -P $1 -e -U flash:w:optiboot_flash_atmega1284p_UART1_57600_8000000L_B0_BIGBOOT.hex:a
echo "If none errors above - Please connect the USB232R01B module to bootload the LABduino via Arduino software."



