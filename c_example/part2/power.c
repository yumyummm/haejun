//n의 제곱을 구하는 함수를 작성해서 2의 62제곱 출력

#include <stdio.h>
long long power(int base, int exponent);
void power2(int base, int exponent, long long *result);

int main(void)
{
    long long result = power(2, 62);
    printf("2의 62제곱은 %lld입니다.\n", result);
    long long result2;
    power2(2, 62, &result2);
    printf("2의 62제곱은 %lld입니다.\n", result2);
    return 0;
}

long long power(int base, int exponent)
{
    long long result = 1;
    for(int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}

void power2(int base, int exponent, long long *result)
{
    *result = 1;
    for(int i = 0; i < exponent; i++)
    {
        *result *= base;
    }
}//레퍼런스형식으로 변환 (이러면 콜바이밸류와 달리 데이터 자체가 복사되는 게 아니라 데이터 주소값만 복사되는 거라 메모리 효율 높음.)