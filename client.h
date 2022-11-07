//
// Created by dell on 11/7/2022.
//

#ifndef MAIN_CPP_CLIENT_H
#define MAIN_CPP_CLIENT_H

#include <iostream>
#include <string>
#include <fstream>
#include "BankAccount.h"

using namespace std;

class client {
private:
    string name, address, phoneNum;
    BankAccount *itsClient;
public:
    void setName(string Name);
    void setAddress(string Address);
    void setPhoneNumber(string PhoneNum);
    void setClientAccount(BankAccount *ptrClint);
    void setBalance(double new_value);

    string getAccount_Id();
    double getBalance();
    string getName();
    string getAddress();
    string getPhoneNum();
};


#endif //MAIN_CPP_CLIENT_H
