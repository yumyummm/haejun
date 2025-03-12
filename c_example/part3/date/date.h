#pragma once
 
#include <stdio.h>

typedef struct
{
    int year;
    int month;
    int day;
    int temp[31];

} Date;
 

#include "date.h"

void printDate(Date *);
 