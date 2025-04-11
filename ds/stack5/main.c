#include <stdio.h>
#include "stack.h"

int main(void)
{
    Stack s1, s2;
    initStack(&s1, 10, sizeof(int));  
    initStack(&s2, 100, sizeof(double));

    int i;
    // i=100; push(&s1, &i,  );
    // i=200; push(&s1, &i,  );
    // i=300; push(&s1, &i,  ); s1 인자 안에 이미 데이터 크기가 들어있으므로 사이즈오브 삭제
    i=100; push(&s1, &i);
    i=200; push(&s1, &i);
    i=300; push(&s1, &i); 

    int re;
    pop(&s1, &re); printf("s1 1st pop() :  %d\n", re);
    pop(&s1, &re); printf("s1 2nd pop() :  %d\n", re);
    pop(&s1, &re); printf("s1 3nd pop() :  %d\n", re);

    double d;
    d=1.1; push(&s2, &d);
    d=2.2; push(&s2, &d);
    d=3.3; push(&s2, &d);
    double re2;
    pop(&s2, &re2); printf("s2 1st pop() :  %f\n",re2);
    pop(&s2, &re2); printf("s2 2nd pop() :  %f\n",re2);
    pop(&s2, &re2); printf("s2 3nd pop() :  %f\n",re2);

    cleanupStack(&s1);
    cleanupStack(&s2);
    return 0;
}

