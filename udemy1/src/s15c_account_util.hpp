#ifndef S15C_ACCOUNT_UTIL_HPP
#define S15C_ACCOUNT_UTIL_HPP

#include "s15c_account.hpp"
#include "s15c_checking_account.hpp"
#include "s15c_savings_account.hpp"
#include "s15c_trust_account.hpp"

#include <vector>

namespace udemy1::s15c
{

// Utility helper functions for Account class
void display(const std::vector<Account>& acc);
void deposit(std::vector<Account>& acc, double amt);
void withdraw(std::vector<Account>& account, double amt);

// Utility helper functions for Savings Account class
void display(const std::vector<Savings_Account>& acc);
void deposit(std::vector<Savings_Account>& acc, double amt);
void withdraw(std::vector<Savings_Account>& account, double amt);

// Utility helper functions for Checking Account class
void display(const std::vector<Checking_Account>& acc);
void deposit(std::vector<Checking_Account>& acc, double amt);
void withdraw(std::vector<Checking_Account>& account, double amt);

// Utility helper functions for Trust Account class
void display(const std::vector<Trust_Account>& acc);
void deposit(std::vector<Trust_Account>& acc, double amt);
void withdraw(std::vector<Trust_Account>& account, double amt);

} // namespace udemy1::s15c

#endif // S15C_ACCOUNT_UTIL_HPP
