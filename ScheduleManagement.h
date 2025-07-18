#ifndef SCHEDULE_MANAGEMENT_H
#define SCHEDULE_MANAGEMENT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "Models.h"
#include "Utils.h"
#include "DataLoader.h"

using namespace std;

vector<Schedule> selectedSchedules;

// ? Add Schedules for Courses
void addScheduleForCourses(vector<Course> courses) {
    clear();
    Schedule sched;
    ofstream file("schedules.txt", ios::app);

    ifstream check("schedules.txt");
    bool isEmpty = check.peek() == ifstream::traits_type::eof();
    check.close();

    if (isEmpty) {
        file << "Code|Title|Units|Year|Term|Section|Day|Time|Room|\n";
    }

    for (int i = 0; i < courses.size(); i++) {
        Schedule s;
        s.courseCode = courses[i].courseCode;
        s.courseTitle = courses[i].courseTitle;
        s.units = courses[i].units;
        s.yearLevel = courses[i].yearLevel;
        s.term = courses[i].term;

        cout << "\nEnter schedule for: " << s.courseCode << " - " << s.courseTitle << "\n";

        do {
            cout << "Section (A/B): ";
            getline(cin, s.section);
        } while (!(s.section == "A" || s.section == "B"));

        do {
            cout << "Day [1] MWF, [2] TTh: ";
            string input;
            getline(cin, input);
            if (input == "1") s.day = "MWF";
            else if (input == "2") s.day = "TTh";
        } while (s.day != "MWF" && s.day != "TTh");

        do {
            cout << "Time [1] 7-10AM, [2] 1-4PM, [3] 5-8PM: ";
            string t;
            getline(cin, t);
            if (t == "1") s.time = "7:00AM - 10:00AM";
            else if (t == "2") s.time = "1:00PM - 4:00PM";
            else if (t == "3") s.time = "5:00PM - 8:00PM";
        } while (s.time == "");

        do {
            cout << "Room [1] Main Branch, [2] Branch Building: ";
            string r;
            getline(cin, r);
            if (r == "1") s.room = "Main Branch";
            else if (r == "2") s.room = "Branch Building";
        } while (s.room == "");

        selectedSchedules.push_back(s);

        file << s.courseCode << "|"
             << s.courseTitle << "|"
             << s.units << "|"
             << s.yearLevel << "|"
             << s.term << "|"
             << s.section << "|"
             << s.day << "|"
             << s.time << "|"
             << s.room << "|\n";
    }

    file.close();
    cout << "\nSchedules successfully added.\n";
    pause();
}

// ? View All Schedules
void viewSchedules() {
    clear();
    ifstream file("schedules.txt");
    if (!file.is_open()) {
        cout << "Unable to open schedules.txt.\n";
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
         << setw(6)  << "Term"
         << setw(10) << "Section"
         << setw(8)  << "Day"
         << setw(20) << "Time"
         << setw(20) << "Room" << "\n";

    cout << string(130, '-') << "\n";

    while (getline(file, line)) {
        // Skip header line if detected
        if (lineNumber == 0 && line.find("Code") != string::npos) {
            lineNumber++;
            continue;
        }

        stringstream ss(line);
        Schedule s;
        string unitsStr, yearStr, termStr;

        getline(ss, s.courseCode, '|');
        getline(ss, s.courseTitle, '|');
        getline(ss, unitsStr, '|');
        getline(ss, yearStr, '|');
        getline(ss, termStr, '|');
        getline(ss, s.section, '|');
        getline(ss, s.day, '|');
        getline(ss, s.time, '|');
        getline(ss, s.room, '|');

        // Convert to integer safely
        s.units = atoi(unitsStr.c_str());
        s.yearLevel = atoi(yearStr.c_str());
        s.term = atoi(termStr.c_str());

        cout << left << setw(12) << s.courseCode
             << setw(30) << s.courseTitle
             << setw(6)  << s.units
             << setw(6)  << s.yearLevel
             << setw(6)  << s.term
             << setw(10) << s.section
             << setw(8)  << s.day
             << setw(20) << s.time
             << setw(20) << s.room << "\n";

        hasData = true;
        lineNumber++;
    }

    if (!hasData) {
        cout << "No valid schedule records found.\n";
    }

    file.close();
    pause();
}

// ? Edit Schedule
void editSchedule() {
    clear();
    vector<Schedule> schedules = loadSchedules();
    if (schedules.empty()) {
        cout << "No schedules found.\n";
        pause();
        return;
    }

    string code;
    cout << "Enter Course Code to edit: ";
    getline(cin, code);
    bool found = false;

    for (int i = 0; i < schedules.size(); i++) {
        if (toUpper(schedules[i].courseCode) == toUpper(code)) {
            found = true;

            cout << "\nEditing schedule for: " << schedules[i].courseCode << " - " << schedules[i].courseTitle << "\n";

            cout << "New Section (A/B): ";
            getline(cin, schedules[i].section);

            cout << "New Day [1] MWF, [2] TTh: ";
            string d;
            getline(cin, d);
            schedules[i].day = (d == "1") ? "MWF" : "TTh";

            cout << "New Time [1] 7-10AM, [2] 1-4PM, [3] 5-8PM: ";
            string t;
            getline(cin, t);
            if (t == "1") schedules[i].time = "7:00AM - 10:00AM";
            else if (t == "2") schedules[i].time = "1:00PM - 4:00PM";
            else schedules[i].time = "5:00PM - 8:00PM";

            cout << "New Room [1] Main Branch, [2] Branch Building: ";
            string r;
            getline(cin, r);
            schedules[i].room = (r == "1") ? "Main Branch" : "Branch Building";

            break;
        }
    }

    if (!found) {
        cout << "Schedule not found.\n";
        pause();
        return;
    }

    ofstream file("schedules.txt");
    file << "Code|Title|Units|Year|Term|Section|Day|Time|Room|\n";

    for (int i = 0; i < schedules.size(); i++) {
        Schedule s = schedules[i];
        file << s.courseCode << "|"
             << s.courseTitle << "|"
             << s.units << "|"
             << s.yearLevel << "|"
             << s.term << "|"
             << s.section << "|"
             << s.day << "|"
             << s.time << "|"
             << s.room << "|\n";
    }

    file.close();
    cout << "\nSchedule updated successfully.\n";
    pause();
}

// ? Delete Schedule
void deleteSchedule() {
    clear();
    vector<Schedule> schedules = loadSchedules();
    if (schedules.empty()) {
        cout << "No schedules found.\n";
        pause();
        return;
    }

    string code;
    cout << "Enter Course Code to delete: ";
    getline(cin, code);
    bool found = false;

    for (int i = 0; i < schedules.size(); i++) {
        if (toUpper(schedules[i].courseCode) == toUpper(code)) {
            found = true;
            cout << "Are you sure you want to delete the schedule for "
                 << schedules[i].courseCode << "? (Y/N): ";
            string confirm;
            getline(cin, confirm);
            if (toupper(confirm[0]) == 'Y') {
                schedules.erase(schedules.begin() + i);
                break;
            } else {
                cout << "Deletion cancelled.\n";
                pause();
                return;
            }
        }
    }

    if (!found) {
        cout << "Schedule not found.\n";
        pause();
        return;
    }

    ofstream file("schedules.txt");
    file << "Code|Title|Units|Year|Term|Section|Day|Time|Room|\n";

    for (int i = 0; i < schedules.size(); i++) {
        Schedule s = schedules[i];
        file << s.courseCode << "|"
             << s.courseTitle << "|"
             << s.units << "|"
             << s.yearLevel << "|"
             << s.term << "|"
             << s.section << "|"
             << s.day << "|"
             << s.time << "|"
             << s.room << "|\n";
    }

    file.close();
    cout << "\nSchedule deleted successfully.\n";
    pause();
}

#endif

