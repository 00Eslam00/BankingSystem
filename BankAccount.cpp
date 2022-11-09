#include "BankingApplication.h"

//Initialize counter
int BankAccount::counter = 0;

//Parametrized Constructor
BankAccount::BankAccount(double new_Value) {
    this->balance = new_Value;
    ++counter;
    order = counter;
}

//Default Constructor
BankAccount::BankAccount() : balance(0) {
    ++counter;
    order = counter;
    basic = true;
}

//ID getter
string BankAccount::get_account_ID() {
    return (account_ID + to_string(order));
}

//Balance getter
double &BankAccount::get_balance() {
    return this->balance;
}

//Balance setter
void BankAccount::set_balance(double new_value) {
    this->balance = new_value;
}

//Withdraw Function
double BankAccount::withdraw() {
    double amount;
    cout << "Account ID: " << this->get_account_ID() << endl;
    cout << "Acocunt Type: " << (this->getState() ? "Basic" : "Saving") << endl;
    cout << "Balance: " << this->get_balance() << endl;
    cout << "Please Enter The Amount to Withdraw =========> ";
    cin >> amount;
    while (balance - amount < 0) {
        cout << "Sorry. This is more than what you can withdraw.\n";
        cout << "Please Enter The Amount to Withdraw =========> ";
        cin >> amount;
    }
    this->balance -= amount;
    cout << "Thank you.\n";
    cout << "Account ID: " << get_account_ID() << endl;
    cout << "New Balance: " << get_balance() << endl;
    return amount;
}

//Deposit Function
double BankAccount::deposit() {
    double amount;
    cout << "Please Enter The Amount to Deposit =========> ";
    cin >> amount;
    balance += amount;
    cout << "Thank you.\n";
    cout << "Account ID: " << get_account_ID() << endl;
    cout << "New Balance: " << get_balance() << endl;
    return amount;
}

//setClient to Account
void BankAccount::setClient(client *Client) {
    this->itsAccount = Client;
}

//setName to client by BankAccount Pointer
void BankAccount::setNm(string nm) {
    this->itsAccount->setName(nm);
}

//setAddress to client by BankAccount Pointer
void BankAccount::setAdd(string add) {
    this->itsAccount->setAddress(add);
}

//setPhoneNumber to client by BankAccount Pointer
void BankAccount::setPhn(string phn) {
    this->itsAccount->setPhoneNumber(phn);
}

//getName to client by BankAccount Pointer
string BankAccount::getNm() {
    return this->itsAccount->getName();
}

//getPhoneNumber to client by BankAccount Pointer
string BankAccount::getPhn() {
    return this->itsAccount->getPhoneNum();
}

//getAddress to client by BankAccount Pointer
string BankAccount::getAdd() {
    return this->itsAccount->getAddress();
}

bool BankAccount::getState() {
    return basic;
}


//---------------------------------------------------------------------------------------------------------
//setName to client by set function
void client::setName(string Name) {
    this->name = Name;
}

//setAddress to client by set function
void client::setAddress(string Address) {
    this->address = Address;
}

//setPhoneNumber to client by set function
void client::setPhoneNumber(string PhoneNum) {
    this->phoneNum = PhoneNum;
}

//set Account to Client
void client::setBankAccount(BankAccount *ptrClint) {
    this->itsClient = ptrClint;
}

//getClientAccount_id by client pointer
string client::getAccount_Id() {
    return (this->itsClient->get_account_ID());
}

//getClientName by client pointer
string client::getName() {
    return (this->name);
}

//getClientAddress by client pointer
string client::getAddress() {
    return (this->address);
}

//getClientPhoneNumber by client pointer
string client::getPhoneNum() {
    return (this->phoneNum);
}

//getClientBalance by client pointer
double client::getBalance() {
    return (this->itsClient->get_balance());
}

//setClientBalance by client pointer
void client::setBalance(double new_value) {
    this->itsClient->set_balance(new_value);
}