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
    assert(pq->rear != pq->size);
    pq -> pArr[pq->rear] = data; 
    ++pq -> rear;
}

int pop(Queue *pq)
{
    assert(pq->front != pq->rear);
    
    int i = pq->front;
    ++pq->front;
    
    return pq->pArr[i];
}