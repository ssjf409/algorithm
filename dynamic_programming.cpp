/*
�ϳ��� ������ �� �ѹ��� Ǯ���� �ϴ� �˰���

���� : ���������Ͽ��� �ٽ� Ǯ�ԵǴ� ������ ����

1�� ����. ū ������ ���� ������ ���� �� �ִ�.
2�� ����. ���� �������� ���� ������ �װ��� �����ϴ� ū ���������� ����
����� ����� �迭�� ���������ν�(�޸������̼�)
 
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
