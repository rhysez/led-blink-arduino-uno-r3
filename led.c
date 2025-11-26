#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    DDRB = DDRB | (1 << DDB5);

    while (1) {
        // PORTB is now 0010 0000 as result of OR
        PORTB = PORTB | (1 << PORTB5);

        _delay_ms(1000);

        // PORTB has AND applied with an inversed mask (1101 1111)
        // This gives us 0000 0000, resetting PB5 to zero and leaving all other bits unchanged.
        PORTB = PORTB & ~(1 << PORTB5);

        _delay_ms(1000);
    }
}
