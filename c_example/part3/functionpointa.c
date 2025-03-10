#include <stdio.h>

int add(int a, int b){
    return a + b ;
}

int substract (int a, int b)
{
    return a - b;
}

int main(void){

    int x = 9;
    int y = 6;
    printf("add(x, y) : %d\n", add(x, y));
    printf("substract(x, y) : %d\n", substract(x, y));
    
    int(*fp)(int, int);

    fp = &add; //함수의 주소를 포인터에 연결. 함수의 이름 자체가 포인터
    // fp = add; 이래 써도 됨
    printf("add(x, y) : %d\n", (*fp)(x, y));
    fp = &substract;
    printf("substract(x, y) : %d\n", fp(x, y));// 역참조를 안 하고 그냥 해도 됨

    return 0;


}