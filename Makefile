CC=avr-gcc
OBJCOPY=avr-objcopy
RM=rm -f
UPLOAD=avrdude -F -V
PROTOCOL=arduino
BAUD=115200
PART=ATMEGA328P
DEV=/dev/cu.usbmodem1421
MCU=atmega328p

CFLAGS=-Os -g -DF_CPU=16000000L -DARDUINO=10610 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR -flto -mmcu=$(MCU)

PROG=motor

$(PROG).elf:
	$(CC) $(CFLAGS) -c -o $(PROG).o $(PROG).c 	
	$(CC) $(CFLAGS) $(PROG).o -o $(PROG).elf

clean:
	$(RM) $(PROG).o $(PROG).elf

$(PROG).hex: $(PROG).elf	
	$(OBJCOPY) -O ihex -R .eeprom $(PROG).elf $(PROG).hex

upload: $(PROG).hex
	$(UPLOAD) -c $(PROTOCOL) -p $(PART) -P $(DEV) -b $(BAUD) -U flash:w:$(PROG).hex -C avrdude.conf
	


