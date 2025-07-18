#ifndef MODELS_H
#define MODELS_H

#include <string>
#include <vector>
using namespace std;

// ?? STUDENT STRUCT
struct Student {
    string studentID;
    string lastName;
    string firstName;
    string middleName;
    string gender;
    string birthday;
    string address;
    string degreeProgram;
    int yearLevel;
    int term;
};

// ?? COURSE STRUCT
struct Course {
    string courseCode;
    string courseTitle;
    int units;
    int yearLevel;
    int term;
};

// ??? SCHEDULE STRUCT
struct Schedule {
    string courseCode;
    string courseTitle;
    int units;
    int yearLevel;
    int term;
    string section;
    string day;
    string time;
    string room;
};

// ?? ENROLLMENT STRUCT
struct Enrollment {
    string studentID;
    string courseCode;
    string courseTitle;
    string section;
    string day;
    string time;
    string room;
};

// ?? GLOBAL current student used in Student ? Course ? Schedule flow
extern Student currentStudent;
extern vector<Course> selectedCourses;
extern vector<Schedule> selectedSchedules;

#endif

