#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"


void initQueue(Queue *pq, int size)
{
    pq->pArr = malloc(size * sizeof(int));
    pq->size = size;
    assert(pq->pArr ); // malloc이 실패하면 NULL을 리턴함
    pq->rear=0;
    pq->front=0;
}

void cleanupQueue(Queue *pq)
{
    free(pq->pArr);
}

void push(Queue *pq, int data)
{
    // assert(pq->rear != pq->size);
    // assert(pq->rear +1 != pq->front); 
    assert((pq->rear +1) % pq -> size != pq->front); 
    pq -> pArr[pq->rear] = data; 
    // ++pq -> rear;
    pq->rear = (pq->rear + 1) % pq->size; // ++pq -> rear를 풀어쓰면 pq->rear = (pq->rear + 1) 여기에 사이즈로 나머지 연산한 거임. 
}

int pop(Queue *pq)
{
    assert(pq->front != pq->rear);
    
    int i = pq->front;
    // ++pq->front;
    pq->front = (pq->front + 1) % pq->size; // ++pq->front를 풀어쓰면 pq->front = (pq->front + 1) 여기에 사이즈로 나머지 연산한 거임.
    return pq->pArr[i];
}