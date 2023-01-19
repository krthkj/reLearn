#include "s15c_trust_account.hpp"

namespace udemy1::s15c
{
Trust_Account::Trust_Account(std::string n, double b, double r)
    : Savings_Account{n, b, r}
    , num_withdraw{0}
{
}

Trust_Account::~Trust_Account() {}

bool Trust_Account::deposit(double amt)
{
    if (amt >= bonus_low_limit)
        amt += bonus_amt;
    return Savings_Account::deposit(amt);
}

bool Trust_Account::withdraw(double amt)
{
    if (num_withdraw >= max_withdraw_limit || (amt > balance * max_withdraw_percentage))
        return false;
    else {
        ++num_withdraw;
        return Savings_Account::withdraw(amt);
    }
}

std::ostream& operator<<(std::ostream& os, const Trust_Account& acc)
{
    os << "[Trust_Account: " << acc.name << ": " << acc.balance << ", " << acc.int_rate
       << "%, withdrawals: " << acc.num_withdraw << "]";
    return os;
}
} // namespace udemy1::s15c
