#include <stdio.h>

int main(void)
{
    int a, b, temp;
    a = 10;
    b = 20;

    // swap
    temp = a;
    a = b;
    b = temp;

    printf("a = %d, b = %d\n", a, b);
    return 0;
}