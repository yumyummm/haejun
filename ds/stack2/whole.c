#include <stdio.h>
#include "stack.h"



void push(int data); //func. declaration
int pop(void);

int stack[100]; //굳이 초기화 안 시켜줘도 된다고 함
int tos; //top of stack

int main(void)
{
    push(100);
    push(200);
    push(300);

    int re = pop(); printf("1st pop(): %d\n", re);
    re = pop();  printf("2st pop(): %d\n", re);
    re = pop();  printf("3st pop(): %d\n", re);
    return 0;
}


void push(int data)
{
    stack[tos] = data; 
    tos++; // tos = tos + 1;    
}

int pop(void)
{
    tos--; 
    return stack[tos]; 
}
