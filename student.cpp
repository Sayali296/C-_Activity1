#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

class Student {
public:
    int id;
    string name;
    float marks;
    char grade;

    Student(int _id, string _name, float _marks) {
        id = _id;
        name = _name;
        marks = _marks;
        calculateGrade();
    }

    void calculateGrade() {
        if (marks >= 90) grade = 'A';
        else if (marks >= 80) grade = 'B';
        else if (marks >= 70) grade = 'C';
        else if (marks >= 60) grade = 'D';
        else grade = 'F';
    }

    void display() const {
        cout << left << setw(5) << id << setw(20) << name << setw(10) << marks << setw(5) << grade << endl;
    }
};

vector<Student> loadStudentsFromCSV(string filename) {
    vector<Student> students;
    ifstream file(filename);
    if (!file) {
        cout << "❌ Error: Unable to open file.\n";
        return students;
    }

    string line, idStr, name, marksStr;
    getline(file, line); // Skip header line

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, marksStr, ',');

        int id = stoi(idStr);
        float marks = stof(marksStr);

        students.push_back(Student(id, name, marks));
    }
    file.close();
    return students;
}

int main() {
    vector<Student> students = loadStudentsFromCSV("students.csv");

    if (students.empty()) {
        cout << "❌ No student data found.\n";
        return 0;
    }

    cout << "\n📊 Student Records:\n";
    cout << left << setw(5) << "ID" << setw(20) << "Name" << setw(10) << "Marks" << setw(5) << "Grade" << endl;
    cout << "------------------------------------------------\n";

    for (const Student& s : students) {
        s.display();
    }

    return 0;
}
