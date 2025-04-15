#include "rational.h"
#include <cassert>

Rational::Rational()
{
    this->num = 0;
    this->den = 1;
}

Rational::Rational(int num)
{
    this->num = num;
    this->den = 1;
}

Rational::Rational(int num, int den)
{
    assert(den ); // den가 0이 아니어야 함.
    this->num = num;
    this->den = den;
};

Rational::~Rational()
{

}

int Rational::getNum()
{
    return this->num;
}

void Rational::operator=(const Rational& rr)
{
    this->num = rr.num; 
    this->den = rr.den; 
}


bool Rational::operator==(const Rational& rr)
{
    return (this->num == rr.num && this->den == rr.den); 
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