//
// Created by LaithB on 11/12/2020.
//
#include <iostream>
#include "../headers/oop/Student.h"
#include "../headers/oop/Animal.h"
#include "../headers/oop/Lion.h"
#include <string>
using namespace std;

void oop(){
    // class student
    Student s = Student("Laith");
    s.setId(5);

    cout << "Student Id: " << s.getId() << '\n';
    cout << "Student Name: " << s.getName() << '\n';

    setStudentGrade(s);
    cout << '\n';

    // inheritance
    Lion l;

    l.eat();

    cout << '\n';

    // polymorphism
    Animal baseAnimal = Lion('A');
    baseAnimal.eat();

    cout << "\nUsing polymorphism for method binding to call the right eat function for lion\n";

    Animal* animalPoly =new Lion();
    animalPoly->eat();
    cout << "Lion classification: " << animalPoly->classification << '\n';

    delete animalPoly;
    cout << '\n';

}

