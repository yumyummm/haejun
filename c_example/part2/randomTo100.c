//두 난수를 발생시켜서 비교
//10까지의 두 난수가 서로 일치할 때까지 비교 반복


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int a, b, i;
    double rand1, rand2;
    while (1)
    {
        i++;
        srand((unsigned int)time(NULL) + i); //random 셋
        rand1 = rand() / (double)RAND_MAX * 10;
        srand((unsigned int)time(NULL) + i + 10000);// 우분투에서는 동시에 실행하는 코드로 작성 시 같은 수가 출력될 수 있어서 이렇게 임의의 수를 더하면 괜찮아짐
        rand2 = rand() / (double)RAND_MAX * 10;
        
        a = (int)rand1;
        b = (int)rand2;        
        printf("0-10 사이의 랜덤한 숫자: %f\n", rand1);
        printf("0-10 사이의 랜덤한 숫자: %f\n", rand2);
        printf("%d > %d : %s\n", a, b, a > b ? "참" : "거짓"); //정수 형태로 표현하고 싶어서 일부러 %d로 표현함
        printf("%d < %d : %s\n", a, b, a < b ? "참" : "거짓"); 
        printf("%d == %d : %s\n", a, b, a == b ? "참" : "거짓"); 
        printf("%d != %d : %s\n", a, b, a != b ? "참" : "거짓"); 
        if(a == b)
            break;
    }    
    return 0;
}