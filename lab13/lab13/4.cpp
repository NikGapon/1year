#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void F1(int n) {
	if (n > 2) {
		printf("%d\n", n);
		F1(n - 3);
		F1(n - 4);
	}
}

void F2(int n) {
	printf("%d\n", n);
	if (n < 5) {
		F2(n + 1);
		F2(n + 3);
	}
}

void EGE1(int n) { //ÈÇ ÅÃÝ
	printf("%d ", n);
	if (n < 6) {
		EGE1(n + 2);
		EGE1(n * 3);
	}
}

void EGE2(int n)
{
	printf(" %d", n);
	if (n > 3)
	{
		EGE2(n - 2);
		EGE2(n / 2);
	}
}

void recEGE1(int n) {
	if (n >= 1) {
		printf(" %d", n);
		recEGE1(n - 1);
		recEGE1(n - 1);
	}
}

void main() {
	recEGE1(3);
	printf("\n");
	F1(10);
	printf("\n");
	F2(1);
	printf("\n");
	EGE1(1);
	printf("\n");
	EGE2(10);
	{
		int x;
		scanf("%d", &x);
	}
}
