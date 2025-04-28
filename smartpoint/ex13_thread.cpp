#include <iostream>
#include <thread>
#include <mutex> // mutually exclusive의 약자

using namespace std;

int counter = 0;
mutex mtx;

void increment(){
    for(int i=0; i < 1000; ++i){ 
        // lock_guard<mutex> lock(mtx);
        ++counter;
    }
}

int main()
{
    thread t1(increment);
    thread t2(increment);
    // ... t1, t2가 실행(execution)이 되고 있음
    t1.join(); //t1에서 실행되는 상황이 끝나면 대기하라
    // ... main 끝나고 t1이 끝난 다음
    t2.join(); // t2에서 실행되는 상황이 끝나면 대기하라
    //execution- main thread, t1 thread, t2 thread가 끝난 다음 
    cout << "최종 카운터 값" << counter << endl;
}
