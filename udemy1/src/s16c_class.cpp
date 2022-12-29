#include "s16c_class.hpp"

namespace udemy1::s16c
{
//------------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const I_Printable& obj)
{
    obj.print(os);
    return os;
}
//------------------------------------------------------------------------------------
Account::Account(std::string n, double b)
    : name{n}
    , balance{b}
{
}
bool Account::deposit(double amt)
{
    if(amt <= 0)
        return false;
    else {
        balance += amt;
        return true;
    }
}
bool Account::withdraw(double amt)
{
    if(amt > balance)
        return false;
    else {
        balance -= amt;
        return true;
    }
}
double Account::get_balance(void) const
{
    return balance;
}
void Account::print(std::ostream& os) const
{
    os.precision(2);
    os << std::fixed;
    os << "[Account: " << this->name << ": " << this->balance << "]";
}
//------------------------------------------------------------------------------------
Savings::Savings(std::string n, double b, double r)
    : Account{n, b}
    , int_rate{r}
{
}
bool Savings::deposit(double amt)
{
    amt += (amt * int_rate / 100);
    return Account::deposit(amt);
}
bool Savings::withdraw(double amt)
{
    return Account::withdraw(amt);
}
void Savings::print(std::ostream& os) const
{
    os.precision(2);
    os << std::fixed;
    os << "[Savings_Account: " << this->name << ": " << this->balance << ", " << this->int_rate << "%]";
}
//------------------------------------------------------------------------------------
Checking::Checking(std::string n, double b)
    : Account{n, b}
{
}
bool Checking::withdraw(double amt)
{
    amt += per_withdraw_fee;
    return Account::withdraw(amt);
}
bool Checking::deposit(double amt)
{
    return Account::deposit(amt);
}
void Checking::print(std::ostream& os) const
{
    os.precision(2);
    os << std::fixed;
    os << "[Checking: " << this->name << ": " << this->balance << "]";
}
//------------------------------------------------------------------------------------
Trust::Trust(std::string n, double b, double r)
    : Savings{n, b, r}
    , num_withdraw{0}
{
}
Trust::~Trust()
{
}
bool Trust::deposit(double amt)
{
    if(amt >= bonus_low_limit)
        amt += bonus_amt;
    return Savings::deposit(amt);
}
bool Trust::withdraw(double amt)
{
    if(num_withdraw >= max_withdraw_limit || (amt > balance * max_withdraw_percentage))
        return false;
    else {
        ++num_withdraw;
        return Savings::withdraw(amt);
    }
}
void Trust::print(std::ostream& os) const
{
    os.precision(2);
    os << std::fixed;
    os << "[Trust: " << this->name << ": " << this->balance << ", " << this->int_rate
       << "%, withdrawals: " << this->num_withdraw << "]";
}
//------------------------------------------------------------------------------------
void display(std::vector<Account*>& accounts)
{
    std::cout << "\n=== Displaying Accounts ===============================================" << std::endl;
    for(const Account* const acc : accounts)
        std::cout << *acc << std::endl;
}
void deposit(std::vector<Account*>& accounts, double amt)
{
    std::cout << "\n=== Depositing to Accounts ============================================" << std::endl;
    for(Account* const acc : accounts) {
        if(acc->deposit(amt))
            std::cout << "Deposited " << amt << " to " << *acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amt << " to " << *acc << std::endl;
    }
}
void withdraw(std::vector<Account*>& accounts, double amt)
{
    std::cout << "\n=== Withdrawing from Accounts =========================================" << std::endl;
    for(Account* const acc : accounts) {
        if(acc->withdraw(amt))
            std::cout << "Withdrew " << amt << " from " << *acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amt << " from " << *acc << std::endl;
    }
}

} // namespace udemy1::s16c
