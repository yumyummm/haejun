//현대차의 자동차 번호를 출력하는 프로그램
//extern int count; //여기서 int count 전역변수 serial.h에서처럼 또 쓰면 에러남.
// int count = 0; 걍 이래 써도 되는디 전역변수는 웬만하면 안 쓰는 게 좋으니까 정적 지역변수로 써

#include "serial.h"

int getSerialNumber(void) {
    static int count = 0;
    int result = count;
    ++count;
    return result;
}