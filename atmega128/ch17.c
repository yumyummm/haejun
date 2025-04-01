#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#define NOTE_C4  261
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define REST     0

uint16_t doReMi[8] = { NOTE_C4, NOTE_D4, NOTE_E4, NOTE_C4, NOTE_C4,
    NOTE_D4, NOTE_E4, NOTE_C4, NOTE_E4, NOTE_F4, NOTE_G4,
    NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4,
    NOTE_G4, NOTE_F4, NOTE_E4, NOTE_C4, REST};
uint8_t piano = 0;

int main()
{
    // PB7 핀 피에조 -> OCR1C
    DDRB = _BV(PB7); // 7번 출력 설정

    TCCR1A = _BV(COM1C1) | _BV(WGM11);            // com 10 -> clear on compare
    TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS00); // 분주비 1, fast PWM

    sei(); // 전역 인터럽트 허용

    while (1)
    {
        ICR1 = 14745600 / doReMi[piano]; // 주파수 만큼 duty cycle을 설정 하겠다.
        OCR1C = ICR1 / 2;                // 절반을 on 시키겠다.
        piano++;
        if (piano > 7)
            piano = 0;
        _delay_ms(300);
    }
    return 0;
}