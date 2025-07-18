#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

void clear() {
    system("cls"); // Use "clear" on Linux/Mac if needed
}

void pause() {
    system("pause");
}

bool isAlphaString(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (!isalpha(s[i]) && s[i] != ' ' && s[i] != '-') return false;
    }
    return true;
}

bool isAllDigits(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) return false;
    }
    return true;
}

int generateStudentID() {
    ifstream file("students.txt");
    string line;
    int lastID = 20250000;

    getline(file, line); // Skip header

    while (getline(file, line)) {
        istringstream iss(line);
        string id;
        iss >> id;

        if (!id.empty() && isAllDigits(id)) {
            int num;
            stringstream convert(id);
            convert >> num;
            lastID = max(lastID, num);
        }
    }

    file.close();
    return lastID + 1;
}

string toUpper(string s) {
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}

#endif

