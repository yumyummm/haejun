#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *str1 = "apple";
    char str2[] = "apple";
    char *str3;
    str3 = (char *)malloc(sizeof(char) * 6);
    strcpy(str3, str2);
    printf("apple : %s adress %p\n", "apple", "apple");
    printf("str1 : %s adress: %p\n", str1, str1);
    printf("str2 : %s adress: %p\n", str2, str2);
    printf("str3 : %s adress: %p\n", str3, str3);

    free(str3);
    return 0;
}