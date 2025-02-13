#include <iostream>
using namespace std;

class Employee {
    int empId;
    string name;
    float basicPay;
    float hra;
    float da;
    float grossPay;
    
public:
    Employee() {
        empId = 0;
        name = "";
        basicPay = hra = da = grossPay = 0.0;
    }
    
    Employee(int id, string n, float bp) {
        empId = id;
        name = n;
        basicPay = bp;
        hra = 0.2 * basicPay;
        da = 0.1 * basicPay;
        grossPay = basicPay + hra + da;
    }
    
    Employee(const Employee &emp) {
        empId = emp.empId;
        name = emp.name;
        basicPay = emp.basicPay;
        hra = emp.hra;
        da = emp.da;
        grossPay = emp.grossPay;
    }
    
    void displayDetails() {
        cout << "\nEmployee ID: " << empId;
        cout << "\nName: " << name;
        cout << "\nBasic Pay: " << basicPay;
        cout << "\nHRA: " << hra;
        cout << "\nDA: " << da;
        cout << "\nGross Pay: " << grossPay << endl;
    }
};

int main() {
    int num;
    cout << "Enter number of employees: ";
    cin >> num;
    
    Employee employees[num];
    
    for (int i = 0; i < num; i++) {
        int id;
        string name;
        float basicPay;
        
        cout << "\nEnter details for Employee " << i + 1 << ":";
        cout << "\nEmployee ID: ";
        cin >> id;
        cout << "Name: ";
        cin >> ws;
        getline(cin, name);
        cout << "Basic Pay: ";
        cin >> basicPay;
        
        employees[i] = Employee(id, name, basicPay);
    }
    
    cout << "\nEmployee Payroll Details:";
    for (int i = 0; i < num; i++) {
        employees[i].displayDetails();
    }
    
    cout << "\nDemonstrating Copy Constructor:";
    Employee copyEmployee = employees[0];
    copyEmployee.displayDetails();
    
    return 0;
}
