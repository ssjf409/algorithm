#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	vector<pair<int, string> > v;
	v.push_back(pair<int, string>(90, "박 한 울")); 
	v.push_back(pair<int, string>(85, "이 태 일")); 
	v.push_back(pair<int, string>(82, "나 동 빈")); 
	v.push_back(pair<int, string>(98, "강 종 구")); 
	v.push_back(pair<int, string>(79, "이 상 욱")); 
	
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i < v.size(); i++) {
		cout << v[i].second << ' ';
	}
	return 0;
}
