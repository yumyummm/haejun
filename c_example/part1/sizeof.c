#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int num;
    printf("sizeof(char) : %zu\n", sizeof(char));
    printf("sizeof(short) : %zu\n", sizeof(short));
    printf("sizeof(int) : %zu\n", sizeof(int));
    printf("sizeof(long) : %zu\n", sizeof(long)); 
    printf("sizeof(long long) : %zu\n", sizeof(long long));
    printf("sizeof(float) : %zu\n", sizeof(float));
    printf("sizeof(double) : %zu\n", sizeof(double));
    printf("sizeof(num) : %zu\n", sizeof(num));
    printf("sizeof(3.14159) : %zu\n", sizeof(3.14159));
    printf("sizeof(uint32_t) : %zu\n", sizeof(uint32_t));
    return 0;
}