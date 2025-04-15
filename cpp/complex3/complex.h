#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
class Complex; // 클래스 선언 (7번에 정의되고 있는데 6번에 이미 클래스 레퍼런스를 해버려서 이렇게 해줘야 함.) 
std::ostream& operator<<(std::ostream& out, const Complex& rhs); 

class Complex {
friend std::ostream& operator<<(std::ostream& out, const Complex& rhs); 

private: // attributes
    double re;
    double im;

public: //method
    Complex(double re =0.0, double im=0.0); // Complex(double re, double im); default argument는 뒤쪽부터 줘야 함.
    Complex(const Complex& rhs); //Complex c4(c3);와 같음. 왜 콘스트? c3를 받아와서 c4를 만드는 거니까 원본인 c3는 안 바뀜.
    ~Complex();

    Complex& operator=(const Complex& rhs);
    bool operator==(const Complex& rhs);

    //get, set 함수는 아직 안 만듦.
};

#endif