// 1-10까지 while문을 이용하여 출력

#include <stdio.h>
#include <stdbool.h>
int main(void)
{
    int i = 0;
    do
    {
        printf("%d번 출력합니다\n", i+1); 
        ++i;

    } while (i < 10);
    return 0;

}