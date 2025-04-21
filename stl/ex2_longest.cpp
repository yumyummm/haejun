#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    cout << "문장을 넣으시오." << endl;
    string word;
    vector<int> sizes;
    vector<string> sentence;
    while(word!="0")
   {  cin >> word;
         sizes.push_back(word.size());
        sentence.push_back(word);
   }

    sort(sizes.begin(), sizes.end());

    cout<< "The longest line is: " << sizes[0] <<endl;
    cout<< "The shortest line is: " << sizes[sizes.size() -1] <<endl;
    for(auto v: sentence){ // 모던 형식의 for문
        cout << v << " ";
    }
    cout<< endl;
    return 0;
    

}