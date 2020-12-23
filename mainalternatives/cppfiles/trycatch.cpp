//
// Created by LaithB on 11/26/2020.
//
#include <iostream>
#include <sstream>
using namespace std;

float division(int a, int b);

void exceptions() {
    stringstream ss;
    try {
        float x =  division(5, 0);
        cout << x << endl;
    }
    catch (const char* e) {
        cerr << e << endl;

    }
}

float division(int a, int b){
    if(b == 0) {
        throw invalid_argument("Error: Division by zero");
    }
    return a / b;
}
