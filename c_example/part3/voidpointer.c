#include <stdio.h>

int main(void)
{
    int i = 1000;
    double d = 3.141952;
   
    void *p;
    //p로 i 가리키기
    
    p = &i;
    printf("p의 주소값은 : &p\n", p);
    printf("p의 값은 : %d\n", *(int *)p);
    
    p = &d;
    //*p = 6.713;// 보이드 포인터 역참조는 안 됨.
    *(double *)p = 6.713;
    printf("p의 주소값은 : &p\n", p);
    printf("p의 값은 : %f\n", *(double *)p);
    
    return 0;
}