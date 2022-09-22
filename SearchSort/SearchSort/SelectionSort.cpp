#include "SelectionSort.h"
#include<iostream>
using namespace std;
void SelectionSort::Sort(int arr[], int n) {
	int i, j;			//Setup of variables
	int minindex;
	int* temp;
	temp = new int;
	for (i = 0; i < n; ++i) {
		minindex = i;
		for (j = i + 1; j < n; ++j) {
			if (arr[j] < arr[minindex]) {
				minindex = j;
			}
		}
		if (minindex != i) {
			*temp = arr[minindex];
			arr[minindex] = arr[i];
			arr[i] = *temp;
		}
	}
}