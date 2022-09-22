#include "LinearSearch.h"
int LinearSearch::Search(int arr[], int n, int find) {
	int flag = -1;
	for (int i = 0; i < n; ++i) {
		if (arr[i] == find) {
			flag = i;
		}
	}
	return flag;
}