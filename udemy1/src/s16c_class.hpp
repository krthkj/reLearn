#ifndef S16C_CLASS_HPP
#define S16C_CLASS_HPP

#include <iostream>
#include <vector>

namespace udemy1::s16c
{
/**
 * @class I_Printable
 * @author Karthik Jain
 * @date 30/12/22
 * @file s16c_class.hpp
 * @brief Interface for all objects to print to cout
 */
class I_Printable
{
    friend std::ostream& operator<<(std::ostream& os, const I_Printable& obj);

  public:
    ~I_Printable() = default;
    virtual void print(std::ostream& os) const = 0;
};

/**
 * @class Account
 * @author Karthik Jain
 * @date 30/12/22
 * @file s16c_class.hpp
 * @brief Abstract class for alll accounts
 */
class Account : public I_Printable
{
  private:
    static constexpr const char* def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;

  protected:
    std::string name;
    double balance;

  public:
    Account(std::string n = def_name, double b = def_balance);
    virtual ~Account() = default;
    virtual bool deposit(double amt) = 0;
    virtual bool withdraw(double amt) = 0;
    virtual void print(std::ostream& os) const override;
    double get_balance(void) const;
};

/**
 * @class Savings
 * @author Karthik Jain
 * @date 30/12/22
 * @file s16c_class.hpp
 * @brief
 */
class Savings : public Account
{
  private:
    static constexpr const char* def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;

  protected:
    double int_rate;

  public:
    Savings(std::string n = def_name, double b = def_balance, double r = def_int_rate);
    virtual ~Savings() = default;
    virtual bool withdraw(double amt) override;
    virtual bool deposit(double amt) override;
    virtual void print(std::ostream& os) const override;
};

/**
 * @class Checking
 * @author Karthik Jain
 * @date 30/12/22
 * @file s16c_class.hpp
 * @brief
 */
class Checking : public Account
{
  private:
    static constexpr const char* def_name = "Unnamed Checking Account";
    static constexpr const double def_balance = 0.0;
    static constexpr const double per_withdraw_fee = 1.5;

  public:
    Checking(std::string n = def_name, double b = def_balance);
    virtual ~Checking() = default;
    virtual bool withdraw(double amt) override;
    virtual bool deposit(double amt) override;
    virtual void print(std::ostream& os) const override;
};

/**
 * @class Trust
 * @author Karthik Jain
 * @date 30/12/22
 * @file s16c_class.hpp
 * @brief
 */
class Trust : public Savings
{
  private:
    static constexpr const char* def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;

    static constexpr double bonus_amt = 50.0;
    static constexpr double bonus_low_limit = 5000.0;

    static constexpr int max_withdraw_limit = 3;
    static constexpr double max_withdraw_percentage = 0.2;

  protected:
    int num_withdraw;

  public:
    Trust(std::string n = def_name, double b = def_balance, double r = def_int_rate);
    virtual ~Trust();
    virtual bool deposit(double amt) override;  // $50 bonus if deposit is >= $5000
    virtual bool withdraw(double amt) override; // max 3 transaction allowed, max allowed 20% or balance
    virtual void print(std::ostream& os) const override;
};

// Util Functions
void display(std::vector<Account*>& accounts);
void deposit(std::vector<Account*>& accounts, double amt);
void withdraw(std::vector<Account*>& accounts, double amt);

} // namespace udemy1::s16c

#endif // S16C_CLASS_HPP
