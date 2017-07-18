//
// Created by sunlggggg on 2017/7/18.
//
#include <stdio.h>
/**
 * n >= 1
 * @param A
 * @param n
 * @return
 */
int Majority(int A[] , int n ){
    int i, c , count = 1;
    c = A[0];
    for(i = 1; i < n ; i++ ){
        if(A[i] == c ){
            count ++ ;
        } else {
            if (count > 0)
                count--;
            else {
                c = A[i];
                count =1 ;
            }
        }
    }
    if(count > 0 )
        return c ;
    else
        return -1;
}

int main() {
    int A[] = {1,2,2,2,4,2,3,3};
    printf("%d",Majority(A,8));
    return 0;
}
