#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string, pair<int, int> > a,
			 pair<string, pair<int, int> > b) {
	if(a.second.first == b.second.first) {
		return a.second.second > b.second.second;
	} else {
		return a.second.first > b.second.first;
	}
}

int main(void) {
	vector<string, pair<int, int > > > v;
	v.push_back(pair<string, pair<int, int> >("나 동 빈", pair<int, int> (90, 19961222)));
	v.push_back(pair<string, pair<int, int> >("이 태 일", pair<int, int> (97, 19930518)));
	v.push_back(pair<string, pair<int, int> >("박 한 울", pair<int, int> (95, 19930203)));
	v.push_back(pair<string, pair<int, int> >("이 상 욱", pair<int, int> (90, 19921207)));
	v.push_back(pair<string, pair<int, int> >("강 종 구", pair<int, int> (88, 19900302)));
	
	sort(v.begin(), v.end()), compare);
	
	for(int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ';
	}
	return 0;
}
