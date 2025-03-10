#include <stdio.h>

int sum(int a, int b);

int main(void)
{
    int a = 10, b = 20;
    int result = sum(a, b);
    printf("%d + %d = %d\n", a, b, sum(a, b));
}

int sum(int a, int b)
{
    int temp;
    temp = a + b;
    return temp;
}