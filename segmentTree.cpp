#include <iostream>
#include <vector>
#define NUMBER 12

using namespace std;

int a[] = {1, 9, 3, 8, 4, 5, 5, 9, 10, 3, 4, 5};
int tree[4 * NUMBER]; // 4를 곱하면 모든 범위를 커버할 수 있음. 갯수에 대해서 2의 제곱 형태의 길이를 가지기 때문입니다.

// start : 시작 인덱스, end : 끝 인덱스
int init(int start, int end, int node) {
    if(start == end) return tree[node] = a[start];
    int mid = (start + end) / 2;
    
    // 재귀적으로 두 부분으로 나눈 뒤에 그 합을 자기 자신으로 합니다.
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

// start : 시작 인덱스, end : 끝 인덱스
// left, right : 구간 합을 구하고자 하는 범위
int sum(int start, int end, int node, int left, int right) {
    // 범위 밖에 있는 경우
    if(left > end || right < start) return 0;
    // 범위 안에 있는 경우
    if(left <= start && end <= right) return tree[node];
    // 그렇지 않다면 두 부분으로 나누어 합을 구하기
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

// start : 시작 인덱스, end : 끝 인덱스
// index : 구간 합을 수정하고 하는 노드
// dif : 수정할 값
void update(int start, int end, int node, int index, int dif) {
    // 범위 밖에 있는 경우
    if(index < start || index > end) return;
    // 범위 안에 있으면 내려가며 다른 원소도 갱신
    tree[node] += dif;
    if(start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, dif);
    update(mid + 1, end, node * 2 + 1, index, dif);
}

int main() {
    // 구간 합 트리의 인덱스를 제외하고는 모두 인덱스 0부터 시작합니다.
    // 구간 합 트리 생성하기
    init(0, NUMBER - 1, 1);

    // 구간 합 구하기
    cout << "0부터 12까지의 구간합 : " << sum(0, NUMBER - 1, 1, 0, 12) << '\n';

    // 구간 합 구하기
    cout << "3부터 8까지의 구간합 : " << sum(0, NUMBER - 1, 1, 3, 8) << '\n';
    
    // 구간 합 갱신하기
    cout << "인덱스 5의 원소를 -5만큼 수정" << '\n';
    update(0, NUMBER - 1, 1, 5, -5);
    
    // 구간 합 다시 구하기
    cout << "3부터 8까지 구간 합 : " << sum(0, NUMBER - 1, 1, 0, 12) << '\n';
    return 0;
}

/*
#include <cstdio>
#include <iostream>
#include <math.h>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
ll init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end)
{
    if (start == end)
        return tree[node] = arr[start];
 
    int mid = (start + end) / 2;
 
    return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}
 
void update(vector<ll> &tree, int node, int start, int end, int index, ll diff)
{
    if (!(start <= index && index <= end))
        return;
    
    tree[node] += diff;
 
    if(start != end)
    {
        int mid = (start + end) / 2;
        update(tree, node * 2, start, mid, index, diff);
        update(tree, node * 2 + 1, mid + 1, end, index, diff);
    }
 
}
 
ll sum(vector<ll> &tree, int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return 0;
 
    if (left <= start && end <= right)
        return tree[node];
 
    int mid = (start + end) / 2;
    return sum(tree, node * 2, start, mid, left, right) + sum(tree, node*2+1, mid+1, end, left, right);
}
int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
 
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
 
    vector<ll> arr(n); 
    vector<ll> tree(tree_size);
 
    for (int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);
        
    init(arr, tree, 1, 0, n - 1);
 
    m += k;
 
    while (m--)
    {
        int get;
        scanf("%d", &get);
 
        if (get == 1)
        {
            int pos;
            ll val;
            scanf("%d %lld", &pos, &val);
            ll diff = val - arr[pos - 1];
            arr[pos - 1] = val;
            update(tree, 1, 0, n - 1, pos - 1, diff);
        }
 
        else if (get == 2)
        {
            int left, right;
            scanf("%d %d", &left, &right);
            printf("%lld\n", sum(tree, 1, 0, n - 1, left - 1, right - 1));
        }
    }
    
    return 0;
}
 


출처: https://www.crocus.co.kr/649 [Crocus]

출처: https://www.crocus.co.kr/649 [Crocus]
*/