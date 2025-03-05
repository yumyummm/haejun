#include <stdio.h>
int main(void)
{
    int length;
    int height;
int area;

printf("Enter triangle's length ; ");
scanf("%d", &length);
printf("enter triangle's height : ");
scanf("%d", &height);
area = length * height / 2;
printf("triangles's area is : %d\n", area );

return 0;
}