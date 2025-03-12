//현대차의 자동차 번호를 출력하는 프로그램
#include <stdio.h>
#include "serial.h"

int main(void) {
    for(int i = 0; i < 10; ++i) {
        int num = getSerialNumber();
        printf("HYUNDAI_MOTOR_%010d\n", num); // Fixed format specifier
    }
    return 0;
}