#ifndef E16_CLASSES_HPP
#define E16_CLASSES_HPP

#include <iostream>
#include <string>

/**
 * @brief Example of Dynamic-binding, along with static binding
 */
namespace udemy1::e16::ex2
{

class Account
{
  public:
    double balance;
    Account();
    void deposit(double amount);
    virtual void withdraw(double amount);
    virtual ~Account();
};

class Checking : public Account
{
  public:
    void deposit(double amount);          // static-binding
    virtual void withdraw(double amount); // dynamic-binding
    Checking();
    virtual ~Checking();
};

class Savings : public Account
{
  public:
    void deposit(double amount);          // compile-time-binding
    virtual void withdraw(double amount); // run-time-binding
    Savings();
    virtual ~Savings();
};

class Trust : public Account
{
  public:
    void deposit(double amount);          // early binding
    virtual void withdraw(double amount); // late binding
    Trust();
    virtual ~Trust();
};

} // namespace udemy1::e16::ex2

/**
 * @brief Example of Virtul functions
 */
namespace udemy1::e16::ex3
{
class Account
{
  public:
    virtual void withdraw(double amount);
    virtual ~Account();
};

class Checking : public Account
{
  public:
    virtual void withdraw(double amount); // dynamic-binding
    virtual ~Checking();
};

class Savings : public Account
{
  public:
    virtual void withdraw(double amount); // run-time-binding
    virtual ~Savings();
};

class Trust : public Account
{
  public:
    virtual void withdraw(double amount); // late binding
    virtual ~Trust();
};

} // namespace udemy1::e16::ex3

/**
 * @brief Example of Pure virtual function and abstract class
 */
namespace udemy1::e16::ex6
{

class Shape // abstract class
{
  public:
    virtual void draw()   = 0; // pure virtual functions
    virtual void rotate() = 0; // pure virtual functions
    virtual ~Shape()      = default;
};

class Open_Shape : public Shape // abstract class
{
  public:
    virtual ~Open_Shape() = default;
};

class Closed_Shape : public Shape // abstract class
{
  public:
    virtual ~Closed_Shape() = default;
};

class Line : public Open_Shape // comcrete class
{
  public:
    virtual void draw() override;
    virtual void rotate() override;
    virtual ~Line() = default;
};

class Circle : public Closed_Shape // comcrete class
{
  public:
    virtual void draw() override;
    virtual void rotate() override;
    virtual ~Circle() = default;
};

class Square : public Closed_Shape // comcrete class
{
  public:
    virtual void draw() override;
    virtual void rotate() override;
    virtual ~Square() = default;
};

} // namespace udemy1::e16::ex6

/**
 * @brief Example of why abstract class as interfaces is needed
 */
namespace udemy1::e16::ex7_1
{
// below is Account Hierarchey
class Account
{
    friend std::ostream& operator<<(std::ostream& os, const Account& acc);

  public:
    std::string name;
    virtual void withdraw(double amount);
    Account(std::string n = "Unnamed Account");
    virtual ~Account() = default;
};

class Checking : public Account
{
    friend std::ostream& operator<<(std::ostream& os, const Checking& acc);

  public:
    virtual void withdraw(double amount);
    Checking(std::string n = "Unnamed Checking Account");
    virtual ~Checking() = default;
};

class Savings : public Account
{
    friend std::ostream& operator<<(std::ostream& os, const Savings& acc);

  public:
    virtual void withdraw(double amount);
    Savings(std::string n = "Unnamed Savings Account");
    virtual ~Savings() = default;
};

class Trust : public Account
{
    friend std::ostream& operator<<(std::ostream& os, const Trust& acc);

  public:
    virtual void withdraw(double amount);
    Trust(std::string n = "Unnamed Trust Account");
    virtual ~Trust() = default;
};
} // namespace udemy1::e16::ex7_1

/**
 * @brief Example of abstract class as interfaces
 */
namespace udemy1::e16::ex7_2
{

/**
 * @class I_Printable
 * @author Karthik Jain
 * @date 29/12/22
 * @file e16_classes.hpp
 * @brief Interface class example
 */
class I_Printable // Interface class
{
    friend std::ostream& operator<<(std::ostream& os, const I_Printable& obj);

  public:
    virtual void print(std::ostream& os) const = 0;
};

// below is Account Hierarchey
class Account : public I_Printable
{
  public:
    std::string name;
    virtual void withdraw(double amount);
    virtual void print(std::ostream& os) const override;
    Account(std::string n = "Unnamed Savings Account");
    virtual ~Account() = default;
};

class Checking : public Account
{
  public:
    virtual void withdraw(double amount) override;
    virtual void print(std::ostream& os) const override;
    virtual ~Checking() = default;
    Checking(std::string n = "Unnamed Checking Account");
};

class Savings : public Account
{

  public:
    virtual void withdraw(double amount) override;
    virtual void print(std::ostream& os) const override;
    virtual ~Savings() = default;
    Savings(std::string n = "Unnamed Savings Account");
};

class Trust : public Account
{
  public:
    virtual void withdraw(double amount) override;
    virtual void print(std::ostream& os) const override;
    Trust(std::string n = "Unnamed Trust Account");
    virtual ~Trust() = default;
};

class Dog : public I_Printable
{
  public:
    std::string name;
    virtual void print(std::ostream& os) const override;
    virtual ~Dog() = default;
    Dog(std::string n = "Unnamed Dog");
};
} // namespace udemy1::e16::ex7_2

#endif // E16_CLASSES_HPP
