#ifndef BANKINGAPPLICATION_H
#define BANKINGAPPLICATION_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class client;

class BankAccount;

class BankingApplication {
private:
    vector<pair<client, BankAccount>> users;
public:
    void run();

    void createaccount();

    void listusers();

    void Withdraw();

    void deposit();
};


class BankAccount {
protected:
    bool basic;
    static int counter;
    int order;
    string account_ID = "FCAI-";
    double balance;
    client *itsAccount;
public:
    BankAccount(double new_Value);

    BankAccount();

    string get_account_ID();

    double &get_balance();

    void set_balance(double new_value);

    virtual double withdraw();

    virtual double deposit();

    void setNm(string nm);

    void setAdd(string add);

    void setPhn(string phn);

    void setClient(client *Client);

    bool getState();

    string getNm();

    string getAdd();

    string getPhn();

};

class client {
private:
    string name, address, phoneNum;
    BankAccount *itsClient;
public:
    void setName(string Name);

    void setAddress(string Address);

    void setPhoneNumber(string PhoneNum);

    void setBankAccount(BankAccount *ptrClint);

    void setBalance(double new_value);

    string getAccount_Id();

    double getBalance();

    string getName();

    string getAddress();

    string getPhoneNum();
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

    void set_minBalance(int);

    double withdraw();

    double deposit();
};


#endif
