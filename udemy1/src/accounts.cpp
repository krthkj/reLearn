#include "accounts.hpp"
#include <iostream>

namespace udemy::e15
{

using std::cout, std::endl;

// base class
Account::Account()
    :  balance{0.0}, name{"An Account"}
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
: int_rate {3.0} 
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

} // namespace udemy::e15
