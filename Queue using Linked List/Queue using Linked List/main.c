#include <stdio.h>
#include <stdlib.h>
#define INF 9999999

// ť ����
typedef struct {
	int data;
	struct Node* next;
}Node;

typedef struct {
	Node* front;
	Node* rear;
	int count;
}Queue;

// ť ���� �Լ�
void push(Queue* queue, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	if (queue->count == 0) {
		queue->front = node;
	}
	else {
		queue->rear->next = node;
	}
	queue->rear = node;
	queue->count++;
}

// ť ���� �Լ�
int pop(Queue* queue) {
	if (queue->count == 0) {
		printf("ť ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;
	}
	Node* node = queue->front;
	int data = node->data;
	queue->front = node->next;
	free(node);
	queue->count--;
	return data;
}

// ť ��ü ��� �Լ�
void show(Queue* queue) {
	Node* cur = queue->front;
	printf("--- ť�� �� ---\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- ť�� �� ---\n");
}

// ���� �Լ�
int main(void) {
	Queue queue;
	queue.front = queue.rear = NULL;
	queue.count = 0;
	push(&queue, 7);
	push(&queue, 5);
	push(&queue, 4);
	pop(&queue);
	push(&queue, 6);
	pop(&queue);
	show(&queue);
	system("pause");
	return 0;
}
