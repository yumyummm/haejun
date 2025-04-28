#include<array>
#include <deque>
#include<iostream>
#include <list> 
#include <set> 

//고정 크기 배열. stl 중 속도가 가장 빠름. 오버헤드가 살짝 있어서 그냥 배열보다는 살짝 느림.
using namespace std;

int main()
{
    array<int, 10> arr = {0,1,2,3,4,5,6,7,8,9};
    for(const auto& x : arr)
        cout << x << " ";
    cout << endl;
//deque (디큐에는 많은 멤버가 정의돼 있음. 동적 크기, 장점: 양쪽 삽입과 삭제가 가능)
    deque<int> dq = {1,2,3};
    dq.push_back(4);
    dq.push_front(0);
    dq.emplace_back(5);
    dq.emplace_front(-1);
    dq.insert(dq.begin() + 3, 2.5);
    
    for(const auto& v: dq)
        cout << v << " ";
    cout << endl;
    
    dq.pop_back();
    dq.pop_front();
    
    for(const auto& v: dq)
        cout << v << " ";
    cout << endl;
    
    //list 삽입 사게 특화
    list<int> lst = {1,2,3};
    auto it = lst.begin();
    ++it;
    ++it;
    lst.insert(it, 3);
    for(const auto& v : lst)
        cout << v << " ";
    cout<<endl;

    //set 집합 - 중복이 없는 자료들, 자동 정렬
    set<int> s = {3, 1, 2, 2, 1};
    for(const auto& v : s)
        cout << v << " ";
    cout<<endl;
    cout<<"s 집합의 크기는 " << s.size() << endl;
    return 0;
}