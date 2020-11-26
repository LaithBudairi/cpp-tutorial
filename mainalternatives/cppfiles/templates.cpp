//
// Created by LaithB on 11/26/2020.
//

#include <iostream>

using namespace std;

template <typename T> void print(T value);

template<typename T, int N>
class Array {
private:
    T m_array[N];

public:
    int getSize() const { return N; }
};

void templates() {
    cout << "Printing with same function different types: \n";

    print<string>("Laith");
    print(4.5);
    print(4);

    cout << "template class: \n";
    Array<int, 5> array;
    cout << array.getSize();
}

template <typename T> void print(T value) {
    cout << value << endl;
};
