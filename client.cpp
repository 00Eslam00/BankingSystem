#include "BankAccount.h"
#include "client.h"
void client::setName(string Name)
{
    name = Name;
}
void client::setAddress(string Address)
{
    address = Address;
}
void client::setPhoneNumber(string PhoneNum)
{
    phoneNum = PhoneNum;
}
void client::setClientAccount(BankAccount *ptrClint)
{
    itsClient = ptrClint;
}

string client::getAccount_Id()
{
    return (itsClient->get_account_ID());
}
string client::getName()
{
    return (this->name);
}
string client::getAddress()
{
    return (this->address);
}
string client::getPhoneNum()
{
    return (this->phoneNum);
}
double client::getBalance()
{
    return (itsClient->get_balance());
}
void client::setBalance(double new_value) {
    itsClient->set_balance(new_value);
}