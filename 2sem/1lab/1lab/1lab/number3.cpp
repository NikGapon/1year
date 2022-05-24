#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <iostream>

#define maxn 100
using namespace std;
int n;
int main_list[10] = { 8, 19, -3, 7, 2, 5, 4, 20, 1, 0 };


void Sort_s(int left, int right) {
	if (right == left)
		return;
	if (right - left == 1) {
		if (main_list[right] < main_list[left])
			swap(main_list[right], main_list[left]);
		return;
	}
	int mid = (right + left) / 2;
	Sort_s(left, mid);
	Sort_s(mid + 1, right);
	int buf[maxn];
	int xl = left;
	int xr = mid + 1;
	int cur = 0;
	while (right - left + 1 != cur) {
		if (xl > mid)
			buf[cur++] = main_list[xr++];
		else if (xr > right)
			buf[cur++] = main_list[xl++];
		else if (main_list[xl] > main_list[xr])
			buf[cur++] = main_list[xr++];
		else buf[cur++] = main_list[xl++];

	}
	for (int i = 0; i < cur; i++)
		main_list[i + left] = buf[i];
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> main_list[i];

	Sort_s(0, n - 1);

	
	for (int i = 0; i < n; i++)
		cout << main_list[i] << " ";

	
	
	return 0;
}