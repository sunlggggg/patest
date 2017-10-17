//
// Created by sunlggggg on 2017/9/11.
//

#include <iostream>

using namespace std;

int binarySearch(int data[], int value, int low, int high) {

    while (1) {
        int mid = (low + high) / 2;
        if (data[mid] == value) {
            return mid;
        } else if (data[mid] > value) {
            high = mid-1;
        } else {
            low = mid+1;
        }
        if (low == high + 1) {
            return -1;
        }
    }
}

int main() {
    int data[] = {2, 4, 6, 8, 10, 12, 14, 15};
    cout << binarySearch(data, 8, 0, 7);
    return 0;
}