#include <cstdio>
#include <cassert>
#include "queue.h"
//const int QUEUE_SIZE = 100;
const int Queue::QUEUE_SIZE = 100;

Queue::Queue(int size)
:arr_(size), front_(0), rear_(0)
{
   
}

Queue::~Queue()
{
    // delete[] pArr_; 
}

bool Queue::empty() const
{
    return front_ == rear_;
}
bool Queue::full() const
{
    return rear_ == arr_.size();
}

int Queue::size() const{
    return arr_.size();
}

int Queue::remain() const{
    return arr_.size() - rear_;
}

void Queue::push(int data)
{
    assert(!full());
    arr_[rear_] = data; 
    ++rear_;
}

int Queue::pop()
{
    assert(front_ != rear_);
    int i = front_;
    ++front_;
    
    return arr_[i];
}