#ifndef STACK_H
#define STACK_H
#include "array.h"


class Stack{
    private:
    static const int STACK_SIZE;

    // int *pArr_;
    Array arr_; // 'has-a': 클래스가 멤버로 다른 클래스의 멤버를 가지는 경우
    int size_; 
    int tos_;
    int remain_;
    
    Stack(const Stack&);
    Stack& operator=(const Stack& );
public:
    //Stack();
    explicit Stack(int size = STACK_SIZE);
    ~Stack(); //힙메모리를 쓰기 때문에 명시적인 소멸자가 필요함.
    //Stack(const Stack&) {}
    //Stack& operator=(const Stack&){}
    //Stack *operator&() {}
    //const Stack *operator&() const {};
    int size() const;
    int remain() const;

    bool isEmpty() const;
    bool isFull() const;

    void push(int data);
    int pop();
}; 

 #endif 

 