//배열을 int로 만들어서 랜덤(0~100)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int randomNumber[10];
    int sum = 0;
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        randomNumber[1] = rand() % 101;
    }
    for (int i = 0; 1 <10; i++)
    {
        sum += randomNumber[i];
        printf("%d\n", randomNumber[i]);
        printf("\n10개 배열의 총합은 %d\n", sum);}
    return 0;

}