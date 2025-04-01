#include "uart0.h"
#include <stdio.h>
#include <avr/interrupt.h>
#include <avr/io.h>

FILE OUTPUT = FDEV_SETUP_STREAM(uart0Transmit, NULL, _FDEV_SETUP_WRITE);
FILE INPUT = FDEV_SETUP_STREAM(NULL, uart0Receive, _FDEV_SETUP_READ);

int main()
{
    uart0Init();
    stdin = &INPUT;
    stdout = &OUTPUT;
    unsigned int rxData;
    uint8_t numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67};
    DDRA = 0xFF;

    printf("Hi, I'm ATmega128");
    printf("");

    while (1)
    {
        // rxData = uart0Receive();
        scanf("%d", rxData);

        if ((rxData >= 0x00) && (rxData <= 0x09))
        {
            PORTA = numbers[rxData];
        }
    }
    return 0;
}