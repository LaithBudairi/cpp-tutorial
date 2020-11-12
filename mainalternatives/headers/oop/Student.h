//
// Created by LaithB on 11/12/2020.
//

#ifndef CPP_TUTORIAL_STUDENT_H
#define CPP_TUTORIAL_STUDENT_H
#include <iostream>

using namespace std;

class Student {
public:
    Student();
    Student(string name);
    ~Student();

    int id;
    string name;
    static int count;

    void setId(int id);

    int getId();

    string getName();

    void setName(string name);

    friend void setStudentGrade(Student s);

private:
    float grade;

};
#endif //CPP_TUTORIAL_STUDENT_H
