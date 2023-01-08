
/* ATmega328P operating in 8MHz (for _delay_ms()) */
#define F_CPU 8000000UL

#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/power.h>
#include <avr/sleep.h>
#include <util/delay.h>

void _start()
{
    /* Clear interrupts */
    cli();

    /* Shut down ADC */
    ADCSRA = 0; /* could also be: ADCSRA &= ~_BV(ADEN) */

    /* Disable all unused units (timers, SPI, I2C) for power saving */
    power_all_disable();

    /* Set up ports B, C and D as input low (except PORTB6) */
    DDRB = 0x40; PORTB = 0;
    DDRC = 0; PORTC = 0;
    DDRD = 0; PORTD = 0;

    /* Set 'power down' sleep mode */
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();

    /* (Re)enable interrupts */
    sei();

    /* Blink LED on PORTB6 5 times */
    for (int i = 0; i < 5; i++) {
        PINB |= _BV(PINB6);
        _delay_ms(150);
        PINB |= _BV(PINB6);
        _delay_ms(150);
    }

    /* Put ATmega328P CPU to sleep */
    sleep_cpu();

    while (1) {}
}
