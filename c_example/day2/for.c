//1부터 10까지 출력하는 for문

#include <stdio.h>

int main(void){
    for(int i = 0; i < 10; ++i)
    { 
        printf("출력되는 숫자는 %d d입니다\n", i + 1);
    }
    
    return 0;
    // for(int i = 1; i <= 10; ++i)
    // { 
    //     printf("출력되는 숫자는 %d d입니다\n", i);
    // }
    
    // return 0;  ---이건 100번 중 1번 쓸까 말까 왜냐 컴터 메모리는 0부터 세기 때문에 0부터 세는 습관을 들여야 함
    
}