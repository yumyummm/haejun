#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1) ;
    v.push_back(11);
    v.push_back(111);
    v.push_back(12345);
    // cout << "v의 첫 번째 원소는: " << v[0] << endl;
    // cout << "v의 두 번째 원소는: " << v[0] << endl;
    // cout << "v의 세 번째 원소는: " << v[0] << endl; 이 3줄은 안 좋은 하드코딩이니까 주석처리
 
    //vector<int>::iterator it; 이렇게 하면 너무 기니까 아래처럼 앞에 오토만 붙여서 씀.
    auto it = v.begin() +2;
    v.erase(it); // 111삭제
    v.at(0) = 2;

    //for문을 쓰는 첫 번째
    for(auto i=0; i<v.size(); ++i)
    {
        // cout<< "v의 " << i+1 <<"번째 원소는: "<< v[i]<<endl;
        cout<< "v의 " << i+1 <<"번째 원소는: "<< v.at(i)<<endl;
    }

    return 0;
}