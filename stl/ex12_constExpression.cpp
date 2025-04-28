#include <iostream>
#include <type_traits> // 추가: std::is_integral_v를 사용하기 위해 필요
constexpr int square(int x) { return x * x; }
using namespace std;

template <typename T>
auto process(T value)
{
    if constexpr (is_integral_v<T>)
        return value + 1;
    else   
        return value + 0.5;
}

int main()
{
    constexpr int result = square(5); // const를 사용하면 컴파일 타임 최적화 가능
    cout << result << endl;
    cout << process(10) << endl;  // int
    cout << process(5.6) << endl; // float
    return 0;
}