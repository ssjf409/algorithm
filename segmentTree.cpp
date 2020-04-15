#include <iostream>
#include <vector>
#define NUMBER 12

using namespace std;

int a[] = {1, 9, 3, 8, 4, 5, 5, 9, 10, 3, 4, 5};
int tree[4 * NUMBER]; // 4�� ���ϸ� ��� ������ Ŀ���� �� ����. ������ ���ؼ� 2�� ���� ������ ���̸� ������ �����Դϴ�.

// start : ���� �ε���, end : �� �ε���
int init(int start, int end, int node) {
    if(start == end) return tree[node] = a[start];
    int mid = (start + end) / 2;
    
    // ��������� �� �κ����� ���� �ڿ� �� ���� �ڱ� �ڽ����� �մϴ�.
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

// start : ���� �ε���, end : �� �ε���
// left, right : ���� ���� ���ϰ��� �ϴ� ����
int sum(int start, int end, int node, int left, int right) {
    // ���� �ۿ� �ִ� ���
    if(left > end || right < start) return 0;
    // ���� �ȿ� �ִ� ���
    if(left <= start && end <= right) return tree[node];
    // �׷��� �ʴٸ� �� �κ����� ������ ���� ���ϱ�
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

// start : ���� �ε���, end : �� �ε���
// index : ���� ���� �����ϰ� �ϴ� ���
// dif : ������ ��
void update(int start, int end, int node, int index, int dif) {
    // ���� �ۿ� �ִ� ���
    if(index < start || index > end) return;
    // ���� �ȿ� ������ �������� �ٸ� ���ҵ� ����
    tree[node] += dif;
    if(start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, dif);
    update(mid + 1, end, node * 2 + 1, index, dif);
}

int main() {
    // ���� �� Ʈ���� �ε����� �����ϰ�� ��� �ε��� 0���� �����մϴ�.
    // ���� �� Ʈ�� �����ϱ�
    init(0, NUMBER - 1, 1);

    // ���� �� ���ϱ�
    cout << "0���� 12������ ������ : " << sum(0, NUMBER - 1, 1, 0, 12) << '\n';

    // ���� �� ���ϱ�
    cout << "3���� 8������ ������ : " << sum(0, NUMBER - 1, 1, 3, 8) << '\n';
    
    // ���� �� �����ϱ�
    cout << "�ε��� 5�� ���Ҹ� -5��ŭ ����" << '\n';
    update(0, NUMBER - 1, 1, 5, -5);
    
    // ���� �� �ٽ� ���ϱ�
    cout << "3���� 8���� ���� �� : " << sum(0, NUMBER - 1, 1, 0, 12) << '\n';
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
 


��ó: https://www.crocus.co.kr/649 [Crocus]

��ó: https://www.crocus.co.kr/649 [Crocus]
*/