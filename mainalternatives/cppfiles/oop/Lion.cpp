//
// Created by LaithB on 11/12/2020.
//


#include "../../headers/oop/Lion.h"

void Lion::eat() {
    cout << "Lion eating...\n";
}

Lion::Lion() {
    cout << "Lion created\n";
}

Lion::Lion(char classification) : Animal(classification){

}
