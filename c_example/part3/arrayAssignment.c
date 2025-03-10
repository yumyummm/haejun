#include <stdio.h>
int main(void){

    int nums1[] = {1, 2, 3, 4, 5};
    int nums2[5]; 
    //num2 = muns1;이라고 쓰면 안 됨. 왜냐하면 배열은 상수이기 때문임.
    for(int i = 0; i < 5; ++i)
    {
        nums2[i] = nums1[i];
    }
    printf("nums1의 주소값 %p", nums1);
    printf("nums2의 주소값 %p", nums2);
    nums2[3] =14;
    
    int *nums3;
    nums3 = nums1;
    printf("num3의 주소값 %p", nums3);
    nums3[2] = 23;
    
    for(int i = 0; i < 5; ++i)
    {
        printf("nums1 %d : %d, \n", 1, nums1[i]);
        printf("nums2 %d : %d, \n", 1, nums2[i]);
    }




    return 0;
}