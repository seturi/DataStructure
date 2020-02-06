#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ���� ����Ʈ ����ü
typedef struct {
	int data;
	struct Node* next;
} Node;

Node* head;

// ���� ����Ʈ ���� �Լ�
void addFront(Node* root, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = root->next;
	root->next = node;
}

// ���� ����Ʈ ���� �Լ�
void removeFront(Node* root) {
	Node* front = root->next;
	root->next = front->next;
	free(front);
}

// ���� ����Ʈ �޸� ���� �Լ�
void freeAll(Node* root) {
	Node* cur = head->next;
	while (cur != NULL) {
		Node* next = cur->next;
		free(cur);
		cur = next;
	}
}

// ���� ����Ʈ ��ü ��� �Լ�
void showAll(Node* root) {
	Node* cur = head->next;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

// ���� �Լ�
int main(void) {
	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	addFront(head, 2);
	addFront(head, 1);
	addFront(head, 7);
	addFront(head, 9);
	addFront(head, 8);
	removeFront(head);
	showAll(head);
	freeAll(head);
	system("pause");
	return 0;
}