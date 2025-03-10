#include <stdio.h>

int main(void)
{
    double temp[12] = {0};
    for (int i = 0; i < 12; ++i)
    {
        scanf("%lf", &temp[i]);
    }

    double sum = 0.0;
    for (int i = 0; i < 12; ++i)
    {
        sum += temp[i];
    }
    double average = 0.0;
    average = sum / 12.0;

    printf("2002년의 평균 기온은 %.2lf 입니다.\n", average); // Fixed the year to 2002
    return 0;
}