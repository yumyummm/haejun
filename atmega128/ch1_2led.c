#include <avr/io.h>
#include <util/delay.h>
int main()
{
    while(1)
    {
        DDRC = 0x03; //0011 0,1번을 출력모드로 한다.
        PORTC = 0x0F; //1111 0, 1, 2, 3번을 1(on)으로 출력함. 
        _delay_ms(500);
        
        PORTC = 0x00;
        _delay_ms(500);
    }
    
return 0;
}