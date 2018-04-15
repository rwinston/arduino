#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 2000

void delay_ms(uint16_t count) {
      while(count--) {
              _delay_ms(1);
      }
}

int main(void) {
    DDRB = _BV(DDB1);
    int j = 0;

    while (1) {
            PORTB = _BV(PORTB1);
            delay_ms(2500);
            PORTB = ~_BV(PORTB1);
            delay_ms(1000);
    }
    
}
