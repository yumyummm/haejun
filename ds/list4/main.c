#include <stdio.h>
#include "list.h"

void printInt(const void *pData)
{
    printf("%d ", *(int *)pData); //void포인터는 역참조 안 돼서 포인터가 가리키는 타입으로 타입캐스팅을 해줘야 함.
}

void printDouble(const void *pData)
{
    printf("%lf ", *(double *)pData); //void포인터는 역참조 안 돼서 포인터가 가리키는 타입으로 타입캐스팅을 해줘야 함.
}

int main(void)
{

    List list1, list2;
    initList(&list1, sizeof(int));
    initList(&list2, sizeof(double));

    int i = 4; insertFirstNode(&list1, &i); // {4}
    i = 3; insertFirstNode(&list1, &i); // {3, 4}
    i = 1; insertFirstNode(&list1, &i); // {1, 3, 4}
    int j = 1;
    i = 2; insertNode(&list1, &j, &i); // {1, 2, 3, 4}
    i = 3; deleteNode(&list1, &i); // {1, 2, 4}
    printList(&list1, printInt);
    
    double d = 4.4; insertFirstNode(&list2, &d); // {4.4}
    d = 3.3; insertFirstNode(&list2, &d); // {3.3, 4.4}
    d = 1.1; insertFirstNode(&list2, &d); // {1.1, 3.3, 4.4}
    double f = 1.1;
    d = 2.2; insertNode(&list2, &f, &d); // {1.1, 2.2, 3, 4}
    d = 3.3; deleteNode(&list2, &d); // {1.1, 2, 4}
    printList(&list2, printDouble);

    cleanupList(&list1);
    cleanupList(&list2);
    return 0;
}