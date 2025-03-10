// 숫자를 입력받아서 양수, 제로, 홀수를 출력하는 프로그램
//if else 구문으로 만드세요.
// print는 한 번만 쓰세요

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argcv[]){
// {
// int num;
// char *string;
// printf("숫자를 넣으세요: ");
// scanf("%d", &num);
// if (num > 0){
//     string  = "양수";}
//     else if(num < 0){
//     string = "음수";
// }
// else
// {
//     string = "영";
// }

// printf("%d 이 숫자는 %s 입니다.\n", num, string);
// return 0;
// }

int num;
scanf("%d", &num);
printf("%d 이 숫자는  %s\n", atoi(argcv[1]) > 0 ? "양수" : num < 0 ? "음수" : "영"); 
return 0;}