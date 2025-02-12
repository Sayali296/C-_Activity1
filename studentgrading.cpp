#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

class Student {
private:
    int studentId;
    string name;
    float marks;
    char grade;
    static int nextId;

    char calculateGrade(float marks) {
        if (marks >= 90) return 'A';
        else if (marks >= 80) return 'B';
        else if (marks >= 70) return 'C';
        else if (marks >= 60) return 'D';
        else return 'F';
    }

public:
    Student(string n, float m) {
        studentId = nextId++;
        name = n;
        marks = m;
        grade = calculateGrade(marks);
    }

    void displayDetails() {
        cout << left << setw(8) << studentId 
             << setw(20) << name 
             << setw(10) << fixed << setprecision(2) << marks 
             << setw(8) << grade << endl;
    }

    static void displayHeader() {
        cout << left << setw(8) << "ID" 
             << setw(20) << "Name" 
             << setw(10) << "Marks" 
             << setw(8) << "Grade" << endl;
        cout << string(46, '-') << endl;
    }
};

int Student::nextId = 1;

int main() {
    vector<Student> students;
    int choice;
    
    do {
        cout << "\n=== Student Grading System ===";
        cout << "\n1. Add Student Data";
        cout << "\n2. Display All Students";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();  // Clear the newline

        switch (choice) {
            case 1: {
                cout << "\nEnter student data (name marks): ";
                string input;
                getline(cin, input);
                
                istringstream iss(input);
                string name;
                float marks;
                
                iss >> name;
                if (iss >> marks) {
                    if (marks >= 0 && marks <= 100) {
                        Student newStudent(name, marks);
                        students.push_back(newStudent);
                        cout << "Student added successfully!\n";
                    } else {
                        cout << "Invalid marks! Please enter marks between 0 and 100.\n";
                    }
                } else {
                    cout << "Invalid input format! Please use: name marks\n";
                }
                break;
            }
            case 2: {
                if (students.empty()) {
                    cout << "\nNo students in the system.\n";
                } else {
                    cout << "\n";
                    Student::displayHeader();
                    for (Student& student : students) {
                        student.displayDetails();
                    }
                }
                break;
            }
            case 3: {
                cout << "Exiting program...\n";
                break;
            }
            default: {
                cout << "Invalid choice! Please try again.\n";
            }
        }
    } while (choice != 3);
    
    return 0;
}
