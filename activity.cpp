#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    int accountId;
    string accountHolder;
    float balance;

public:
    
    Account(int id = 0, string name = "Unknown", double bal = 0.0) {
        accountId = id;
        accountHolder = name;
        balance = bal;
    }

    
    void setAccountDetails(int id, string name, double bal) {
        accountId = id;
        accountHolder = name;
        balance = bal;
    }

    
    void displayAccount() const {
        cout << "Account ID: " << accountId << endl;
        cout << "Account Holder Name: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
        cout << "-------------------------" << endl;
    }
};

int main() {
    const int numAccounts = 2; // Number of accounts to store
    Account accounts[numAccounts]; // Array of Account objects

    // Input account details
    for (int i = 0; i < numAccounts; i++) {
        int id;
        string name;
        double balance;

        cout << "Enter details for Account " << i + 1 << ":" << endl;
        cout << "Enter Account ID: ";
        cin >> id;
        cin.ignore(); // Ignore newline character
        cout << "Account Holder Name: ";
        getline(cin, name);
        cout << "Initial Balance: ";
        cin >> balance;

        accounts[i].setAccountDetails(id, name, balance);
        cout << "-------------------------" << endl;
    }

    // Display account details
    cout << "\nStored Account Details:\n";
    for (int i = 0; i < numAccounts; i++) {
        accounts[i].displayAccount();
    }

    return 0;
}
