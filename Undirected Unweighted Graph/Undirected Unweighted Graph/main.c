#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ������ ����ġ �׷����� ���� ���
int a[1001][1001];
int n, m;

int main(void) {
	printf("������ ������ ����: ");
	scanf("%d %d", &n, &m);
	printf("����Ǿ��ִ� ������\n");
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		a[x][y] = 1;
		a[y][x] = 1;
	}
	printf("\n<���� ���>\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	system("pause");
}
