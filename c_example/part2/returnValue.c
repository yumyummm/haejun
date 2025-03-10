//값으로 부른다. call by value 참조로 부른다 call by reference

#include <stdio.h>

int f(void);
void f2(int *pResult);

int main(void)
{
    int result = f();
    printf("f1의 반환 결과는 : %d\n", result); // call by value 왜냐 상수를 복사했으니까
    int f2_result;
    f2(&f2_result);
    printf("f2의 반환 결과는 : %d\n", f2_result);
    return 0; // call by reference 
}

int f(void)
{
    return 100;
}

void f2(int *pResult)
{
    *pResult = 100;
}