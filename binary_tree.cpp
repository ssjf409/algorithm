/*
�������� Ž�� �ӵ��� ������ ���� ����ϴ� ���� 


������ ���� ���̱� ���ؼ� �����͸� Ȱ���Ѵ�. 

1. ���� ��ȸ : �ڽ�, ��, �� 

2. ���� ��ȸ : ��, �ڽ�, �� 

3. ���� ��ȸ  : ��, ��, �ڽ� , ���İ��� ��쿡 ���� ��� �� 

*/

#include <iostream>

using namespace std;

int number = 15;

// �ϳ��� ��� ������ �����մϴ�.

typedef struct node *treePointer; // node��� ����ü�� �������������� ����ϰٴ�. 
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
} node;

// ���� ��ȸ�� �����մϴ�.
void preorder(treePointer ptr) {
	if(ptr) {
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}


// ����  ��ȸ�� �����մϴ�.
void inorder(treePointer ptr) {
	if(ptr) {
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
} 


// ���� ��ȸ�� �����մϴ�.
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
