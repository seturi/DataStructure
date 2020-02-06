#include <stdio.h>
#define SIZE 10000
#define INF 9999999

// ���� ����
int stack[SIZE];
int top = -1;

// ���� ���� �Լ�
void push(int data) {
	if (top == SIZE - 1) {
		printf("���� �����÷ο찡 �߻��߽��ϴ�.\n");
		return;
	}
	stack[++top] = data;
}

// ���� ���� �Լ�
int pop() {
	if (top == -1) {
		printf("���� ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;
	}
	return stack[top--];
}

// ���� ��ü ��� �Լ�
void show() {
	printf("--- ������ �ֻ�� ---\n");
	for (int i = top; i >= 0; i--) {
		printf("%d\n", stack[i]);
	}
	printf("--- ������ ���ϴ� ---\n");
}

// ���� �Լ�
int main(void) {
	push(7);
	push(5);
	push(4);
	pop();
	push(6);
	pop();
	show();
	system("pause");
	return 0;
}
