#include "SavingBankAccount.h"

SavingBankAccount::SavingBankAccount(double new_value, int minbalance) {
    while (new_value < minbalance) {
        cout << "Enter Balance greater than the minimum balance\n";
        cin >> new_value >> minbalance;
    }
    this->balance = new_value;
    this->minimumBalance = minbalance;
    cout << "Thank you.\n";
    cout << "Account ID: " << get_account_ID() << endl;
    cout << "New Balance: " << get_balance() << endl;

}

int SavingBankAccount::get_minimum() {
    return minimumBalance;
}

void SavingBankAccount::set_minBalance(int x) {
    this->minimumBalance = x;
}

double SavingBankAccount::withdraw() {
    double amount;
    cout << "Please Enter The Amount to Withdraw not less than Minimum Balance =========> ";
    cin >> amount;
    while (amount < minimumBalance) {
        cout << "Sorry. This is more than what you can withdraw.\n";
        cout << "Please Enter The Amount to Withdraw not less than Minimum Balance =========> ";
        cin >> amount;
    }
    balance -= amount;
    cout << "Thank you.\n";
    cout << "Account ID: " << get_account_ID() << endl;
    cout << "New Balance: " << get_balance() << endl;

}

double SavingBankAccount::deposit() {
    double amount;
    cout << "Please Enter The Amount to Deposit (Greater Than 100 L.E.) =========> ";
    cin >> amount;
    while (amount < 100) {
        cout << "Sorry. This is less than what you can deposit.\n";
        cout << "Please Enter The Amount to Deposit (Greater Than 100 L.E.) =========> ";
        cin >> amount;
    }
    balance += amount;
    cout << "Thank you.\n";
    cout << "Account ID: " << get_account_ID() << endl;
    cout << "New Balance: " << get_balance() << endl;
}

