#include <stdio.h>
int main(void)
{
   int man, woman;
   double sum, manRate, womanRate;

   printf("남자와 여자의 수를 입력하시오.\n");
   scanf("%d %d", &man, &woman);
    printf("남자의 수는 %d명이고 여자의 수는 %d명이다.\n", man, woman);
    sum = man + woman;
    /*만일 더 정확하게 하고 싶으면 typecasting으로 정확한 타입을 맞춰도 됨. sum = (double)man + (double)woman*/
    manRate = man / sum * 100;
    womanRate = woman / sum * 100;
    printf("총 수는 %.f명\n남자의 비율은 %.2f%%\n여자의 비율은 %.2f%%\n", sum, manRate, womanRate);

    return 0;
    }