#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "queue.h"


void initQueue(Queue *pq, int size, int eleSize)
{
    // pq->pArr = malloc(size * sizeof(int));
    pq->pArr = malloc(size * eleSize);
    pq->size = size;
    assert(pq->pArr); // malloc이 실패하면 NULL을 리턴함
    pq->eleSize = eleSize;
    pq->rear=0;
    pq->front=0;
}

void cleanupQueue(Queue *pq)
{
    free(pq->pArr);
}

void push(Queue *pq, const void *pData)
{
    assert(pq->rear != pq->size);
    memcpy((unsigned char *)pq -> pArr + pq->rear * pq->eleSize, pData, pq->eleSize); 
    ++pq -> rear;
}

void pop(Queue *pq, void *pData)
{
    assert(pq->front != pq->rear);
    int i = pq->front;
    ++pq->front;
    // return pq->pArr[i];
    memcpy(pData, (unsigned char *)pq -> pArr + i * pq -> eleSize, pq->eleSize);
}


// int pop(Queue *pq)
// {
//     assert(pq->front != pq->rear);
//     return pq->pArr[pq->front++];
// }