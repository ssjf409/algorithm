/*
퀵 정렬
'분할 정복' 알고리즘
O(N * logN)

특정 값을 기준으로 큰 숫자와 작은 숫자를 서로 교환한 뒤에 배열을 반으로 나눈다.
 
단점 : 비벗값 설정에 따라 최악의 경우 O(N^2)입니다. 
*/

#include <stdio.h>

int number = 10;
int data[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

void show() {
	int i;
	for(int i = 0; i < number; i++) {
		printf("%d ", data[i]); 
	}
}

void quickSort(int *data, int start, int end) {
	if(start >= end) { // 원소가 1개인 경우
		return; 
	}
	
	int key = start; // 키는 첫번째 원소
	int i = start + 1, j = end, temp;
	
	
	while(i <= j) { // 엇갈릴 때까지 반복
		while(i <= end && data[i] <= data[key]) { // 키 값보다 큰 값을 만날 때까지 
			i++; 
		}
		while(j > start && data[j] >= data[key]) { // 키 값복다 작은 값을 만날때 까지 
			j--;
		}
		if(i > j) { // 현재 엇갈린 상태면 키 값과 교체
			temp = data[j];
			data[j] = data[key];
			data[key] = temp; 
		} else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	
	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}

int main(void) {
	quickSort(data, 0, number - 1);
	show(); 
	return 0;
}
