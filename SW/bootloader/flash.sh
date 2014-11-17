# Linux Shell Script
# ATprogISPUSB02A fash script
# Uses DAPA (Direct Parallel Access) Programmer
read -p "WARNING: This procedure enables external clock. Make sure if a 16MHz crystal is installed on MCU module with ATmega328 and connect the MCU module to the programmer ATprogISPUSB02A"
avrdude -F -p atmega328P -P /dev/ttyUSB1 -c stk500v2 -B 50 -v -U efuse:w:0x05:m -U lfuse:w:0xff:m -U hfuse:w:0xda:m 
avrdude -F -p atmega328P -P /dev/ttyUSB1 -c stk500v2 -B 50 -U flash:w:ATmegaBOOT_168_atmega328.hex:a 
echo "If none errors above - Please connect the USB232R01B module to bootload the LABduino via Arduino software."
