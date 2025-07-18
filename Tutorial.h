#ifndef TUTORIAL_H
#define TUTORIAL_H

#include <iostream>
#include "Utils.h"
using namespace std;

void showTutorial() {
    clear();
    cout << "==================== SYSTEM TUTORIAL ====================\n";
    cout << "Welcome to the POWERPUFFS Enrollment Management System!\n\n";
    cout << "To use this system properly, follow these steps:\n\n";

    cout << "1. STUDENT MANAGEMENT\n";
    cout << "   - Add new student info (auto-generated ID)\n";
    cout << "   - View, Edit, or Delete student records\n\n";

    cout << "2. COURSE MANAGEMENT\n";
    cout << "   - Automatically loads BSIT subjects\n";
    cout << "   - Filtered based on student Year Level and Term\n";
    cout << "   - You can View, Edit, or Delete any course\n\n";

    cout << "3. SCHEDULE MANAGEMENT\n";
    cout << "   - Assign schedules for each selected subject\n";
    cout << "   - Set Section (A/B), Day (MWF/TTh), Time & Room\n";
    cout << "   - View, Edit, or Delete subject schedules\n\n";

    cout << "4. ENROLLMENT\n";
    cout << "   - Enter Student Number to begin enrollment\n";
    cout << "   - Review subject schedules and confirm enrollment\n";
    cout << "   - View full list of enrolled students\n\n";

    cout << "=========================================================\n";
    pause();
}

#endif

