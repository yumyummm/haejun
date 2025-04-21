#include <cstdlib>
#include "list.h"
#include <cassert>

// void printList(const List *plist)
std::ostream& operator<<(std::ostream& out, const List& rhs)
{
    Node *p = rhs.ptr->next;
    out << "[";
    while (p ) {
      out << p->data;
      out << ((p->next ) ? ", ": "");
        p = p->next;
    }
    out << "]";

    return out;
}

Node::Node(int data, Node *next)
{
    this->data = data;
    this ->next= next;
}

List::List()
{
    this->ptr = new Node(-1, NULL); // dummy node
}

List::~List()
{
    Node *p =this->ptr;
    while(p ){
        Node *temp = p;
        p = p->next;
        delete temp;
    }
}

void insertFirstNode(List *pList, int data)
{
    this->ptr ->next = new Node(data, this->ptr->next);
}

void insertNode(List *pList, int prevData, int data)
{
    Node *p = this->ptr->next;
    while(p ){
        if(p->data == prevData){
           break;
        }
        p = p->next;
    }
        // p->next = createNode(data, p->next);
        p->next = new Node(data, p->next);
    }
    
void deleteNode(List *plist, int data)
{
    Node *p = this->ptr->next;
    Node *p2 = this->ptr;

    while(p ){
        if(p -> data == data)
            break;
        p = p->next;
        p2 = p2 ->next;
    }
    if(p){
        p2->next = List();
        void cleanupList(List *plist);
        void insertFirstNode(List *plist, int data);
        void insertNode(List *plist, int prevData, int data);
        void deleteNode(List *plist, int data);
        void printList(const List *plist);
        delete(p);
    }
}

