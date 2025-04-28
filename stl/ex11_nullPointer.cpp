#include<iostream>
void func(int){ std::cout << "int\n";}
void func(int *) {std::cout << "pointer\n";}
void func(long) { std::cout << "long\n";}

int main()
{
    int *ptr = nullptr;
    int *fp;
    if(ptr==nullptr)
    {
        std::cout<< "Null pointer" << std::endl;
    }
    func(0L);
    func(1);
    func(NULL); //nullpointer로 명시를 안 하면 널포인터로 받아지지가 않고 롱으로 받아짐
    func(nullptr);
    func(ptr);
    func(fp);

    return 0;
}