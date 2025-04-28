#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <functional>
#include <vector>
#include <atomic>
#include <condition_variable>

using namespace std;

class TaskQueue{
private: 
    queue<function<void()>> tasks;
    mutex mix;
    condition_variable cv;
    vector<thread> workers;
    atomic<bool> strop(false);
};