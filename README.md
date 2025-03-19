#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

class ExpenseTracker {
private:
    map<string, double> expenses;

    // Function to load expenses from file
    void loadExpenses() {
        ifstream infile("expenses.txt");
        string category;
        double amount;
        while (infile >> category >> amount) {
            expenses[category] = amount;
        }
        infile.close();
    }

    // Function to save expenses to file
    void saveExpenses() {
        ofstream outfile("expenses.txt");
        for (auto& entry : expenses) {
            outfile << entry.first << " " << entry.second << endl;
        }
        outfile.close();
    }

public:
    ExpenseTracker() {
        loadExpenses();
    }

    // Add an expense
    void addExpense(const string& category, double amount) {
        expenses[category] += amount;
        saveExpenses();
    }

    //
