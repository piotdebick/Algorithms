//merge.h
#pragma once

//The merge function
void merge(int a[], int startIndex, int mid, int endIndex)
{
	int size = (endIndex - startIndex) + 1;
	int *b = new int[size];
	int i = startIndex;
	int k = 0;
	int j = mid + 1;
	while (i <= mid && j <= endIndex)
	{
		b[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
	}
	// Note: Only one of these two loop will execute.
	while (i <= mid)
	{
		b[k++] = a[i++];
	}
	while (j <= endIndex)
	{
		b[k++] = a[j++];
	}
	for (k = 0; k < size; k++)
	{
		a[startIndex + k] = b[k];
	}
	delete[]b;
}

//The recursive merge sort function
void merge_sort(int A[], int startIndex, int endIndex)
{
	//divide in half
	int midIndex = (startIndex + endIndex) / 2;

	//Check for base case
	if (startIndex >= endIndex)
	{
		return;
	}
	//First recursive call
	merge_sort(A, startIndex, midIndex);
	//Second recursive call
	merge_sort(A, midIndex + 1, endIndex);
	//The merge function
	merge(A, startIndex, midIndex, endIndex);

}
