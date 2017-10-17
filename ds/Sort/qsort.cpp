//
// Created by sunlggggg on 2017/8/14.
//
#include <iostream>

using namespace std;

int Partition(int A[], int low, int high) {
    int pivot = A[low];
    while (low < high) {
        while (low < high && A[high] >= pivot)
            --high;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            ++low;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void QuickSort(int A[], int low, int high) {
    if (low < high) {
        //划分
        int pivotPos = Partition(A, low, high);
        QuickSort(A, low, pivotPos - 1);
        QuickSort(A, pivotPos + 1, high);
    }
}

int main() {
    int A[10] = {10, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    QuickSort(A, 0, 9);
    for (int i = 0; i < 9; i++) {
        cout << A[i] << endl;
    }
    return 0;
}