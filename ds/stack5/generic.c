#include <stdio.h>
#include <string.h>

int main(void)
{
    int a =100;
    int b;
    
    //b=0;
    memset(&b, 0, sizeof(int)); //b를 0으로 초기화
    printf("a: %d\t b: %d\n",a, b);

    // b = a;
    memccpy(&b, &a, 0, sizeof(int)); //b에 a를 복사
    printf("a: %d\t b: %d\n",a, b);

    // int isEqual = (a == b); //연산자 우선순위
    int isEqual = (memcmp(&a, &b, sizeof(int)) == 0) ? 1 : 0; // a와 b를 비교하여 같으면 1, 다르면 0
    //int isEqual;
    // if(memcmp(&a, &b, sizeof(int)) == 0) // a와 b를 비교
    //     isEqual = 1; // 같으면 1
    // else
    //     isEqual = 0; // 다르면 0
    //int isEqual = !memcmp(&a, &b, sizeof(int)) 이렇게 써도 됨. 그런데 가독성 떨어져.

    printf("a == b: %d\n", isEqual);
    
    return 0;
}

