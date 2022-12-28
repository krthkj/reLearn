#ifndef S15C_SAVINGS_ACCOUNT_HPP
#define S15C_SAVINGS_ACCOUNT_HPP

#include "s15c_account.hpp"

namespace udemy::s15c
{
/**
 * @class Savings_Account
 * @author Karthik Jain
 * @date 29/12/22
 * @file s15c_savings_account.hpp
 * @brief Savings account of type Account
 *        Adds a interest rate
 *        withdraw - same as regular
 *        Deposit - Amount supplied to deposit wil be incremented by (amount * int_rate/100)
 *                  and tehn updated amount will be deposited
 */
class Savings_Account : public Account
{
    friend std::ostream& operator<<(std::ostream& os, const Savings_Account& acc);

  private:
    // need C++11 to create following static constexpr varialbes
    static constexpr const char* def_name = "Unnamed Saving Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;

  protected:
    double int_rate;

  public:
    Savings_Account(std::string n = def_name, double b = def_balance, double r = def_int_rate);
    ~Savings_Account();
    bool deposit(double amt);
    // withdraw is inherited
};

} // namespace udemy::s15c
#endif // S15C_SAVINGS_ACCOUNT_HPP
