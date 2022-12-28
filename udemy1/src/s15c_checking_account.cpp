#include "s15c_checking_account.hpp"

namespace udemy::s15c
{
Checking_Account::Checking_Account(std::string n, double b):
Account{n,b}
{
}
Checking_Account::~Checking_Account()
{
}
bool Checking_Account::withdraw(double amt)
{
    amt+=per_withdraw_fee;
    return Account::withdraw(amt);
}

std::ostream& operator<<(std::ostream& os, const Checking_Account& acc)
{
    os << "[Checking_Account: " << acc.name << ": " << acc.balance << "]";
    return os;
}

} // namespace udemy::s15c
