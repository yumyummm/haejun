//점수를 받아서 A~F까지 출력

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    char grades[] = "FFFFFFDCBAA";
    int score;
    char grade = 'F';

    while (true)
    {
        printf("점수를 넣으세요 (종료하려면 음수를 입력하세요): ");
        scanf("%d", &score);

        if (score < 0)
        {
            break;
        }

        if(score >= 0 && score <= 100)
        {
            grade = grades[score / 10];
        }
        else
        {
            grade = 'F';
        }
        printf("점수는: %d --- %c\n", score, grade);
    }
    return 0;
}