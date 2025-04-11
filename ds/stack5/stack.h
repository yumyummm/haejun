#ifndef STACK_H
#define STACK_H
//#define STACKSIZE 100

typedef struct stack{
    // int *pArr; // 포인터로 바꿔줌
    void *pArr; //데이터의 시작주소
    int eleSize; 
    int size; 
    int tos;
}Stack;

void initStack(Stack *ps, int size, int eleSize);
void cleanupStack(Stack *ps);

// void push(Stack *ps,int data);
void push(Stack *ps, const void *pData); // const가 붙어있으면 읽기 전용으로 가리키는 대상이 안 바뀜.
//int pop(Stack *ps);
// void pop(Stack *ps, int *pRe);// 리턴이 아니라 인자로 값을 받아오는 함수로 pop을 바꿔버림.
void pop(Stack *ps, void *pData); // 리턴값을 없애고 인자로 값을 받아오는 함수로 pop을 바꿔버림. 포인터를 쓰는 1번째 경우이자 5번 경우 임의의 자료를 인자로 받을 때 
 #endif 

 