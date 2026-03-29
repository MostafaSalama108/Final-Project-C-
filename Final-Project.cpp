#include <iostream>
#include <vector>
#include <algorithm>
#include "Student.h"

using namespace std;

vector<Student> students;

// Add Student
void addStudent() {
    int id;
    string name;
    double gpa;

    cout << "Enter ID: ";
    cin >> id;

    for (auto& s : students) {
        if (s.getId() == id) {
            cout << "ID already exists!\n";
            return;
        }
    }

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter GPA: ";
    cin >> gpa;

    if (gpa < 0.0 || gpa > 4.0) {
        cout << "Invalid GPA!\n";
        return;
    }

    students.push_back(Student(id, name, gpa));
    cout << "Student added successfully.\n";
}

// Remove Student
void removeStudent() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    auto it = remove_if(students.begin(), students.end(),
        [id](Student& s) { return s.getId() == id; });

    if (it != students.end()) {
        students.erase(it, students.end());
        cout << "Student removed.\n";
    }
    else {
        cout << "Student not found.\n";
    }
}

// Search Student
void searchStudent() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    for (auto& s : students) {
        if (s.getId() == id) {
            s.display();
            return;
        }
    }
    cout << "Not found.\n";
}

// Display All
void displayAll() {
    for (auto& s : students) {
        s.display();
    }
}

// Enroll Course
void enrollCourse() {
    int id;
    string course;

    cout << "Enter ID: ";
    cin >> id;

    for (auto& s : students) {
        if (s.getId() == id) {
            cout << "Enter Course: ";
            cin >> course;
            s.addCourse(course);
            cout << "Course added.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

// Show Courses
void showCourses() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    for (auto& s : students) {
        if (s.getId() == id) {
            s.showCourses();
            return;
        }
    }
    cout << "Student not found.\n";
}

// Sort by GPA
void sortByGPA() {
    sort(students.begin(), students.end(),
        [](Student& a, Student& b) {
            return a.getGpa() > b.getGpa();
        });

    cout << "Students sorted by GPA.\n";
}

// Main Menu
int main() {
    int choice;

    do {
        cout << "\n1. Add Student\n";
        cout << "2. Remove Student\n";
        cout << "3. Search Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Enroll Course\n";
        cout << "6. Show Courses\n";
        cout << "7. Sort by GPA\n";
        cout << "8. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addStudent(); break;
        case 2: removeStudent(); break;
        case 3: searchStudent(); break;
        case 4: displayAll(); break;
        case 5: enrollCourse(); break;
        case 6: showCourses(); break;
        case 7: sortByGPA(); break;
        case 8: cout << "Goodbye!\n"; break;
        default: cout << "Invalid choice!\n";
        }

    } while (choice != 8);

    return 0;
}

