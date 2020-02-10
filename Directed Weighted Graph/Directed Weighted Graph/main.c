#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 방향 가중치 그래프와 인접 리스트

// 연결 리스트 구조체
typedef struct {
	int index;
	int distance;
	struct Node* next;
}Node;

// 연결 리스트 삽입 함수
void addFront(Node* root, int index, int distance) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->distance = distance;
	node->next = root->next;
	root->next = node;
}

// 연결 리스트 출력 함수
void showAll(Node* root) {
	Node* cur = root->next;
	while (cur != NULL) {
		printf("%d(거리: %d) ", cur->index, cur->distance);
		cur = cur->next;
	}
}

// 메인 함수
int main(void) {
	int n, m;
	printf("정점과 간선의 수: ");
	scanf("%d %d", &n, &m);
	Node** a = (Node**)malloc(sizeof(Node*) * (n + 1));
	for (int i = 1; i <= n; i++) {
		a[i] = (Node*)malloc(sizeof(Node));
		a[i]->next = NULL;
	}
	printf("연결된 정점과 가중치\n");
	for (int i = 0; i < m; i++) {
		int x, y, distance;
		scanf("%d %d %d", &x, &y, &distance);
		addFront(a[x], y, distance);
	}
	printf("\n<인접 리스트>\n");
	for (int i = 1; i <= n; i++) {
		printf("원소 [%d]: ", i);
		showAll(a[i]);
		printf("\n");
	}
	system("pause");
	return 0;
}
