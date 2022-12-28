#ifndef S15C_CHECKING_ACCOUNT_HPP
#define S15C_CHECKING_ACCOUNT_HPP

#include "s15c_account.hpp"
namespace udemy1::s15c
{
/**
 * @class Checking_Account
 * @author Karthik Jain
 * @date 29/12/22
 * @file s15c_checking_account.hpp
 * @brief Checking account of type Account
 *        will have name and balance
 *        Adds a fee of $1.5 per withdrawal transaction
 */
class Checking_Account : public Account
{
    friend std::ostream& operator<<(std::ostream& os, const Checking_Account& acc);

  private:
    static constexpr const char* def_name = "Unnamed Checking Account";
    static constexpr const double def_balance = 0.0;
    static constexpr const double per_withdraw_fee = 1.5;

  public:
    Checking_Account(std::string n = def_name, double b = def_balance);
    ~Checking_Account();

    // deposit method in inherited
    bool withdraw(double amt);
};

} // namespace udemy1::s15c

#endif // S15C_CHECKING_ACCOUNT_HPP
