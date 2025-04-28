#include<iostream>
#include<memory>
using namespace std;

class B; 

class A
{
public:
    int a_var = 100;
    shared_ptr<B> b_ptr;
    ~A(){cout<< "A 소멸" << endl;}
};

class B
{
public:
    int b_var = 200;
    weak_ptr<A> a_ptr;
    ~B(){cout<< "B 소멸" << endl;}
};

int main()
{

    auto a = make_shared<A>();
    auto b = make_shared<B>();
    a-> b_ptr = b;
    b-> a_ptr = a;
    cout << a->b_ptr->b_var << endl;
    cout << b->a_ptr.lock()->a_var << endl;
    return 0;
}

