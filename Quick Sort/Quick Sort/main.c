#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 1000

// �迭 ����
int a[SIZE];

int swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// �� ����
void quickSort(int start, int end) {
	if (start >= end) return;
	int key = start, i = start + 1, j = end, temp;
	while (i <= j) {
		while (i <= end && a[i] <= a[key]) {
			i++;
		}
		while (j > start&& a[j] >= a[key]) {
			j--;
		}
		if (i > j) {
			swap(&a[key], &a[j]);
		}
		else {
			swap(&a[i], &a[j]);
		}
	}
	quickSort(start, j - 1);
	quickSort(j + 1, end);
}

// ���� �Լ�
int main(void) {
	int n;
	printf("������ �迭�� ������ ��: ");
	scanf("%d", &n);
	printf("������ �迭: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	quickSort(0, n - 1);
	printf("���� ���: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}
