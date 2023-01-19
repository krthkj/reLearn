#ifndef ACCOUNTS_HPP
#define ACCOUNTS_HPP

#include <string>

/**
 * @brief Example of inheritance
 */
namespace udemy1::e15::ex1
{

class Account
{
  public:
    double balance;
    std::string name;

  public:
    Account();
    ~Account() = default;

    void deposit(double amt);
    void withdraw(double amt);
};

class Savings_Account : public Account
{
  public:
    double int_rate;

  public:
    Savings_Account();
    ~Savings_Account() = default;

    void deposit(double amt);
    void withdraw(double amt);
};

} // namespace udemy1::e15::ex1

/**
 * @brief Example of redefinig base class methods
 *        Example of static binding
 */
namespace udemy1::e15::ex6
{

class Account
{
    friend std::ostream& operator<<(std::ostream& os, const Account& obj);

  public:
    double balance;

  public:
    Account();
    ~Account() = default;
    Account(double bal);

    void deposit(double amt);
    void withdraw(double amt);
};

/*
 * Saving account:
 * - Deposit method increments amount to be despoited by amount*int_rate percentage!!
 * - so, a 1000 deposit at 5% interest rate will deposit 1000+50 = 1050
 */
class Savings_Account : public Account
{
    friend std::ostream& operator<<(std::ostream& os, const Savings_Account& account);

  public:
    double int_rate;

  public:
    Savings_Account();
    ~Savings_Account() = default;
    Savings_Account(double balance, double int_rate);

    void deposit(double amt);
    // withdraw method is inherited
};

} // namespace udemy1::e15::ex6

#endif // ACCOUNTS_HPP
