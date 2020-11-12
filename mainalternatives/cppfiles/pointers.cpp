//
// Created by LaithB on 11/11/2020.
//
#include <iostream>
using namespace std;

void changeValue(int*);
void changeValue(int &);
void funcPtr();

void pointers() {

    int x = 66;

    int* pInt = &x;

    cout << "Pointer to Integer x address: " << pInt << endl;
    cout << "Pointer to Integer x value: " << *pInt << endl;

    changeValue(pInt);

    cout << "Value of x after change: " << x << endl;
    cout << "Pointer to Integer x value: " << *pInt << endl;

    // pointer to array
    int arr[5];
    arr[0] = 33;
    arr[1] = 22;
    arr[2] = 11;
    arr[3] = 44;
    arr[4] = 55;

    int* pArr;
    pArr = arr;

    cout << "Printing arr values using pArr pointer: ";

    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < n; i++) {
        printf("%d ", pArr[i]);
    }
    printf("\n");

    // array of pointers;
    int* p[3];
    int pVar = 45;
    p[0] = &pVar;

    cout << "Value of 1st element in array of pointers p: " << *p[0] << endl;

    // pointer to a char in a string
    const char* pChar = "Laith"; //you cannot change the string but you can point to sth else

    cout << "2nd character that pChar is pointing to in the string is: " << pChar[1] << endl;
    cout << "1st character that pChar is pointing to in the string is: " << *pChar << endl;
    cout << "The whole string that pChar is pointing to is: " << pChar << endl;

    // void pointer
    float f = 2.5;
    int i = 6;

    void *ptr;

    ptr = &f;

    cout << "Float value of f pointed to by void pointer: " << f << endl;
    cout << "Void pointer will now point to an integer: \n" ;

    ptr = &i;

    cout << "Integer value of i pointed to by void pointer: " << i << endl;

    // You can point to a void pointer from another pointer but you need casting

    // References
    int a =10;
    int &ref = a;

    cout << "Value of a referenced by ref: " << ref << endl;

    changeValue(ref);
   // changeValue(&ref); //would pass it to the other function which takes pointer as param so a value would be 99

    cout << "Value of a referenced by ref after changing it using ref in a function: " << ref << endl;
    cout << "Value of a: " << a << endl;

    // Pointer to a function
    void(*pFunc)();
    pFunc = funcPtr;

    pFunc();

}

void changeValue(int* pInt) {
    *pInt = 99;
}

void changeValue(int &ref) {
    ref = 76;
}

void funcPtr() {
    cout << "Called function through a function pointer \n";
}
