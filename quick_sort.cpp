/*
�� ����
'���� ����' �˰���
O(N * logN)

Ư�� ���� �������� ū ���ڿ� ���� ���ڸ� ���� ��ȯ�� �ڿ� �迭�� ������ ������.
 
���� : ����� ������ ���� �־��� ��� O(N^2)�Դϴ�. 
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
	if(start >= end) { // ���Ұ� 1���� ���
		return; 
	}
	
	int key = start; // Ű�� ù��° ����
	int i = start + 1, j = end, temp;
	
	
	while(i <= j) { // ������ ������ �ݺ�
		while(i <= end && data[i] <= data[key]) { // Ű ������ ū ���� ���� ������ 
			i++; 
		}
		while(j > start && data[j] >= data[key]) { // Ű ������ ���� ���� ������ ���� 
			j--;
		}
		if(i > j) { // ���� ������ ���¸� Ű ���� ��ü
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
