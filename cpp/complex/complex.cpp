#include "complex.h"

Complex::Complex(double re, double im)
{
    this->re = re; //this->re는 클래스의 멤버변수, re는 매개변수
    this->im = im; //this->im는 클래스의 멤버변수, im은 매개변수
}

Complex::Complex(double re)
{
    this->re = re;
    this->im = 0.0; 
}

Complex::Complex()
{
    this->re = 0.0; 
    this->im = 0.0; 
}

Complex::~Complex()
{

} //앞선 코드들에서는 new를 썼기 때문에 여기서 delete를 해줘야 했지만 여기서는 아무것도 쓸 필요없음.

double Complex::real()
{
    return this->re; 
}

double Complex::imag()
{
    return this->im; 
}

void Complex::real(double re)
{
    this->re = re; 
}

void Complex::imag(double im)
{
    this->im = im; 
}