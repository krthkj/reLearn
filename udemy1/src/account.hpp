#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>

namespace udemy1::myclass
{

class Account
{
  private:
    std::string name{"Account"};
    double balance{0.0};

  public:
    void set_balance(double);
    double get_balance();

    void set_name(std::string);
    std::string get_name();

    bool deposit(double);
    bool withdraw(double);
};

} // namespace udemy1::ex4
#endif // ACCOUNT_HPP
