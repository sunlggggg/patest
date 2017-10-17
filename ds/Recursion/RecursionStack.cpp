//
// Created by sunlggggg on 2017/8/14.
//
#include <iostream>
using namespace std;
void Recursion(int i){
    if(i == 2 )
        return;
    Recursion(++i);
    Recursion(++i);
}
int main(){
    Recursion(0);
    return 0 ;
}
