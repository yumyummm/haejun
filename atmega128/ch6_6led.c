#include <avr/io.h>
#include <util/delay.h>


int main()
{
    unsigned char switchFlag = 0;
    DDRC = 0x0F; // PORTC의 하위 4비트를 출력으로 설정
    PORTE = _BV(2); // 풀업 설정

    while(1)
    {
        if (PINE >> 2) // 스위치 입력 확인
        {
            switchFlag = PINE >>2;
        }
        if(!(switchFlag))
        {
            PORTC ^= 0x0F; // 1번 비트 반전
        }

        // PORTC ^= 0x01; // 1번 비트 반전
        // _delay_ms(1000); // 1초 대기
    
    }
    
    return 0;
}