#include <iostream>
#include <map>

using namespace std;

class Bank {
private:
    map<int, float> accounts; // Map to store account number and balance

public:
    // Function to create a new account
    void createAccount(int accountNumber, float initialDeposit) {
        if (accounts.find(accountNumber) == accounts.end()) { // Check if account already exists
            accounts[accountNumber] = initialDeposit;
            cout << "Account created successfully!\n";
        } else {
            cout << "Account already exists with this account number.\n";
        }
    }

    // Function to deposit money into an account
    void deposit(int accountNumber, float amount) {
        if (accounts.find(accountNumber) != accounts.end()) { // Check if account exists
            accounts[accountNumber] += amount;
            cout << "Deposit successful!\n";
        } else {
            cout << "Account does not exist.\n";
        }
    }

    // Function to withdraw money from an account
    void withdraw(int accountNumber, float amount) {
        if (accounts.find(accountNumber) != accounts.end()) { // Check if account exists
            if (accounts[accountNumber] >= amount) {
                accounts[accountNumber] -= amount;
                cout << "Withdrawal successful!\n";
            } else {
                cout << "Insufficient balance.\n";
            }
        } else {
            cout << "Account does not exist.\n";
        }
    }

    // Function to check account balance
    void checkBalance(int accountNumber) {
        if (accounts.find(accountNumber) != accounts.end()) { // Check if account exists
            cout << "Account balance: " << accounts[accountNumber] << endl;
        } else {
            cout << "Account does not exist.\n";
        }
    }
};

int main() {
    Bank bank;
    int choice, accountNumber;
    float amount;

    while (true) {
        cout << "\n1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter initial deposit amount: ";
                cin >> amount;
                bank.createAccount(accountNumber, amount);
                break;
            case 2:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter deposit amount: ";
                cin >> amount;
                bank.deposit(accountNumber, amount);
                break;
            case 3:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                bank.withdraw(accountNumber, amount);
                break;
            case 4:
                cout << "Enter account number: ";
                cin >> accountNumber;
                bank.checkBalance(accountNumber);
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

