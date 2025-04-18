#include <cstdio>
#include <cassert>
#include "stack.h"

//const int STACK_SIZE=100; static멤버변수로 만들어져서 아래의 형태로 변함.
const int Stack::STACK_SIZE = 100;

Stack::Stack(int size)
: pArr_(new int[size]), size_(size), tos_(0)
{
    assert(pArr_ ); 
}


int Stack::size() const
{
    return size_;
}


int Stack::remain() const
{
    return size_ - tos_;
}

bool Stack::isEmpty() const
{
    return tos_ == 0; // 변경: `tos_ == size`를 `tos_ == 0`으로 수정.
}

bool Stack::isFull() const
{
    return tos_ == size_; // tos_가 size_와 같을 때 스택이 꽉 찼습니다.
}

void Stack::push(int data)
{
    assert(!this->isFull());
    pArr_[tos_] = data;
    ++tos_;
}

int Stack::pop()
{
    assert(!this->isEmpty());
    --tos_;
    return pArr_[tos_];
}

Stack::~Stack()
{
    delete[] pArr_; 
}
