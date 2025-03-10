//숫자 3개를 만드시오 (0~9 사이의 서로 다른 숫자)
//숫자 3개를 입력받으세요
//위치와 숫자가 같으면 strike +1
//위치가 다르지만 숫자가 같으면 ball +1
//모든 데이터의 위치와 숫자가 동일하면 성공
//시도 횟수를 출력하는 프로그램을 만드세요


#include <stdio.h>  
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(void)
{
    int answer[3];
    int question[3];
    srand((unsigned int)time(NULL));
    
    answer[0] = rand() % 10;

    do {
        answer[1] = rand() % 10;
    } while(answer[0] == answer[1]);

    do {
        answer[2] = rand() % 10;
    } while(answer[0] == answer[2] || answer[1] == answer[2]);

    printf("%d %d %d\n", answer[0], answer[1], answer[2]);

    int count = 0;
    while (true) {
        printf("숫자 3개를 입력해주세요:\n");

        for (int i = 0; i < 3; i++) {
            scanf("%d", &question[i]);
        }

        int strike = 0;
        int ball = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (question[i] == answer[j]) {
                    if (i == j)
                        strike++;
                    else
                        ball++;
                }
            }
        }

        printf("Strike: %d, Ball: %d\n", strike, ball);

        ++count;

        if (strike == 3)
            break;
    }

    printf("축하합니다. 당신의 시도횟수는 %d입니다.\n", count);
    return 0;
}

//     for (int i = 0; i < 3; ++i)
//     {
//         randomNumber[i] = rand() % 10;

//     if (a == randomNumber[0] && b == randomNumber[1] && c == randomNumber[2])
//     {
//         printf("STRIKE + 1");
//     }
//     else
//     {
//         continue;
//         printf("YOU LOSE!\n");
//     }}

//     return 0;
// }