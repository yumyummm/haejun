#include "gcd.h"

int gcd(int a , int b)
{
    int remain;
    // remain = a % b;
    while((remain = a % b) != 0){
        a = b;
        b = remain;
        // remain = a % b;
    }

    return b;
}