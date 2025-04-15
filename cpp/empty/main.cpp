#include <iostream>
#include "empty.h"

int main()
{
    Empty e1;
    Empty e2 = e1;

    e1 = e2; 

    Empty *p1 = &e1; //e1.operator&();

    const Empty e3; //상수 객체이므로 값을 바꿀 수 없음.
    const Empty *p2 = &e3;

    return 0;
}