CC=avr-gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -Os -nostdlib -mmcu=atmega328p
RM=rm -vf

FTDI ?= /dev/ttyUSB0

OBJS=main.o

.PHONY: all
all: $(OBJS) main.elf main.hex

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

main.elf: $(OBJS)
	$(CC) $(CFLAGS) $< -o $@

main.hex: main.elf
	avr-objcopy -O ihex -j .text -j .data $^ $@

.PHONY: install
install: main.hex
	avrdude -v -patmega328p -carduino -P$(FTDI) -b38400 -D -U flash:w:$^:i

.PHONY: clean
clean:
	@$(RM) *.o *.elf

.PHONY: mrproper
mrproper: clean
	@$(RM) *.hex
