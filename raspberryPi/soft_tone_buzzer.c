#include <softPwm.h>
#include <stdio.h>
#include <wiringPi.h>
#include <softTone.h>

// gpio pin
#define LED1 23
#define LED2 24
#define LED3 25
#define LED4 1

#define BUZZER_PIN 12

int doReMi[8] = {523, 587, 659, 698, 783, 880, 987, 1046};

int main(void)
{
    wiringPiSetupGpio(); // BCM 기준 gpio 핀번호
    pinMode(BUZZER_PIN, OUTPUT);
 
    softToneCreate(BUZZER_PIN);

    while (1)
    {
        for (int i = 0; i < 8; ++i)
        {
            softToneWrite(BUZZER_PIN, doReMi[i]);
            delay(100);
        }
    }
    return 0;
}