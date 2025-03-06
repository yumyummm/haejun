//100 + 101 + .... + 10000


#include <stdio.h>

int main(void)
{
    int sum = 0;
    // int sum;
    // sum = 0;
    // for(int i = 1; i < 10000; ++i)
    // {
    //     sum += i;
    // }
    // printf("1부터 10000까지의 더한 숫자는 %d입니다.\n", sum);

    for(int i = 0; i <= 9901; ++i)
    {
        sum += i + 100;
    }
    printf("100부터 10000까지의 더한 숫자는 %d입니다.\n", sum);

    return 0;
}