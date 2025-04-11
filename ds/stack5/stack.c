#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "stack.h"

void initStack(Stack *ps, int size, int eleSize)
{
    ps->pArr = malloc(eleSize*size); //eleS
    ps->eleSize = eleSize;
    ps->size = size;
    assert(ps->pArr != NULL); 
    ps->tos=0;
}

void cleanupStack(Stack *ps)
{
    free(ps->pArr);
}

// void push(Stack *ps,int data)
void push(Stack *ps, const void *pData)
{
    assert(ps->tos != ps->size);
    // ps->pArr[ps->tos] = data;
    // memcpy(&ps->pArr[ps->tos], pData, ps->eleSize); // memcpy는 메모리 복사 함수. pArr의 tos번째에 pData를 복사한다.
    memcpy((unsigned char *)ps->pArr + ps->tos * ps->eleSize, pData, ps->eleSize); // memcpy는 메모리 복사 함수. pArr의 tos번째에 pData를 복사한다.
    ++ps->tos;
}

// void pop(Stack *ps, int *pRe)
void pop(Stack *ps, void *pData)
{
    assert(ps->tos != 0);
    --ps->tos;
    // *pRe = ps->pArr[ps->tos];
    // memcpy(pData, &ps->pArr[ps->tos],ps->eleSize); 
    memcpy(pData, (unsigned char *)ps->pArr + ps->tos * ps -> eleSize, ps->eleSize); 
}




// int pop(Stack *ps)
// {
//     assert(ps->tos != 0);

//     --ps->tos;
//     return ps->pArr[ps->tos];
//   if (ps->tos == 0)
//     {
//         fprintf(stderr,"stack is empty.\n");
//         exit(2);
//     }

//     --ps->tos;
//     return ps->pArr[ps->tos];
// }