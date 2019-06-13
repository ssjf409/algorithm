/*
데이터의 탐색 속도를 증진을 위해 사용하는 구조 


데이터 낭비를 줄이기 위해서 포인터를 활용한다. 

1. 전위 순회 : 자신, 왼, 오 

2. 중위 순회 : 왼, 자신, 오 

3. 후위 순회  : 왼, 오, 자신 , 수식같은 경우에 많이 사용 됨 

*/

#include <iostream>

using namespace std;

int number = 15;

// 하나의 노드 정보를 선언합니다.

typedef struct node *treePointer; // node라는 구조체를 포인터형식으로 사용하겟다. 
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
} node;

// 전위 순회를 구현합니다.
void preorder(treePointer ptr) {
	if(ptr) {
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}


// 중위  순회를 구현합니다.
void inorder(treePointer ptr) {
	if(ptr) {
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
} 


// 후위 순회를 구현합니다.
void postorder(treePointer ptr) {
	if(ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}  

int main(void) {
	node nodes[number + 1];
	for(int i = 1; i <= number; i++) {
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}
	for(int i = 1; i <= number; i++) {
		if(i % 2 == 0) {
			nodes[i / 2].leftChild = &nodes[i];
		}
		else {
			nodes[i / 2].rightChild = &nodes[i];
		}
	}
	preorder(&nodes[1]);
	return 0;
	
}
