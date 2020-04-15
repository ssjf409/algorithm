 /*
 
 탐색을 할때 너비를 우선으로 탐색

큐가 사용됨 
 최단거리를 구해준다. 
 
 
 다른 알고리즘에 적용한다는 것이 핵심 
 */
 
#include <iostream>
#include <queue>
#include <vector>
 
using namespace std;
 
int number = 7;
int c[7];
vector<int> a[8];
 
void bfs(int start) {
 	queue<int> q;
 	q.push(start);
 	c[start] = true;
 	while(!q.empty()) {
 		int x = q.front();
		q.pop();
		printf("%d ", x);
		for(int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if(!c[y]) {
				q.push(y);
				c[y] = true;
			}
		}
	}
} 

int main(void) {
	// 1과 2을 연겹할니다. 
	a[1].push_back(2);
	a[2].push_back(1);
	
	// 1과 3을 연겹할니다.
	a[1].push_back(3);
	a[3].push_back(1);
	
	// 2과 3을 연겹할니다.
	a[2].push_back(3);
	a[3].push_back(2); 
	
	// 2과 4을 연겹할니다.
	a[2].push_back(4);
	a[4].push_back(2);
	
	// 2과 5을 연겹할니다.
	a[2].push_back(5);
	a[5].push_back(2);
	
	// 3과 6을 연겹할니다.
	a[3].push_back(6);
	a[6].push_back(3);
	
	// 3과 7을 연겹할니다.
	a[3].push_back(7);
	a[7].push_back(3);
	
	// 4과 5을 연겹할니다.
	a[4].push_back(5);
	a[5].push_back(4);
	
	// 6과 7을 연겹할니다.
	a[6].push_back(7);
	a[7].push_back(6);
	
	
	
	bfs(1);
	
	return 0;	
}
