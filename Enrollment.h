#ifndef ENROLLMENT_H
#define ENROLLMENT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include "Models.h"
#include "Utils.h"
#include "DataLoader.h"

using namespace std;

static inline vector<Enrollment> loadEnrollments() {
    vector<Enrollment> enrollments;
    ifstream file("enrollments.txt");
    string line;
    int lineNumber = 0;

    while (getline(file, line)) {
        // Skip header line
        if (lineNumber == 0 && line.find("StudentID") != string::npos) {
            lineNumber++;
            continue;
        }

        Enrollment e;
        stringstream ss(line);

        getline(ss, e.studentID, '|');
        getline(ss, e.courseCode, '|');
        getline(ss, e.courseTitle, '|');
        getline(ss, e.section, '|');
        getline(ss, e.day, '|');
        getline(ss, e.time, '|');
        getline(ss, e.room, '|');

        enrollments.push_back(e);
        lineNumber++;
    }

    file.close();
    return enrollments;
}


// Custom schedule loader for enrollment
vector<Schedule> loadSchedulesForEnrollment() {
    vector<Schedule> schedules;
    ifstream file("schedules.txt");
    string line;
    int lineNumber = 0;

    while (getline(file, line)) {
        // Skip header line
        if (lineNumber == 0 && line.find("Code") != string::npos) {
            lineNumber++;
            continue;
        }

        Schedule s;
        string unitsStr, yearStr, termStr;
        stringstream ss(line);

        getline(ss, s.courseCode, '|');
        getline(ss, s.courseTitle, '|');
        getline(ss, unitsStr, '|');
        getline(ss, yearStr, '|');
        getline(ss, termStr, '|');
        getline(ss, s.section, '|');
        getline(ss, s.day, '|');
        getline(ss, s.time, '|');
        getline(ss, s.room, '|');

        s.units = atoi(unitsStr.c_str());
        s.yearLevel = atoi(yearStr.c_str());
        s.term = atoi(termStr.c_str());

        schedules.push_back(s);
    }

    file.close();
    return schedules;
}

// ? Enroll a Student by Student Number
void enrollStudentFinal() {
    clear();
    vector<Student> students = loadStudents();
    vector<Schedule> schedules = loadSchedulesForEnrollment();
    vector<Enrollment> enrollees;

    string studentID;
    cout << "Enter your Student Number: ";
    getline(cin, studentID);

    Student selectedStudent;
    bool found = false;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].studentID == studentID) {
            selectedStudent = students[i];
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found.\n";
        pause();
        return;
    }

    // ? Filter schedules by student year/term
    vector<Schedule> matchingSchedules;
    for (int i = 0; i < schedules.size(); i++) {
        if (schedules[i].yearLevel == selectedStudent.yearLevel &&
            schedules[i].term == selectedStudent.term) {
            matchingSchedules.push_back(schedules[i]);
        }
    }

    if (matchingSchedules.empty()) {
        cout << "No schedules available for your year and term.\n";
        pause();
        return;
    }

    ofstream file("enrollments.txt", ios::app);
    ifstream check("enrollments.txt");
    bool isEmpty = check.peek() == ifstream::traits_type::eof();
    check.close();

    if (isEmpty) {
        file << left << setw(10) << "StudentID"
             << setw(12) << "CourseCode"
             << setw(30) << "Title"
             << setw(10) << "Section"
             << setw(8)  << "Day"
             << setw(20) << "Time"
             << setw(20) << "Room" << "\n";
    }

    // ? Enroll in each schedule
    for (int i = 0; i < matchingSchedules.size(); i++) {
        Schedule s = matchingSchedules[i];

        cout << "\nDo you want to enroll in:\n";
        cout << " " << s.courseCode << " - " << s.courseTitle << "\n";
        cout << " Section: " << s.section
             << ", Day: " << s.day
             << ", Time: " << s.time
             << ", Room: " << s.room << "\n";
        cout << "Enroll this subject? (Y/N): ";

        string confirm;
        getline(cin, confirm);

        if (toupper(confirm[0]) == 'Y') {
            file << left << setw(10) << studentID
                 << setw(12) << s.courseCode
                 << setw(30) << s.courseTitle
                 << setw(10) << s.section
                 << setw(8)  << s.day
                 << setw(20) << s.time
                 << setw(20) << s.room << "\n";
        }
    }

    file.close();
    cout << "\nYou are now enrolled in the selected subjects.\n";
    pause();
}

// ? View Enrolled Students
void viewEnrollees() {
    clear();
    vector<Enrollment> enrollees = loadEnrollments();

    if (enrollees.empty()) {
        cout << "No enrollees found yet.\n";
        pause();
        return;
    }

    cout << left << setw(10) << "StudentID"
         << setw(12) << "CourseCode"
         << setw(30) << "Title"
         << setw(10) << "Section"
         << setw(8)  << "Day"
         << setw(20) << "Time"
         << setw(20) << "Room" << "\n";

    cout << string(110, '-') << "\n";

    for (int i = 0; i < enrollees.size(); i++) {
        Enrollment e = enrollees[i];
        cout << left << setw(10) << e.studentID
             << setw(12) << e.courseCode
             << setw(30) << e.courseTitle
             << setw(10) << e.section
             << setw(8)  << e.day
             << setw(20) << e.time
             << setw(20) << e.room << "\n";
    }

    pause();
}

#endif

