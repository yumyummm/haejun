#include <memory>
#include <cstdio>
#include <iostream>
using namespace std;

class FileCloser {
public:
    void operator()(FILE *fp)
    {
        if(fp)
        {
            cout << "fclose 동작!!" << endl;
            fclose(fp);
        }
    }
};

void useUnique(unique_ptr<FILE, FileCloser> ptr) //FILE, 뒤에는 함수객체로 된 클래스를 넣으면 됨.
{
    cout << "fp를 받아서 사용한 함수" << endl;
}


int main(){
    auto fp =fopen("/home/yujin/haejun/stl/1000.txt", "r");
    unique_ptr<FILE, FileCloser> filePtr(fp);
    //
    //
    //
    // fclose(fp);
    useUnique(move(filePtr));
    cout << "main 함수의 끝" << endl;
    return 0;
}

