# Linux Shell Script
# ATprogISPUSB02A fash script
# Uses DAPA (Direct Parallel Access) Programmer
read -p "WARNING: This procedure enables external clock. Make sure a crystal is connected to the MCU and connect a programmer to the ATprogISPUSB02A"
avrdude -F -p atmega328P -P /dev/ttyUSB0 -c stk500v2 -B 50 -v -U efuse:w:0x05:m -U lfuse:w:0xff:m -U hfuse:w:0xda:m 
avrdude -F -p atmega328P -P /dev/ttyUSB0 -c stk500v2 -B 50 -U flash:w:ATmegaBOOT_168_atmega328.hex:a 
echo "If none errors above - Please connect the USB232R01B module to bootload the LABduino via Arduino software."
