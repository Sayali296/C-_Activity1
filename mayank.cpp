#include <iostream>
using namespace std;

class Student {
private:
    int studentId;
    string name;
    float grade;

public:
    // Default Constructor
    Student() {
        studentId = 0;
        name = "Unknown";
        grade = 0.0;
    }

    // Function to Input Student Details
    void inputDetails() {
        cout << "Enter Student ID: ";
        cin >> studentId;
        cout << "Enter Name: ";
        cin >> name;

        // Input validation for grade
        do {
            cout << "Enter Grade (0-100): ";
            cin >> grade;
            if (grade < 0 || grade > 100) {
                cout << "Invalid Grade! Please enter a value between 0 and 100.\n";
            }
        } while (grade < 0 || grade > 100);
    }

    // Function to Determine Letter Grade
    char getLetterGrade() const {
        if (grade >= 90) return 'A';
        else if (grade >= 80) return 'B';
        else if (grade >= 70) return 'C';
        else if (grade >= 60) return 'D';
        else return 'F';
    }

    // Function to Display Student Details
    void displayDetails() const {
        cout << "Student ID: " << studentId 
             << ", Name: " << name 
             << ", Grade: " << grade 
             << ", Letter Grade: " << getLetterGrade() << endl;
    }

    // Getter Functions
    int getStudentId() const { return studentId; }
    float getGrade() const { return grade; }
    string getName() const { return name; }
};

// Function to Find the Student with the Highest Grade
void findTopStudent(Student students[], int size) {
    int topIndex = 0;
    for (int i = 1; i < size; i++) {
        if (students[i].getGrade() > students[topIndex].getGrade()) {
            topIndex = i;
        }
    }
    cout << "\nTop Student:\n";
    students[topIndex].displayDetails();
}

// Function to Search for a Student by ID
void searchStudentById(Student students[], int size, int id) {
    for (int i = 0; i < size; i++) {
        if (students[i].getStudentId() == id) {
            cout << "\nStudent Found:\n";
            students[i].displayDetails();
            return;
        }
    }
    cout << "Student with ID " << id << " not found!\n";
}

int main() {
    const int SIZE = 3;
    Student students[SIZE];

    // Input Student Details
    for (int i = 0; i < SIZE; i++) {
        cout << "\nEnter details for Student " << i + 1 << ":\n";
        students[i].inputDetails();
    }

    // Display All Students
    cout << "\nStudent Details:\n";
    for (int i = 0; i < SIZE; i++) {
        students[i].displayDetails();
    }

    // Find and Display the Top Student
    findTopStudent(students, SIZE);

    // Search for a Student by ID
    int searchId;
    cout << "\nEnter Student ID to Search: ";
    cin >> searchId;
    searchStudentById(students, SIZE, searchId);

    return 0;
}
