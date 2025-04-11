#include <cstdio>
// #include <cstdlib>
#include <cassert>
#include "stack.h"

Stack::Stack(int size)
{
    // this->pArr = (int *)malloc(size * sizeof(int)); // c99표준에서는 타입캐스트 안 해도 되는데 씨쁠쁠은 해줘야 함.
    this -> pArr = new int[size]; // c++에서는 malloc 대신 new를 사용함. (c언어보다 타입을 엄격하게 사용함.)
    this->size = size;
    assert(this->pArr ); 
    this->tos=0;
}

Stack::~Stack()
{
    // free(this->pArr);
    delete[] this->pArr; // c++에서는 free 대신 delete를 사용함.
}

void Stack::push(int data)
{
    assert(this->tos != this->size);

    this->pArr[this->tos] = data;
    ++this->tos;
}
int Stack::pop()
{
    assert(this->tos != 0);

    --this->tos;
    return this->pArr[this->tos];
  if (this->tos == 0)
    {
        fprintf(stderr,"stack is empty.\n");
        // exit(2);
    }

    --this->tos;
    return this->pArr[this->tos];
}  // printf("s1 1st pop() :  %d\n",s1.pop());