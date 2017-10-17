//
// Created by sunlggggg on 2017/8/15.
//
#include <iostream>

using namespace std;
//binary Search
int bi_search(int A[], int low, int high, int key) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (A[mid] < key) //A[mid] <=  key 对应low大于目标值一个位置
                          //A[mid] < key)  对应high小于目标值一个位置
            low = ++mid;
        else
            high = --mid;
    }
    return high;
}

int main() {
    int A[10] = {1, 2, 3, 4, 5, 6, 6, 6, 9, 10};
    int i = bi_search(A, 0, 9, 6);
    cout << i << endl;
    cout << A[i] << endl;
    flush(cout);
    return 0;
}
