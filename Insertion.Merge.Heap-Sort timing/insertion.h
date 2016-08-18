//insertion.h
#pragma once

//insertion sort
void insertion_sort(int a[], int size) {
	int i, j, tmp;
	for (i = 1; i < size; i++) {
		j = i;
		while (j > 0 && a[j - 1] > a[j]) {
			tmp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = tmp;
			j--;
		}
	}
}
