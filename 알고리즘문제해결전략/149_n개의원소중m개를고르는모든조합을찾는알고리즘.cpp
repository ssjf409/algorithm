#include <iostream>
#include <vector>

using namespace std;

void printPicked(vector<int>& picked) {
    
    return;
}

// n : 전체 원소의 수
// picked : 지금까지 고른 원소들의 번호
// toPick : 더 고를 원소의 수
// 일 때, 앞으로 toPick개의 원소를 고르는 모든 방법을 출력합니다.

// void pick(int n, vector<int>& picked, int toPick) {
//     // 기저 사례 : 더 고를 원소가 없을 때 고른 원소들을 출력한다.
//     if(toPick == 0) { printPicked(picked); return; }
//     // 고를 수 있는 가장 작은 번호를 계산한다.
//     int smallest = picked.empty() ? 0 : picked.back() + 1;
//     // 이 단계에서 원소 하나를 고른다.
//     for(int next = smallest; next < n; next++) {
//         picked.push_back(next);
//         pick(n, picked, toPick - 1);
//         picked.pop_back();
//     }
// }


void pick(int n, vector<int>& picked, int toPick) {
    if(toPick == 0) { printPicked(picked); return; }
    int smallest = picked.empty() ? 0 : picked.back() + 1;
    for(int next = smallest; next < n; next++) {
        picked.push_back(next);
        pick(n, picked, toPick - 1);
        picked.pop_back();
    }
}


int main() {
    return 0;
}