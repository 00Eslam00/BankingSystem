#ifndef BANKINGAPPLICATION_H
#define BANKINGAPPLICATION_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>


using namespace std;

class client;

class BankAccount;

class BankingApplication {
private:
    vector<pair<client, BankAccount *>> users;

    void setData();

    void getData();

    void createData();

public:
    BankingApplication() {
        createData();
        getData();
    }

    void run();

    void createaccount();

    void listusers();

    void Withdraw();

    void Deposit();
};


class BankAccount {
protected:
    bool basic;
    static int counter;
    int order;
    string account_ID = "FCAI-";
    double balance;
public:
    BankAccount(double new_Value);

    friend class SavingBankAccount;

    BankAccount();

    string getId();

    void setId(string id);

    double getBalance();

    void setBalance(double &new_value);

    virtual void withdraw();

    virtual void deposit();

    bool getState();

    void setState(bool b);

};

class client {
private:
    string name, address, phoneNum;
public:
    void setName(string Name);

    void setAddress(string Address);

    void setPhoneNumber(string PhoneNum);

    string &getName();

    string &getAddress();

    string &getPhoneNum();
};

class SavingBankAccount : public BankAccount {
private:
    int minimumBalance = 1000;
public:
    SavingBankAccount() {
        basic = false;
    };

    SavingBankAccount(double new_value, int minbalance = 1000);

    int get_minimum();

    friend class BankAccount;

    void set_minBalance(int);

    virtual void withdraw();

    virtual void deposit();
};


#endif
