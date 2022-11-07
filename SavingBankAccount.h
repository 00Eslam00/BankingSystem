#ifndef SAVINGBANKACCOUNT_H
#define SAVINGBANKACCOUNT_H

#include "BankAccount.h"

class SavingBankAccount : public BankAccount {
private:
    int minimumBalance = 1000;
public:
    SavingBankAccount(double new_value, int minbalance=1000);

    int get_minimum();

    void set_minBalance(int);

    double withdraw();

    double deposit();
};


#endif
