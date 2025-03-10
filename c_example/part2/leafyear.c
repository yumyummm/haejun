#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int year;
    while (true)
    {
        printf("년도를 넣으세요: ");
        scanf("%d", &year);
        
        //if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
       // {
            //printf("%d 년도는 %d입니다.\n", year, year % 4 ? "윤년" : "평년");
        //}
       // else
       // {
      //      printf("%d 년도는 평년입니다.\n", year);
       // }
       printf("%d 년도는 %s입니다.\n", year, year % 4 ? "윤년" : "평년");
        if (!year)
            break;
    }
}