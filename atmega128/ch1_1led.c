#include <avr/io.h>
#include <util/delay.h>
int main()
{
    while(1){
    PORTC = 0X00;
    _delay_ms(1000);
    PORTC = 0X0F;
    _delay_ms(1000);
}
return 0;
}