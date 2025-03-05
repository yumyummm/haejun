#include <stdio.h>
int main(void)
{
    double length;
    double height;
    double area;
    printf("Enter triangle's length ; ");
    scanf("%lf", &length);
    printf("enter triangle's height : ");
    scanf("%lf", &height);
    area = length * height / 2.0;
    printf("triangles's area is : %.2f\n", area);
    return 0;
}