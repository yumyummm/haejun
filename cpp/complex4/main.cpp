#include <iostream>
#include "complex.h"

int main()
{
    Complex c1; 
    Complex c2 = 3.0;
    Complex c3(3.0, 4.0);
    Complex c4 = c3; // Complex c4(c3) 복사생성자

    c1 = c3; //치환연산(각각의 멤버들을 치환하고 자기 자신을 리턴하는 치환연산을 자동으로 만들어줌.)

    c1 == c3;
    c1 != c3;

    c1 = c2 + c3;
    c1 = c2 - c3;
    c1 += c2 += c3; //식의 결과값: c1

    ++c1;// 전위증감 써라! 왜냐면 내부구현 시 임시변수 안 써도 되고 레퍼런스로 받을 수 있어서 오버헤드X
    c1++;

    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c3: " << c3 << std::endl;
    std::cout << "c4: " << c4 << std::endl;


    const Complex c5(3.0, 5.0); 
    // c5.real(4.0);
    std::cout << "c5: (" << c5.real() << ", " << c5.imag() << "i)" << std::endl;



    return 0;
}