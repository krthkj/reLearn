#include "s15c_savings_account.hpp"

namespace udemy1::s15c
{

Savings_Account::Savings_Account(std::string n, double b, double r)
    : Account{n, b}
    , int_rate{r}
{
}
Savings_Account::~Savings_Account()
{
}
bool Savings_Account::deposit(double amt)
{
    amt += (amt * int_rate / 100);
    return Account::deposit(amt);
}

std::ostream& operator<<(std::ostream& os, const Savings_Account& acc)
{
    os << "[Savings_Account: " << acc.name << ": " << acc.balance << ", " << acc.int_rate << "%]";
    return os;
}

} // namespace udemy1::s15c
