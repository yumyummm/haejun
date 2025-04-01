// #define F_CPU 16000000UL
// #include <avr/io.h>
// #include <util/delay.h>

// // ----- UART 설정 상수 -----
// #define BAUD 9600
// #define MYUBRR (F_CPU/16/BAUD - 1)

// // ----- I2C LCD 주소 (PCF8574 기반 예시) -----
// #define I2C_LCD_ADDR  0x27  // 실제 모듈 주소에 맞게 수정

// // LCD 명령 상수
// #define LCD_CMD_CLEAR 0x01
// #define LCD_CMD_HOME  0x02
// #define LCD_CMD_MODE  0x06 // 자동 커서증가
// #define LCD_CMD_OFF   0x08
// #define LCD_CMD_ON    0x0C // 화면 ON, 커서 OFF
// #define LCD_CMD_FUNC  0x28 // 4비트, 2라인, 5x8 폰트

// // PCF8574 핀 배치 (가정)
// // b7=D7, b6=D6, b5=D5, b4=D4, b3=BL, b2=EN, b1=RW, b0=RS
// #define LCD_BIT_RS  0
// #define LCD_BIT_RW  1
// #define LCD_BIT_EN  2
// #define LCD_BIT_BL  3

// // ----- 전역 변수: PCF8574에 쓸 현재 데이터 보관 -----
// static uint8_t g_lcd_port = 0x00;

// // ========================= UART 함수 =========================
// void uart_init(void) {
//     UBRR0H = (MYUBRR >> 8);
//     UBRR0L = MYUBRR;
//     UCSR0B = (1 << RXEN0) | (1 << TXEN0);  // 수신/송신 활성화
//     UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8비트 데이터
// }

// unsigned char uart_receive(void) {
//     while (!(UCSR0A & (1 << RXC0))); // 데이터 수신 대기
//     return UDR0;
// }

// // ========================= I2C(TWI) 함수 =========================
// void i2c_init(void) {
//     TWSR = 0x00; // 프리스케일러=1
//     TWBR = 72;   // SCL=100kHz (16MHz 기준)
// }

// static void i2c_start(void) {
//     TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
//     while (!(TWCR & (1 << TWINT)));
// }

// static void i2c_stop(void) {
//     TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
// }

// static uint8_t i2c_write(uint8_t data) {
//     TWDR = data;
//     TWCR = (1 << TWINT) | (1 << TWEN);
//     while (!(TWCR & (1 << TWINT)));
//     return (TWSR & 0xF8); // 상태코드 반환
// }

// static void pcf8574_write(uint8_t data) {
//     i2c_start();
//     i2c_write((I2C_LCD_ADDR << 1) | 0); // Write 모드
//     i2c_write(data);
//     i2c_stop();
// }

// // ========================= LCD(PCF8574) 제어 함수 =========================
// static void lcd_port_update(void) {
//     pcf8574_write(g_lcd_port);
//     _delay_us(50);
// }

// static void lcd_port_setbit(uint8_t bit, uint8_t val) {
//     if (val)
//         g_lcd_port |= (1 << bit);
//     else
//         g_lcd_port &= ~(1 << bit);
// }

// static void lcd_en_pulse(void) {
//     lcd_port_setbit(LCD_BIT_EN, 1);
//     lcd_port_update();
//     _delay_us(1);
//     lcd_port_setbit(LCD_BIT_EN, 0);
//     lcd_port_update();
//     _delay_us(50);
// }

// static void lcd_send_nibble(uint8_t nibble) {
//     g_lcd_port &= 0x0F;             // 상위 4비트 지움
//     g_lcd_port |= (nibble << 4);      // nibble를 b4~b7에 대입
//     lcd_port_update();
//     lcd_en_pulse();
// }

// static void lcd_write_byte(uint8_t val, uint8_t rs) {
//     lcd_port_setbit(LCD_BIT_RS, rs);
//     lcd_port_setbit(LCD_BIT_RW, 0);
//     lcd_port_update();
    
//     lcd_send_nibble(val >> 4);      // 상위 4비트 전송
//     lcd_send_nibble(val & 0x0F);      // 하위 4비트 전송
// }

// static void lcd_command(uint8_t cmd) {
//     lcd_write_byte(cmd, 0);
//     if (cmd == LCD_CMD_CLEAR || cmd == LCD_CMD_HOME)
//         _delay_ms(2);
// }

// static void lcd_data(uint8_t data) {
//     lcd_write_byte(data, 1);
// }

// static void lcd_string(const char *str) {
//     while (*str) {
//         lcd_data(*str++);
//     }
// }

// static void lcd_gotoxy(uint8_t row, uint8_t col) {
//     uint8_t addr = (row == 0) ? 0x00 : 0x40;
//     addr += col;
//     lcd_command(0x80 | addr);
// }

// static void lcd_init(void) {
//     g_lcd_port = (1 << LCD_BIT_BL);  // 백라이트 ON
//     lcd_port_update();
//     _delay_ms(50);
    
//     lcd_send_nibble(0x03);
//     _delay_ms(5);
//     lcd_send_nibble(0x03);
//     _delay_us(100);
//     lcd_send_nibble(0x03);
//     _delay_us(100);
//     lcd_send_nibble(0x02);
    
//     lcd_command(LCD_CMD_FUNC);
//     lcd_command(LCD_CMD_ON);
//     lcd_command(LCD_CMD_CLEAR);
//     lcd_command(LCD_CMD_MODE);
// }

// // ========================= 디버그: 수신 문자 ASCII 값을 LCD에 16진수로 출력 =========================
// static void lcd_print_hex(uint8_t val) {
//     char hex[3];
//     hex[0] = (val >> 4) < 10 ? '0' + (val >> 4) : 'A' + ((val >> 4) - 10);
//     hex[1] = (val & 0x0F) < 10 ? '0' + (val & 0x0F) : 'A' + ((val & 0x0F) - 10);
//     hex[2] = '\0';
//     lcd_string("RX: ");
//     lcd_string(hex);
// }

// // ========================= 메인 함수 =========================
// int main(void) {
//     // UART, I2C, LCD 초기화
//     uart_init();
//     i2c_init();
//     lcd_init();

//     lcd_string("Weather Ready!");
//     _delay_ms(1000);
//     lcd_command(LCD_CMD_CLEAR);

//     while (1) {
//         if (UCSR0A & (1 << RXC0)) {
//             char c = uart_receive();

//             // 줄바꿈, 캐리지 리턴, 공백 무시
//             if(c == '\n' || c == '\r' || c == ' ')
//                 continue;
            
//             // LCD 클리어 후 커서 이동
//             lcd_command(LCD_CMD_CLEAR);
//             lcd_gotoxy(0, 0);
            
//             // 디버그: 수신된 문자의 ASCII 값을 먼저 출력
//             lcd_print_hex(c);
//             _delay_ms(500);
//             lcd_command(LCD_CMD_CLEAR);
//             lcd_gotoxy(0, 0);
            
//             // 유효한 입력인 경우에만 처리 ('1'-'4')
//             if(c >= '1' && c <= '4') {
//                 switch(c) {
//                     case '1':
//                         lcd_string("SUNNY");
//                         break;
//                     case '2':
//                         lcd_string("CLOUDY");
//                         break;
//                     case '3':
//                         lcd_string("RAINY");
//                         break;
//                     case '4':
//                         lcd_string("SNOWY");
//                         break;
//                 }
//             } else {
//                 lcd_string("Invalid");
//             }
//         }
//     }
//     return 0;
// }



// //SHT 5초마다 한 번씩 온습도 측정 - timer0를 써서 5초 주기를 계산
// //외부 EEPROM의 주소 0100에는 온도를, 0200에는 습도를 집어넣기
// //SHT에서 측정실패는 error 성공 시에만 EEPROM에 저장
// //int4번 써서 (=스위치를 누르면) eeprom에 데이터를 읽어서 uart로 출력하기
// #include "SHT2x.h"
// #include "TWI_driver.h"
// #include "at25160.h"
// #include "uart0.h"
// #include <avr/interrupt.h>
// #include <avr/io.h>
// #include <stdint.h>
// #include <util/delay.h>

// volatile uint8_t Read_flag = 1, TX_flag = 0;
// uint16_t timer0Cnt = 0;
// uint16_t temperatureC, humidityRH;

// int main(void)
// {
//     nt16 tempRaw, humiRaw;

//     SPI_Init();
//     Init_TWI();
//     SHT2x_Init();
//     uart0Init();

//     DDRE = 0x02;
//     EICRB = 0x03; // INT4 상승 에지
//     EIMSK = 0x10; // INT4 허용
//     TCCR0 = 0x07; // Timer0 프리스케일러 1024
//     TCNT0 = 112;  // 0.01초 인터럽트
//     TIMSK = 0x01; // Timer0 오버플로우 허용

//     sei();
//     stdout = &OUTPUT;

//     while (1)
//     {
//         if (Read_flag)
//         {
//             SHT2x_MeasureHM(TEMP, &tempRaw);
//             temperatureC = (uint16_t)(SHT2x_CalcTemperatureC(tempRaw.u16) * 10);
//             SHT2x_MeasureHM(HUMIDITY, &humiRaw);
//             humidityRH = (uint16_t)(SHT2x_CalcRH(humiRaw.u16) * 10);
//             at25160_Write_Arry(0x0100, (uint8_t *)&temperatureC, 2);
//             at25160_Write_Arry(0x0200, (uint8_t *)&humidityRH, 2);
//             Read_flag = 0;
//         }
//         if (TX_flag)
//         {
//             at25160_Read_Arry(0x0100, (uint8_t *)&temperatureC, 2);
//             at25160_Read_Arry(0x0200, (uint8_t *)&humidityRH, 2);
//             uart0PrintString("\n\rTemp: ");
//             printf("%u.%u[C], Humi: %u.%u[%%]",
//                    temperatureC / 10, temperatureC % 10,
//                    humidityRH / 10, humidityRH % 10);
//             TX_flag = 0;
//         }
//     }
// }

// ISR(TIMER0_OVF_vect)
// {
//     timer0Cnt++;
//     if (timer0Cnt >= 500) // 5초
//     {
//         timer0Cnt = 0;
//         Read_flag = 1;
//     }
//     TCNT0 = 112;
// }

// ISR(INT4_vect)
// {
//     TX_flag = 1;
// }

#include "SHT2x.h" // i2c
#include "TWI_driver.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "lcd.h"

void printf_2dot1(uint8_t sense, uint16_t sense_temp);

uint16_t temperaturC, humidityRH;

int main(void)
{   
    Init_TWI();
    lcdInit();  //lcd
    SHT2x_Init(); //온습도
    nt16 sRH;
    nt16 sT;
    uint8_t error; // SHT2x_MeasureHM가 선언된 헤더에서의 에러를 쓰기위해 그대로 가져옴

    while (1)
    {
        error |= SHT2x_MeasureHM(HUMIDITY, &sRH);
        error |= SHT2x_MeasureHM(TEMP, &sT);
        temperaturC = SHT2x_CalcTemperatureC(sT.u16)*10; //해당 수식이 이미 sht2x.c 파일에 들어가있음
        humidityRH = SHT2x_CalcRH(sRH.u16)* 10;          //이를 불러와 숫자로써 취급하여 출력
        if(error == SUCCESS){
            lcdGotoXY(0,0);
            printf_2dot1(TEMP, temperaturC);        //잘뜨면 이 양식으로 출력해라
            lcdGotoXY(0,1);
            printf_2dot1(HUMIDITY, humidityRH);
        }else{
            lcdGotoXY(0,0);
            lcdPrintData(" Temp: --.-C", 12);       //성공이 아니라면 --로 출력해라
            lcdGotoXY(0,1);
            lcdPrintData(" Humi: --.-%", 12);
        }
        _delay_ms(300);
    }    
    return 0;
}

void printf_2dot1(uint8_t sense, uint16_t sense_temp){

    uint8_t s100, s10;
    if(sense == TEMP){
        lcdPrintData(" Temp: ", 7);
        s100 = sense_temp / 100; // 100의 자리
        if(s100> 0){
            lcdDataWrite(s100 + '0');
        }
        s10 = sense_temp / 10 - s100 * 10; // 10의 자리
        if(s10> 0){
            lcdDataWrite(s10 + '0');
        }
        lcdDataWrite('.');
        lcdDataWrite(sense_temp % 10 + '0'); // 1의 자리
        lcdDataWrite('C');
    }else if(sense == HUMIDITY){
        lcdPrintData(" Humi: ", 7);
        s100 = sense_temp / 100; // 100의 자리
        if(s100> 0){
            lcdDataWrite(s100 + '0');
        }
        s10 = sense_temp / 10 - s100 * 10; // 10의 자리
        if(s10> 0){
            lcdDataWrite(s10 + '0');
        }
        lcdDataWrite('.');
        lcdDataWrite(sense_temp % 10 + '0'); // 1의 자리
        lcdDataWrite('%');
    }
}