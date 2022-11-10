#include "BankingApplication.h"

void BankingApplication::run() {
    char c;
    bool stop = false;
    while (!stop) {
        cout << "Press 1 to start & any other key to end program\n";
        cin >> c;
        if (c == '1') {
            cout << "Welcome to FCAI Banking Application \n"
                    "1. Create a New Account \n"
                    "2. List Clients and Accounts \n"
                    "3. Withdraw Money \n"
                    "4. Deposit Money \n"
                    "Please Enter Choice ====> ";
            int choice;
            cin >> choice;
            if (choice == 1) {
                createaccount();
            } else if (choice == 2) {
                listusers();
            } else if (choice == 3) {
                Withdraw();
            } else if (choice == 4) {
                Deposit();
            } else
                cout << "Enter Valid choice\n";
            setData();
        } else {
            stop = true;
            setData();
            exit(0);
        }

    }
}


void BankingApplication::createaccount() {

    cout << "What Type of Account Do You Like?\n(1) Basic (2) Saving - Type 1 or 2 ====> ";
    int c;
    cin >> c;
    if (c == 1) {
        client c1;
        BankAccount b1;
        string name, address, phone;
        double balance;
        cout << "Please Enter Client Name ====> ";
        cin >> name;
        cout << "\nPlease Enter Client Address ====> ";
        cin >> address;
        cout << "\nPlease Enter Client Phone ====> ";
        cin >> phone;
        cout << "\nPlease Enter the Starting Balance ====> ";
        cin >> balance;
        c1.setAddress(address);
        c1.setName(name);
        c1.setPhoneNumber(phone);
        b1.setBalance(balance);
        users.emplace_back(make_pair(c1, new BankAccount(b1)));
        cout << "\nAn account was created with ID " <<
             b1.getId() << " and Starting Balance "
             << b1.getBalance() << " L.E." << endl
             << "-----------------------------------\n";
    } else {
        client c1;
        string name, address, phone;
        double balance;
        cout << "Please Enter Client Name ====> ";
        cin >> name;
        cout << "\nPlease Enter Client Address ====> ";
        cin >> address;
        cout << "\nPlease Enter Client Phone ====> ";
        cin >> phone;
        cout << "\nPlease Enter the Starting Balance ====> ";
        cin >> balance;
        c1.setAddress(address);
        c1.setName(name);
        c1.setPhoneNumber(phone);
        cout << "Do you want to set your own Minimum Balance?\ntype (1)YES or (2)NO ====> ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            int minbalance;
            cout << "Enter your Min Balance ===> ";
            cin >> minbalance;
            SavingBankAccount sa1(balance, minbalance);
            users.emplace_back(make_pair(c1, new SavingBankAccount(sa1)));
        } else {
            SavingBankAccount sa1(balance);
            users.emplace_back(make_pair(c1, new SavingBankAccount(sa1)));
        }
    }
}

void BankingApplication::listusers() {
    for (auto &user: users) {
        cout << "Name: " << user.first.getName() << endl;
        cout << "Adderss: " << user.first.getAddress() << endl;
        cout << "Account ID: " << (user.second)->getId();
        cout << ((user.second)->getState() ? " (Basic)" : " (Saving)") << endl;
        cout << "Balance: " << (user.second)->getBalance() << endl;
    }
}

void BankingApplication::Withdraw() {
    cout << "Please Enter Account ID ===> ";
    string id;
    cin >> id;
    bool found = false;
    while (!found) {
        for (auto &element: users) {
            if (element.second->getId() == id) {
                element.second->withdraw();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Please Enter Correct ID\n";
            cin >> id;
        }
    }

}

void BankingApplication::Deposit() {
    cout << "Please Enter Account ID ===> ";
    string id;
    cin >> id;
    bool found = false;
    while (!found) {
        for (auto &element: users) {
            if (element.second->getId() == id) {
                element.second->deposit();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Please Enter Correct ID\n";
            cin >> id;
        }
    }
}

void BankingApplication::setData() {
    fstream file_;
    file_.open("Bank.csv", ios::out);
    for (auto &e: users) {
        file_ << e.first.getName() << ',';
        file_ << e.first.getPhoneNum() << ',';
        file_ << e.first.getAddress() << ',';
        file_ << e.second->getBalance() << ',';
        file_ << e.second->getId() << ',';
        file_ << (e.second->getState() ? "Basic" : "Saving") << '\n';
    }
    file_.close();
}

void BankingApplication::getData() {
    ifstream file_;
    file_.open("Bank.csv");
    string line;
    client user;
    while (getline(file_, line)) {
        istringstream ss(line);
        string name, id, phone, balance, address, state;
        getline(ss, name, ',');
        getline(ss, phone, ',');
        getline(ss, address, ',');
        getline(ss, balance, ',');
        getline(ss, id, ',');
        id.pop_back();
        getline(ss, state);
        double Balance = stod(balance);
        user.setName(name);
        user.setAddress(address);
        user.setPhoneNumber(phone);
        if (state == "Saving") {
            SavingBankAccount s1;
            s1.setBalance(Balance);
            s1.setId(id);
            s1.setState(false);
            users.emplace_back(make_pair(user, new SavingBankAccount(s1)));
        } else {
            BankAccount b1;
            b1.setBalance(Balance);
            b1.setId(id);
            b1.setState(true);
            users.emplace_back(make_pair(user, new BankAccount(b1)));
        }
    }
}

void BankingApplication::createData() {
    ifstream file_;
    file_.open("Bank.csv");
    if (!file_) {
        file_.close();
        ofstream file2("Bank.csv");
        file2.close();
    }
}



