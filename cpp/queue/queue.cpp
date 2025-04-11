#include <cstdio>
// #include <cstdlib>
#include <cassert>
#include "queue.h"


Queue::Queue(int size)
{
    // this->pArr = malloc(size * sizeof(int));
    this->pArr = new int[size]; // c++에서는 malloc 대신 new를 사용함.
    this->size = size;
    assert(this->pArr ); // malloc이 실패하면 NULL을 리턴함
    this->rear=0;
    this->front=0;
}

Queue::~Queue()
{
    // free(this->pArr);
    delete[] this->pArr; // c++에서는 free 대신 delete를 사용함.
}

void Queue::push(int data)
{
    assert(this->rear != this->size);
    this -> pArr[this->rear] = data; 
    ++this -> rear;
}

int Queue::pop()
{
    assert(this->front != this->rear);
    
    int i = this->front;
    ++this->front;
    
    return this->pArr[i];
}