#ifndef E17_CLASS_HPP
#define E17_CLASS_HPP

#include <iostream>
#include <vector>

/**
 * @brief Example of Smart pointer
 */
namespace udemy1::e17::ex1
{

class Test
{
  private:
    int data;

  public:
    Test();
    Test(int d);
    ~Test();
    int get_data() const;
};

} // namespace udemy1::e17::ex1

namespace udemy1::e17::ex2
{
class I_Printable
{
    friend std::ostream& operator<<(std::ostream& os, const I_Printable& obj);

  public:
    virtual void print(std::ostream& os) const = 0;
    virtual ~I_Printable() = default;
};

class Account : public I_Printable
{
  private:
    static constexpr const char* def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;

  protected:
    std::string name;
    double balance;

  public:
    Account(std::string name = def_name, double balance = def_balance);
    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual void print(std::ostream& os) const override;
    virtual ~Account() = default;
};

class Checking_Account : public Account
{
  private:
    static constexpr const char* def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double per_check_fee = 1.5;

  public:
    Checking_Account(std::string name = def_name, double balance = def_balance);
    virtual bool withdraw(double) override;
    virtual bool deposit(double) override;
    virtual void print(std::ostream& os) const override;
    virtual ~Checking_Account() = default;
};

class Savings_Account : public Account
{
  private:
    static constexpr const char* def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;

  protected:
    double int_rate;

  public:
    Savings_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual void print(std::ostream& os) const override;
    virtual ~Savings_Account() = default;
};

class Trust_Account : public Savings_Account
{
  private:
    static constexpr const char* def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr double bonus_amount = 50.0;
    static constexpr double bonus_threshold = 5000.0;
    static constexpr int max_withdrawals = 3;
    static constexpr double max_withdraw_percent = 0.2;

  protected:
    int num_withdrawals;

  public:
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);

    // Deposits of $5000.00 or more will receive $50 bonus
    virtual bool deposit(double amount) override;

    // Only allowed maximum of 3 withdrawals, each can be up to a maximum of 20% of the account's value
    virtual bool withdraw(double amount) override;
    virtual void print(std::ostream& os) const override;
};

// Utility helper functions for Account * class

void display(const std::vector<Account*>& accounts);
void deposit(std::vector<Account*>& accounts, double amount);
void withdraw(std::vector<Account*>& accounts, double amount);
} // namespace udemy1::e17::ex2

#endif // E17_CLASS_HPP
