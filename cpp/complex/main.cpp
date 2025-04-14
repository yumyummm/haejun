#include <iostream>
#include "complex.h"

int main()
{
    Complex c1(3.0, 4.0); // (3.0, 4.0i)
    Complex c2(3.0); // (3.0, 0.0i)
    Complex c3; // (0.0, 0.0i) 

    c3.real(3.0); // c3의 실수부를 5.0으로 설정
    c3.imag(4.0); // c3의 허수부를 6.0으로 설정

    std::cout << "c1: (" << c1.real() << ", " << c1.imag() << "i)" << std::endl;
    std::cout << "c2: (" << c2.real() << ", " << c2.imag() << "i)" << std::endl;
    std::cout << "c3: (" << c3.real() << ", " << c3.imag() << "i)" << std::endl;
    return 0;
}