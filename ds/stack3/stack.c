#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void initStack(Stack *ps)
{
    ps->tos = 0;
}
void push(Stack *ps, int data)
{
    //full??? - 예외처리
    if(ps->tos == STACKSIZE){
        fprintf(stderr, "Stack is full\n");
        exit(1);
    }
	// stack[tos] = data;
	// ++tos;
    // s.array[s.tos] = data;
	// ++s.tos;
    // (*ps).array[(*ps).tos] = data;
	ps->array[ps->tos] = data;
	++ps->tos;
}

//포인터 -> 멤버
//ps->array[ps->tos] = data;
//	++ps->tos; 이렇게 써도 됨.

int pop(Stack *ps)
{ 
    //empty???
    if(ps->tos == 0){
        fprintf(stderr, "Stack is empty\n");
        exit(2);
    }
	//	--tos;
// 	return stack[tos];
	--ps->tos;
	return (*ps).array[(*ps).tos];
}
