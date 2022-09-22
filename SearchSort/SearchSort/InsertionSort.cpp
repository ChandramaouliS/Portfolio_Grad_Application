#include "InsertionSort.h"
#include<iostream>
using namespace std;
void InsertionSort::Sort(int arr[], int n) {
	int i, j, key;
	for (i = 1; i < n; ++i) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
