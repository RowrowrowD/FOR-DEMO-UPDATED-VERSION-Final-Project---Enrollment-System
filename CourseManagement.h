#ifndef COURSE_MANAGEMENT_H
#define COURSE_MANAGEMENT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "Models.h"
#include "Utils.h"
#include "DataLoader.h"

using namespace std;

vector<Course> selectedCourses;

vector<Course> courses = loadCourses();

// BSIT Curriculum Predefined (Year 1 - Year 4)
vector<Course> getBSITSubjects() {
    vector<Course> s;
    Course c;

    // Year 1 - Term 1
    c.courseCode = "ART_APP";
    c.courseTitle = "Art Appreciation";
    c.units = 3;
    c.yearLevel = 1;
    c.term = 1;
    s.push_back(c);

    c.courseCode = "ICS2601";
    c.courseTitle = "Intro to Computing";
    c.units = 3;
    c.yearLevel = 1;
    c.term = 1;
    s.push_back(c);

    c.courseCode = "ICS2602";
    c.courseTitle = "Computer Programming I";
    c.units = 5;
    c.yearLevel = 1;
    c.term = 1;
    s.push_back(c);

    c.courseCode = "MATHMW";
    c.courseTitle = "Math in Modern World";
    c.units = 3;
    c.yearLevel = 1;
    c.term = 1;
    s.push_back(c);

    c.courseCode = "THY1";
    c.courseTitle = "Christian Vision";
    c.units = 3;
    c.yearLevel = 1;
    c.term = 1;
    s.push_back(c);

    // Year 1 - Term 2
    c.courseCode = "PURCOMM";
    c.courseTitle = "Purposive Communication";
    c.units = 3;
    c.yearLevel = 1;
    c.term = 2;
    s.push_back(c);

    c.courseCode = "ICS2603";
    c.courseTitle = "Computer Programming II";
    c.units = 5;
    c.yearLevel = 1;
    c.term = 2;
    s.push_back(c);

    c.courseCode = "PE1";
    c.courseTitle = "Physical Education 1";
    c.units = 2;
    c.yearLevel = 1;
    c.term = 2;
    s.push_back(c);

    c.courseCode = "NSTP1";
    c.courseTitle = "NSTP 1";
    c.units = 3;
    c.yearLevel = 1;
    c.term = 2;
    s.push_back(c);

    c.courseCode = "PHILO";
    c.courseTitle = "Ethics";
    c.units = 3;
    c.yearLevel = 1;
    c.term = 2;
    s.push_back(c);

    // Year 2 - Term 1
    c.courseCode = "DSA";
    c.courseTitle = "Data Structures & Algorithms";
    c.units = 3;
    c.yearLevel = 2;
    c.term = 1;
    s.push_back(c);

    c.courseCode = "OOP";
    c.courseTitle = "Object-Oriented Programming";
    c.units = 3;
    c.yearLevel = 2;
    c.term = 1;
    s.push_back(c);

    c.courseCode = "DBMS";
    c.courseTitle = "Database Management Systems";
    c.units = 3;
    c.yearLevel = 2;
    c.term = 1;
    s.push_back(c);

    c.courseCode = "PE2";
    c.courseTitle = "Physical Education 2";
    c.units = 2;
    c.yearLevel = 2;
    c.term = 1;
    s.push_back(c);

    c.courseCode = "NSTP2";
    c.courseTitle = "NSTP 2";
    c.units = 3;
    c.yearLevel = 2;
    c.term = 1;
    s.push_back(c);

    // Year 2 - Term 2
    c.courseCode = "WEBDEV1";
    c.courseTitle = "Web Development 1";
    c.units = 3;
    c.yearLevel = 2;
    c.term = 2;
    s.push_back(c);

    c.courseCode = "OS";
    c.courseTitle = "Operating Systems";
    c.units = 3;
    c.yearLevel = 2;
    c.term = 2;
    s.push_back(c);

    c.courseCode = "NET1";
    c.courseTitle = "Networking Fundamentals";
    c.units = 3;
    c.yearLevel = 2;
    c.term = 2;
    s.push_back(c);

    c.courseCode = "PE3";
    c.courseTitle = "Physical Education 3";
    c.units = 2;
    c.yearLevel = 2;
    c.term = 2;
    s.push_back(c);

    // Year 3 - Term 1
    c.courseCode = "SE";
    c.courseTitle = "Software Engineering";
    c.units = 3;
    c.yearLevel = 3;
    c.term = 1;
    s.push_back(c);

    c.courseCode = "MOBDEV";
    c.courseTitle = "Mobile Development";
    c.units = 3;
    c.yearLevel = 3;
    c.term = 1;
    s.push_back(c);

    c.courseCode = "HCI";
    c.courseTitle = "Human-Computer Interaction";
    c.units = 3;
    c.yearLevel = 3;
    c.term = 1;
    s.push_back(c);

    c.courseCode = "PE4";
    c.courseTitle = "Physical Education 4";
    c.units = 2;
    c.yearLevel = 3;
    c.term = 1;
    s.push_back(c);

    // Year 3 - Term 2
    c.courseCode = "CAP1";
    c.courseTitle = "Capstone Project 1";
    c.units = 3;
    c.yearLevel = 3;
    c.term = 2;
    s.push_back(c);

    c.courseCode = "WEBDEV2";
    c.courseTitle = "Web Development 2";
    c.units = 3;
    c.yearLevel = 3;
    c.term = 2;
    s.push_back(c);

    c.courseCode = "NET2";
    c.courseTitle = "Network & Admin";
    c.units = 3;
    c.yearLevel = 3;
    c.term = 2;
    s.push_back(c);

    c.courseCode = "ELEC1";
    c.courseTitle = "Elective 1";
    c.units = 3;
    c.yearLevel = 3;
    c.term = 2;
    s.push_back(c);

    // Year 4 - Term 1
    c.courseCode = "ITPRACT";
    c.courseTitle = "IT Practicum";
    c.units = 6;
    c.yearLevel = 4;
    c.term = 1;
    s.push_back(c);

    c.courseCode = "PM";
    c.courseTitle = "Project Management";
    c.units = 3;
    c.yearLevel = 4;
    c.term = 1;
    s.push_back(c);

    c.courseCode = "IS";
    c.courseTitle = "Information Security";
    c.units = 3;
    c.yearLevel = 4;
    c.term = 1;
    s.push_back(c);

    // Year 4 - Term 2
    c.courseCode = "CAP2";
    c.courseTitle = "Capstone Project 2";
    c.units = 3;
    c.yearLevel = 4;
    c.term = 2;
    s.push_back(c);

    c.courseCode = "ENTREP";
    c.courseTitle = "Technopreneurship";
    c.units = 3;
    c.yearLevel = 4;
    c.term = 2;
    s.push_back(c);

    c.courseCode = "ELEC2";
    c.courseTitle = "Elective 2";
    c.units = 3;
    c.yearLevel = 4;
    c.term = 2;
    s.push_back(c);

    c.courseCode = "ELEC3";
    c.courseTitle = "Elective 3";
    c.units = 3;
    c.yearLevel = 4;
    c.term = 2;
    s.push_back(c);

    return s;
}

// ?? Add Courses for a Student (Filtered by Year/Term)
void addCoursesForStudent(Student currentStudent) {
    clear();
    vector<Course> bsitCourses = getBSITSubjects();
    ofstream file("courses.txt", ios::app);

    for (int i = 0; i < bsitCourses.size(); i++) {
        if (bsitCourses[i].yearLevel == currentStudent.yearLevel &&
            bsitCourses[i].term == currentStudent.term) {

            Course c = bsitCourses[i];
            selectedCourses.push_back(c);

            file << c.courseCode << "|"
                 << c.courseTitle << "|"
                 << c.units << "|"
                 << c.yearLevel << "|"
                 << c.term << "|\n";
        }
    }

    file.close();
    cout << "\nCourses saved for BSIT Year " << currentStudent.yearLevel
         << ", Term " << currentStudent.term << "\n";
    pause();
}

// View All Courses
void viewCourses() {
    clear();
    ifstream file("courses.txt");
    if (!file.is_open()) {
        cout << "Unable to open courses.txt.\n";
        pause();
        return;
    }

    string line;
    int lineNumber = 0;
    bool hasData = false;

    cout << left << setw(12) << "Code"
         << setw(30) << "Title"
         << setw(6)  << "Units"
         << setw(6)  << "Year"
         << setw(6)  << "Term" << "\n";
    cout << string(60, '-') << "\n";

    while (getline(file, line)) {
        // Skip header line
        if (lineNumber == 0 && line.find("Code") != string::npos) {
            lineNumber++;
            continue;
        }

        stringstream ss(line);
        Course c;
        string unitsStr, yearStr, termStr;

        getline(ss, c.courseCode, '|');
        getline(ss, c.courseTitle, '|');
        getline(ss, unitsStr, '|');
        getline(ss, yearStr, '|');
        getline(ss, termStr, '|');

        c.units = atoi(unitsStr.c_str());
        c.yearLevel = atoi(yearStr.c_str());
        c.term = atoi(termStr.c_str());

        cout << left << setw(12) << c.courseCode
             << setw(30) << c.courseTitle
             << setw(6)  << c.units
             << setw(6)  << c.yearLevel
             << setw(6)  << c.term << "\n";

        hasData = true;
        lineNumber++;
    }

    if (!hasData) {
        cout << "No valid course data found.\n";
    }

    file.close();
    pause();
}



void editCourse() {
    clear();
    vector<Course> courses = loadCourses();
    if (courses.empty()) {
        cout << "No courses available.\n";
        pause();
        return;
    }

    string code;
    cout << "Enter Course Code to edit: ";
    getline(cin, code);
    bool found = false;

    for (int i = 0; i < courses.size(); i++) {
        if (toUpper(courses[i].courseCode) == toUpper(code)) {
            found = true;

            cout << "\nEditing " << courses[i].courseCode << " - " << courses[i].courseTitle << "\n";
            cout << "Enter new Course Title: ";
            getline(cin, courses[i].courseTitle);

            cout << "Enter new Units: ";
            cin >> courses[i].units; cin.ignore();

            cout << "Enter new Year Level (1–4): ";
            cin >> courses[i].yearLevel; cin.ignore();

            cout << "Enter new Term (1 or 2): ";
            cin >> courses[i].term; cin.ignore();

            break;
        }
    }

    if (!found) {
        cout << "Course not found.\n";
        pause();
        return;
    }

    // Save updated list
    ofstream file("courses.txt");
    for (int i = 0; i < courses.size(); i++) {
        Course c = courses[i];
        file << c.courseCode << "|"
             << c.courseTitle << "|"
             << c.units << "|"
             << c.yearLevel << "|"
             << c.term << "|\n";
    }

    file.close();
    cout << "\nCourse updated successfully.\n";
    pause();
}


// Delete Course
void deleteCourse() {
    clear();
    vector<Course> courses = loadCourses();
    if (courses.empty()) {
        cout << "No courses available.\n";
        pause();
        return;
    }

    string code;
    cout << "Enter Course Code to delete: ";
    getline(cin, code);
    bool found = false;

    for (int i = 0; i < courses.size(); i++) {
        if (toUpper(courses[i].courseCode) == toUpper(code)) {
            found = true;
            cout << "Are you sure you want to delete " << courses[i].courseCode << "? (Y/N): ";
            string confirm;
            getline(cin, confirm);
            if (toupper(confirm[0]) == 'Y') {
                courses.erase(courses.begin() + i);
                break;
            } else {
                cout << "Deletion cancelled.\n";
                pause();
                return;
            }
        }
    }

    if (!found) {
        cout << "Course not found.\n";
        pause();
        return;
    }

    ofstream file("courses.txt");
    for (int i = 0; i < courses.size(); i++) {
        Course c = courses[i];
        file << c.courseCode << "|"
             << c.courseTitle << "|"
             << c.units << "|"
             << c.yearLevel << "|"
             << c.term << "|\n";
    }

    file.close();
    cout << "\nCourse deleted successfully.\n";
    pause();
}


#endif

