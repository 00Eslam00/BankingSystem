#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class BankAccount {
protected:
    static int counter;
    string account_ID = "FCAI-";
    double balance;
public:
    BankAccount(double new_Value);

    BankAccount();

    string get_account_ID();

    double get_balance();

    void set_balance(double new_value);

    virtual double withdraw();

    virtual double deposit();

};


#endif