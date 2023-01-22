CC=avr-gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -Os -nostdlib -mmcu=attiny85
RM=rm -vf

DEVICE ?= /dev/ttyACM0

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
	avrdude -v -p t85 -c avrisp -P$(DEVICE) -b 19200 -D -U flash:w:$^:i

.PHONY: clean
clean:
	@$(RM) *.o *.elf

.PHONY: mrproper
mrproper: clean
	@$(RM) *.hex
