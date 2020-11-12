//
// Created by LaithB on 11/12/2020.
//

#include "../../headers/oop/Student.h"

Student::Student() {
    cout << "Student created\n";
}

Student::Student(string name) {
    this->name = name;
}

Student::~Student() {
    cout << "Student is destructed \n";
}

void Student::setId(int id) {
    this->id = id;
}

int Student::getId() {
    return id;
}

string Student::getName() {
    return name;
}

void Student::setName(string name) {
    this->name = name;
}

void setStudentGrade(Student s) {
    s.grade = 66;
    cout << "Student grade from friend function: " << s.grade << '\n';
}