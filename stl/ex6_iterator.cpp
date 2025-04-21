#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int>::iterator it; // classs A:: class B의 형태로, iterator라는 클래스는 vector라고 하는 클래스의 멤버로 정의함이란 뜻
    vector<int> test_vector = {1,2,3,4,5,6};
    for(it = test_vector.begin(); it != test_vector.end();++it)
    {
        cout<< *it <<endl;
    }

    //iterator가 정의 - begin(), end()
    //*it 역참조가 가능헤야 한다.
    for(auto v: test_vector) //세 번째 방식 모던 C++
    {
        cout<< v <<endl;
    }
    for(auto &v: test_vector) //하나씩 순회해서 값을 변경하고 싶다.
    {    cout<< v <<endl;
    }
    for(const auto &v: test_vector) 
    {    cout<< v <<endl;
    }
    return 0;
}