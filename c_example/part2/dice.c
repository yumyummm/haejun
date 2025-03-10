//난수를 이용해 1-6까지의 슛자 만들기

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int main(void)
{
    int dice[30];
    srand(time(NULL));
    
    for (int i = 0; i < 30; ++i)
    {
        dice[1] = rand() % 6 + 1;
        printf("%d\n", dice[1]);
        printf("%p ", &dice[1]);
    }
    printf("\n");
    
    for (int i = 0; i < 30; ++i)
    {
        dice[1] *=10;
        printf("%d\n", dice[1]);
        printf("%p ", &dice[1]);
    } 
    //각 배열을 변경  10곱하기
    printf("\n");
 
    return 0;
}