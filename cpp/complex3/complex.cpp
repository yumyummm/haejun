#include"complex.h"

std::ostream& operator<<(std::ostream& out, const Complex& rhs)
{
    out << "(" << rhs.re << ", " << rhs.im << "i)"; //operator<<는 전역함수이기 때문에 private에 있는 re, im에 접근할 수 없음. 그래서 get함수를 하나 만들어 쓰든지, friend로!
    return out;
}   

Complex::Complex(double re, double im) //default constructor
{
    this->re = re;
    this->im = im;
}

Complex::Complex(const Complex& rhs) //right hand side(오른쪽에 있는 오퍼랜드(피연산자)란 뜻임.)
{
    this->re = rhs.re;
    this->im = rhs.im;
}

Complex:: ~Complex()
{

}

Complex& Complex::operator=(const Complex& rhs)
{
    this->re = rhs.re;
    this->im = rhs.im;

    return *this; // *this = c1임, c1에 이미 c3를 대입했기 때문에 c1을 리턴하면 됨.
}

bool Complex::operator==(const Complex& rhs)
{
    return (this->re == rhs.re && this->im == rhs.im);
}

const Complex Complex::operator+(const Complex& rhs)
{
    Complex result(this->re + rhs.re, this->im + rhs.im);
    
    return result; //result는 지역변수, 지역변수에 대해서는 주소값을 리턴하면 안 됨. 따라서 레퍼런스를 쓸 수가 없음. 그리고 더하기의 결과값은 상수가 돼야 하므로 콘스트
}

const Complex Complex::operator-(const Complex& rhs)
{
    Complex result(this->re - rhs.re, this->im - rhs.im);
    
    return result; 
}