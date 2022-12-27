#ifndef ACCOUNTS_HPP
#define ACCOUNTS_HPP

#include <string>

namespace udemy::e15
{

class Account
{
  public:
    double balance;
    std::string name;

  public:
    Account();
    ~Account();

    void deposit(double amt);
    void withdraw(double amt);
};

class Savings_Account : public Account
{
  public:
    double int_rate;

  public:
    Savings_Account();
    ~Savings_Account();

    void deposit(double amt);
    void withdraw(double amt);
};

} // namespace udemy::e15

#endif // ACCOUNTS_HPP
