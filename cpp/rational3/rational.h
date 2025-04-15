#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational
{friend std::ostream& operator<<(std::ostream& out, const Rational& rhs);
private:
    int num; // numerator라고 변수명을 정하는 게 좋음.
    int den; // denominator

public:
    Rational(int num = 0, int den = 1);
    Rational(const Rational& rhs);
    ~Rational();

    Rational& operator=(const Rational& rhs);
    bool operator==(const Rational& rhs);

    // +, - *
    const Rational operator+(const Rational& rhs);
    const Rational operator-(const Rational& rhs);

    //get, set
    int getNum();
    int getDen();

    void setNum(int num);
    void setDen(int den);
};

#endif