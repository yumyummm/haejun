#include <cstdio>
#include <cassert>
#include "queue.h"
//const int QUEUE_SIZE = 100;
const int Queue::QUEUE_SIZE = 100;

Queue::Queue(int size)
:pArr_(new int(size)), size_(size), front_(0), rear_(0)
{

}

Queue::~Queue()
{
    delete[] pArr_; 
}

bool Queue::empty() const
{
    return front_ == rear_;
}
bool Queue::full() const
{
    return rear_ == size_;
}

int Queue::size() const{
    return size_;
}

int Queue::remain() const{
    return size_ - rear_;
}

void Queue::push(int data)
{
    assert(!full());
    pArr_[rear_] = data; 
    ++rear_;
}

int Queue::pop()
{
    assert(front_ != rear_);
    int i = front_;
    ++front_;
    
    return pArr_[i];
}