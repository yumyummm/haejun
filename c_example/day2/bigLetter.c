// 임의의 char를 scanf로 하나 받아서 대문자이지 소문자인지 출력하라.


#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    char ch;
    printf("알파벳 하나를 입력하시오.\n");
    scanf("%s", &ch);
    
    if(ch >= 'A' && ch <= 'Z')
    {
        printf("%c는 대문자입니다.\n", ch);
    }
    else if(ch >= 'a' && ch <= 'z')
    {
        printf("%c는 소문자입니다.\n", ch);
    }
    else
    {  
        printf("알파벳이 아닙니다.\n");
    }
return 0;

}