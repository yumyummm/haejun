// 60이상이면 합격을 출력

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argcv[])
{
    if(argc < 2)
    {

        printf("인자를 하나 넣어서 실험하세요.\n");
        return 0;
    }
    
    printf("score: %s --- %s\n", argcv[1], atoi(argcv[1]) >= 60 ? "합격" : "실패");
   
    return 0;

}