#include <stdio.h>

int queue[100];
int rear = 0;
int front = 0;

void push(int data)
{
    queue[rear] = data; //rear는 데이터가 들어갈 위치. 전역으로 썼기 때문에 자동으로 0으로 초기화
    rear++;
}

int pop(void)
{
    int i = front;
    ++front;
    return queue[i]; 
    // return queue[i]; 
    // ++front; 얘는 안 됨. 왜냐면, 리턴을 하고 나면 함수가 종료되니까 ++front는 실행이 안 됨.
}

int main(void)
{
    push(100);
    push(200);
    printf("1st pop() :  %d\n", pop());
    
    push(300);
    printf("2nd pop() :  %d\n", pop());
    printf("3nd pop() :  %d\n", pop());

    return 0;
}