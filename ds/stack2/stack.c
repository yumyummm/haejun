
int stack[100]; //굳이 초기화 안 시켜줘도 된다고 함
int tos; //top of stack

void push(int data)
{
    stack[tos] = data; 
    tos++; // tos = tos + 1;    
}

int pop(void)
{
    tos--; 
    return stack[tos]; 
}

