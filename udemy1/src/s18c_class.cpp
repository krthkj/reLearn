#include "s18c_class.hpp"

namespace udemy1::s18c
{

const char* IllegalBalanceException::what() const noexcept
{
    return "Illegal Balance Exception";
}
const char* InsufficentFundsException::what() const noexcept
{
    return "Insufficient Funds Exception";
}

std::ostream& operator<<(std::ostream& os, const I_Printable& obj)
{
    obj.print(os);
    return os;
}

Account::Account(std::string name, double balance)
    : name{name}
    , balance{balance}
{
    if(balance < 0.0)
        throw IllegalBalanceException();
}

bool Account::deposit(double amount)
{
    if(amount < 0)
        return false;
    else {
        balance += amount;
        return true;
    }
}

bool Account::withdraw(double amount)
{
    if(balance - amount >= 0) {
        balance -= amount;
        return true;
    } else
        throw InsufficentFundsException();
}

void Account::print(std::ostream& os) const
{
    os.precision(2);
    os << std::fixed;
    os << "[Account: " << name << ": " << balance << "]";
}

Checking_Account::Checking_Account(std::string name, double balance)
try : Account{name, balance} {

} catch(...) {
    ;
}

bool Checking_Account::withdraw(double amount)
{
    amount += per_check_fee;
    return Account::withdraw(amount);
}

bool Checking_Account::deposit(double amount)
{
    return Account::deposit(amount);
}

void Checking_Account::print(std::ostream& os) const
{
    os.precision(2);
    os << std::fixed;
    os << "[Checking_Account: " << name << ": " << balance << "]";
}

Savings_Account::Savings_Account(std::string name, double balance, double int_rate)
    : Account{name, balance}
    , int_rate{int_rate}
{
}

// Deposit:
//      Amount supplied to deposit will be incremented by (amount * int_rate/100)
//      and then the updated amount will be deposited
//
bool Savings_Account::deposit(double amount)
{
    amount += amount * (int_rate / 100);
    return Account::deposit(amount);
}

bool Savings_Account::withdraw(double amount)
{
    return Account::withdraw(amount);
}

void Savings_Account::print(std::ostream& os) const
{
    os.precision(2);
    os << std::fixed;
    os << "[Savings_Account: " << name << ": " << balance << ", " << int_rate << "]";
}

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account{name, balance, int_rate}
    , num_withdrawals{0}
{
}

// Deposit additional $50 bonus when amount >= $5000
bool Trust_Account::deposit(double amount)
{
    if(amount >= bonus_threshold)
        amount += bonus_amount;
    return Savings_Account::deposit(amount);
}

// Only allowed 3 withdrawals, each can be up to a maximum of 20% of the account's value
bool Trust_Account::withdraw(double amount)
{
    if(num_withdrawals >= max_withdrawals || (amount > balance * max_withdraw_percent))
        return false;
    else {
        ++num_withdrawals;
        return Savings_Account::withdraw(amount);
    }
}

void Trust_Account::print(std::ostream& os) const
{
    os.precision(2);
    os << std::fixed;
    os << "[Trust Account: " << name << ": " << balance << ", " << int_rate << "%, withdrawals: " << num_withdrawals
       << "]";
}

// Displays Account objects in a  vector of Account object pointers
void display(const std::vector<Account*>& accounts)
{
    std::cout << "\n=== Accounts===========================================" << std::endl;
    for(const auto acc : accounts)
        std::cout << *acc << std::endl;
}

// Deposits supplied amount to each Account object in the vector
void deposit(std::vector<Account*>& accounts, double amount)
{
    std::cout << "\n=== Depositing to Accounts =================================" << std::endl;
    for(auto acc : accounts) {
        if(acc->deposit(amount))
            std::cout << "Deposited " << amount << " to " << *acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << *acc << std::endl;
    }
}

// Withdraw amount from each Account object in the vector
void withdraw(std::vector<Account*>& accounts, double amount)
{
    std::cout << "\n=== Withdrawing from Accounts ==============================" << std::endl;
    for(auto acc : accounts) {
        if(acc->withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << *acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << *acc << std::endl;
    }
}

} // namespace udemy1::s18c
