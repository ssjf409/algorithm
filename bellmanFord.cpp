#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;


int N, M;

vector<pair<int, pair<int, int>>> edge;
vector<long long> dist;

// 음수 사이클이 있을 경우 텅 빈 배열을 반환한다.
bool bellmanFord(int start) {
    dist.assign(N + 1, INF);
	dist[start] = 0;
    
    // 모든 간선을 살펴본다.
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < edge.size(); j++) {
            int here = edge[j].first;
            int next = edge[j].second.first;
            int distance = edge[j].second.second;
            //(here, next)간선을 따라 완화를 시도한다.
            if(dist[here] == INF) continue;
            if (dist[next] > dist[here] + distance) {
                dist[next] = dist[here] + distance;
            }
        }
    }

    for (int i = 0; i < edge.size(); i++) {
        int here = edge[i].first;
        int next = edge[i].second.first;
        int distance = edge[i].second.second;
        //(here, next)간선을 따라 완화를 시도한다.
        if(dist[here] == INF) continue;
        if (dist[next] > dist[here] + distance) {
            return false;
        }
    }

    return true;
}

int main() {
    int A, B, C;
    cin >> N >> M;

    edge.assign(M, pair<int, pair<int, int>>());

    for(int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        edge[i] = {A, {B, C}};
    }

    if(bellmanFord(1)) {
        
        for(int i = 2; i <= N; i++) {
            if(dist[i] == INF) cout << -1 << '\n';
            else cout << dist[i] << '\n';
        }

    } else {
        cout << -1;
    }


    return 0;
}