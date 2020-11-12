//
// Created by LaithB on 11/11/2020.
//
#include <iostream>;
#include "../../add/test.h";
using namespace std;
void myFunction();

void fun(short arr[]) {
    std::cout << "Size of array pointer is : " << sizeof(arr) << std::endl;
}

int add(int a , int b) {
    return a+b;
}

class Test {
    int x;
    int y;
    char c;
};

void myMain() {
    cout << "addd(1,2,3)= " << addd(1, 2, 3) << endl;
    cout << "Hello, World!" << endl; // endl inserts new line or just use \n
    float x = -2.0;
    char y = 'a';
    cout << "x is: " << x << endl;
    cout << y << endl;


    // user input
//    cout << "Type a number: ";
//    cin >> x;
//    cout << "\nNumber is: " << x << endl;

    //strings
    string s = "Laith";
    s.append(" Omar\n");

    cout << s;

    s[0] = 'G';

    cout << s;

    string name;
    // string input
//    cout << "Enter Name\n";
//
//    cin >> name;
//
//    cout << name + '\n';

    // string input whole line
//    cout << "Enter Name Again\n";
//
//    getline(cin, name);
//
//    cout << name + '\n';

    // math h
    cout << "max is: " << max(5, 10) << '\n';

    // pointers
    string food = "pizza";
    string* ptr = &food;
    string food2 = "hamburger";

    cout << *ptr << '\n';
    ptr = &food2;

    cout << *ptr << '\n';
    cout << food << '\n';

    //functions
    myFunction();


    //size of operator
    cout << "size of operator: \n";

    cout << "Size of bool: " << sizeof(bool) << endl;
    cout << "Size of short: " << sizeof(short) << endl;
    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of long: " << sizeof(long) << endl;
    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of float: " << sizeof(float) << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "Size of test class: " << sizeof(Test) << endl;

    short arr[] = {10, 20, 30, 40, 50};

    cout << "Size of arr: " << sizeof(arr) << endl;
    fun(arr);

    short *pArr = arr;

    cout << "Value of arr[0]: " << *arr << endl;
    cout << "Value of pArr: " << *pArr << endl;

    //array of strings + pointers

    string str[] = {"hi", "bye"};

    cout << "Value of str[0]: " << str[0] << endl;

    char *names[ ] = {"john",
                      "Peter",
                      "Marco",
                      "Devin",
                      "Ronan"};

    cout << names[0] << endl;

    // reference variables (must be initialized at declaration time or throws a compile-time error)
    int a = 99;
    int &ref = a;

    cout << "ref variable ref is: " << ref << '\n';

    // function pointer
    int(*funcptr)(int, int);
    funcptr = add;
    cout << "sum from function add with function pointer: " << funcptr(3, 3) << '\n';

}

void myFunction() {
    cout << "my function\n";
}

