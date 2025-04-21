#include <iostream>
#ifndef COMPLEX_H
#define COMPLEX_H

class Complex{
friend std::ostream& operator<<(std::ostream& out, const Complex& rhs); 

private:   
    double re_; //언더바를 써서 멤버변수임을 알려줌
    double im_;
 
public:

    Complex(double re = 0.0, double im = 0.0);
    //Complex(const Complex&){memberwise copy}
    //~Complex(){}
   
    //Complex& operator=(const Copmlex&)
    Complex& operator+=(const Complex& rhs);
    //+=, -=, *=, /= (O) 
    //&=. ^=, %= (X)
    bool operator==(const Complex& rhs) const; //비교만 하는 거니까 기존의 값을 바꾸지 않으므로 const
    bool operator!=(const Complex& rhs) const;
    // !=, <=, >=, >, < (O)
    const Complex operator+(const Complex& rhs) const; 
    const Complex operator-(const Complex& rhs) const; 
    //+, -, *, / (O) 
    //% (X)

    Complex& operator++(); //단항연산이라 입력값 없음. prefix
    Complex operator++(int ); //postfix 의미없는 int를 써서 후위증감식임을 표시해줌. 
    //++, -- (X) 증감연산식은 정수형 변수에 대해서 주로 쓰지만 그래도 연습용으로 한 번 해보자.

    // &, }, -, ^ (X) //비트연산자도 이 코드에서는 못 써

    //type casting(X)

    //Complex *operator&() {return *this;}
    //const Comples *operator&() const{return *this;}
// get, set 함수
double real() const;
double imag() const;
void real(double re);
void imag(double im);

};

#endif