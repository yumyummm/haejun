#include <iostream>
#include "array.h"

int main()
{
    int nums[] = {1,2,3,4,5};
    Array arr1(nums, 5);
    Array arr2(10); // Array arr2 = 10; //묵시적으로 int타입이 어레이형으로 바뀜/ 변환생성자 앞에 expicit를 붙이면 묵시적인 변환생성이 일어나지 않게 됨. 따라서 이제는 
    // Array arr2(10); 의미: 내부적으로 사이즈 10짜리의 배열을 만드는데 엘리멘트들이 초기화는 안 돼있음.
    Array arr3;
    Array arr4 = arr1;

    arr2=arr1;
    if(arr1==arr2){
        std::cout << "arr1 and arr2 are equal" << std::endl;
    } else {
        std::cout << "arr1 and arr2 are not equal" << std::endl;
    }

    for(int i=0;i<arr1.size(); ++i)
    {
        std::cout << arr1[i]<<std::endl; // arr1.operator[](i)
    }

    for(int i=0;i<arr4.size(); ++i)
    {
        std::cout << arr4[i]<<std::endl; // arr1.operator[](i)
    }

    // std::cout << "ARRAY_SIZE: "<< ARRAY_SIZE <<std::endl;
    // std::cout << "ARRAY_SIZE: "<< Array::ARRAY_SIZE << std::endl; 
    std::cout << "ARRAY_SIZE: " << Array::getDefaultArraySize() << std::endl; 
    
}

