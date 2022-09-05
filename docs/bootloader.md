
# Bootloader
Bootloader is software that enables firmware uploading through a different interface than the default interface for the used microprocessor.
A bootloader is used because it makes it easier to update the firmware and often makes it possible to update the firmware in a production 
deployment without the need to connect additional specialized circuits.

There are several different bootloaders that have different features or use a different interface. Because MLAB LABDUINO is a professional 
replacement for Arduino, we use the [MightyCore](https://github.com/MCUdude/MightyCore) bootloader by default. 


## MightyCore
### Bootloader flashing
You need an appropriate programmer to load the bootloader. For bootloader uploading it is recommended to use the [MLAB ATprogISPUSB02A](https://www.mlab.cz/module/ATprogISPUSB02A/) programmer compatible with the STK500 protocol.

> This procedure assumes that you are installing with Linux operating software and that you have the USB rights set correctly.

#### Connection 
In the first step, we will connect the programmer board to the ATmega MCU board with SPI wires. On both modules, required pins are all connected to a separate header marked as `AVR ISP`/`ATMEL ISP`. Pins are 1:1, 1st pin is marked with small symbol of `1`. 
