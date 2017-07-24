//
// Created by sunlggggg on 2017/7/24.
//
#include <iostream>
#include <malloc.h>

using namespace std;

void change(int **a ){
    int * b;
    b = (int *)malloc(sizeof(int) * 10 );
    for (int i = 0; i < 10; ++i) {
        b[i] = 10-i;
    }
    *a = b;
}

int main(){
    int **a , **b ;
    int *M , *N;
    M =  (int *)malloc(sizeof(int) * 10 );
    N =  (int *)malloc(sizeof(int) * 10 );
    for (int i = 0; i < 10; ++i) {
        M[i] = 1;
        N[i] = 2;
    }
    a = &M;
    b = &N;
    int **c ;
    *c = *a ;
    *a = *b;
    *b = *c;

    for (int i = 0; i < 10; ++i) {
        cout<<*a[i] <<endl;
        cout<<*b[i] <<endl;
    }
    return 0 ;
}