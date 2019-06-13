/*
하나의 문제를 단 한번만 풀도록 하는 알고리즘

정렬 : 분할정복하여도 다시 풀게되는 문제가 없다

1번 가정. 큰 문제를 작은 문제로 나눌 수 있다.
2번 가정. 작은 문제에서 구한 정답은 그것을 포함하는 큰 문제에서도 동일
계산한 결과를 배열에 저장함으로써(메모이제이션)
 
*/

// O(N)

#include <stdio.h>

int d[100];

int dp(int x) {
	if(x == 1) return 1;
	if(x == 2) return 1;
	if(d[x] != 0) return d[x];
	return d[x] = dp(x - 1) + dp(x - 2);
}

int main(void) {
	printf("%d", dp(40));
}


/*
//2^N

#include <stdio.h>

int d[100];

int dp(int x) {
	if(x == 1) return 1;
	if(x == 2) return 1;
	return dp(x - 1) + dp(x - 2);
}

int main(void) {
	printf("%d", dp(50));
}


*/
