#include "rational.h"
#include <cassert>

std::ostream& operator<<(std::ostream& out, const Rational& rhs)
{
    out << "(" << rhs.num << "/" << rhs.den << ")";
    return out;
}

Rational::Rational(int num, int den)
{
    assert(den ); // den가 0이 아니어야 함.
    this->num = num;
    this->den = den;
};

Rational::Rational(const Rational& rhs)
{
    this->num = rhs.num;
    this->den = rhs.den;
}

Rational::~Rational()
{

}

Rational& Rational::operator=(const Rational& rhs)
{
    this->num = rhs.num; 
    this->den = rhs.den; 
    
    return *this;
}


bool Rational::operator==(const Rational& rhs)
{
    return (this->num == rhs.num && this->den == rhs.den); 
}

const Rational Rational::operator+(const Rational& rhs)
{
     int common_den = this->den * rhs.den; // 공통 분모
     int result_num = this->num * rhs.den + rhs.num * this->den; // 분자의 덧셈
 
     return Rational(result_num, common_den);
}

const Rational Rational::operator-(const Rational& rhs)
{
    int common_den = this->den * rhs.den; // 공통 분모
    int result_num = this->num * rhs.den - rhs.num * this->den; // 분자의 뺄셈

    return Rational(result_num, common_den);
}

int Rational::getNum()
{
    return this->num;
}

int Rational:: getDen()
{
    return this->den;
}

void Rational:: setNum(int num)
{
    this->num = num;
}

void Rational:: setDen(int den)
{
    assert(this->den ); // den가 0이 아니어야 함.
    this->den = den;
}