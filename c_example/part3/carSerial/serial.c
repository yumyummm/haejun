// 현대 차의 자동차 번호를 출력하는 프로그램
// int count = 0;
// #include "serial.h"
// extern int count;

int getSerialNumber(void)
{
    static int count = 0;
    int result = count;
    ++count;
    return result;
    // return count++;
}