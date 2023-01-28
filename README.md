# Simplest AVR projects

Those projects aim to (at least they try to) be the smallest and simplest ones possible for the
Microchip's (formerly Atmel) [ATmega328P](https://www.microchip.com/en-us/product/ATmega328P)
and [ATtiny85](https://www.microchip.com/en-us/product/ATtiny85) microcontrollers, both pretty
popular among the hobbyist community. They can be freely used as a basis for bigger, more
elaborated, projects.

The projects are intended to be built on a GNU/Linux environment; [see below](#environment). To
build on Windows, a tool such as [MinGW-w64](https://www.mingw-w64.org/), [MSYS2](https://www.msys2.org/)
or [Cygwin](http://cygwin.com/) is required.

## Content

This repo is comprised of two projects, one for ATmega328P and the other for ATtiny85, each one in
separated directories. Each project dir. contains:

 - A single C source file (`main.c`). What it does is just disable ADC and other units for power
   saving, blink a LED connected to a pin for 3 times and then power the uC down.

 - A GNU makefile. Running `make` or `make all` will only compile the source and generate a `.hex`
   file; to burn down the `.hex` onto the microcontroller, `make install` must be issued.

## Environment

The softwares used to compile the codes, "extract" from the binary ELF the HEX file and write them
onto the ICs were, respectively:

 - `avr-gcc` (GCC) 5.4.0
 - GNU `avr-objcopy` (GNU Binutils) 2.26.20160125
 - `avrdude` version 6.3-20171130
 - OS: Ubuntu 22.04.1 LTS x86-64 GNU/Linux

## Targets

### ATmega328P

The first target is a custom, homebrew board with an ATmega328P running by its internal clock source
at 8MHz. The following is a picture of the board used to test this project, connected to a LED.

![The homemade ATmega328P board](https://raw.githubusercontent.com/rddevitte/simplest-atmega-project/master/img/img1.jpg)

Its bootloader is the [MiniCore one by MCUdude](https://github.com/MCUdude/MiniCore).

To program the chip it was used a FTDI serial-to-USB breakout module. Below is a picture of the
board being programmed.

![The chip being programmed by a FTDI module](https://raw.githubusercontent.com/rddevitte/simplest-atmega-project/master/img/img2.jpg)

### ATtiny85

The second target is an ATtiny85 running at 8MHz in a breadboard. It has no bootloader.

To program the chip it was made a custom shield board to connect to an Arduino, which in its turn
acts as an AVRISP programmer. Below is a picture of the ATtiny chip being programmed.

![The chip connectd to a homemade shield being programmed by an Arduino](https://raw.githubusercontent.com/rddevitte/simplest-atmega-project/master/img/img3.jpg)

The following shows the microcontroller already programmed and running in a breadboard sketch.

![The chip running in a breadboard](https://raw.githubusercontent.com/rddevitte/simplest-atmega-project/master/img/img4.jpg)

## References / Credits

Those projects were mostly inspired by [Mitch Davis' YT playlist on Fundamentals of Microcontrollers](https://www.youtube.com/playlist?list=PLNyfXcjhOAwOF-7S-ZoW2wuQ6Y-4hfjMR).

The low power stuff was based off of [Nick Gammon's material on Power saving techniques for microprocessors](https://www.gammon.com.au/power).
