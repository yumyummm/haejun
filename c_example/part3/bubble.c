#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int nums[20] = {0}; // 배열 초기화 수정
    srand(time(NULL));

    // 배열 초기화 및 출력
    for(int i = 0; i < 20; ++i){
        nums[i] = rand() % 101;
        printf("%d, ", nums[i]);
    }
    printf("\n");

    // 버블 정렬
    for (int i = 20 -1; i >= 1; --i) {
        for(int j = 0; j < i - 1; ++j){
            if(nums[j] > nums[j + 1]){
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    // 정렬된 배열 출력
    for(int i = 0; i < 20; ++i){
        printf("%d, ", nums[i]);
    }
    printf("\n");

    return 0;
}


