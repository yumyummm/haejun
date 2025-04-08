#include <stdio.h>

int stack[100]; //굳이 초기화 안 시켜줘도 된다고 함
int tos; //top of stack

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





// void main(void)
// {
//   
// } 펌웨어의 경우 코드에 이상이 없으면 무한반복해야 하므로 리턴값 없다는 의미로 함수 앞에 보이드 쓰는데 사실 문법에는 어긋남