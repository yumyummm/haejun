
#include "date.h"
 


 

int main(void)
 {

    // Date d;
    // d.year = 2025;
    // d.month = 3;
    // d.day = 11;
    // Date d = {2025, 3, 11}; 일일이 넣지 말고 이렇게 넣어도 됨.
    Date d = {.year = 2025, .month = 3, .day =11, .temp = {1, 2, 3, 4, 5, 6}};
 
    Date today;
    today = d;
    printDate(&today);
    today.temp[0] = 10;
    printDate(&d);
 
    return 0;
 
}