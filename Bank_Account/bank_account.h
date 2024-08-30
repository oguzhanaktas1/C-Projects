#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
string account_number;
string account_holder_name;
double balance;
double interest_rate;
int account_type;

    // Static variables
    static double total_balance;
    static int num_accounts;

public:
    // Constructors
    BankAccount(string acc_num="", string acc_holder_name="", double bal=0, double int_rate=0, int acc_type=0);

    // Destructor
    ~BankAccount();
    // Gtters and Setters
    string getAccountNumber();
    string getAccountHolderName();
    double getBalance();
    double getInterestRate();
    int getAccountType();
    static int getNumAccounts();
    static double getTotalBalance();

    void setAccountNumber(string acc_num);
    void setAccountHolderName(string acc_holder_name);
    void setBalance(double bal);
    void setInterestRate(double int_rate);
    void setAccountType(int acc_type);

    // Utility functions
    void deposit(double amount);
    void withdraw(double amount);
    void display();

    // Operator overloading functions
    friend bool operator==(const BankAccount& lhs, const BankAccount& rhs);
    friend bool operator!=(const BankAccount& lhs, const BankAccount& rhs);
    friend BankAccount operator+(const BankAccount& lhs, const BankAccount& rhs);
};

#endif
