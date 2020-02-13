#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define NODE_MAX 2001
#define EDGE_MAX 600001	// 양방향 간선이므로 300,000개

// 다익스트라 알고리즘 간선 구조체 정의
typedef struct {
	int cost;
	int node;
}Edge;

void swap(Edge* a, Edge* b) {
	Edge temp;
	temp.cost = a->cost;
	temp.node = a->node;
	a->cost = b->cost;
	a->node = b->node;
	b->cost = temp.cost;
	b->node = temp.node;
}

// 다익스트라 알고리즘 우선순위 큐 정의 및 삽입 함수 구현
typedef struct {
	Edge* heap[EDGE_MAX];
	int count;
}priorityQueue;

void push(priorityQueue* pq, Edge* edge) {
	if (pq->count >= EDGE_MAX) return;
	pq->heap[pq->count] = edge;
	int now = pq->count;
	int parent = (pq->count - 1) / 2;
	// 새 원소를 삽입한 이후에 상향식으로 힙을 구성합니다.
	while (now > 0 && pq->heap[now]->cost < pq->heap[parent]->cost) {
		swap(pq->heap[now], pq->heap[parent]);
		now = parent;
		parent = (parent - 1) / 2;
	}
	pq->count++;
}

// 다익스트라 알고리즘 우선순위 큐 추출 함수 구현
Edge* pop(priorityQueue* pq) {
	if (pq->count <= 0) return NULL;
	Edge* res = pq->heap[0];
	pq->count--;
	pq->heap[0] = pq->heap[pq->count];
	int now = 0, leftChild = 1, rightChild = 2;
	int target = now;
	// 새 원소를 추출한 이후에 하향식으로 힙을 구성합니다.
	while (leftChild < pq->count) {
		if (pq->heap[target]->cost > pq->heap[leftChild]->cost) target = leftChild;
		if (pq->heap[target]->cost > pq->heap[rightChild]->cost&& rightChild < pq->count) target = rightChild;
		if (target == now)break;	// 더 이상 내려가지 않아도 될 때 종료
		else {
			swap(pq->heap[now], pq->heap[target]);
			now = target;
			leftChild = now * 2 + 1;
			rightChild = now * 2 + 2;
		}
	}
	return res;
}

// 다익스트라 알고리즘 간선 연결 리스트 구현
typedef struct Node {
	Edge* data;
	struct Node* next;
}Node;

Node** adj;
int ans[NODE_MAX];

void addNode(Node** target, int index, Edge* edge) {
	if (target[index] == NULL) {
		target[index] = (Node*)malloc(sizeof(Node));
		target[index]->data = edge;
		target[index]->next = NULL;
	}
	else {
		Node* node = (Node*)malloc(sizeof(Node));
		node->data = edge;
		node->next = target[index];
		target[index] = node;
	}
}

// 메인 함수
int main(void) {
	int n, m, k;
	printf("정점과 간선의 수, 출발지점: ");
	scanf("%d %d %d", &n, &m, &k);
	adj = (Node**)malloc(sizeof(Node*) * (n + 1));
	for (int i = 1; i <= n; i++) {
		adj[i] = NULL;
		ans[i] = INT_MAX;
	}
	priorityQueue* pq;
	pq = (priorityQueue*)malloc(sizeof(priorityQueue));
	pq->count = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		printf("~에서 ~로 ~가중치: ");
		scanf("%d %d %d", &a, &b, &c);
		Edge* edge = (Edge*)malloc(sizeof(Edge));
		edge->node = b;
		edge->cost = c;
		addNode(adj, a, edge);
	}
	// 다익스트라 알고리즘을 시작합니다.
	ans[k] = 0;
	Edge* start = (Edge*)malloc(sizeof(Edge));
	start->cost = 0; start->node = k; push(pq, start);
	while (1) {
		Edge* now = pop(pq);
		if (now == NULL) break;
		int curNode = now->node;
		int curCost = now->cost;
		if (ans[curNode] < curCost) continue;
		Node* cur = adj[curNode];
		while (cur != NULL) {
			Edge* temp = cur->data;
			temp->cost += curCost;
			if (temp->cost < ans[temp->node]) { ans[temp->node] = temp->cost; push(pq, temp); }
			cur = cur->next;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (ans[i] == INT_MAX) printf("INF\n");
		else printf("%d\n", ans[i]);
	}
	system("pause");
}
