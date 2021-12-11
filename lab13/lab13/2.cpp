#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void f1(int n) {
	printf("%d ", n);
	if (n > 1) {
		f1(n - 2);
	}
}

void f2(int n) {
	if (n > 1) {
		f2(n - 2);
	}
	printf("%d ", n);
}

void f3(int n) {
	if (n != 1) printf("%d ", n);
	if (n > 1) {
		f3(n - 2);
	}
	if (n != 1) printf(" %d", n);
	else printf("%d", n);
}

void main() {
	f1(11);
	printf("\n");
	f2(11);
	printf("\n");
	f3(11);
	printf("\n");
	f1(7);
	printf("\n");
	f2(7);
	printf("\n");
	f3(7);
	{
		int x;
		scanf("%d", &x);
	}
}
