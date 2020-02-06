#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 1000

// 배열 선언
int a[SIZE];

int swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 메인 함수 - 삽입 정렬 수행
int main(void) {
	int n;
	printf("정렬할 배열의 원소의 수: ");
	scanf("%d", &n);
	printf("정렬할 배열: ");
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
	printf("정렬 결과: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}
