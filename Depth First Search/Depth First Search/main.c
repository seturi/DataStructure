#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001

// 연결 리스트 정의
typedef struct {
	int index;
	struct Node* next;
}Node;

Node** a;
int n, m, c[MAX_SIZE];

//  연결 리스트 삽입 함수
void addFront(Node* root, int index) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->next = root->next;
	root->next = node;
}

// 깊이 우선 탐색 함수
void dfs(int x) {
	if (c[x]) {
		return;
	}
	c[x] = 1;
	printf("%d ", x);
	Node* cur = a[x]->next;
	while (cur != NULL) {
		int next = cur->index;
		dfs(next);
		cur = cur->next;
	}
}

// 메인 함수
int main(void) {
	printf("정점과 간선의 수: ");
	scanf("%d %d", &n, &m);
	a = (Node**)malloc(sizeof(Node*) * (MAX_SIZE));
	for (int i = 1; i <= n; i++) {
		a[i] = (Node*)malloc(sizeof(Node));
		a[i]->next = NULL;
	}
	printf("연결된 정점\n");
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		addFront(a[x], y);
		addFront(a[y], x);
	}
	printf("DFS 탐색 결과: ");
	dfs(1);
	system("pause");
	return 0;
}
