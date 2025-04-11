#ifndef STACK_H
#define STACK_H
class Stack{
private: //implementation
    int *pArr; // 포인터로 바꿔줌
    int size; // 스택의 크기
    int tos;
public: //interface  
    //void initStack(int size);
    // void cleanupStack(); //void cleanupStack(void);로 써도 됨.
    Stack(int size); //constructor!!! 초기화가 역할이기 때문에 반환타입이 없어야 함. 괄호 안에 void도 넣으면 안 됨.
    ~Stack();
    void push(int data);
    int pop();
}; 

 #endif 

 