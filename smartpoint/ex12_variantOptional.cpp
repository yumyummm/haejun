#include <iostream>
#include <variant>
#include <string>
#include <optional>
#include <any>
using namespace std;
int main()
{
    variant<int, string> data; //데이터가 하나의 메모리에 저장
    data = 42;
    cout << get<int>(data) << endl;
    data = string("hello");
    cout << get<string>(data) << endl;

    optional<int>maybeInt; //데이터가 없을 때 none이거나 nullptr일 수가 있어서 int인지 확실하지 않을 때 maybe
    maybeInt = 10;
    if(maybeInt)
        cout << *maybeInt <<endl;
    any anything = 123;
    cout << any_cast<int>(anything) <<endl;
    anything = string("hi");
    anything = 1.1;
    return 0;
}