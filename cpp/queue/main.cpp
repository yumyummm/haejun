#include <iostream>
#include "queue.h"

int main()// 괄호 안의 void 안 써도 됨
{
    Queue q1(10), q2(100);
    // q1.initQueue(10);
    // q1.initQueue(100);

    q1.push(100);
    q1.push(200);
    q1.push(300);

    std:: cout << "q1 1st pop(): " << q1.pop() << std::endl; //"q1 1st pop(): " 얜 문자열 상수, q1.pop() 얜 인트, endl 얜 알 수 없음. 서로 다른 자료형이 출력되고 있음(특이점).
    std:: cout << "q1 2nd pop(): " << q1.pop() << std::endl;
    std:: cout << "q1 3rd pop(): " << q1.pop() << std::endl;  

    q2.push(900);
    q2.push(800);
    q2.push(700);

    std:: cout << "q2 1st pop(): " << q2.pop() << std::endl;
    std:: cout << "q2 2nd pop(): " << q2.pop() << std::endl;
    std:: cout << "q2 3rd pop(): " << q2.pop() << std::endl;  

    // q2.cleanupQueue();
    // q2.cleanupQueue();
  
    return 0;
}