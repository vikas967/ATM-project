#include <iostream>
using namespace std;

// Global variables to store account balance and PIN
double balance = 90000.00;  // Initial balance
int pin = 8744;            // Default PIN

// Function to check account balance
void checkBalance() {
    cout << "\nYour current balance is: ₹" << balance << endl;
}

// Function to deposit money
void deposit() {
    double amount;
    cout << "\nEnter amount to deposit: ₹";
    cin >> amount;

    if (amount > 0) {
        balance += amount;
        cout << "₹" << amount << " has been deposited successfully." << endl;
    } else {
        cout << "Invalid amount entered!" << endl;
    }
}

// Function to withdraw money
void withdraw() {
    double amount;
    cout << "\nEnter amount to withdraw: ₹";
    cin >> amount;

    if (amount > balance) {
        cout << "Insufficient balance!" << endl;
    } else if (amount <= 0) {
        cout << "Invalid amount entered!" << endl;
    } else {
        balance -= amount;
        cout << "₹" << amount << " has been withdrawn successfully." << endl;
    }
}

// Function to display the main menu
void menu() {
    cout << "\n===== ATM Menu =====" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Exit" << endl;
    cout << "====================" << endl;
    cout << "Enter your choice: ";
}

// Main function
int main() {
    int enteredPin, choice;

    cout << "Welcome to the ATM!" << endl;
    cout << "Enter your PIN: ";
    cin >> enteredPin;

    // Verify PIN
    if (enteredPin != pin) {
        cout << "Invalid PIN! Exiting..." << endl;
        return 0;
    }

    // Loop for menu interaction
    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                cout << "Thank you for using the ATM. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
