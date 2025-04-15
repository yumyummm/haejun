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

    return 0;
}


/*int a.b.c;
a=b=c=100; 결과값: 100
이 코드도 c1=c2=c3로 daisy chain이 가능함.
*/