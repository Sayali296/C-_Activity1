#include <iostream>
using namespace std;

int main() {
    int marks;
    char grade;

    // Taking the student's marks as input
    cout << "Enter the marks of the student: ";
    cin >> marks;

    // Determining the grade based on marks
    if (marks >= 90) {
        grade = 'A';
    } else if (marks >= 80) {
        grade = 'B';
    } else if (marks >= 70) {
        grade = 'C';
    } else if (marks >= 60) {
        grade = 'D';
    } else {
        grade = 'F';
    }

    // Displaying the grade
    cout << "The grade of the student is: " << grade << endl;

    return 0;
}
