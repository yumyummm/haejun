#include<iostream>

int main()
{
    int a = 0x12345678;

    // char *p = static_cast<char *>(&a); // 이렇게 쓰면 15줄 이하처러 에러가 뜸. 왜냐 문자형 포인터는 인트형 포인터 값을 받을 수 없음. 따라서 8줄처럼 강제 형변환을 시켜줘야 함.
    char *p = reinterpret_cast<char *>(&a); 

    printf("0x%x\n", *p);

    return 0;
}

/*yujin@yujin-virtual-machine:~/haejun/cpp$ g++ -o pointer pointer.cpp
pointer.cpp: In function ‘int main()’:
pointer.cpp:7:15: error: invalid ‘static_cast’ from type ‘int*’ to type ‘char*’
    7 |     char *p = static_cast<char *>(&a);
      |               ^~~~~~~~~~~~~~~~~~~~~~~
yujin@yujin-virtual-machine:~/haejun/cpp$ ./pointer*/