/*함수를 두 숫자로 받아서 크기 관계를 0과 1로 표기*/

#include <stdio.h>

int main(void)
{
    int a, b;
    int greater;
    printf("두 정수를 입력하세요 : ");
    scanf("%d %d", &a, &b);

    greater = a > b;
    printf("greater는 %d 입니다.\n", greater);
    
    return 0;
}