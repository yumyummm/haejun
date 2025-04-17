#include "complex.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out, const Complex& rhs) // 얘는 전역함수니까 const 멤버함수인지 고려해볼 필요 X!
{
    out << "(" << rhs.re_ << ", " << rhs.im_ << "i)";
    return out;
}

Complex::Complex(double re, double im)
: re_(re), im_(im) // constructor init. list 생성자 초기화 리스트(생성자에 한해서 이렇게 쓸 수 있음.)
{
    //re_ = re; //this-> 생략 가능 (단, 이때 멤버변수임을 알려주기 위해 _를 써서 '멤번변수 이름 =/= 인자 이름이라 가능) //멤버번수가 레퍼런스일 때, 콘스트일 때, 
    //im_ = im;
}

Complex& Complex::operator+=(const Complex& rhs)
{
    this->re_+=rhs.re_;
    this->im_+=rhs.im_;

    return *this;
}

bool Complex::operator==(const Complex& rhs) const
{
    return this->re_ == rhs.re_ && this->im_ == rhs.im_;
}

bool Complex::operator!=(const Complex& rhs) const
{
    return !this->operator==(rhs); //기존에 만들어져있는 멤버함수를 다른 멤버함수에서 호출해서 쓰는 이런 모양도 많이 쓰이니까 꼭 기억해둬!
    //return !(*this==rhs); 
    //return !(this->re_ == rhs.re_ && this->im_ == rhs.im_);
    //this->re_ =\!= rhs.re_ || this->im_ != rhs.im_
}

const Complex Complex::operator+(const Complex& rhs) const
{
    Complex result(this->re_ +rhs.re_, this->im_+rhs.im_);
    return result;
}

const Complex Complex::operator-(const Complex& rhs) const
{
    Complex result(this->re_-rhs.re_, this->im_-rhs.im_);
    return result;
}

Complex& Complex::operator++() 
{
    re_ += 1.0;
    return *this;
}

Complex Complex::operator++(int ) //얘 앞에 const 붙이면 안 됨.
{
    Complex tmp = *this; //위에 비해 임시변수 하나 더 쓰고 tmp객체 하나 더 불러온다고 생성자, 소멸자 1번 더 호출하는 만큼 오버헤드
    re_ += 1.0;

    return tmp; //tmp가 지역변수이므로 레퍼런스로 넘길 수 없으므로 반환형은 Complex 

}

double Complex::real() const
{
    return re_;
}

double Complex::imag() const
{
    return im_;
}

void Complex::real(double re)
{
    re_ = re;
}

void Complex::imag(double im)
{
    im_ = im;
}