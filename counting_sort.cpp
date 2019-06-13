/*
계수 정렬 

'범위 조건'이 있는 경우 한해서 굉장히 빠른 알고리즘
O(N) 

'크기를 기준'으로 갯수만 세주면 되는 알고리즘  
*/

#include <stdio.h>

int main(void) {
	int temp;
	int count[5];
	int array[30] = {
		1, 3, 2, 4, 3, 2, 5, 3, 1, 2,
		3, 4, 4, 3, 5, 1, 2, 3, 5, 2,
		3, 1, 4, 3, 5, 1, 2, 1, 1, 1
	};
	for(int i = 0; i < 5; i++) {
		count[i] = 0;
	}
	for(int i = 0; i < 30; i++) {
		count[array[i] - 1]++;
	}
	for(int i = 0; i < 5; i++) {
		if(count[i] != 0) {
			for(int j = 0; j < count[i]; j++) {
				printf("%d", i + 1);
			}
		}
	}
	return 0;
}
