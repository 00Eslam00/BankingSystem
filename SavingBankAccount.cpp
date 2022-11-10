#include "BankingApplication.h"


SavingBankAccount::SavingBankAccount(double new_value, int minbalance) {
    basic = false;
    while (new_value < minbalance) {
        cout << "Enter Balance greater than the minimum balance\n";
        minimumBalance = minbalance;
        cout << "Min Balance: " << get_minimum() << endl;
        cin >> new_value;
    }
    this->balance = new_value;
    this->minimumBalance = minbalance;
    cout << "Thank you.\n";
    cout << "Account ID: " << getId() << endl;
    cout << "Account type: " << (getState() ? " (Basic)" : " (Saving)") << endl;
    cout << "New Balance: " << getBalance() << endl;
    cout << "Min Balance: " << get_minimum() << endl;

}

int SavingBankAccount::get_minimum() {
    return minimumBalance;
}

void SavingBankAccount::set_minBalance(int x) {
    minimumBalance = x;
}

void SavingBankAccount::withdraw() {
    double amount;
    cout << "Please Enter The Amount to Withdraw not less than Minimum Balance =========> ";
    cin >> amount;
    while (amount < minimumBalance) {
        cout << "Sorry. This is less than what you can withdraw.\n";
        cout << "Please Enter The Amount to Withdraw not less than Minimum Balance =========> ";
        cin >> amount;
    }
    balance -= amount;
    cout << "Thank you.\n";
    cout << "Account ID: " << getId() << endl;
    cout << "New Balance: " << getBalance() << endl;

}

void SavingBankAccount::deposit() {
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
    cout << "Account ID: " << getId() << endl;
    cout << "New Balance: " << getBalance() << endl;
}
