#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{private: //implementation details
    double re; //실수부 real part
    double im; //허수부 imaginary part

public: //interface (멤버함수를 지정할 때는 생성자와 소멸자를 가장 먼저 생각해)
    Complex(double re, double im); //constructor (구조체 멤버변수가 2개니까 일단 인자 2개를 넣고 시작해 봐.)
    Complex(double re); 
    Complex(); //constructor 
    ~Complex(); //destructor
    
    double real();
    double imag();

    void real(double re);//실수부를 받아서 실수부를 세팅하는 함수
    void imag(double im);//허수부를 받아서 허수부를 세팅하는 함수

};

#endif

