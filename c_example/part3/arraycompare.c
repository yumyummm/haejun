#include <stdio.h>
int main(void){

    int nums1[] = {1, 2, 3, 4, 5};   
    int nums2[] = {1, 2, 3, 4, 5};
    if(nums1 == nums2){
        printf("nums1과 nums2는 같다.");
    } 
    else
    {
        printf("nums1과 nums2는 다르다.");
    };

    int i;
    for(int i = 0; i < 5; ++i)
    {
        if(nums1[i] != nums2[i])
        break;
    }
    if(i == 5)
        printf("nums1과 nums2의 원소는 모두 같다.");
    else
        printf("nums1과 nums2의 원소는 다르다.");


return 0;
}