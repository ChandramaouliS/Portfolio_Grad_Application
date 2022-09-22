#include "MergeSort.h"
#include<iostream>
#pragma once
void MergeSort::merge(int array[], int l, int m, int r) {
    int i, j, k, nl, nr;
    //size of left and right sub-arrays
    nl = m - l + 1; nr = r - m;
    int *larr = new int(nl); 
    int *rarr= new int(nr);
    //fill left and right sub-arrays
    for (i = 0; i < nl; i++)
        larr[i] = array[l + i];
    for (j = 0; j < nr; j++)
        rarr[j] = array[m + 1 + j];
    i = 0; j = 0; k = l;
    //merge temp arrays to real array
    while (i < nl && j < nr) {
        if (larr[i] <= rarr[j]) {
            array[k] = larr[i];
            i++;
        }
        else {
            array[k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < nl) {       //remnants of left array
        array[k] = larr[i];
        i++; k++;
    }
    while (j < nr) {     //remnants of right array
        array[k] = rarr[j];
        j++; k++;
    }
}
void MergeSort::mergeSort(int array[], int l, int r) {
    int m;
    if (l < r) {
        int m = l + (r - l) / 2;
        // Sort first and second arrays
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }
}