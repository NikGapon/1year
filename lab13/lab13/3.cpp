#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void rec1(int n) {
	printf(" %d", n);
	if (n > 1) {
		rec1(n - 1);
	}
}

void rec2(int n) {
	if (n > 1) {
		rec2(n - 1);
	}
	printf(" %d", n);
}

void rec3(int n) {
	printf(" %d", n);
	if (n > 1) {
		rec3(n - 1);
	}
	printf(" %d", n);
}

void main() {
	rec1(3);
	printf(" rec1 FINISH\n");

	rec2(3);
	printf(" rec2 FINISH\n");

	rec3(3);
	printf(" rec3 FINISH\n");
	{
		int x;
		scanf("%d", &x);
	}
}
