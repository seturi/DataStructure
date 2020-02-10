#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ���� ����ġ �׷����� ���� ����Ʈ

// ���� ����Ʈ ����ü
typedef struct {
	int index;
	int distance;
	struct Node* next;
}Node;

// ���� ����Ʈ ���� �Լ�
void addFront(Node* root, int index, int distance) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->distance = distance;
	node->next = root->next;
	root->next = node;
}

// ���� ����Ʈ ��� �Լ�
void showAll(Node* root) {
	Node* cur = root->next;
	while (cur != NULL) {
		printf("%d(�Ÿ�: %d) ", cur->index, cur->distance);
		cur = cur->next;
	}
}

// ���� �Լ�
int main(void) {
	int n, m;
	printf("������ ������ ��: ");
	scanf("%d %d", &n, &m);
	Node** a = (Node**)malloc(sizeof(Node*) * (n + 1));
	for (int i = 1; i <= n; i++) {
		a[i] = (Node*)malloc(sizeof(Node));
		a[i]->next = NULL;
	}
	printf("����� ������ ����ġ\n");
	for (int i = 0; i < m; i++) {
		int x, y, distance;
		scanf("%d %d %d", &x, &y, &distance);
		addFront(a[x], y, distance);
	}
	printf("\n<���� ����Ʈ>\n");
	for (int i = 1; i <= n; i++) {
		printf("���� [%d]: ", i);
		showAll(a[i]);
		printf("\n");
	}
	system("pause");
	return 0;
}
