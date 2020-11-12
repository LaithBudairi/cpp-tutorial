//
// Created by LaithB on 11/12/2020.
//

#include "../../headers/oop/Animal.h"


Animal::Animal() {
    cout << "Animal Created\n";
}

Animal::Animal(char *color) {
    this->color = color;
}

Animal::~Animal() {
    cout << "Animal Destructed\n";
}

void Animal::eat() {
    cout << "Animal Eating...\n";
}

char *Animal::getColor() {
    return color;
}

char Animal::getClass() {
    return this->classification;
}

void Animal::setClass(char classification) {
    this->classification = classification;
}

Animal::Animal(char classification) {
    this->classification = classification;
}
