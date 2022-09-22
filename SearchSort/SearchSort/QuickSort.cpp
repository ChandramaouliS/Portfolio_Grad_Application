#include "QuickSort.h"
#include<iostream>
using namespace std;
int QuickSort::Partition(int l, int h,int arr[]) {
	int pivot = arr[l];
	int i = l;
	int j = h;
	int* temp;
	while (i < j) {
		do {
			i++;
		} while (arr[i] <= pivot);
		do {
			j--;
		} while (arr[j] > pivot);
		if (i < j) {
			temp = new int;
			*temp = arr[j];
			arr[j] = arr[i];
			arr[i] = *temp;
			delete temp;
		}

	}
	temp = new int;
	*temp = arr[j];
	arr[j] = arr[l];
	arr[l] = *temp;
	delete temp;
	return j;
}
void QuickSort::SortOperation(int l1, int h1,int arr[]) {
	int j;
	if (l1 < h1) {
		j = Partition(l1, h1,arr);
		SortOperation(l1, j,arr);
		SortOperation(j + 1, h1,arr);
	}
}

