
// //10개짜리 배열을 랜덤으로 0~100까지 만들어서 인트를 하나 scanf으로 받은 다음 같은 원소가 있는지 Index가 몇 번인지 출력하시오

// #include <stdio.h>  
// #include <stdlib.h>
// #include <time.h>

// int main(void)
// {
//     int randomNumber[10];
//     srand((unsigned int)time(NULL));
//     for (int i = 0; i < 10; ++i)
//     {
//         randomNumber[1] = rand() % 101;
//         printf("%d ", randomNumber[i]);
//         scanf("%d", &randomNumber[1])
//         if(randomNmber[1] = scanf("%d", &randomNmber[i]))
         
//             printf("")
//         }
//         /* code */
//     }
//     printf("\n");
    
//     int inputValue;
//     scanf("%d", &inputValue);
//     for(int i=0; i <10; ++i)
//     {
//         if (max < randomNmber[i])
//             max = randomNmber[i];
//             /* code */
//         }
//         printf("max : %d\n", max);
//         return 0;
//     }


#include <stdio.h>  
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int randomNumber[10];
    int value;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        randomNumber[i] = rand() % 101;
        printf("%d", randomNumber[i]);
    }
    printf("\n찾을 숫자를 입력하세요 :\n");
    
    int i;
    for(i=0; i <10; ++i)
    {
        if (value == randomNumber[i])
            break;}
            if (i < 10)
            printf("%d 숫자를 찾았다. 인덱스는 %d이다.\n", value, i);
        else
            printf("%d 숫자를 찾지 못했다.\n", value);
        
        return 0;
    }
