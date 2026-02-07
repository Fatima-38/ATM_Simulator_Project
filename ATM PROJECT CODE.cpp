#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function prototypes
void displayMenu();
void checkBalance();
void deposit();
void withdraw();
void changePin();
void loadBalance();
void saveBalance();
void loadPin();
void savePin();
void displayAccountInfo();
void updateAccountInfo();

struct ATMSimulator {
    string filename;
    string pinFilename;
    double balance;
    string pin;
    string accountNumber;
    string customerName;
    string email;

    ATMSimulator(string file, string pinFile, string pinCode) : filename(file), pinFilename(pinFile), balance(0.0), pin(pinCode) {
        loadBalance();
        loadPin();
    }
};

ATMSimulator atm("balance.txt", "pin.txt" , "1234");

int main() {
    displayMenu();
    return 0;
}

// Function to display the ATM menu and handle user choices
void displayMenu() {
    int choice;
    string userPin;
    cout << "Welcome to the ATM Simulator!" << endl;
    cout << "Enter your PIN: ";
    getline(cin, userPin); // Using getline to read the PIN

    if (userPin == atm.pin) {
        do {
            cout << "\nATM Simulator Menu:" << endl;
            cout << "1. Check Balance" << endl;
            cout << "2. Deposit Money" << endl;
            cout << "3. Withdraw Money" << endl;
            cout << "4. Change PIN" << endl;
            cout << "5. Display Account Information" << endl;
            cout << "6. Update Account Information" << endl;
            cout << "7. Exit" << endl;
            cout << "Enter your choice: ";
            string choiceStr;
            getline(cin, choiceStr); // Using getline to read the choice
            choice = stoi(choiceStr); // Convert string to integer

            switch (choice) {
                case 1: checkBalance(); break;
                case 2: deposit(); break;
                case 3: withdraw(); break;
                case 4: changePin(); break;
                case 5: displayAccountInfo(); break;
                case 6: updateAccountInfo(); break;
                case 7: cout << "Thank you for using the ATM Simulator. Goodbye!" << endl; break;
                default: cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 7);
    } else {
        cout << "Invalid PIN. Please try again." << endl;
    }
}

// Function to load the balance
void loadBalance() {
    ifstream infile(atm.filename); // Open the file
    if (infile.is_open()) {
        string balanceStr;
        getline(infile, balanceStr); // Read the balance
        atm.balance = stod(balanceStr); // Convert string to double
        getline(infile, atm.accountNumber);
        getline(infile, atm.customerName);
        getline(infile, atm.email);
        infile.close(); // Close the file
    } else {
        atm.balance = 0.0;
        cout << "Could not open file for reading. Setting balance to $0.00." << endl;
    }
}

// Function to save the balance
void saveBalance() {
    ofstream outfile(atm.filename); // Open the file
    if (outfile.is_open()) {
        outfile << atm.balance << endl;
        outfile << atm.accountNumber << endl;
        outfile << atm.customerName << endl;
        outfile << atm.email << endl;
        outfile.close();
    } else {
        cout << "Could not open file for writing." << endl;
    }
}

// Function to load the PIN
void loadPin() {
    ifstream infile(atm.pinFilename); // Open the file
    if (infile.is_open()) {
        string pinStr;
        getline(infile, pinStr); // Read the PIN
        atm.pin = pinStr;
        infile.close(); // Close the file
    } else {
        atm.pin = "1234"; // Default PIN
        cout << "Could not open file for reading. Using default PIN." << endl;
        savePin();
    }
}

// Function to save the PIN
void savePin() {
    ofstream outfile(atm.pinFilename); // Open the file
    if (outfile.is_open()) {
        outfile << atm.pin << endl;
        outfile.close();
    } else {
        cout << "Could not open file for writing." << endl;
    }
}

// Function to check the current balance
void checkBalance() {
    cout << "Your current balance is: $" << atm.balance << endl;
}

// Function to deposit money
void deposit() {
    string amountStr;
    cout << "Enter amount to deposit: $";
    getline(cin, amountStr);  // Using getline to read the deposit amount
    double amount = stod(amountStr);  // Convert string to double
    if (amount > 0) {
        atm.balance += amount;
        cout << "$" << amount << " deposited successfully." << endl;
        saveBalance();
    } else {
        cout << "Invalid deposit amount." << endl;
    }
}

// Function to withdraw money
void withdraw() {
    string amountStr;
    cout << "Enter amount to withdraw: $";
    getline(cin, amountStr); 
    double amount = stod(amountStr);  // Convert string to double
    if (amount > 0 && amount <= atm.balance) {
        atm.balance -= amount;
        cout << "$" << amount << " withdrawn successfully." << endl;
        saveBalance();
    } else if (amount > atm.balance) {
        cout << "Insufficient funds." << endl;
    } else {
        cout << "Invalid withdrawal amount." << endl;
    }
}

// Function to change the PIN
void changePin() {
    string oldPin, newPin, confirmPin;
    cout << "Enter your old PIN: ";
    getline(cin, oldPin);  // Using getline to read the old PIN
    if (oldPin == atm.pin) {
        cout << "Enter your new PIN: ";
        getline(cin, newPin);  // Using getline to read the new PIN
        cout << "Confirm your new PIN: ";
        getline(cin, confirmPin);  // Using getline to confirm the new PIN
        if (newPin == confirmPin) {
           atm.pin = newPin;
            cout << "PIN changed successfully." << endl;
            savePin();
        } else {
            cout << "PINs do not match. Please try again." << endl;
               }
    }
}

// function for displayAccountInfo
void displayAccountInfo(){
	cout << "Account Information:" << endl;
    cout << "Account Number: " << atm.accountNumber << endl;
    cout << "Customer Name: " << atm.customerName << endl;
    cout << "Email: " << atm.email << endl;
}

// Function to update account information
void updateAccountInfo() {
    string newAccountNumber, newCustomerName, newEmail;
    cout << "Enter new account number: ";
    getline(cin, newAccountNumber);
    cout << "Enter new customer name: ";
    getline(cin, newCustomerName);
    cout << "Enter new email: ";
    getline(cin, newEmail);
	atm.accountNumber = newAccountNumber;
    atm.customerName = newCustomerName;
    atm.email = newEmail;

    saveBalance();
    cout << "Account information updated successfully!" << endl;
}
