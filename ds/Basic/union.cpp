//
// Created by sunlggggg on 2017/7/9.
//
// union use the same memory to store the multiple variable, and
// the size of a union is the maximum size of member
#include <cstdio>
int main(){
    union {
        int k ;
        char ch[2];
    } u ;
    u.k = 258;
    printf("%d %d\n", u.ch[0], u.ch[1]);

}

