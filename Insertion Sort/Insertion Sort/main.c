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

// ���� �Լ� - ���� ���� ����
int main(void) {
	int n;
	printf("������ �迭�� ������ ��: ");
	scanf("%d", &n);
	printf("������ �迭: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		int j = i;
		while (j >= 0 && a[j] > a[j + 1]) {
			swap(&a[j], &a[j + 1]);
			j--;
		}
	}
	printf("���� ���: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}
