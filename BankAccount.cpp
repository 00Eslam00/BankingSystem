#include "BankAccount.h"

//Initialize counter
int BankAccount::counter = 0;

//Parametrized Constructor
BankAccount::BankAccount(double new_Value) {
    this->balance = new_Value;
    ++counter;
}

//Default Constructor
BankAccount::BankAccount() : balance(0) {
    ++counter;
}

//ID getter
string BankAccount::get_account_ID() {
    return (account_ID + to_string(counter));
}

//Balance getter
double BankAccount::get_balance() {
    return balance;
}

//Balance setter
void BankAccount::set_balance(double new_value) {
    this->balance = new_value;
}

//Withdraw Function
double BankAccount::withdraw() {
    double amount;
    cout << "Please Enter The Amount to Withdraw =========> ";
    cin >> amount;
    while (balance - amount < 0) {
        cout << "Sorry. This is more than what you can withdraw.\n";
        cout << "Please Enter The Amount to Withdraw =========> ";
        cin >> amount;
    }
    balance -= amount;
    cout << "Thank you.\n";
    cout << "Account ID: " << get_account_ID() << endl;
    cout << "New Balance: " << get_balance() << endl;

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
}
