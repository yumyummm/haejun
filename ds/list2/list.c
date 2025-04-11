#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void initList(List *plist)
{
    plist ->ptr =malloc(sizeof(Node)); // dummy node
   
    plist->ptr->next = NULL;
}
void cleanupList(List *plist)
{
    Node *p =plist->ptr;
    while(p){
        Node *temp = p;
        p = p->next;
        free(temp);
    }
}
void insertFirstNode(List *plist, int data)
{
    Node *p = malloc(sizeof(Node));
    p -> data   = data;
    p -> next   = plist->ptr->next;
    plist ->ptr->next = p;
}
void insertNode(List *plist, int prevData, int data)
{
    Node *p = plist->ptr->next;
    while(p){
        if(p->data == prevData){
           break;
        }
        p = p->next;
    }
    if(p){Node *tmp = malloc(sizeof(Node));
        tmp->data = data;
        tmp->next = p->next;
        p->next = tmp;
    }
    
}
void deleteNode(List *plist, int data)
{
    Node *p = plist->ptr->next;
    Node *p2 = plist->ptr;

    while(p){
        if(p -> data == data)
            break;
        p = p->next;
        p2 = p2 ->next;
    }
    if(p){
        p2->next = p->next;
        free(p);
    }
}

void printList(const List *plist)
{
    Node *p = plist->ptr->next;
    printf("[");
    while (p) {
        printf("%d", p->data);
        printf(( p->next)? ", " :"");
        p = p->next;
    }
    printf("]\n");
}
