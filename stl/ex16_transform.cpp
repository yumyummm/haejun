#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> nums = {1,2,3,4,5,6};
    vector<int> evens; //짝수만 필터링
    copy_if(nums.begin(), nums.end(), back_inserter(evens), [](int x){ return x % 2 == 0;});

    //제곱해서 저장하기
    vector<int> squares (evens.size());
    transform(evens.begin(), evens.end(), squares.begin(), [](int x){ return x % 2 == 0;});
    
    //출력
    cout << "짝수의 제곱 결과: "; 
    for(const auto & v : squares)
        cout << v << " ";
    cout << endl;
    return 0;
}