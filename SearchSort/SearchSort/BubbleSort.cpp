#include "BubbleSort.h"
using namespace std;
void BubbleSort::Sort(int* arr,int n) {
	int *temp;
	temp = new int;
	for (int i = 0; i < n-1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (arr[j + 1] < arr[j]) {
				*temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = *temp;
			}
		}
	 }
	delete temp;
}