#include <stdio.h>
#include <stdlib.h> // malloc, free

int main(void)
{
    int size;
    scanf("%d",&size);
   
    //int array[size]; // c99
    int *pArr = malloc(sizeof(int) * size); //힙 상에 할당된 주소값의 시작이 이 함수의 결과값
    // int *array = (int *)malloc(size * sizeof(int)); 엠알록은 보이드 포인터라서 옛날에는 이렇게 써줘야 했음 
    // pArr == NULL이라면, 메모리 할당 실패
    if(pArr == NULL){
        printf("Memory allocation failed\n");
        return 1; // 메모리 할당 실패
    }

    for(int i=0; i<size; ++i){
        *(pArr + i) = i + 1; //pArr[i] = i + 1; // 이렇게 해도 됨, 포인터 연산
    }

    for(int i=0; i<size; ++i){
        printf("%d ", *(pArr + i));
        //printf("%d", pArr[i]) // 포인터 연산
    }
    printf("\n");
    free(pArr); // 메모리 해제
    return 0;
}

//c99 출범 이전에는 중간에 선언하는 게 안 돼서 이렇게 코드를 써야만 했음