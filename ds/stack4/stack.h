#ifndef STACK_H
#define STACK_H
//#define STACKSIZE 100

typedef struct stack{
    //int array[STACKSIZE];
    int *pArr; // 포인터로 바꿔줌
    int size; // 스택의 크기
    int tos;
}Stack;

void initStack(Stack *ps, int size);
void cleanupStack(Stack *ps);

void push(Stack *ps,int data);
int pop(Stack *ps);

 #endif 

 