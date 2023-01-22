
/* ATtiny85 operating in 8MHz (for _delay_ms()) */
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
    ADCSRA = 0x00; /* could also be: ADCSRA &= ~_BV(ADEN); */

    /* Disable all unused peripherals for power saving */
    power_all_disable();
    /* For ATtiny85 it must be equivalent to:
       PRR = _BV(PRTIM1) | _BV(PRTIM0) | _BV(PRUSI) | _BV(PRADC); */

    /* Set up all I/O pins as input except PORTB0 as output */
    DDRB = _BV(DDB0);

    /* Enable internal pull-up on input pins
       in order to not keep them floating */
    PORTB = 0x3E; /* 0b00111110 */

    /* Set 'power down' sleep mode */
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();

    /* (Re)enable interrupts */
    sei();

    /* Blink LED on PORTB0 for 3 times */
    for (int i = 0; i < 3; i++) {
        PINB |= _BV(PINB0);
        _delay_ms(500);
        PINB |= _BV(PINB0);
        _delay_ms(500);
    }

    /* Put ATtiny85 CPU to sleep */
    sleep_cpu();

    while (1) {}
}
