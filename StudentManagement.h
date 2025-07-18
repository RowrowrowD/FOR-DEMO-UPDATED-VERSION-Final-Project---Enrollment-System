#ifndef STUDENT_MANAGEMENT_H
#define STUDENT_MANAGEMENT_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include "Models.h"
#include "Utils.h"
#include "DataLoader.h"
using namespace std;

bool compareByLastName(Student a, Student b) {
    return a.lastName < b.lastName;
}

// ADD STUDENT
void addStudent() {
    clear();
    Student s;

    cout << "========= ADD NEW STUDENT =========\n";

    stringstream ss;
    ss << generateStudentID();
    s.studentID = ss.str();
    cout << "Student ID: " << s.studentID << "\n";

    do {
        cout << "Enter Last Name: ";
        getline(cin, s.lastName);
    } while (!isAlphaString(s.lastName));

    do {
        cout << "Enter First Name: ";
        getline(cin, s.firstName);
    } while (!isAlphaString(s.firstName));

    do {
        cout << "Enter Middle Name: ";
        getline(cin, s.middleName);
    } while (!isAlphaString(s.middleName));

    cout << "Enter Gender (M/F): ";
    getline(cin, s.gender);

    cout << "Enter Birthday (YYYY-MM-DD): ";
    getline(cin, s.birthday);

    cout << "Enter Address: ";
    getline(cin, s.address);

    s.degreeProgram = "BSIT";

    do {
        cout << "Enter Year Level (1-4): ";
        cin >> s.yearLevel;
    } while (s.yearLevel < 1 || s.yearLevel > 4);

    do {
        cout << "Enter Term (1 or 2): ";
        cin >> s.term;
    } while (s.term < 1 || s.term > 2);
    cin.ignore();

    currentStudent = s;

    ifstream check("students.txt");
    bool isEmpty = check.peek() == ifstream::traits_type::eof();
    check.close();

    ofstream file("students.txt", ios::app);

    if (isEmpty) {
        file << left << setw(10) << "ID"
             << setw(15) << "LastName"
             << setw(15) << "FirstName"
             << setw(15) << "MiddleName"
             << setw(8)  << "Gender"
             << setw(12) << "Birthday"
             << setw(20) << "Address"
             << setw(8)  << "Program"
             << setw(6)  << "Year"
             << setw(6)  << "Term" << "\n";
    }

    file << left << setw(10) << s.studentID
         << setw(15) << s.lastName
         << setw(15) << s.firstName
         << setw(15) << s.middleName
         << setw(8)  << s.gender
         << setw(12) << s.birthday
         << setw(20) << s.address
         << setw(8)  << s.degreeProgram
         << setw(6)  << s.yearLevel
         << setw(6)  << s.term << "\n";

    file.close();
    cout << "\nStudent added successfully.\n";
    pause();
}

// VIEW STUDENT LIST
void viewStudentList() {
    clear();
    vector<Student> students = loadStudents();

    if (students.empty()) {
        cout << "No student records found.\n";
        pause();
        return;
    }

    sort(students.begin(), students.end(), compareByLastName);

    cout << left << setw(10) << "ID"
         << setw(15) << "Last Name"
         << setw(15) << "First Name"
         << setw(15) << "Middle Name"
         << setw(8)  << "Gender"
         << setw(12) << "Birthday"
         << setw(20) << "Address"
         << setw(10) << "Program"
         << setw(5)  << "Year"
         << setw(5)  << "Term" << "\n";

    cout << string(120, '-') << "\n";

    for (int i = 0; i < students.size(); i++) {
        Student s = students[i];
        cout << left << setw(10) << s.studentID
             << setw(15) << s.lastName
             << setw(15) << s.firstName
             << setw(15) << s.middleName
             << setw(8)  << s.gender
             << setw(12) << s.birthday
             << setw(20) << s.address
             << setw(10) << s.degreeProgram
             << setw(5)  << s.yearLevel
             << setw(5)  << s.term << "\n";
    }

    pause();
}


// EDIT STUDENT
void editStudent() {
    clear();
    vector<Student> students = loadStudents();
    if (students.empty()) {
        cout << "No students available.\n";
        pause();
        return;
    }

    string id;
    cout << "Enter Student ID to edit: ";
    getline(cin, id);
    bool found = false;

    for (int i = 0; i < students.size(); i++) {
        Student& s = students[i];

        if (s.studentID == id) {
            found = true;

            cout << "\nEditing student: " << s.studentID << " - " << s.lastName << ", " << s.firstName << "\n";

            cout << "Enter new Last Name: ";
            getline(cin, s.lastName);

            cout << "Enter new First Name: ";
            getline(cin, s.firstName);

            cout << "Enter new Middle Name: ";
            getline(cin, s.middleName);

            cout << "Enter new Gender: ";
            getline(cin, s.gender);

            cout << "Enter new Birthday: ";
            getline(cin, s.birthday);

            cout << "Enter new Address: ";
            getline(cin, s.address);

            do {
                cout << "Enter Year Level (1-4): ";
                cin >> s.yearLevel;
            } while (s.yearLevel < 1 || s.yearLevel > 4);

            do {
                cout << "Enter Term (1 or 2): ";
                cin >> s.term;
            } while (s.term < 1 || s.term > 2);
            cin.ignore();

            break;
        }
    }

    if (!found) {
        cout << "Student not found.\n";
        pause();
        return;
    }

    ofstream file("students.txt");
    file << left << setw(10) << "ID"
         << setw(15) << "LastName"
         << setw(15) << "FirstName"
         << setw(15) << "MiddleName"
         << setw(10) << "Gender"
         << setw(15) << "Birthday"
         << setw(20) << "Address"
         << setw(10) << "Program"
         << setw(6)  << "Year"
         << setw(5)  << "Term" << "\n";

    for (int i = 0; i < students.size(); i++) {
        Student s = students[i];
        file << left << setw(10) << s.studentID
             << setw(15) << s.lastName
             << setw(15) << s.firstName
             << setw(15) << s.middleName
             << setw(10) << s.gender
             << setw(15) << s.birthday
             << setw(20) << s.address
             << setw(10) << s.degreeProgram
             << setw(6)  << s.yearLevel
             << setw(5)  << s.term << "\n";
    }

    file.close();
    cout << "\nStudent record updated successfully.\n";
    pause();
}

// DELETE STUDENT
void deleteStudent() {
    clear();
    vector<Student> students = loadStudents();
    if (students.empty()) {
        cout << "No student records found.\n";
        pause();
        return;
    }

    string id;
    cout << "Enter the Student ID to delete: ";
    getline(cin, id);
    bool found = false;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].studentID == id) {
            found = true;
            cout << "Are you sure you want to delete " 
                 << students[i].lastName << ", " << students[i].firstName << "? (Y/N): ";
            string confirm;
            getline(cin, confirm);
            if (toupper(confirm[0]) == 'Y') {
                students.erase(students.begin() + i);
                break;
            } else {
                cout << "Deletion cancelled.\n";
                pause();
                return;
            }
        }
    }

    if (!found) {
        cout << "Student not found.\n";
        pause();
        return;
    }

    ofstream file("students.txt");
    file << left << setw(10) << "ID"
         << setw(15) << "LastName"
         << setw(15) << "FirstName"
         << setw(15) << "MiddleName"
         << setw(10) << "Gender"
         << setw(15) << "Birthday"
         << setw(20) << "Address"
         << setw(10) << "Program"
         << setw(6)  << "Year"
         << setw(5)  << "Term" << "\n";

    for (int i = 0; i < students.size(); i++) {
        Student s = students[i];
        file << left << setw(10) << s.studentID
             << setw(15) << s.lastName
             << setw(15) << s.firstName
             << setw(15) << s.middleName
             << setw(10) << s.gender
             << setw(15) << s.birthday
             << setw(20) << s.address
             << setw(10) << s.degreeProgram
             << setw(6)  << s.yearLevel
             << setw(5)  << s.term << "\n";
    }

    file.close();
    cout << "\nStudent successfully deleted.\n";
    pause();
}

#endif

