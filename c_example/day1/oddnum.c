/*짝홀 구별하기 짝수이면 0, 홀수이면 1*/

#include <stdio.h>
int main()
{
    int num;
    printf("숫자를 입력하세요: ");
    scanf("%d", &num);

    int isodd;
    isodd = (num % 2 == 1);
    //isodd = num % 2;
    printf("num: %d\f isodd: %d\n", num, isodd);
    //printf("num: %d\f isodd: %d\n", num, num % 2); isodd = 이런 거 쓸 필요 없이 그냥 이렇게만 써도 됨.
    return 0;
    




} 