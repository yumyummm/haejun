
#ifndef LIST_H
#define LIST_H

typedef struct node {
    // int data;
    struct node *next;
} Node;

typedef struct list {
    Node *ptr;
    int eleSize;
} List;

void initList(List *plist, int eleSize);
void cleanupList(List *plist);

void insertFirstNode(List *plist, const void *pData);
void insertNode(List *plist, const void *pPrevData, const void *pData);
void deleteNode(List *plist, const void *pData);

void printList(const List *plist, void (*print)(const void *));//printInt는 int형 함수포인터로, printDouble은 double형 함수포인터로 받아야 하는 문제 >> void포인터 써라.

#endif