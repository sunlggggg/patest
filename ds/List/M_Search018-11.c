//
// Created by sunlggggg on 2017/7/18.
//
#include <stdio.h>
/**
 * find the middle of A and B respectively, and marked a and b.
 * case1:a = b return a.
 * case2:a > b  discard the greater number(the right of a ),
 *       and discard the less number(the right of b),requiring
 *       the length of discarded numbers is equal.
 * case3:b < a opposite to above.
 * @param A the array that its length is n, increasing.
 * @param B the array has the same length with A , increasing.
 * @param n the length of A and B.
 * @return the middle number
 */
int M_search(int A[] , int B[] , int n ){
    int s1 = 0 , d1 = n-1 , s2 = 0 , d2 = n - 1 , m1 , m2 ;
    while (s1 != d1 || s2 != d2 ){
        m1 = (s1 + d1)/2;
        m2 = (s2 + d2)/2;
        if(A[m1] == B[m2] )
            return  A[m1];
        else if(A[m1] < B[m2]){
            //discard the same length sequence
            if((d1+s1)%2 == 0 ){ //the length is odd
                s1 = m1 ;
                d2 = m2 ;
            }else {   //the length is even
                s1 = m1+1;
                d2 = m2 ;
            }
        }else {
            //discard the same length sequence
            if((d1+s1)%2 == 0 ){ // odd
                d1 = m1;
                s2 = m2 ;
            }else {  //even
                d1 = m1;
                s2 = m2 + 1;
            }
        }
    }
    return A[s1]<B[s2]?A[s1]:B[s2];
}
int main() {
    int A[] = {1,2,3,4,5,6};
    int B[] = {3,4,5,6,7,8};
    printf("%d",M_search(A,B,6));
    return 0;
}