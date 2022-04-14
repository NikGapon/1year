#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <iostream>

using namespace std;
string x;
string c;
int y;
int xx = 0;
int yy = 0;

struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
};

struct list
{
	struct Node* head;
	struct Node* tail;
	struct Node* MAX;
};

//struct Sli
//{
//	struct Node* MAX;
//	struct Node* TEC;
//};

struct list list = { NULL, NULL, NULL };
//struct list Sli = { NULL, NULL };

struct Node* first = NULL;
void addToHead(struct list* list, int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	
	if (newNode)
	{
		newNode->data = value;
		newNode->next = list->head;
		newNode->prev = NULL;

		first = newNode;
		if (list->head) list->head->prev = newNode;

		list->head = newNode;
		if (!list->tail) list->tail = newNode;
	}
}
void stack(struct list* list)
{
	cout << list->head->data;
	
	if (list->head)
	{
		struct Node* tmp = list->head;

		list->head = list->head->next;

		

		//if (list->head) list->head->prev= NULL;
		//else list->tail = NULL;

		free(tmp);
		
	}
}


	void print(struct list* list) {
		struct Node* ptr = list->head;
		while (ptr != NULL)
		{
			printf("(%d) -> ", ptr->data);
			ptr = ptr->next;
		}
		printf("NULL\n");
	}

	void go_ptr(struct list* list) {
		struct Node* ptr = list->head;
		printf("-( (%d) )- ", ptr->data);
		while (c != "0") {
			cin >> c;
			if (c == "->") {
				ptr = ptr->next;
				printf("-( (%d) )- ", ptr->data);
			}
			if (c == "<-") {
				ptr = ptr->prev;
				printf("-( (%d) )- ", ptr->data);
			}
			print(list);
		}
	}


	void test(struct list* list) {
		/*struct Node* ptr = list->head;
		struct Node* d = first;
		cout << d->data;
		cout << ptr->data;
		cout << "\n";
		cout << d->next->data;
		cout << ptr->next->data;
		cout << "\n";*/
		//cout << d->prev->data;
		//cout << ptr->prev->data;
		// 
		// 
		
		/*cout << ptr->data;
		cout << ptr->next->data;*/
		/*struct Node* d = list->tail;
		struct Node* ptr = list->head;
		
		ptr->prev = list->tail;
		d->next = list->head;*/
		/*xx = list->tail->data ;
		yy= list->head->data;
		list->head->data = xx;
		list->tail->data = yy;*/
	}
	void Eternal(struct list* list) {
		struct Node* d = list->tail;
		struct Node* ptr = list->head;

		ptr->prev = list->tail;
		d->next = list->head;
	}

	void sort_sli(struct list* list) {
		struct Node* ptr = list->head;
		struct Node* mm = list->head;
		struct Node* min = list->tail;

		while (ptr->data != min->data) {
			ptr = list->head;
			mm = list->head;
			
			while (ptr->data != min->data)
			{
				


				ptr = ptr->next;
				if (ptr->data > mm->data) {
					mm = ptr;
				}

			}
			while (min->data < mm->data) {
				if (min->data < mm->data) {
					xx = mm->data;
					yy = min->data;
					min->data = xx;
					mm->data = yy;
					if (min->data > min->prev->data) {
						min = min->prev;
					}
				}
				else {
					if (min->data > min->prev->data) {
						min = min->prev;
					}

				}
				
			}
			
			/*cout << "KOK";
			cout << ptr->data;
			cout << "\n";
			cout << mm->data;
			cout << "\n";
			cout << min->data;
			cout << "\n";
			cout << "\n";*/
		}
		
}
	

int main() {
	x = "1";
	
	addToHead(&list, 1);
	addToHead(&list, 3);
	addToHead(&list, 6);
	addToHead(&list, 8);
	print(&list);

	while ( x != "0" ) {
		cin >> x;
		//cout << x;
		
		if (x == "go") {
			go_ptr(&list);
		}
		if (x == "print") {
			print(&list);
		}
		if (x == "input") {
			cin >> y;
			addToHead(&list, y);
		}
		if (x == "stack") {

			//cout << stack(&list);
			stack(&list);
		}
		if (x == "test") {

			//cout << stack(&list);
			test(&list);
		}
		if (x == "TRUE") {

			//cout << stack(&list);
			Eternal(&list);
		}
		if (x == "sort") {

			//cout << stack(&list);
			sort_sli(&list);
		}
	}
	//printf("KOK");
	cout << "KOK";
}