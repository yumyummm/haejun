#include <stdio.h>

int main()
{
    int celsius;
    celsius = 15;
    printf("input selsius temp: 7");
    scanf("%d", &celsius);
    printf("celsius temp : %d \n", celsius);
    

    double fahr;
    fahr = celsius * 9.0 / 5.0, + 32;
    printf("fahr temp : %f \n", fahr);

    return 0; 
}