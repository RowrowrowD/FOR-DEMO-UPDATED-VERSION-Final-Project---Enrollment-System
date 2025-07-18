#include <iostream>
#include <cstdlib>
#include <limits>
#include "Models.h"
#include "Utils.h"
#include "DataLoader.h"
#include "StudentManagement.h"
#include "CourseManagement.h"
#include "ScheduleManagement.h"
#include "Enrollment.h"
#include "Tutorial.h"
#include "Exit.h"

using namespace std;

Student currentStudent;

// Function Declarations
void enrollmentMenu();
void studentMenu();
void courseMenu();
void scheduleMenu();
void mainMenu();

// Enrollment Menu
void enrollmentMenu() {
    string choice;
    do {
        clear();
        cout << "=========== ENROLLMENT MENU ===========\n";
        cout << "[1] Enroll a Student\n";
        cout << "[2] View List of Enrollees\n";
        cout << "[X] Return to Main Menu\n";
        cout << "=======================================\n";
        cout << "Enter choice: ";
        getline(cin, choice);

        if (choice == "1") enrollStudentFinal();
        else if (choice == "2") viewEnrollees();
        else if (choice == "x" || choice == "X") return;
        else { cout << "Invalid choice.\n"; pause(); }
    } while (true);
}

// Student Management
void studentMenu() {
    string choice;
    do {
        clear();
        cout << "======= STUDENT MANAGEMENT MENU =======\n";
        cout << "[1] Add Student (Proceed to Flow)\n";
        cout << "[2] View Student List\n";
        cout << "[3] Edit Student\n";
        cout << "[4] Delete Student\n";
        cout << "[X] Return to Main Menu\n";
        cout << "=======================================\n";
        cout << "Enter choice: ";
        getline(cin, choice);

        if (choice == "1") {
            addStudent(); // Generates student + sets global currentStudent
            addCoursesForStudent(currentStudent); // For Year/Term
            addScheduleForCourses(selectedCourses); // Uses selectedCourses
        }
        else if (choice == "2") viewStudentList();
        else if (choice == "3") editStudent();
        else if (choice == "4") deleteStudent();
        else if (choice == "x" || choice == "X") return;
        else { cout << "Invalid choice.\n"; pause(); }
    } while (true);
}

// Course Management
void courseMenu() {
    string choice;
    do {
        clear();
        cout << "======== COURSE MANAGEMENT MENU =======\n";
        cout << "[1] View Courses\n";
        cout << "[2] Edit Course\n";
        cout << "[3] Delete Course\n";
        cout << "[X] Return to Main Menu\n";
        cout << "=======================================\n";
        cout << "Enter choice: ";
        getline(cin, choice);

        if (choice == "1") viewCourses();
        else if (choice == "2") editCourse();
        else if (choice == "3") deleteCourse();
        else if (choice == "x" || choice == "X") return;
        else { cout << "Invalid choice.\n"; pause(); }
    } while (true);
}

// Schedule Management
void scheduleMenu() {
    string choice;
    do {
        clear();
        cout << "====== SCHEDULE MANAGEMENT MENU ======\n";
        cout << "[1] View Schedules\n";
        cout << "[2] Edit Schedule\n";
        cout << "[3] Delete Schedule\n";
        cout << "[X] Return to Main Menu\n";
        cout << "======================================\n";
        cout << "Enter choice: ";
        getline(cin, choice);

        if (choice == "1") viewSchedules();
        else if (choice == "2") editSchedule();
        else if (choice == "3") deleteSchedule();
        else if (choice == "x" || choice == "X") return;
        else { cout << "Invalid choice.\n"; pause(); }
    } while (true);
}

// Main Menu
void mainMenu() {
    string choice;
    do {
        clear();
        cout << "========================================\n";
        cout << "  POWERPUFFS COLLEGE ENROLLMENT SYSTEM  \n";
        cout << "========================================\n";
        cout << "[1] Student Management\n";
        cout << "[2] Course Management\n";
        cout << "[3] Schedule Management\n";
        cout << "[4] Enrollment\n";
        cout << "\n[T] Tutorial\n";
        cout << "[X] Exit Program\n";
        cout << "----------------------------------------\n";
        cout << "Enter choice: ";
        getline(cin, choice);

        if (choice == "1") studentMenu();
        else if (choice == "2") courseMenu();
        else if (choice == "3") scheduleMenu();
        else if (choice == "4") enrollmentMenu();
        else if (choice == "t" || choice == "T") showTutorial();
        else if (choice == "x" || choice == "X") {
            showExitScreen();
            break;
        } else {
            cout << "Invalid input.\n";
            pause();
        }
    } while (true);
}

// Entry Point
int main() {
    showTutorial();
    mainMenu();
    return 0;
}

