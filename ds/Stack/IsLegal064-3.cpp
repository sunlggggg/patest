//
// Created by sunlggggg on 2017/7/25.
//
#include <stdio.h>

#define PUSH 'I'
#define POP 'O'

bool IsLegal(char operartes[]) {
    int i = 0;
    bool legal = true;
    int countPush = 0;
    int countPop = 0;
    while (operartes[i] != '\0') {
        if (operartes[i] == POP) {
            countPop++;
            if (countPop > countPush) {
                legal = false;
                break;
            }
        } else
            countPush++;
        i++;
    }
    legal = legal ? countPop == countPush:legal;
    return legal;
}

int main() {
    char operates[4];
    scanf("%s",&operates);
     IsLegal(operates);
    return 0;
}