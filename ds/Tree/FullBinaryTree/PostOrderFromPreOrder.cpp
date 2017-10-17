//
// Created by sunlggggg on 2017/8/15.
//

#include <iostream>

using namespace std;

//复杂度 分析 空间复杂度为O(logN) //使用了递归
//            时间复杂度为O(N*logN)
/*
 * 递归树 n (n) 2^0
 *    n/2  n/2 (n) 2^1
 *   .  ....  .    (n) 2^i-1
 *       ..
 *  1 1 .... 1 1        (n) 2^(level-1) = n
 *
 */

//如果使用数组显然只需要 N次拷贝
//            空间复杂度为O(N+logN)
//每一层内只移动一个元素
//              时间复杂度为O(N)
void trans(char A[], int pre_form, int pre_to) {
    if (pre_form < pre_to) {
        char post_root = A[pre_form];
        //移动
        int i;
        for (i = pre_form; i < pre_to; i++)
            A[i] = A[i + 1];
        A[i] = post_root;

        trans(A, pre_form, pre_form + (pre_to - pre_form - 1) / 2);
        trans(A, pre_form + (pre_to - pre_form) / 2, pre_to - 1);
    }
}

int main() {

    char A[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    trans(A, 0, 6);
    for (int i = 0; i < 7; i++) {
        cout << A[i];
    }
    return 0;
}