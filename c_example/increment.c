#include <stdio.h>
int main(void)
{
    int a, b;
    a = 5;
    b = ++a;
    printf("a: %d \t b: %d", a, b);

    a = 5;
    b = a++;
    printf("a: %d \t b: %d", a, b);
    
    return 0;
}