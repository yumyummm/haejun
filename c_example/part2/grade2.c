// 60이상이면 합격을 출력

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argcv[])
{
    int score;
    if(argc < 2)
    {

        printf("인자를 하나 넣어서 실험하세요.\n");
        return 0;
    }
    
    score = atoi(argcv[1]);
    switch (score/10)
    {
        case 10:
            printf("축하합니다, 백점이에요!");
        case 9:
            printf("score : %d == A\n", score);
            break;
        case  8:
            printf("score : %d == B\n", score);
            break;
        case 7:
            printf("score : %d == C\n", score);
            break;
        case 6:
            printf("score : %d == D\n", score);
            break;
    }


    return 0;
}
