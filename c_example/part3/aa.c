#include <stdio.h>

int main(void)
{
int nums[] ={1, 2, 3, 4, 5};
int *p;

p = nums;// 배열의 이름은 배열의 첫 번쩨 값의 주소와 같다. 
for (int i = 0; i < 5; ++i)
{
    printf("%d번째 원소는: %d", 1, nums[i]);
    printf("%d번째 원소는: %d", 1, p[i]);
    printf("%d번째 원소는: %d", 1, *(p+i));
}
return 0;
}