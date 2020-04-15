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
queue<int> q;
vector<int> result;

void addEdge(int u, int v) {
   adj_list[u].push_back(v);
   indegree[v]++;
}

bool topologicalSort(int V) {
    for (int v = 1; v <= V; v++) {
        if (indegree[v] == 0)
            q.push(v);
    }

    for (int i = 0; i < V; i++) {
        if (q.empty()) {
            printf("has Cycle\n");
            return false;
        }
        int cur = q.front();
        q.pop();
        result.push_back(cur);
        for (auto adj : adj_list[cur]) {
            //  indegree[adj]--;
            //  if (indegree[adj] == 0) {
            //     q.push(adj);
            //  }
            if (--indegree[adj] == 0) {
                q.push(adj);
            }
        }      
    }
    return true;
}

