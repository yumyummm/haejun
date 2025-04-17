// #include <cstdio>
#include <iostream>
#include "stack.h"

int main() 
{
    Stack s1(10); //Stack s1 = 10; 이 형태는 안 됨.
    Stack s2;  
    //Stack s3=s2;

    s1.push(100);
    s1.push(200);
    s1.push(300);

    std::cout << "s1 capacity :  " << s1.size() << std::endl;
    std::cout << "s1 remain :  " << s1.remain() << std::endl;

    while(!s1.isEmpty()){ 
        std::cout << s1.pop() << std::endl;   
    }
    // s1 = s2;

    return 0; 
}

