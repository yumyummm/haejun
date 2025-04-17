#include <stdio.h>


int sumArray(const int *pArr, int size)
{
   int sum = 0;
   for(int i=0; i < size; ++i)
   {
      sum +=pArr[i]; 
    }
    return sum;
}

int sumArray2(int arr[])
// int sumArray2(int arr[10]) //대괄호 안에 사이즈를 써도 무시됨. 배열-배열 복사처럼 보이지만 아님. 인자에 대괄호 쓰면 배열이 아니라 포인터임!
{
   int sum = 0;
   for(int i=0;i < sizeof(arr)/ sizeof(arr[0]); ++i) 
   {
      // sum += arr[i];
      sum  += *arr++;
   }

   return sum;
}

int main(void)
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
   //  int sum = sumArray(nums + 5, 5);
    int sum = sumArray2(nums);
    printf("sum: %d\n", sum);
    return 0;
}