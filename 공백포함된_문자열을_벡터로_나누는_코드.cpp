#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
// #include <string>


using namespace std;


int main() {
    string str;
    
    getline(cin, str);










    int bIndex = -1;
    int index = 0;

    vector<string> v;

    while(true) {
        bIndex = index;
        index = str.find(' ', bIndex);
        v.push_back(str.substr(bIndex, index - bIndex));
        if(index == -1) break;
        index++;
    }




    
    


    for(const auto& element : v) {
        cout << element << ' ' << element.size() << endl;
    }

    return 0;
}