#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#define SIZE 1000

// 배열 선언
int a[SIZE];

int swap(int* a, int* b) {
	int temp = *a;;
	*a = *b;
	*b = temp;
}

// 메인 함수 - 선택 정렬 수행
int main(void) {
	int n, min, index;
	printf("정렬할 배열의 원소의 개수: ");
	scanf("%d", &n);
	printf("정렬할 배열: ");
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
	printf("정렬 결과: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}
