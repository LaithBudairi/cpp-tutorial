//
// Created by LaithB on 11/11/2020.
//

#include <cstdio>
#include <iostream>

using namespace std;
void dummyFunc();
int* dummyFunc2();

void functions() {
    int* pArr = dummyFunc2();

    int n = sizeof(pArr);
    cout << "n is: " << n << endl;
    for(int i = 0; i < n; i++) {
        cout << pArr[i] << " ";
    }
    printf("\n");
    delete(pArr);
}

void dummyFunc() {
    printf("dummyFunc called\n");
}

int* dummyFunc2() {
    int* x = new int[5];

    x[0] = 5;
    x[1] = 44;
    x[2] = 23;
    x[3] = 56;
    x[4] = 14;

    return x;
}

