//
// Created by sunlggggg on 2017/7/28.
//
/**
 * input n(the depth of recursion ), x(calculating param)
 * recursion expression
 * fv1 = 1 ; n = 0
 * fv2 = 2 * x; n = 1
 * fv(n,x) = 2*x*fv(n-1,x) -2(n-1)fv(n-2,x) n>1
 */
#include <iostream>

#define MAXSIZE 100

int RecursionByStack(int n, int x) {
    if (n == 0) {
        return 1;
    }

    struct {
        int depth;
        int val;
    } st[MAXSIZE];
    int top = -1;

    //recursion base
    int fv1 = 1;
    int fv2 = 2 * x;
    //push
    for (int i = n; i >= 2; --i) {
        st[++top].depth = i;
    }
    while (top > -1) {
        //fv(n,x) = 2*x*fv(n-1,x) -2(n-1)fv(n-2,x) n>1
        st[top].val = 2 * x * fv2 - 2 * (st[top].depth - 1) * fv1;
        fv1 = fv2;
        fv2 = st[top--].val;
    }
    return fv2;
}

int main() {
    while (1) {
        int n;
        int x;
        std::cin >> n >> x;
        std::cout << RecursionByStack(n, x) << std::endl;
    }
}