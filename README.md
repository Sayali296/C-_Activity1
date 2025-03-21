# C-_Activity1
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    static int idCounter;  // Static counter for unique student ID
    int studentId;
    string name;
    float grade;

public:
    // Default Constructor
    Student() {
        studentId = ++idCounter; // Assign unique ID
        name = "Unknown";
        grade = 0.0;
    }

    // Method to input student details
    void inputDetails() {
        cout << "Enter name for Student " << studentId << ": ";
        cin.ignore(); // Ignore newline from previous input
        getline(cin, name);
        cout << "Enter grade: ";
        cin >> grade;
    }

    // Method to display student details
    void displayDetails() const {
        cout << "Student ID: " << studentId << ", Name: " << name << ", Grade: " << grade << endl;
    }
};

// Initialize static variable
int Student::idCounter = 0;

int main() {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    Student students[numStudents]; // Array of Student objects

    // Input details for each student
    for (int i = 0; i < numStudents; i++) {
        cout << "\nEnter details for Student " << (i + 1) << ":\n";
        students[i].inputDetails();
    }

    // Display student details
    cout << "\nStudent Details:\n";
    for (int i = 0; i < numStudents; i++) {
        students[i].displayDetails();
    }

    return 0;
}
