#include <cassert>
#include "rational.h"
#include "gcd.h"

std::ostream& operator<<(std::ostream& out , Rational& rhs)
{
    return out << rhs.num_ << "/" << rhs.den_;
}

void Rational::reduce()
{
    int g = gcd(num_ , den_);
    num_ = num_ / g;
    den_ = den_ / g;
}

Rational::Rational(int num , int den)
: num_(num) , den_(den)
{
    assert(den);
    this->reduce();

    // num_ = num;
    // den_ = den;
}

bool Rational::operator==(const Rational& rhs) const
{
    return num_ == rhs.num_ && den_ == rhs.den_;
}
bool Rational::operator!=(const Rational& rhs) const
{
    return !this->operator==(rhs);
}

const Rational Rational::operator+(const Rational& rhs) const
{
    Rational result(num_ * rhs.den_ + rhs.num_ * den_ , den_ * rhs.den_);

    return result;
}

int Rational::num() const
{
    return num_;
}
int Rational::den() const
{
    return den_;
}

void Rational::num(int num)
{
    num_ = num;
}
void Rational::den(int den)
{
    den_ = den;
}