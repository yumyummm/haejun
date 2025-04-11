#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

void initStack(Stack *ps, int size)
{
    ps->pArr = malloc(size * sizeof(int));
    ps->size = size;
    assert(ps->pArr != NULL); // malloc이 실패하면 NULL을 리턴함
    //assert(ps->pArr); 이것도 가능
    ps->tos=0;
}

void cleanupStack(Stack *ps)
{
    free(ps->pArr);
}

void push(Stack *ps,int data)
{
    //if (ps->tos == STACKSIZE)
    // if (ps->tos == ps->size)
    // {
    //     fprintf(stderr,"stack is full.\n");
    //     exit(1);
    // }

    assert(ps->tos != ps->size);

    //(*ps).array[(*ps).tos]=data;
    //*(ps->pArr + ps->tos)=data;
    ps->pArr[ps->tos] = data;
    ++ps->tos;
}
int pop(Stack *ps)
{
    // --tos;
    // return stack[tos];

    // --ps->tos;
    // return ps->array[ps->tos];

    // if (ps->tos == 0)
    // {
    //     fprintf(stderr,"stack is empty.\n");
    //     exit(2);
    // }
    assert(ps->tos != 0);

    --ps->tos;
    return ps->pArr[ps->tos];
  if (ps->tos == 0)
    {
        fprintf(stderr,"stack is empty.\n");
        exit(2);
    }

    --ps->tos;
    return ps->pArr[ps->tos];
}