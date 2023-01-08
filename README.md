# Simplest ATmega (megaAVR) project

This project aims to (at least it tries to) be the smallest and simplest one possible for the
Microchip's (formerly Atmel) [ATmega328P](https://www.microchip.com/en-us/product/ATmega328P)
microcontroller, but it can be for every other one such as the [ATtiny85](https://www.microchip.com/en-us/product/ATtiny85),
both of them pretty popular among the hobbyist community.

The project is intended to be run on a GNU/Linux environment; [see below](#environment).

## Content

The project comprises of:

 - A single C source file (`main.c`). What it does is just disable ADC and other units for power
   saving, blink an LED connected at pin B6 for 5 times and then power the uC down.
 - A GNU makefile. Running `make` or `make all` will only compile the source and generate a `.hex`
   file; to burn down the `.hex` onto the microcontroller, `make install` must be issued.

## Environment

The software used for compiling the code and write it onto the chip was:

 - `avr-gcc` (GCC) 5.4.0
 - GNU `avr-objcopy` (GNU Binutils) 2.26.20160125
 - `avrdude` version 6.3-20171130
 - OS: Ubuntu 22.04.1 LTS x86-64 GNU/Linux

## Target

The target is a custom, homebrew board with an ATmega328P running by its internal clock source at
8MHz. The following is a picture of the board used to test this project.

![The homemade ATmega328P board](https://raw.githubusercontent.com/rddevitte/simplest-atmega-project/master/img/img1.jpg)

Its bootloader is the [MiniCore one by MCUdude](https://github.com/MCUdude/MiniCore).

To program the chip it was used a FTDI serial-to-USB breakout module. Below is a picture of the
board being programmed.

![The chip being programmed by a FTDI module](https://raw.githubusercontent.com/rddevitte/simplest-atmega-project/master/img/img2.jpg)

## References / Credits

This modest project was mostly inspired by [Mitch Davis' YT playlist on Fundamentals of Microcontrollers](https://www.youtube.com/playlist?list=PLNyfXcjhOAwOF-7S-ZoW2wuQ6Y-4hfjMR).

The low power stuff was based off of [Nick Gammon's material on Power saving techniques for microprocessors](https://www.gammon.com.au/power).
