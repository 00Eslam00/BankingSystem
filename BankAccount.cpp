#include "BankingApplication.h"

//Initialize counter
int BankAccount::counter = 0;

//Parametrized Constructor
BankAccount::BankAccount(double new_Value) {
    this->balance = new_Value;
    ++counter;
    order = counter;
    basic = true;
}

//Default Constructor
BankAccount::BankAccount() : balance(0) {
    ++counter;
    order = counter;
    basic = true;
}

//ID getter
string BankAccount::getId() {

    return (account_ID + to_string(order));
}

//Balance getter
double BankAccount::getBalance() {
    return balance;
}

//Balance setter
void BankAccount::setBalance(double &new_value) {
    balance = new_value;
}

//Withdraw Function
void BankAccount::withdraw() {
    if (getState()) {
        double amount;
        cout << "Account ID: " << this->getId() << endl;
        cout << "Acocunt Type: " << (this->getState() ? "Basic" : "Saving") << endl;
        cout << "Balance: " << this->getBalance() << endl;
        cout << "Please Enter The Amount to Withdraw ====> ";
        cin >> amount;
        while (balance - amount < 0) {
            cout << "Sorry. This is more than what you can withdraw.\n";
            cout << "Please Enter The Amount to Withdraw ====> ";
            cin >> amount;
        }
        balance = balance - amount;
        cout << "Thank you.\n";
        cout << "Account ID: " << getId() << endl;
        cout << "New Balance: " << getBalance() << endl;
    } else {

    }
}

//Deposit Function
void BankAccount::deposit() {
    double amount;
    cout << "Please Enter The Amount to Deposit ====> ";
    cin >> amount;
    balance = balance + amount;
    cout << "Thank you.\n";
    cout << "Account ID: " << getId() << endl;
    cout << "New Balance: " << getBalance() << endl;
}

bool BankAccount::getState() {
    return basic;
}

void BankAccount::setId(string id) {
    account_ID = id;
}

void BankAccount::setState(bool b) {
    if (b)
        basic = true;
    else
        basic = false;
}

//setName to client by set function
void client::setName(string Name) {
    name = Name;
}

//setAddress to client by set function
void client::setAddress(string Address) {
    address = Address;
}

//setPhoneNumber to client by set function
void client::setPhoneNumber(string PhoneNum) {
    phoneNum = PhoneNum;
}

//set Account to Client
//void client::setBankAccount(BankAccount *ptrClint) {
//    this->itsClient = ptrClint;
//}

//getClientAccount_id by client pointer
//string client::getAccount_Id() {
//    return (this->itsClient->get_account_ID());
//}

//getClientName by client pointer
string &client::getName() {
    return name;
}

//getClientAddress by client pointer
string &client::getAddress() {
    return address;
}

//getClientPhoneNumber by client pointer
string &client::getPhoneNum() {
    return phoneNum;
}

//getClientBalance by client pointer
//double& client::getBalance() {
//    return (this->itsClient->get_balance());
//}

//setClientBalance by client pointer
//void client::setBalance(double new_value) {
//    this->itsClient->set_balance(new_value);
//}