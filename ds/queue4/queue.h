#ifndef QUEUE_H
#define QUEUE_H
//1#define QUEUESIZE 100

typedef struct queue{
    int *pArr;
    int size; // 큐의 크기
    int rear;
    int front;
}Queue;

void initQueue(Queue *pq, int size); 
void cleanupQueue(Queue *pq);
void push(Queue *pq, int data);
int pop(Queue *pq);

#endif

