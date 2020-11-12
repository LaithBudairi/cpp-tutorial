//
// Created by LaithB on 11/12/2020.
//

#ifndef CPP_TUTORIAL_ANIMAL_H
#define CPP_TUTORIAL_ANIMAL_H
#include <iostream>

using namespace std;

class Animal {
    char* color;

public:
    Animal();
    Animal(char*);
    Animal(char);
    ~Animal();

    char classification = 'D';

    char* getColor();
    virtual void eat();

    char getClass();
    void setClass(char);


};

#endif //CPP_TUTORIAL_ANIMAL_H
