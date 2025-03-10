//랜덤함수로 1~100사이의 난수 20개 정렬 후 프린트
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int nums[20] = {0}; // 배열 초기화 수정
    srand(time(NULL));

    for(int i = 0; i < 20; ++i){

        nums[i] = rand() % 101;
    }
    
    for(int i = 0; i < 20; ++i){

        printf("%d, ", nums[i]);}
        printf("\n");
    
    /* selection sorting */
    for (int i = 0; i < 20-1; i++)
    {
        for(int j = i+1; j<20; ++j )
        {
            if(nums[i] > nums[j]){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }

    for(int i = 0; i < 20; ++i){

        printf("%d, ", nums[i]);}
        printf("\n");
    
    return 0;
}