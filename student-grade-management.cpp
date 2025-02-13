#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int studentId;
    string name;
    float grade;
    static int idCounter; 

public:
   
    Student() {
        studentId = ++idCounter;
        name = "Unknown";
        grade = 0.0;
    }

    void inputDetails() {
        cout << "Enter name for Student " << studentId << ": ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter grade: ";
        cin >> grade;
    }
    void displayDetails() const {
        cout << "Student ID: " << studentId << " | Name: " << name << " | Grade: " << grade << endl;
    }
};
int Student::idCounter = 0;

int main() 
{
    const int numStudents = 3;
    Student students[numStudents];

    for (int i = 0; i < numStudents; i++) {
        students[i].inputDetails();
    }

    cout << "\nDisplaying Student Details:\n";

    for (int i = 0; i < numStudents; i++) {
        students[i].displayDetails();
    }

    return 0;
}
