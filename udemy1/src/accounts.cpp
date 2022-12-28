#include "accounts.hpp"
#include <iostream>

using std::cout, std::endl;

/**
 * @brief Example of inheritance
 */
namespace udemy::e15::ex1
{

// base class
Account::Account()
    : balance{0.0}
    , name{"An Account"}
{
}
Account::~Account()
{
}
void Account::deposit(double amt)
{
    cout << "Account deposit called with " << amt << endl;
}
void Account::withdraw(double amt)
{
    cout << "Account withdraw called with " << amt << endl;
}

// derived class
Savings_Account::Savings_Account()
    : int_rate{3.0}
{
}
Savings_Account::~Savings_Account()
{
}
void Savings_Account::deposit(double amt)
{
    cout << "Savings Account deposit called with " << amt << endl;
}
void Savings_Account::withdraw(double amt)
{
    cout << "Savings Account withdraw called with " << amt << endl;
}

} // namespace udemy::e15::ex1

/**
 * @brief Example of redefinig base class methods
 *        Example of static binding
 */
namespace udemy::e15::ex6
{

Account::Account()
    : balance{0.0}
{
}
Account::Account(double bal)
    : balance{bal}
{
}

Account::~Account()
{
}
void Account::deposit(double amt)
{
    balance += amt;
    cout << amt << " Deposited" << endl;
}
void Account::withdraw(double amt)
{
    if(balance - amt >= 0) {
        balance -= amt;
        cout << amt << " Withdrawn" << endl;
    } else
        cout << "Insufficient funds" << endl;
}

Savings_Account::Savings_Account()
    : Savings_Account{0.0, 0.0}
{
}
Savings_Account::~Savings_Account()
{
}
Savings_Account::Savings_Account(double bal, double rate)
    : Account{bal}
    , int_rate{rate}
{
}

void Savings_Account::deposit(double amt)
{
    amt += (amt * int_rate / 100);
    Account::deposit(amt);
}

std::ostream& operator<<(std::ostream& os, const Account& account)
{
    cout << "Account Balance: " << account.balance;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Savings_Account& account)
{
    cout << "Savings Account Balance: " << account.balance << " Interest rate: " << account.int_rate;
    return os;
}

} // namespace udemy::e15::ex6
