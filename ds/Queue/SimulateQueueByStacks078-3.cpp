//
// Created by sunlggggg on 2017/7/26.
//
#include <iostream>

using namespace std;
#define MAXSIZE 2

struct Stack {
    int data[MAXSIZE];
    int top = -1;
};


bool Push(Stack &s, int x) {
    if (s.top != MAXSIZE - 1) {
        s.data[++s.top] = x;
        return true;
    } else
        return false;
}

bool Pop(Stack &s, int &retX) {
    if (s.top == -1)
        return false;
    else {
        retX = s.data[s.top--];
        return true;
    }
}

/**
 * S1 是暂存栈 S2是已经倒叙的栈
 * @return
 */
bool Enqueue(Stack &s1, Stack &s2, int x) {
    if (s1.top != MAXSIZE - 1) {
        Push(s1, x);
        return true;
    } else {
        if (s2.top != -1) { //s1.top == MAXSIZE - 1 &&s2.top == -1 为满
            return false;
        } else {
            while (s1.top != -1) {
                int x;
                Pop(s1, x);
                Push(s2, x);
            }
        }
        Push(s1, x);
        return true;
    }
}

bool DeQueue(Stack &s1, Stack &s2, int &x) {
    //判空
    if (s1.top == -1 && s2.top == -1)
        return false;
    else {
        if (s2.top == -1) {
            while (s1.top != -1) {
                int x;
                x = s1.data[s1.top--];
                s2.data[++s2.top] = x;
            }
        }
        x = s2.data[s2.top--];
        return true;
    }
}

int main() {
    Stack s1, s2;
    int x;
    cout << Enqueue(s1, s2, 1);
    cout << Enqueue(s1, s2, 2);
    cout << Enqueue(s1, s2, 3);
    cout << Enqueue(s1, s2, 4);

    DeQueue(s1, s2, x);
    cout << x;
    DeQueue(s1, s2, x);
    cout << x;
    DeQueue(s1, s2, x);
    cout << x;
    DeQueue(s1, s2, x);
    cout << x;
    cout << DeQueue(s1, s2, x);
    cin >> s1.top;
}