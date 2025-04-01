
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

volatile uint8_t ledData = 0x00;
uint8_t timer0Cnt = 0;

ISR(TIMER0_OVF_vect);

int main(void)
{
    DDRC = 0x0F;

    TCCR0 = 0x07;
    // TCNT0 = 112; 생략가능
    TIMSK = 0x01;
    // TIFR |= _BV(TOV0); 생략가능

    sei();
    while (1)
    {
        if (timer0Cnt == 100)
        {
            ledData++;
            if (ledData > 0x0F)
                ledData = 0;
            timer0Cnt = 0;
        }
        PORTC = ledData;
    }
}

ISR(TIMER0_OVF_vect)
{
    cli();
    TCNT0 = 112; // 113, 114 .... 255 .. 144-> 0.0025 초
    timer0Cnt++;
    sei();
}



// #include <avr/io.h>
// #include <avr/interrupt.h>

// volatile uint8_t ledDate = 0x00;
// uint8_t timer0Cnt = 0;
// ISR(TIMER0_OVF_vect);

// int main()
// {

//     DDRC = 0x0F; 
//     TCCR0 = 0x07;
//     TCNT0 = 112;
//     TIMSK = 0x01;
//     TIFR |= _BV(TOV0);

//     sei();       
//     while (1)
//     {
//         if(timer0Cnt == 100)
//     {
//         ledDate++;
//         if(ledDate >0x0F)
//             ledDate = 0;
//             timer0Cnt =0;
//         PORTC = ledDate;
        
//     }

//     return 0;
// }
// }


// ISR(TIMER0_OVF_vect)
// {
//     cli();
//     TCNT0 = 112; //113, 114 ... 255까지 가면 오버플로우 일어남. 255-112 =144- 0.0025sec / 
//     timer0Cnt++;
    
    
//     sei();// ADC 변환 값 저장 (0 ~ 1023)
// }
// #include <avr/io.h>
// #include <avr/interrupt.h>

// volatile uint8_t ledDate = 0x00;
// uint8_t timer0Cnt = 0;
// ISR(TIMER0_OVF_vect);

// int main()
// {

//     DDRC = 0x0F; 
//     TCCR0 = 0x07;
//     TCNT0 = 112;
//     TIMSK = 0x01;
//     TIFR |= _BV(TOV0);

//     sei();       
//     while (1)
//     {
//         if(timer0Cnt == 100)
//     {
//         ledDate++;
//         if(ledDate >0x0F)
//             ledDate = 0;
//             timer0Cnt =0;
//         PORTC = ledDate;
        
//     }

//     return 0;
// }
// }


// ISR(TIMER0_OVF_vect)
// {
//     cli();
//     TCNT0 = 112; //113, 114 ... 255까지 가면 오버플로우 일어남. 255-112 =144- 0.0025sec / 
//     timer0Cnt++;
    
    
//     sei();// ADC 변환 값 저장 (0 ~ 1023)
// }
