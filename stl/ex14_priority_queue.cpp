#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Task{
public: 
    string name;
    int priority;
    //other 대신 rhs or lhs로 변수명을 설정하는 사람도 많음. 취향 차이
    bool operator<(const Task& rhs) const {
        return priority < rhs.priority; //내림차순, 오름차순은 '>'로 바꾸면 됨!
    }
};

int main()
{
    priority_queue<Task> schedular;
    schedular.push({"Write report", 2}); //중괄호를 넣어서 입력하면 생성자 없이도 초기화가 되어서 각 값이 변수에 들어감.
    schedular.push({"Fix bug", 3});
    schedular.push({"Email team", 1});
 
    cout << "작업 처리 순서" << endl;
    while(!schedular.empty()){
        Task t = schedular.top();
        schedular.pop();
        cout << t.name << " 우선순위" <<t.priority << endl;
    } 
    return 0;
}