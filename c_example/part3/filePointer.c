#include <stdio.h>

int main(void)
{
    FILE *a;
    a = fopen("test.dat", "w"); // Changed "W" to "w"
    if(a == NULL){
        printf("can't open file\n");
        return 1;
    }
    fprintf(a, "이것은 파일로 저장되는 예시 데이터입니다.\n");
    fclose(a);
    return 0;
}