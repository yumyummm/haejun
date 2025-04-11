#include <stdio.h>

// void my_strcpy(char *des, const char *src)
// {
// // 	int i;
// // 	for(i=0; src[i] /*!= '\0'*/; ++i)
// // 	{des[i] = src[i];}
// // des[i] = '\0';
// while (*src != '\0')
// {
// 	*des = *src; // des에 src의 값을 복사
// 	++des; // des를 다음 위치로 이동
// 	++src;
// }
// }

// void my_strcpy(char *des, const char *src)
// {
// // 	int i;
// // 	for(i=0; src[i] /*!= '\0'*/; ++i)
// // 	{des[i] = src[i];}
// // des[i] = '\0';

// while (*src)
// {
// 	*des = *src; 
// 	*des++ = *src++;
// *des = '\0'}
// }

void my_strcpy(char *des, const char *src)
{
while (*des++ = *src++)
;
}



int main(void)
{
	char str[100];
	char *str2 = "hello, world>\n";
	
	my_strcpy(str, str2);
	printf("Str2: %s\n", str);
	}
