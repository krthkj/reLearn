#ifndef E17_CLASS_HPP
#define E17_CLASS_HPP

#include <iostream>
#include <memory>
#include <vector>

/**
 * @brief Example of Smart pointer test class
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

/**
 * @brief Example of Common Account related classes
 */
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

/**
 * @brief Test class for weak pointer or cyclic reference
 */
namespace udemy1::e17::ex4
{

// Problem: Strong circular reference
class B; // forward decleration

class A
{
  private:
    std::shared_ptr<B> b_ptr; // Strong circular reference
  public:
    void set_B(std::shared_ptr<B>& b)
    {
        b_ptr = b;
    }

    A()
    {
        std::cout << "A Constructor" << std::endl;
    }

    ~A()
    {
        std::cout << "A Destructor" << std::endl;
    }
};

class B
{
  private:
    std::shared_ptr<A> a_ptr; // Strong circular reference
  public:
    void set_A(std::shared_ptr<A>& a)
    {
        a_ptr = a;
    }

    B()
    {
        std::cout << "B Constructor" << std::endl;
    }

    ~B()
    {
        std::cout << "B Destructor" << std::endl;
    }
};

// Solution: makeing weak circular reference
class B_weak; // forward decleration

class A_weak
{
  private:
    std::shared_ptr<B_weak> b_ptr; // Strong reference
  public:
    void set_B(std::shared_ptr<B_weak>& b)
    {
        b_ptr = b;
    }

    A_weak()
    {
        std::cout << "A_weak Constructor" << std::endl;
    }

    ~A_weak()
    {
        std::cout << "A_weak Destructor" << std::endl;
    }
};

class B_weak
{
  private:
    std::weak_ptr<A_weak> a_ptr; // make weak to break the strong circular reference
  public:
    void set_A(std::shared_ptr<A_weak>& a)
    {
        a_ptr = a;
    }

    B_weak()
    {
        std::cout << "B_weak Constructor" << std::endl;
    }

    ~B_weak()
    {
        std::cout << "B_weak Destructor" << std::endl;
    }
};
} // namespace udemy1::e17::ex4
#endif // E17_CLASS_HPP
