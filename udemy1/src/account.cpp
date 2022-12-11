#include "account.hpp"

namespace udemy1::myclass
{

void Account::set_name(std::string n)
{
    name = n;
}

std::string Account::get_name()
{
    return name;
}

void Account::set_balance(double bal)
{
    balance = bal;
}

double Account::get_balance()
{
    return balance;
}

bool Account::deposit(double amt)
{
    balance += amt;
    return true;
}

bool Account::withdraw(double amt)
{
    if(balance - amt >= 0) {
        balance -= amt;
        return true;
    }
    return false;
}

} // namespace udemy1::ex4
