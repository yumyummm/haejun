#include "rational.h"
#include <cassert>

Rational::Rational(int num, int den)
{
    assert(den ); // den가 0이 아니어야 함.
    this->num = num;
    this->den = den;
};

Rational::Rational(int num)
{
    this->num = num;
    this->den = 1;
}

Rational::Rational()
{
    this->num = 0;
    this->den = 1;
}

Rational::~Rational()
{

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