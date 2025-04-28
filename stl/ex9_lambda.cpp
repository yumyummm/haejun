#include <iostream>

using namespace std;
//클래스 객체를 함수 객체로 만들기
class Adder{
public:
    int offset;
    Adder(int o) : offset(o){};
    int operator()(int x) const {return x + offset;}
 };

int main()
{
    double pi= 3.1415926535;
    auto calc = [&pi](int r) -> double
    {
        pi = 30;
        return pi * r * r;};
    cout << "면적은 " << calc(3) <<endl;
    cout << "pi의 값은 " << pi <<endl;

    int sum =0;
    auto calc2 = [&sum](int x, int y)
    { sum = x + y;};
    calc2(2, 3);
    cout << "합은: " << sum << endl;

    auto calc3 = [&](int x, int y) //이렇게 그냥 전부 참조하는 식으로 &해도 됨.
    { sum = x + y + pi;};
    calc3(2, 3);
    cout << "합은: " << sum << endl;

    // vector<int> test; 
    // test(); 벡터 객체는 함수형으로 쓸 수 없기 때문에 이렇게 쓰면 오류남. 따라서 Adder라는 함수 객체를 만들어서 아래와 같이 씀.

    Adder addObject(4);
    cout << addObject(10) << endl;

    return 0;
}