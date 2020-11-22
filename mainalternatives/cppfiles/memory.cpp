//
// Created by LaithB on 11/19/2020.
//
#include "../headers/memory.h"
#include <iostream>
#define cube(b) b*b*b
#define MACRO(num, str) ({\
            printf("%d", num);\
            printf("is "); \
            printf("%s number", str);\
            printf("\n");\
           })

using namespace std;

void memoryManagement() {
    // new operator
    int *x = new int;
    *x = 77;

    cout << "Pointer x value stored in the referenced address (new) is: " << *x << endl;
    delete x;
    cout << "Pointer x value stored in the referenced address after de-allocating (delete) is: " << *x << endl;
//    delete x; // will cause an error

    // deleting NULL pointer
    int *p = NULL;
    delete p;
    delete p;
    delete p; // deleting NULL pointer has no effect no matter how many times you delete it
    cout << "Null pointer p address after deleting three times" << endl;

    // malloc function
    int *y = (int*) malloc(sizeof(int));
    *y = 4;

    cout << "Value of pointer y (malloc) is: " << y << endl;

    cout << "Value of pointer y stored value (malloc) is: " << *y << endl;

    // free
    free(y);

    cout << "Value of pointer y stored value (free) is: " << *y << endl;
//    free(y); // causes an error

    // calloc function
    int *z = (int*)(calloc(1, sizeof(int)));

    cout << "Initial value of z after allocating (calloc) is: " << *z << endl;

    free(z);
//    free(z); // throws Error

    cout << "Initial value of z after allocating (calloc) is: " << *z << endl;
    cout << endl;


    // Macros
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num & 1)
        MACRO(num, "Odd");
    else
        MACRO(num, "Even");
}