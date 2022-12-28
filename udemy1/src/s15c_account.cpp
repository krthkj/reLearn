#include "s15c_account.hpp"

namespace udemy::s15c
{
Account::Account(std::string name, double balance)
    : name{name}
    , balance{balance}
{
}
Account::~Account()
{
}
bool Account::deposit(double amt)
{
    if(amt < 0)
        return false;
    else {
        balance += amt;
        return true;
    }
}
bool Account::withdraw(double amt)
{
    if(balance - amt >= 0) {
        balance -= amt;
        return true;
    } else
        return false;
}
double Account::get_balance() const
{
    return balance;
}

std::ostream& operator<<(std::ostream& os, const Account& acc)
{
    os << "[Account: " << acc.name << ": " << acc.balance << "]";
    return os;
}

} // namespace udemy::s15c
