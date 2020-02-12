#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TABLE_SIZE 10007
#define INPUT_SIZE 5000

// ���� ����� ����ü ����
typedef struct {
	int id;
	char name[20];
}Student;

// ���� ����� �ؽ� ���̺��� �ʱ�ȭ �� ��ȯ �Լ�
void init(Student** hashTable) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		hashTable[i] = NULL;
	}
}

// �ؽ� ���̺��� �޸𸮸� ��ȯ�մϴ�.
void destructor(Student** hashTable) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hashTable[i] != NULL) {
			free(hashTable[i]);
		}
	}
}

// �ؽ� ���̺� �� �� ������ ���� Ž������ ã���ϴ�.
int findEmpty(Student** hashTable, int id) {
	int i = id % TABLE_SIZE;
	while (1) {
		if (hashTable[i % TABLE_SIZE] == NULL) {
			return i % TABLE_SIZE;
		}
		i++;
	}
}

// Ư���� ID ���� ��Ī�Ǵ� �����͸� �ؽ� ���̺� ������ ã���ϴ�.
int search(Student** hashTable, int id) {
	int i = id % TABLE_SIZE;
	while (1) {
		if (hashTable[i % TABLE_SIZE] == NULL) {
			return -1;
		}
		else if (hashTable[i % TABLE_SIZE]->id == id) {
			return i;
		}
		i++;
	}
}

// Ư���� Ű �ε����� �����͸� �����մϴ�.
void add(Student** hashTable, Student* input, int key) {
	hashTable[key] = input;
}

// �ؽ� ���̺��� Ư���� Ű�� �����͸� ��ȯ�մϴ�.
Student* getValue(Student** hashTable, int key) {
	return hashTable[key];
}

// �ؽ� ���̺� �����ϴ� ��� �����͸� ����մϴ�.
void show(Student** hashTable) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hashTable[i] != NULL) {
			printf("Ű: [%d] �̸�: [%s]\n", i, hashTable[i]->name);
		}
	}
}

// ���� �Լ�
int main(void) {
	Student** hashTable;
	hashTable = (Student**)malloc(sizeof(Student) * TABLE_SIZE);
	init(hashTable);

	for (int i = 0; i < INPUT_SIZE; i++) {
		Student* student = (Student*)malloc(sizeof(Student));
		student->id = rand() % 1000000;
		sprintf(student->name, "���%d", student->id);
		if (search(hashTable, student->id) == -1) {		// �ߺ��Ǵ� ID�� �������� �ʵ��� ��.
			int index = findEmpty(hashTable, student->id);
			add(hashTable, student, index);
		}
	}

	show(hashTable);
	destructor(hashTable);
	system("pause");
	return 0;
}
