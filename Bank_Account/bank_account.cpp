#include "bank_account.h"
#include <iostream>
#include <string>
using namespace std;

// Static variables
int BankAccount::num_accounts = 0;

// Constructors
BankAccount::BankAccount(string acc_num, string acc_holder_name, double bal, double int_rate, int acc_type)
    : account_number(acc_num), account_holder_name(acc_holder_name), balance(bal), interest_rate(int_rate), account_type(acc_type)
{
    num_accounts++;
}

BankAccount::BankAccount() : BankAccount("", "", 0, 0, 0) {}

// Destructor
BankAccount::~BankAccount() {
    num_accounts--;
}

// Getters
string BankAccount::getAccountNumber() const {
    return account_number;
}

string BankAccount::getAccountHolderName() const {
    return account_holder_name;
}

double BankAccount::getBalance() const {
    return balance;
}

double BankAccount::getInterestRate() const {
    return interest_rate;
}

int BankAccount::getAccountType() const {
    return account_type;
}

int BankAccount::getNumAccounts() {
    return num_accounts;
}

// Setters
void BankAccount::setAccountNumber(const string& acc_num) {
    account_number = acc_num;
}

void BankAccount::setAccountHolderName(const string& acc_holder_name) {
    account_holder_name = acc_holder_name;
}

void BankAccount::setBalance(double bal) {
    if (bal >= 0) {
        balance = bal;
    } else {
        cerr << "Error: Invalid balance entered.\n";
    }
}

void BankAccount::setInterestRate(double int_rate) {
    if (int_rate >= 0) {
        interest_rate = int_rate;
    } else {
        cerr << "Error: Invalid interest rate entered.\n";
    }
}

void BankAccount::setAccountType(int acc_type) {
    if (acc_type >= 0 && acc_type <= 2) {
        account_type = acc_type;
    } else {
        cerr << "Error: Invalid account type entered.\n";
    }
}

// Utility functions
void BankAccount::deposit(double amount) {
    if (amount >= 0) {
        balance += amount;
    } else {
        cerr << "Error: Invalid deposit amount entered.\n";
    }
}

void BankAccount::withdraw(double amount) {
    if (balance >= amount && amount >= 0) {
        balance -= amount;
    } else {
        cerr << "Error: Invalid withdrawal amount entered.\n";
    }
}

void BankAccount::display() const {
    cout << "Account Number: " << account_number << endl;
    cout << "Account Holder Name: " << account_holder_name << endl;
    cout << "Balance: " << balance << endl;
    cout << "Interest Rate: " << interest_rate << "%" << endl;
    cout << "Account Type: ";
    if (account_type == 0) {
        cout << "Checking" << endl;
    } else if (account_type == 1) {
        cout << "Savings" << endl;
    } else if (account_type == 2) {
        cout << "Check Done" << endl;
    }
}

// Operator overloading
BankAccount BankAccount::operator+(double amount) const {
    BankAccount temp(*this);
    temp.deposit(amount);
    return temp;
}

BankAccount BankAccount::operator-(double amount) const {
    BankAccount temp(*this);
    temp.withdraw(amount);
    return temp;
}

BankAccount& BankAccount::operator+=(double amount) {
    this->deposit(amount);
    return *this;
}

// Friend function

ostream& operator<<(ostream& os, const BankAccount& acc) {
os << "Account Number: " << acc.account_number << endl;
os << "Account Holder Name: " << acc.account_holder_name << endl;
os << "Balance: " << acc.balance << endl;
os << "Interest Rate: " << acc.interest_rate << "%" << endl;
os << "Account Type: ";
if (acc.account_type == 0) {
os << "Checking" << endl;
} else if (acc.account_type == 1) {
os << "Savings" << endl;
} else if (acc.account_type == 2) {
os << "Check Done" << endl;
}
return os;
}
