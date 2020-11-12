//
// Created by LaithB on 11/11/2020.
//
#include <iostream>
using namespace std;

void arrays() {
    int arr[5] = {1, 9, 3, 4}; // you can assign the 5th element later
    int arr2[2][4] = {{1, 2, 4, 2}, {3, 4, 6, 9}};

    arr[4] = 5;

    cout << "arr 1st element: " << *arr << endl;
    cout << "arr 5th element: " << arr[4] << endl;
    cout << "elements of arr2: " << endl;
    // traverse 2d array
    int n = sizeof(arr2) / sizeof(arr2[0]);
    for(int i = 0; i < n; i++) {
        int m = sizeof(arr2[i]) / sizeof(arr2[i][0]);

        for(int j = 0; j < m; j++) {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }
}
