#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 2000

void delay_ms(uint16_t count) {
      while(count--) {
              _delay_ms(1);
      }
}

int main(void) {
    DDRB = _BV(DDB5) | _BV(DDB4);
    int j = 0;

    while (1) {

        for (j = 500; j > 0; j-=10) {
            PORTB = _BV(PORTB4);
            delay_ms(j);
            PORTB = ~_BV(PORTB4);

            PORTB = _BV(PORTB5);
            delay_ms(j);
            PORTB = ~_BV(PORTB5);
        }

        _delay_ms(BLINK_DELAY_MS);
    }
    
}
