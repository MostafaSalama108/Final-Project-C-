

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <set>
using namespace std;

// Base Class
class Person {
protected:
    string name;
public:
    Person(string n = "");
};

// Derived Class
class Student : public Person {
private:
    int id;
    double gpa;
    set<string> courses;

public:
    Student(int i, string n, double g);

    int getId() const;
    double getGpa() const;
    string getName() const;

    void addCourse(string course);
    void showCourses() const;
    void display() const;
};

#endif