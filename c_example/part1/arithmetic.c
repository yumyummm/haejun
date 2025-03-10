#include <stdio.h>

int main(void)
{
    int a, b;
    printf("Input a, b : ");
    scanf("%d %d", &a, &b);

    printf("Plus %d + %d = %d\n", a, b, a + b);
    printf("Minus %d - %d = %d\n", a, b, a - b);
    printf("Multiply %d * %d = %d\n", a, b, a * b);
    printf("Division %d / %d = %d\n", a, b, a / b);
    printf("나머지 %d %% %d = %d\n", a, b , a % b);

    return 0;
}