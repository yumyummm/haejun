#ifndef QUEUE_H
#define QUEUE_H
//1#define QUEUESIZE 100

typedef struct queue{
    void *pArr;
    int eleSize; // 데이터의 크기
    int size; // 큐의 크기
    int rear;
    int front;
}Queue;

void initQueue(Queue *pq, int size, int eleSize); 
void cleanupQueue(Queue *pq);

// void push(Queue *pq, int data);
void push(Queue *pq, const void *pData); // void *pData는 포인터를 의미함. 자료형에 상관없이 사용 가능
void pop(Queue *pq, void *pData); // 얘는 포인터가 가리키는 곳에 값을 넣어줘야 하니까 콘스트 붙이면 안 됨.

#endif

