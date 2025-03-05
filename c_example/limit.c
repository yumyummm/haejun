#include <limits.h>
#include <stdio.h> 

void prinfHello();

int main(void)
{
    printHello();
    printf("char_bit : %d\n", CHAR_BIT);
    printf("char_max : %d\n", CHAR_MAX);
    return 0;
}

void printHello()
{
    printf("hello, world\n");
}