#include <iostream>
#include"complex.h"

int main() 
{
    Complex c1;
    Complex c2 = 3.0;
    Complex c3(3.0, 4.0);
    Complex c4 = c3; // copy constructor
    
    c1 = c3; // c1.opertatior=(c3) or operator=(c1, c3)

    if(c1==c3){
        std::cout << "c1 and c3 are equal" << std::endl;
    } else {std::cout << "c1 and c3 are not equal" << std::endl;
    }

    c4 = c2 + c3; //c2.operator+(c3) or operator+(c2, c3)
    c4 = c2 - c3;

    //std::cout << c1; //(3.0, 4.0) std::cout.operatior<<(c1) or operator<<(std::cout, c1) //cout은 osteam클래스 타입의 객체. 라이브러리 클래스인 오스트림 안에 멤버함수를 추가하는 건 안 되기 때문에 전역함수로 만들어줘야 함.
    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
    std::cout << c3 << std::endl; 
    std::cout << c4 << std::endl;

    return 0;
}


/*int a.b.c;
a=b=c=100; 결과값: 100
이 코드도 c1=c2=c3로 daisy chain이 가능해지려면 자기참조를 해야 함. 어제는 일단 리턴값이 없다고 간주하고 void 반혼형을 쓰는 걸로 했지만, 사실은 반환값이 있는 거고 Complex&가 반환형임. 
*/