/*
위상 정렬은 "순서가 정해져 있는 작업"
DAG(directed acyclic graph)에만 적용
사이클이 발생하는 경우 위상 정렬을 수행할 수 없다.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj_list;
vector<int> indegree;
vector<int> result;


void addEdge(int u, int v) {
    adj_list[u].push_back(v);
    indegree[v]++;
}

bool topologicalSort(int N) {
	queue<int> q;
    for(int i = 1; i <= N; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    for(int i = 0; i < N; i++) {
        if(q.empty()) {
            cout << "has Cycle\n";
            return false;
        }
        int cur = q.front();
        q.pop();
        result.push_back(cur);
        for(int j = 0; j < adj_list[cur].size(); j++) {
            int a = adj_list[cur][j];
            if(--indegree[a] == 0) q.push(a);
        }
    }
}
