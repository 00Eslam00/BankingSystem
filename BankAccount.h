#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class client;
class BankAccount {
protected:
    static int counter;
    string account_ID = "FCAI-";
    long long balance;
    client *itsAccount;
public:
    BankAccount(double new_Value);

    BankAccount();

    string get_account_ID();

    double get_balance();

    void set_balance(long long new_value);

    virtual double withdraw();

    virtual double deposit();

    void setNm(string nm);

    void setAdd(string add);

    void setPhn(string phn);

    void setClient(client *Client);

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
#endif
