
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
    ADCSRA = 0x00; /* could also be: ADCSRA &= ~_BV(ADEN) */

    /* Disable all unused peripherals for power saving */
    power_all_disable();
    /* In ATmega328P this must be equivalent to:
       PRR = _BV(PRTWI)  | _BV(PRTIM2) | _BV(PRTIM0)   |
             _BV(PRTIM1) | _BV(PRSPI)  | _BV(PRUSART0) | _BV(PRADC); */

    /* Set up ports B, C and D as input low (except PORTB6 as output) */
    DDRB = 0x40; /* 0b01000000 */
    DDRC = 0x00;
    DDRD = 0x00;

    /* Enable internal pull-up on input pins
       in order to not keep them floating */
    PORTB = 0xBF; /* 0b10111111 */
    PORTC = 0x7F; /* 0b01111111 */
    PORTD = 0xFF; /* 0b11111111 */

    /* Set 'power down' sleep mode */
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();

    /* (Re)enable interrupts */
    sei();

    /* Blink LED on PORTB6 for 3 times */
    for (int i = 0; i < 3; i++) {
        PINB |= _BV(PINB6);
        _delay_ms(500);
        PINB |= _BV(PINB6);
        _delay_ms(500);
    }

    /* Put ATmega328P CPU to sleep */
    sleep_cpu();

    while (1) {}
}
