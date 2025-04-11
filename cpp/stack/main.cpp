// #include <cstdio>
#include <iostream>
#include "stack.h"

int main() //c언어에서는 어떤 값이 들어올지 모른다는 'unknown'의 뜻, c++은 입력값이 없을 때 void를 써도 되고 안 써도 됨. 
{
    Stack s1(10), s2(100); //객체가 만들어질 때 자동적으로 생성자 호출됨. 이 경우는 2번 호출됨
    // s1.initStack(10);
    // s2.initStack(100);

    s1.push(100);
    s1.push(200);
    s1.push(300);

    // s1.tos=0;

    // printf("s1 1st pop() :  %d\n",s1.pop());
    std::cout << "s1 1st pop() :  " << s1.pop() << std::endl; //이 식의 결과값은 cout, 사이드 이펙트로 화면 출력
    std::cout << "s1 2nd pop() :  " << s1.pop() << std::endl;
    std::cout << "s1 3rd pop() :  " << s1.pop() << std::endl;
    //pop(&s1); // 스택이 비어있을 때 pop() 호출하면 오류 발생

    s2.push(900);
    s2.push(800);
    s2.push(700);
    std::cout << "s2 1st pop() :  " << s2.pop() << std::endl;
    std::cout << "s2 2nd pop() :  " << s2.pop() << std::endl;
    std::cout << "s2 3rd pop() :  " << s2.pop() << std::endl;

    // s1.cleanupStack();
    // s2.cleanupStack();
    return 0; // 소멸자: 객체가 사라질 때 자동적으로 호출되는 멤버 함수//2번 호출
}

