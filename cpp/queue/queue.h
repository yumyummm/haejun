#ifndef QUEUE_H
#define QUEUE_H

class Queue{
private:
    int *pArr;
    int size; // 큐의 크기
    int rear;
    int front;
public:
    Queue(int size); 
    ~Queue();
    void push(int data);
    int pop();
};

#endif

