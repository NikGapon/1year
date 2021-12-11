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

void deleteElement(int i) {
	if (first == NULL) {
		return;
	}
	if (i == 0) {
		deleteFromHead();
		return;
	}

	struct Node* prev_ptr = first;
	struct Node* ptr = first->next;
	int index = 1;
	while (ptr != NULL) {
		if (index == i) {
			prev_ptr->next = ptr->next;
			return;
		}
		prev_ptr = ptr;
		ptr = ptr->next;
		index++;
	}
}

void main() {
	printList();

	addToHead(1);
	addToHead(3);
	addToHead(6);
	addToHead(8);
	addToHead(12);
	printList();

	deleteElement(1);
	printList();

	deleteElement(2);
	printList();

	deleteElement(4);
	printList();

	{
		int x;
		scanf("%d", &x);
	}
}
