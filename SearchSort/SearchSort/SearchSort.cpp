// SearchSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//This is a personal project to test the concepts I learned in Data Structures courses. The original file was lost, so I take this as an opportunity to try out some new approaches 
//programming. It is implemented as a layered, menu-drivan program which allows the user to input an array and decide which kind of search and sort algorithm to employ.
//I implement the functionalities as headers and seperate classes to keep the main program clutter-free and to exploit the project style of programming that Visual Studio allows me to do
//The progam is still rather complex, which I will try to remedy later.
#include "QuickSort.h"
#include <iostream>
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "InsertionSort.h"
#include <stdlib.h>
#include "LinearSearch.h"
#include "BSearch.h"
using namespace std;
void DisplaySystem(int arr[], bool asc,int n);//For simple coding all sorting is ascending order by default and the array is merely displayed in reverse if the user requests descending.
void TakeInput(int arr[], int n);//Input of the array is abstracted for easier code maintenance
int main()
{
    int Uchoice,Schoice,Ochoice;
    int* arr;
    int n;
    SelectionSort* searchObj = new SelectionSort();
    MergeSort* mergeObj = new MergeSort();
    QuickSort* QsObj = new QuickSort();
    InsertionSort* Iobj = new InsertionSort();
    BubbleSort* BubblesearchObj = new BubbleSort();
    int* find = new int();
    LinearSearch *L1 = new LinearSearch();
    int findflag;
    BSearch* B1 = new BSearch();
L1: system("cls");
    cout << "Welcome" << endl;
    cout << "Please Enter your Choice\n1.Search\n2.Sort\n3.Quit\n";
    cin >> Uchoice;
    if (Uchoice == 3)
        exit(0);
    else {
        cout << "\nPlease enter size of array ";
        cin >> n;
        arr = new int[n + 1];
        TakeInput(arr, n);
        auto arr_size = n;
        switch (Uchoice) {
        case 1:L3:cout << "Please specify search method\n1.Linear search\n2.Binary Search\n3.Return\n";//Search Case
            cin >> Schoice;
            cout << "Enter what to search for ";
            cin >> *find;
            switch (Schoice) {                                                                          //Search Subcase implementations
            case 1:
                findflag = L1->Search(arr, n, *find);
                if (findflag != -1) {
                    cout << "\n The given itew has been found at " << findflag + 1 << endl;
                }
                else cout << " The requested item is not found.";
                break;
            case 2:
                Iobj->Sort(arr, n);//binary search only works if the array is sorted, which is one of the drawbacks.
                findflag = B1->search(arr, 0, n - 1, *find);
                cout << "\nBinary Search requires a sorted array. The given array, sorted in ascending order is:\n";
                DisplaySystem(arr, true, n);
                if (findflag != -1) {
                    cout << "\n The given itew has been found at " << findflag+1<<endl;
                }
                else cout << " The requested item is not found.";
                break;
            case 3:
                goto L1;
            default:
                cout << "Wrong entry please try again.";
                system("pause");
                break;
            }
            system("pause");
            goto L1;
            break;
        case 2:L2:cout << "Please specify which sorting algorithm you intend to use\n1.BubbleSOrt\n2.Selection Sort\n3. Merge Sort\n4. Quick Sort\n5. Insertion Sort\n6.Return\n"; //Sort Case
            cin >> Schoice;
            cout << "Ascending or Descending order? Input 1 for ascending and 0 for descending\n";
            cin >> Ochoice;
            switch (Schoice) {                                                                                      //Sort Subcase implementation.
            case 1:
                BubblesearchObj->Sort(arr, n);
                break;
            case 2:
                searchObj->Sort(arr, n);
                break;
            case 3:
                mergeObj->mergeSort(arr, 0, n - 1);
                break;
            case 4:
                arr[n] = INT_MAX;
                QsObj->SortOperation(0, n, arr);
                break;
            case 5:
                Iobj->Sort(arr, n);

                break;
            case 6:
                goto L1;
            default:
                cout << "Wrong entry. Try again";
                system("pause");
                goto L2;
            }
            if (Ochoice) DisplaySystem(arr, true, n);
            else DisplaySystem(arr, false, n);
            system("pause");
            goto L1;
            break;
        default: cout << " Wrong choice!! Please try again.";
            system("pause");
            goto L1;
            break;
        }
        delete[] arr;
        delete BubblesearchObj, searchObj, mergeObj, QsObj, Iobj;
    }
}

void TakeInput(int arr[], int n) {
    cout << "Please enter the elements of the array: ";
    for (auto i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}
void DisplaySystem(int arr[], bool asc,int n) {
    if (asc)
        for (int i = 0; i < n; ++i)
            cout << arr[i] << " ";
    else
        for (int i = n - 1; i >= 0; --i)
            cout << arr[i] << " ";
}