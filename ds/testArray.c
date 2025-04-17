#include <stdio.h>

int main()
{
    int nums[] = {1, 2, 3, 4};
    int *p;

    p = nums;
     printf("*p: %d\n", *p);
     printf("*(p+1): %d\n", *(p+1));

     int nums1[] = {1,2,3,4,5};
     int nums2[5];

     for(int i=0; i<5; ++i)
     {
        nums2[i] = nums1[i];
     }

     for(int i=0; i<5; ++i)
     {
        printf("%d", nums[i]);
     }
     printf("\n");

     int nums3[] = {1,2,3,4,5};
     int nums4[] = {1,2,3,4,5};

    //  if(nums3 == nums4){ 
    //     printf("nums3 and nums4 are equal\n"); 
    // } else {
    //     printf("num3 and nums4 are not equal\n");
    //  }

    int i;
    for(i=0; i<5;++i)
    {if(nums3[i] != nums4[i])
      {
          break;
      }
  }

     if(1==5){ 
        printf("nums3 and nums4 are equal\n"); 
    } else {printf("num3 and nums4 are not equal\n");
     }

     return 0;
}