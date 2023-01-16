#ifndef S15C_TRUST_ACCOUNT_HPP
#define S15C_TRUST_ACCOUNT_HPP

#include "s15c_savings_account.hpp"

namespace udemy1::s15c
{

/**
 * @class Trust_Account
 * @author Karthik Jain
 * @date 29/12/22
 * @file s15c_trust_account.hpp
 * @brief Checking account of type Account
 *        has name, balance and interest rate
 *        Deposits of $5000 or more will recieve $50 bonus deposit
 *        withdraw same as savings
 *        allow 3 withdrawal per year and each of these must be less than 20% of the account balance
 *        [Hint: don't have to keep track of calendar time for this application, just make sure the 4th withdrawal
 *        fails]
 */
class Trust_Account : public Savings_Account
{
    friend std::ostream& operator<<(std::ostream& os, const Trust_Account& acc);

  private:
    static constexpr const char* def_name = "Unnamed Trust Account";
    static constexpr double def_balance   = 0.0;
    static constexpr double def_int_rate  = 0.0;

    static constexpr double bonus_amt       = 50.0;
    static constexpr double bonus_low_limit = 5000.0;

    static constexpr int max_withdraw_limit         = 3;
    static constexpr double max_withdraw_percentage = 0.2;

  protected:
    int num_withdraw;

  public:
    Trust_Account(std::string n = def_name, double b = def_balance, double r = def_int_rate);
    ~Trust_Account();
    bool deposit(double amt);  // $50 bonus if deposit is >= $5000
    bool withdraw(double amt); // max 3 transaction allowed, max allowed 20% or balance
};

} // namespace udemy1::s15c

#endif // S15C_TRUST_ACCOUNT_HPP
