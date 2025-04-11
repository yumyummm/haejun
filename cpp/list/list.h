#ifndef LIST_H
#define LIST_H


typedef struct node {
    int data;
    struct node *next;
} Node;

struct List {
    Node *ptr;
    void initList();
    void cleanupList();
    void insertFirstNode(int data);
    void insertNode(int prevData, int data);
    void deleteNode(int data);
    void printList();
};


#endif