#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
// class Complex; // 클래스도 함수처럼 이런 식으로 선언할 수도 있음. 
class Complex {
friend std::ostream& operator<<(std::ostream& out, const Complex& rhs); //class안에 들어갔다고 멤버함수가 아님. 여전히 전역함순데 friend로 선언하려고 안에 넣은 것뿐임!

private: // attributes
    double re;
    double im;

public: //method
    Complex(double re =0.0, double im=0.0); // Complex(double re, double im); default argument는 뒤쪽부터 줘야 함.
    Complex(const Complex& rhs); //Complex c4(c3);와 같음. 왜 콘스트? c3를 받아와서 c4를 만드는 거니까 원본인 c3는 안 바뀜.
    ~Complex();

    Complex& operator=(const Complex& rhs);
    // +, - *
    bool operator==(const Complex& rhs);

    const Complex operator+(const Complex& rhs); 
    const Complex operator-(const Complex& rhs); 

    //get, set 함수는 아직 안 만듦.
};

#endif