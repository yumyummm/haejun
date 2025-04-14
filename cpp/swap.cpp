#include<iostream>

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void swap2(int *pa, int *pb)
{
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

void swap3(int &ra, int &rb)
{
    int tmp = ra;
    ra = rb;
    rb = tmp;
}

int main()
{
    int a =100;
    int b = 200;

    std::cout <<"a: " << a << '\t' << "b: " << b << std::endl;
    //swap(a, b);
    swap2(&a, &b);
    std::cout <<"a: " << a << '\t' << "b: " << b << std::endl;
    swap3(a, b);
    std::cout <<"a: " << a << '\t' << "b: " << b << std::endl;

}

/*결과값: 
a: 100  b: 200
a: 200  b: 100
a: 100  b: 200 왜냐하면 막판에 한 번 더 바뀌어서 다시 a, b 값이 바뀌어서 이런 거임. 제대로 출력된 거임*/