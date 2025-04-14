#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{private:
    int num; // numerator라고 변수명을 정하는 게 좋음.
    int den; // denominator
public:
    Rational(int num, int den);
    Rational(int num);
    Rational();
    ~Rational();

    int getNum();
    int getDen();

    void setNum(int num);
    void setDen(int den);
};

#endif