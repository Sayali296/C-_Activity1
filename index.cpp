#include <iostream>
#include <vector>
using namespace std;

class Expense {
private:
    int expenseId;
    double amount;

public:
    // Constructor with default values
    Expense(int id = 0, double amt = 0.0) : expenseId(id), amount(amt) {}

    // Function to input expense details
    void inputExpense() {
        cout << "Enter Expense ID: ";
        cin >> expenseId;
        cout << "Enter Amount: ";
        cin >> amount;
    }

    // Function to display expense details
    void displayExpense() const {
        cout << "Expense ID: " << expenseId << " | Amount: $" << amount << endl;
    }
};

int main() {
    int numExpenses;
    cout << "Enter the number of expenses: ";
    cin >> numExpenses;

    vector<Expense> expenses(numExpenses);
    
    // Input expenses
    for (int i = 0; i < numExpenses; i++) {
        cout << "Enter details for expense " << i + 1 << ":\n";
        expenses[i].inputExpense();
    }

    // Display expenses
    cout << "\nDaily Expenses:\n";
    for (const auto &exp : expenses) {
        exp.displayExpense();
    }

    return 0;
}
