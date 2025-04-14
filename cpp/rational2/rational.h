#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{private:
    int num; // numerator라고 변수명을 정하는 게 좋음.
    int den; // denominator
public:
    Rational();
    Rational(int num);
    Rational(int num, int den);
    ~Rational();

    void operator=(const Rational& rr); 
    bool operator==(const Rational& rr);
    
    int getNum();
    int getDen();

    void setNum(int num);
    void setDen(int den);
};

#endif