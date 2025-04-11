#ifndef QUEUE_H
#define QUEUE_H
#define QUEUESIZE 100

typedef struct queue{
    int array[QUEUESIZE];
    int rear;
    int front;
}Queue;

void initQueue(Queue *pq); 

void push(Queue *pq, int data); //push하면 큐 안의 데이터가 바뀜. 콘스트 붙이면 안 됨.
int pop(Queue *pq);

#endif

