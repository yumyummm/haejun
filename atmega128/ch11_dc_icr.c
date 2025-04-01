
#include <avr/delay.h>
#include <avr/io.h>


int main(void)
{
    DDRD = _BV(PD4) | _BV(PD5);// M1 출력 설정
    DDRB = _BV(PB5); // M1 enable 핀

    TCCR1A = _BV(COM1A1) | _BV(WGM11);
    TCCR1B = _BV(CS11) | _BV(WGM12) | _BV(WGM13);

    ICR1 = 800; //2Mhz : 1초 == 800Hz : x초 ... 2500Hz //듀티사이클의 전체 길이가 얼마가 되는지를 논하는 건데 중요한 의미는 없음.
    OCR1A = 560; //800번을 카운트하는데 560번까지 5V를 주겠다(= PWM의 듀티사이클을 70%로 만들겠다)

    while (1)
    {
        PORTD = _BV(PD4); // M! 정회전
        PORTB = _BV(PB5); // M1 회전
        _delay_ms(500);
        PORTB &= ~_BV(PD4);
        PORTD = _BV(PD5); // M! 정회전 - PD4는 해당 코드로 속도에 영향을 받을 것 같지만, PD5는 과연?
        PORTB = _BV(PB5);
        _delay_ms(500); 
    }
    

    return 0;
}