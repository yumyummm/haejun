#include <cstdio>
#include <cassert>
#include "stack.h"
const int Stack::STACK_SIZE = 100;

Stack::Stack(int size)
: arr_(size), tos_(0)
{
 
}

int Stack::size() const
{
    return size_;
    return arr_.size();
}


int Stack::remain() const
{
    // return size_ - tos_;
    return arr_.size() - tos_;
}

bool Stack::isEmpty() const
{
    return tos_ == 0;  // 스택이 비었을 때 tos_가 0이어야 합니다.
}

bool Stack::isFull() const
{
    return tos_ == size_; // tos_가 size_와 같을 때 스택이 꽉 찼습니다.
}

void Stack::push(int data)
{
    assert(!this->isFull());
    // pArr_[tos_] = data;
    arr_[tos_] = data;
    ++tos_;
}

int Stack::pop()
{
    assert(!this->isEmpty());
    --tos_;
    // return pArr_[tos_];
    return arr_[tos_];    
}


Stack::~Stack()
{
//delete[] pArr_; Array.h에 있는 소멸자가 자동으로 호출되는데 거기 이미 딜리트가 있음.
}
