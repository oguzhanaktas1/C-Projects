#include "bank_account.h"
#include <iostream>
using namespace std;

int main() {
    // Create a bank account
    BankAccount account1("123456789", "Oguzhan Aktas", 1000, 9.5, 0);

    // Display the account information
    cout << "Account Information:\n";
    account1.display();
    cout << endl;

    // Make a deposit
    cout << "Depositing $5000...\n";
    account1.deposit(5000);
    cout << "New balance: $" << account1.getBalance() << endl;
    cout << endl;

    // Make a withdrawal
    cout << "Withdrawing $1200...\n";
    account1.withdraw(1200);
    cout << "New balance: $" << account1.getBalance() << endl;
    cout << endl;

    // Create another bank account
    BankAccount account2("0987654321", "Mehmet Aktas", 5000, 8.0, 1);

    // Display the account information
    cout << "Account Information:\n";
    account2.display();
    cout << endl;

    // Make a deposit using operator overloading
    cout << "Depositing $100 using operator overloading...\n";
    account2 += 100;
    cout << "New balance: $" << account2.getBalance() << endl;
    cout << endl;

    // Make a withdrawal using operator overloading
    cout << "Withdrawing $150 using operator overloading...\n";
    account2 -= 150;
    cout << "New balance: $" << account2.getBalance() << endl;
    cout << endl;

    // Display the number of accounts
    cout << "Number of accounts: " << BankAccount::getNumAccounts() << endl;

    return 0;
}

