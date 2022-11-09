#include "BankingApplication.h"

void BankingApplication::run() {
    while (true) {
        cout << "Welcome to FCAI Banking Application \n"
                "1. Create a New Account \n"
                "2. List Clients and Accounts \n"
                "3. Withdraw Money \n"
                "4. Deposit Money \n"
                "Please Enter Choice =========> ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            createaccount();
        } else if (choice == 2) {
            listusers();
        } else if (choice == 3) {
            Withdraw();
        } else if (choice == 4) {

        } else
            cout << "Enter Valid choice\n";
    }


}

void BankingApplication::createaccount() {

    cout << "What Type of Account Do You Like? (1) Basic (2) Saving - Type 1 or 2 =========> ";
    int c;
    cin >> c;
    if (c == 1) {
        client c1;
        BankAccount b1;
        b1.setClient(&c1);
        string name, address, phone;
        double balance;
        cout << "Please Enter Client Name =========> ";
        cin >> name;
        cout << "\nPlease Enter Client Address =======> ";
        cin >> address;
        cout << "\nPlease Enter Client Phone =======> ";
        cin >> phone;
        cout << "\nPlease Enter the Starting Balance =========> ";
        cin >> balance;
        b1.setAdd(address);
        b1.setNm(name);
        b1.setPhn(phone);
        b1.set_balance(balance);
        users.emplace_back(c1, b1);
        cout << "\nAn account was created with ID " <<
             b1.get_account_ID() << " and Starting Balance "
             << b1.get_balance() << " L.E.";
    } else {
        SavingBankAccount sa1;
        client c1;
        sa1.setClient(&c1);
        string name, address, phone;
        double balance;
        cout << "Please Enter Client Name =========> ";
        cin >> name;
        cout << "\nPlease Enter Client Address =======> ";
        cin >> address;
        cout << "\nPlease Enter Client Phone =======> ";
        cin >> phone;
        cout << "\nPlease Enter the Starting Balance =========> ";
        cin >> balance;
        sa1.setAdd(address);
        sa1.setNm(name);
        sa1.setPhn(phone);
        sa1.set_balance(balance);
        users.emplace_back(c1, sa1);
        cout << "\nAn account was created with ID " <<
             sa1.get_account_ID() << " and Starting Balance "
             << sa1.get_balance() << " L.E.";

    }
}

void BankingApplication::listusers() {
    for (auto element: users) {
        cout << "Name: " << element.first.getName() << endl;
        cout << "Adderss: " << element.first.getAddress() << endl;
        cout << "Account ID: " << element.second.get_account_ID();
        cout << (element.second.getState() ? " (Basic)" : " (Saving)") << endl;
        cout << "Balance: " << element.second.get_balance() << endl;
    }
}

void BankingApplication::Withdraw() {
    cout << "Please Enter Account ID =========> ";
    string id;
    cin >> id;
    bool found = false;
    while (!found) {
        for (auto element: users) {
            if (element.second.get_account_ID() == id) {
                element.second.set_balance(element.second.get_balance() - element.second.withdraw());
                found = true;
            }
        }
        if (!found)
            cout << "Please Enter Correct ID\n";
    }
}

