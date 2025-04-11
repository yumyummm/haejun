#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void initList(List *plist, int eleSize)
{
    // plist ->ptr =malloc(sizeof(Node)); // dummy node
    plist->ptr = malloc(sizeof(Node)/*+eleSize*/);// 더미라 데이터값 필요없어서 엘리멘트사이즈 더해주는 거 생략
    plist->ptr->next = NULL;
    plist->eleSize = eleSize;
}

void cleanupList(List *plist)
{
    Node *p =plist->ptr;
    while(p ){
        Node *temp = p;
        p = p->next;
        free(temp);
    }
}

void insertFirstNode(List *plist, const void* pData)
{
    Node *p = malloc(sizeof(Node) + plist->eleSize);
    // p -> data   = data;
    memcpy((unsigned char *)p + sizeof(Node), pData, plist->eleSize);
    // memcpy(p + 1, pData, plist->eleSize); 위의 문장 이렇게 써도 됨.
    p -> next   = plist->ptr->next;
    plist ->ptr->next = p;
}
void insertNode(List *plist, const void *pPrevData, const void* pData)
{
    Node *p = plist->ptr->next;
    while(p ){
        // if(p->data == prevData) 임의의 변수는 ==으로 비교 못 함
        if(memcmp(p + 1, pPrevData, plist->eleSize == 0))
        {
           break;
        }
        p = p->next;
    }

    if(p ){
        //Node *tmp = malloc(sizeof(Node));
        Node *tmp = malloc(sizeof(Node)+plist->eleSize);
        // tmp->data = data;
        memcpy(tmp + 1, pData, plist->eleSize);
        tmp->next = p -> next;
        p->next = tmp;
    }
    
}
void deleteNode(List *plist, const void* pData)
{
    Node *p = plist->ptr->next;
    Node *p2 = plist->ptr;

    while(p ){
        // if(p->data == prevData)
        if(memcmp(p + 1, pData, plist->eleSize) == 0)
            break;
        p = p->next;
        p2 = p2 ->next;
    }
    if(p ){
        p2->next = p->next;
        free(p);
    }
}

void printList(const List *plist, void (*print)(const void*))
{
    Node *p = plist->ptr->next;
    printf("[");
    while (p ) {
        // printf("%d", p + 1); // 임의의 자료는 %d로 출력 못 함 -> 사용자 정의 연산을 인자로 전달할 때 함수 포인터를 씀. 메인.c로 가서 함수 포인터로 해결해라.
        print(p + 1);
        printf(( p->next)? ", " :"");
        p = p->next;
    }
    printf("]\n");
}

