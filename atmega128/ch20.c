//PWM 설정을 하고 Fast PWM, timer3, COM3A
//FND설정을 함
// 버저를 이용한 프로그램 만들기
//버튼 인터럽트로 버튼 활성화 PE4, PE5, PE6, PE7
// 버튼에 맞는 소리를 2초동안 출력합니다
//FND에 버튼이 눌린 번호를 출력합니당!
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 16000000UL

// === 음계 주파수 정의 ===
#define C4  261
#define D4  294
#define E4  330
#define F4  349

// === FND 숫자 테이블 (common cathode 기준) ===
uint8_t fnd_digits[] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07  // 7
};

// === 전역 변수 ===
volatile uint16_t current_freq = 0;
volatile uint8_t display_number = 0;
volatile uint8_t play_sound_flag = 0;

// === Timer3 Fast PWM 설정 (OC3A = PE3) ===
void init_pwm_timer3() {
    DDRE |= (1 << PE3); // OC3A 출력 설정
    TCCR3A = (1 << COM3A1) | (1 << WGM31); // Fast PWM, non-inverting
    TCCR3B = (1 << WGM33) | (1 << WGM32) | (1 << CS30); // Fast PWM mode 14, no prescaler
}

// === 외부 인터럽트 설정 (INT4 ~ INT7: PE4 ~ PE7) ===
void init_external_interrupts() {
    DDRE &= ~((1 << PE4) | (1 << PE5) | (1 << PE6) | (1 << PE7)); // 버튼 입력
    PORTE |= (1 << PE4) | (1 << PE5) | (1 << PE6) | (1 << PE7);   // 내부 풀업 활성화
    EICRB = 0xAA; // ISCx1 = 1, ISCx0 = 0 → 하강 엣지 트리거
    EIMSK = 0xF0; // INT4 ~ INT7 활성화
}

// === 주파수에 따른 PWM 출력 설정 ===
void play_tone(uint16_t freq) {
    ICR3 = (F_CPU / freq) - 1;
    OCR3A = ICR3 / 2; // 50% 듀티비
    play_sound_flag = 1;
}

// === 소리 정지 ===
void stop_tone() {
    OCR3A = 0;
    play_sound_flag = 0;
}

// === 메인 함수 ===
int main(void) {
    DDRA = 0xFF; // FND 출력용 포트
    init_pwm_timer3();
    init_external_interrupts();
    sei(); // 전역 인터럽트 활성화

    while (1) {
        if (play_sound_flag) {
            PORTA = fnd_digits[display_number];
            _delay_ms(2000);
            stop_tone();
            PORTA = 0x00; // FND 끄기
        }
    }
    return 0;
}

// === 인터럽트 핸들러 (각 버튼 별 ISR) ===
ISR(INT4_vect) {
    play_tone(C4);
    display_number = 4;
}

ISR(INT5_vect) {
    play_tone(D4);
    display_number = 5;
}

ISR(INT6_vect) {
    play_tone(E4);
    display_number = 6;
}

ISR(INT7_vect) {
    play_tone(F4);
    display_number = 7;
}
