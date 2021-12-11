#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* first = NULL;

void printList() {
	struct Node* ptr = first;
	while (ptr != NULL) {
		printf("(%d) -> ", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

void addToHead(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->next = first;
	newNode->data = value;

	first = newNode;
}

int deleteFromHead() {
	int value = first->data;
	struct Node* delNode = first;

	first = first->next;
	free(delNode);

	return value;
}

int contains(int value) {
	struct Node* ptr = first;
	while (ptr != NULL) {
		if (ptr->data == value) {
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}

void clearList() {
	while (first != NULL)
	{
		struct Node* delNode = first;
		first = first->next;
		free(delNode);
	}
}

int evenCount() {
	struct Node* ptr = first;
	int s = 0;
	while (ptr != NULL) {
		if (ptr->data % 2 == 0) {
			s++;
		}
		ptr = ptr->next;
	}
	return s;
}

void main() {
	printList();

	addToHead(1);
	addToHead(3);
	addToHead(6);
	addToHead(10);
	printList();

	printf("even numbers = %d\n", evenCount());

	clearList();
	printList();
	printf("even numbers = %d\n", evenCount());
	{
		int x;
		scanf("%d", &x);
	}
}
