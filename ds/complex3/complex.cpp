#include"complex.h"

Complex::Complex(double re, double im) //default constructor
{
    this->re = re;
    this->im = im;
}

Complex::Complex(const Complex& rhs) //right hand side(오른쪽에 있는 오퍼랜드(피연산자)란 뜻임.)
{
    this->re = rhs.re;
    this->im = rhs.im;
}

Complex:: ~Complex()
{

}

Complex& Complex::operator=(const Complex& rhs)
{
    this->re = rhs.re;
    this->im = rhs.im;

    return *this; // *this = c1임, c1에 이미 c3를 대입했기 때문에 c1을 리턴하면 됨.
}

bool Complex::operator==(const Complex& rhs)
{
    return (this->re == rhs.re && this->im == rhs.im);
}