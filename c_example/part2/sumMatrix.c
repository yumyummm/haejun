#include <stdio.h>

int main(void)
{
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {11, 12, 13, 14},
        {21, 22, 23, 24}};
    int sum;

    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j < 4; ++j)
        {
            sum += matrix[i][j];
        } 
    
}
   printf("행렬의 총합은 %d입니다.\n", sum);
    return 0;
}