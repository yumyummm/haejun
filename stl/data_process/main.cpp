#include "data_process.hpp"
#include <iostream>
using namespace std;

int main()
{
     vector< string> words = {"apple", "ant", "banana", "bear", "cat"};
    DataProcessor processor(words);

    auto sorted = processor.sort_by_length();
     cout << "original sequence : " << endl;
    for (const auto &word : processor.data_)
         cout << word <<  endl;

     cout << "Sorted by length : " <<  endl;
    for (const auto &word : sorted)
         cout << word <<  endl;


     cout << "Filtered by prefix : " <<  endl;
     auto filtered = processor.filter_by_prefix("b");
     for (const auto &word : sorted)
          cout << word <<  endl;
          yujin@yujin-virtual-machine:~/haejun/stl/data_process$ g++ -o data_process data_process.cpp
          /usr/bin/ld: /usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/Scrt1.o: in function `_start':
          (.text+0x1b): undefined reference to `main'
          collect2: error: ld returned 1 exit status
// capture mutable 
    int min_length = 4;
    auto count_long = [=]{} mutable //외부에서 가져온 변수를 내부에서 수정할 수 있도록 만들어줌.
    {
        int count = 0;
        for(const auto &word : words)
        {
            if(word.length() >= min_length)
            {
                count++;
            }
        }
        min_length++;
        cout << "min_length" << min_length << endl;
        return count;
    };
    cout << "World with length >= 4"<< count_long() << endl;
    cout << "After mutable change, min_length: " << min_length << endl;
    return 0;
}