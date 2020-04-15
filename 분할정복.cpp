/*
분할정복 
*/
const int MIN = numeric_limits<int>::min();
// A[lo, hi]의 연속된 부분 구간의 최대 합을 구한다. 시간복잡도 : O(nlgn)
int fastMaxsum(const vector<int>& A, int lo, int hi) {
    // 기저 사례: 구간의 길이가 1일 경우
    if(lo == hi) return A[lo];
    // 배열을 A[lo, mid], A[mid + 1.. hi]의 두 조각으로 나눈다.
    int mid = (lo + hi) / 2;
    // 두 부분에 모두 걸쳐 있는 최대 합 구간을 찾는다. 이 구간은
    // A[i..mid]와 A[mid+1..j] 형태를 갖는 구간의 합으로 이루어진다.
    // A[i..mid] 형태를 갖는 최대 구간을 찾는다.
    int left = MIN, right = MIN, sum = 0;
    for(int i = mid; i >= lo; --i) {
        sum += A[i];
        left = max(left, sum);
    }
    // A[mid+1..j] 형태를 갖는 최대 구간을 찾는다.
    sum = 0;
    for(int j = mid+1; j <= hi; ++j) {
        sum += A[j];
        right = max(right, sum);
    }
    // 최대 구간이 두 조각 중 하나에만 속해 있는 경우의 답을 재귀 호출로 찾는다.
    int single = max(fastMaxsum(A, lo, mid), fastMaxsum(A, mid+1, hi));
    //두 경우 중 최대치를 반환한다.
    return max(left + right, single);
}

//A[]의 연속된 부분 구간의 최대 합을 구한다. 시간 복잡도:O(n)
int fastestMaxSum(const vector<int>& A) {
    int N = A.size(), ret = MIN, psum = 0;
    for(int i = 0; i < N; ++i) {
        psum = max(psum, 0) + A[i];
        ret = max(psum, ret);
    }
    return ret;
}