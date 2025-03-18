#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    int bookid;
    char bookname[40];
    char publisher[40];
    int price;
} Book;

int main(void)
{
    int size;
    scanf("%d", &size);
    int *pArr;
    pArr = (int *)malloc(sizeof(int) * size);

    srand(time(NULL));
    for (int i = 0; i < size; ++i)
    {
        *(pArr + i) = rand() % 101;
    }
    for (int i = 0; i < size; ++i)
    {
        printf("%d, ", *(pArr + i));
    }

    Book *pBook;
    pBook = (Book *)malloc(sizeof(Book) * size);
    for (int i = 0; i < size; ++i)
    {
        (pBook + i)->bookid = rand() % 1001;
        strcpy((pBook + i)->bookname, "책이름");
        strcpy((pBook + i)->publisher, "출판사");
        (pBook + i)->price = rand() % 1001 + 10000;
    }
    for (int i = 0; i < size; ++i)
    {
        printf("%d %s %s %d\n", (pBook + i)->bookid, (pBook + i)->bookname, (pBook + i)->publisher, (pBook + i)->price);
    }
    printf("\n");
    free(pBook);
    free(pArr);
    return 0;
}