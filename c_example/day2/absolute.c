#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    int num;
    int state;

    printf("숫자를 넣으세요: ");
    scanf("%d", &num);

    if (num < 0)
    {
        state = 0;
    } 
    else
    {
        state = 1;
    }

    num = state ? num : -num;

    printf("주어진 숫자의 절대값은 %d입니다.\n", num);
    return 0;
}