#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 문자열 정의
char* parent = "acabacdabc";
char* pattern = "abacdab";

// 테이블 생성 함수 구현하기
int* makeTable(char* pattern) {
	int patternSize = strlen(pattern);
	int* table = (int*)malloc(sizeof(int) * patternSize);
	for (int i = 0; i < patternSize; i++) {
		table[i] = 0;
	}
	int j = 0;
	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

// KMP 함수 구현하기
void KMP(char* parent, char* pattern) {
	int* table = makeTable(pattern);
	int parentSize = strlen(parent);
	int patternSize = strlen(pattern);
	int j = 0;
	for (int i = 0; i < parentSize; i++) {
		while (j > 0 && parent[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (parent[i] == pattern[j]) {
			if (j == patternSize - 1) {
				printf("[인덱스 %d]에서 매칭 성공\n", i - patternSize + 2);
				j = table[j];
			}
			else {
				j++;
			}
		}
	}
}

// 메인 함수
int main(void) {
	KMP(parent, pattern);
	system("pause");
}
