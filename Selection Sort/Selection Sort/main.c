#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#define SIZE 1000

// �迭 ����
int a[SIZE];

int swap(int* a, int* b) {
	int temp = *a;;
	*a = *b;
	*b = temp;
}

// ���� �Լ� - ���� ���� ����
int main(void) {
	int n, min, index;
	printf("������ �迭�� ������ ����: ");
	scanf("%d", &n);
	printf("������ �迭: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		min = INT_MAX;
		for (int j = i; j < n; j++) {
			if (min > a[j]) {
				min = a[j];
				index = j;
			}
		}
		swap(&a[i], &a[index]);
	}
	printf("���� ���: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}
