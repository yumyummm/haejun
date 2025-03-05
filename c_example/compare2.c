/*1과 9사이의 숫자인지 확인해서 맞으면 1, 틀리면 0을 프린트하세요*/

#include <stdio.h>
int main(void)
{
    int a;
    int great;
    printf("숫자를 입력하세요 1-9 : ");
    scanf("%d", &a);
    great = a >= 1 && a <= 9 ;
    printf("1 <= %d <= 9 : %d\n", a, great); 
    /*교수님께서는 여기를 printf("1 <= %d <= 9 : %d\n", a, (1 <= a) && (a <= 9)); 이렇게 하심. 아마도 print 마지막 변수
    받아줄 때 선언한 변수값의 이름 대신 해당 수식 자체를 입력해도 되는 듯하다*/

return 0;}