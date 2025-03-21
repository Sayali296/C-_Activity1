#include <iostream>
using namespace std;

// Define the Account class
class Account {
private:
    int accountId;
    double balance;

public:
    // Constructor with default values
    Account(int id = 0, double bal = 0.0) {
        accountId = id;
        balance = bal;
    }

    // Function to input account details
    void inputDetails() {
        cout << "Enter Account ID: ";
        cin >> accountId;
        cout << "Enter Balance: ";
        cin >> balance;
    }

    // Function to display account details
    void displayDetails() {
        cout << "Account ID: " << accountId << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    const int SIZE = 5; // Define the size of the array
    Account accounts[SIZE]; // Create an array of Account objects

    cout << "Enter details for " << SIZE << " accounts:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "\nAccount " << i + 1 << ":\n";
        accounts[i].inputDetails();
    }

    cout << "\nDisplaying Account Details:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "\nAccount " << i + 1 << ":\n";
        accounts[i].displayDetails();
    }

    return 0;
}