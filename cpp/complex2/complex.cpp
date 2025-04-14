#include "complex.h"

Complex::Complex()
{
    this->re = 0.0; 
    this->im = 0.0; 
}

Complex::Complex(double re)
{
    this->re = re;
    this->im = 0.0; 
}

Complex::Complex(double re, double im)
{
    this->re = re; //this->re는 클래스의 멤버변수, re는 매개변수
    this->im = im; //this->im는 클래스의 멤버변수, im은 매개변수
}

Complex::~Complex()
{

} 

// void Complex::operator=(Complex c)
// {
//     this->re = c.re; //c3는 매개변수, this->re는 클래스의 멤버변수
//     this->im = c.im; //c3는 매개변수, this->im는 클래스의 멤버변수
// }

// void Complex::operator=(const Complex *pc)
// {
//     this->re = pc->re; //c3는 매개변수, this->re는 클래스의 멤버변수
//     this->im = pc->im; //c3는 매개변수, this->im는 클래스의 멤버변수
// }

void Complex::operator=(const Complex& rc)
{
    this->re = rc.re; //c3는 매개변수, this->re는 클래스의 멤버변수
    this->im = rc.im; //c3는 매개변수, this->im는 클래스의 멤버변수
}

bool Complex::operator==(const Complex& rc)
{
    // if (this->re == rc.re && this->im == rc.im) {
    //     return true; 
    // } else {
    //     return false;
    // }
    return (this->re == rc.re && this->im == rc.im); // 어차피 식의 결과값이 true, false이므로 if, else 안 쓰고 막바로 반환하는 게 더 간결함.
}

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