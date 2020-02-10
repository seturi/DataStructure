#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 무방향 비가중치 그래프와 인접 행렬
int a[1001][1001];
int n, m;

int main(void) {
	printf("정점과 간선의 개수: ");
	scanf("%d %d", &n, &m);
	printf("연결되어있는 정점들\n");
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		a[x][y] = 1;
		a[y][x] = 1;
	}
	printf("\n<인접 행렬>\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	system("pause");
}
