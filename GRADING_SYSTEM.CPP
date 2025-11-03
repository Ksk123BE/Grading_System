/* 
   SIMPLE GPA & CGPA CALCULATOR 
   Developed by K.S.Kirutika
   Description:
   This program calculates GPA and CGPA using 
   grades like O, A+, A-, B+, B-, C-, U, AB.
*/

#include <iostream>
#include <string>
using namespace std;

// Function to change grade into grade points
float gradeToPoint(string grade) {
    if (grade == "O" || grade == "o") return 10;
    else if (grade == "A+" || grade == "a+") return 9;
    else if (grade == "A-" || grade == "a-") return 8;
    else if (grade == "B+" || grade == "b+") return 7;
    else if (grade == "B-" || grade == "b-") return 6;
    else if (grade == "C-" || grade == "c-") return 5;
    else if (grade == "U" || grade == "u") return 0; // Arrear
    else if (grade == "AB" || grade == "ab") return 0; // Absent
    else return 0;
}

void calculateGPA() {
    int n;
    cout << "\nEnter number of subjects: ";
    cin >> n;

    float credit, totalCredit = 0, totalPoints = 0;
    string grade;

    for (int i = 1; i <= n; i++) {
        cout << "\nSubject " << i << ":\n";
        cout << "Enter credit: ";
        cin >> credit;
        cout << "Enter grade (O, A+, A-, B+, B-, C-, U, AB): ";
        cin >> grade;

        float gp = gradeToPoint(grade); // convert to points
        totalCredit += credit;
        totalPoints += gp * credit;
    }

    float gpa = totalPoints / totalCredit;
    cout << "\n-----------------------------";
    cout << "\nTotal Credits: " << totalCredit;
    cout << "\nTotal Points : " << totalPoints;
    cout << "\nYour GPA is : " << gpa;
    cout << "\n-----------------------------\n";
}

void calculateCGPA() {
    int sem;
    cout << "\nEnter number of semesters: ";
    cin >> sem;

    float gpa, total = 0;
    for (int i = 1; i <= sem; i++) {
        cout << "Enter GPA for semester " << i << ": ";
        cin >> gpa;
        total += gpa;
    }

    cout << "\n-----------------------------";
    cout << "\nYour CGPA is: " << total / sem;
    cout << "\n-----------------------------\n";
}

void showMethod() {
    cout << "\nGRADE POINT TABLE:\n";
    cout << "O = 10 (91–100)\n";
    cout << "A+ = 9 (81–90)\n";
    cout << "A- = 8 (71–80)\n";
    cout << "B+ = 7 (61–70)\n";
    cout << "B- = 6 (51–60)\n";
    cout << "C- = 5 (Exactly 50)\n";
    cout << "U = Arrear (<50)\n";
    cout << "AB = Absent\n";
    cout << "\nFormulas:\n";
    cout << "GPA = (Sum of (Credit × Point)) / Total Credits\n";
    cout << "CGPA = (Sum of GPA) / No. of Semesters\n";
}

int main() {
    int choice;
    do {
        cout << "\n===============================";
        cout << "\n GPA & CGPA CALCULATOR";
        cout << "\n===============================";
        cout << "\n1. Calculate GPA";
        cout << "\n2. Calculate CGPA";
        cout << "\n3. Show Method";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: calculateGPA(); break;
            case 2: calculateCGPA(); break;
            case 3: showMethod(); break;
            case 4: cout << "\nThank you!\n"; break;
            default: cout << "\nInvalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}