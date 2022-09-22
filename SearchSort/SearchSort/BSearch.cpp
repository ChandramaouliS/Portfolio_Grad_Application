#include "BSearch.h"
int BSearch::search(int arr[], int l, int r, int x) { //recursive binary search
	if (r >= l) {
		int mid = l + (r - 1) / 2;
		if (arr[mid] == x) {
			return mid;
		}
		if (arr[mid] > x)
			return search(arr, 0, mid - 1, x);
		else
			return search(arr, mid + 1, r, x);

	}
	return -1;//This is the not found case.
}