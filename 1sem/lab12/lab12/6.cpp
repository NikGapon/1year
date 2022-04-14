//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <stdlib.h>
//
//struct Node {
//	int data;
//	struct Node* next;
//};
//
//struct Node* first = NULL;
//
//void printList() {
//	struct Node* ptr = first;
//	while (ptr != NULL) {
//		printf("(%d) -> ", ptr->data);
//		ptr = ptr->next;
//	}
//	printf("NULL\n");
//}
//
//void addToHead(int value) {
//	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//
//	newNode->next = first;
//	newNode->data = value;
//
//	first = newNode;
//}
//
//int deleteFromHead() {
//	int value = first->data;
//	struct Node* delNode = first;
//
//	first = first->next;
//	free(delNode);
//
//	return value;
//}
//
//int contains(int value) {
//	struct Node* ptr = first;
//	while (ptr != NULL) {
//		if (ptr->data == value) {
//			return 1;
//		}
//		ptr = ptr->next;
//	}
//	return 0;
//}
//
//void clearList() {
//	while (first != NULL)
//	{
//		struct Node* delNode = first;
//		first = first->next;
//		free(delNode);
//	}
//}
//
//void oddsX10() {
//	struct Node* ptr = first;
//	while (ptr != NULL) {
//		if (ptr->data % 2 == 1) {
//			ptr->data = ptr->data * 10;
//		}
//		ptr = ptr->next;
//	}
//}
//
//void main() {
//	printList();
//
//	addToHead(1);
//	addToHead(3);
//	addToHead(6);
//	addToHead(8);
//	printList();
//
//	oddsX10();
//	printList();
//
//	clearList();
//	printList();
//	{
//		int x;
//		scanf("%d", &x);
//	}
//}
