#include "Student.h"

// Person Constructor
Person::Person(string n) {
    name = n;
}

// Student Constructor
Student::Student(int i, string n, double g) : Person(n) {
    id = i;
    gpa = g;
}

// Getters
int Student::getId() const {
    return id;
}

double Student::getGpa() const {
    return gpa;
}

string Student::getName() const {
    return name;
}

// Add Course
void Student::addCourse(string course) {
    courses.insert(course);
}

// Show Courses
void Student::showCourses() const {
    if (courses.empty()) {
        cout << "No courses enrolled.\n";
        return;
    }

    for (auto c : courses) {
        cout << "- " << c << endl;
    }
}

// Display Student
void Student::display() const {
    cout << "ID: " << id << " | Name: " << name << " | GPA: " << gpa << endl;
}
