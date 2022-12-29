#ifndef S15C_ACCOUNT_HPP
#define S15C_ACCOUNT_HPP

#include <iostream>
#include <string>

namespace udemy1::s15c
{
/**
 * @class Account
 * @author Karthik Jain
 * @date 29/12/22
 * @file s15c_account.hpp
 * @brief
 */
class Account
{
    friend std::ostream& operator<<(std::ostream& os, const Account& acc);

  private:
    // need C++11 to create following static constexpr varialbes
    static constexpr const char* def_name = "Unnames Account";
    static constexpr double def_balance = 0.0;

  protected:
    std::string name;
    double balance;

  public:
    Account(std::string name = def_name, double balance = def_balance);
    ~Account();

    bool deposit(double amt);
    bool withdraw(double amt);
    double get_balance() const;
};
} // namespace udemy1::s15c
#endif // S15C_ACCOUNT_HPP
