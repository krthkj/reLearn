/**
 * Copyright © 2022 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : s15c.cpp
 * Desc : Section 15: Inheritance
 *        Testing operator overloading
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2022-12-29
 *
 */

#include "s15c_account.hpp"
#include "s15c_account_util.hpp"
#include "s15c_checking_account.hpp"
#include "s15c_savings_account.hpp"
#include "s15c_trust_account.hpp"
#include "udemy1.hpp"

#include <iostream>
#include <vector>

namespace udemy1
{
/*
 * Section 15: Challenge - Inheritance challenge
 * =============================================
 * You are provided with a simple Account class hierarchy that contains
 * Account - Base class
 * Savings Account - Derived class
 *
 * An Account has a name and a balance.
 * A Savings Account is an Account and adds an interest rate.
 *
 * I have also provided some Account helper functions in Account_Util.h and Account_Util.cpp
 * that make it easy to display, deposit to, and withdraw from a vector of Accounts and Savings Accounts.
 *
 * Please refer to the source code provided and the video explanation of this challenge for more details.
 *
 * Your challenge is the following:
 *
 * 1. Add a Checking account class to the Account hierarchy
 *     A Checking account has a name and a balance and has a fee of $1.50 per withdrawal transaction.
 *     Every withdrawal transaction will be assessed this flat fee.
 *
 * 2. Add a Trust account class to the Account hierarchy
 *     A Trust account has a name, a balance, and an interest rate
 *     The Trust account deposit works just like a savings account deposit.
 *     However, any deposits of $5000.00 or more will receive a $50.00 bonus deposited to the account.
 *
 *     The Trust account withdrawal should only allow 3 withdrawals per year and each of these must be less than 20% of
 * the account balance. You don't have to keep track of calendar time for this application, just make sure the 4th
 * withdrawal fails :)
 *
 * Hints:
 *     Reuse existing functionality!!
 *     Think about what the Base class will be for the new classes.
 *     Add helper functions to Account_Util.h and Account_Util.cpp if you wish to work with your new classes.
 *     (You don't have to, but it will make your main much easier to use)
 *
 * Have fun!!  You are no longer beginner C++ programmers!
 *
 * If you want more practice with operator overloading you can overload += and -= for deposit and withdrawal :)
 *
 */
/**
 * @brief Challenge 15 - Inheritance
 */
void s15c_run(void)
{
    using udemy1::s15c::Account, udemy1::s15c::Savings_Account;
    using udemy1::s15c::Checking_Account, udemy1::s15c::Trust_Account;

    std::cout.precision(2);
    std::cout << std::fixed;

    // Account
    std::vector<Account> accounts;
    accounts.push_back(Account{});
    accounts.push_back(Account{"Larry"});
    accounts.push_back(Account{"Moe", 2000});
    accounts.push_back(Account{"Curly", 5000});

    udemy1::s15c::display(accounts);
    udemy1::s15c::deposit(accounts, 1000);
    udemy1::s15c::withdraw(accounts, 2000);

    // Savings
    std::vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account{});
    sav_accounts.push_back(Savings_Account{"Superman"});
    sav_accounts.push_back(Savings_Account{"Batman", 2000});
    sav_accounts.push_back(Savings_Account{"Wonder Woman", 5000, 5.0});

    udemy1::s15c::display(sav_accounts);
    udemy1::s15c::deposit(sav_accounts, 1000);
    udemy1::s15c::withdraw(sav_accounts, 2000);

    // Checking

    std::vector<Checking_Account> check_accounts;
    check_accounts.push_back(Checking_Account{});
    check_accounts.push_back(Checking_Account{"Kirk"});
    check_accounts.push_back(Checking_Account{"Spock", 2000});
    check_accounts.push_back(Checking_Account{"Bones", 5000});

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);

    // Trust
    std::vector<Trust_Account> trust_accounts;
    trust_accounts.push_back(Trust_Account{});
    trust_accounts.push_back(Trust_Account{"Athos", 10000, 5.0});
    trust_accounts.push_back(Trust_Account{"Porthos", 20000, 4.0});
    trust_accounts.push_back(Trust_Account{"Aramis", 30000});

    display(trust_accounts);
    deposit(trust_accounts, 1000);
    withdraw(trust_accounts, 3000);

    // Withdraw 5 times from each trust account
    // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
    for (int i = 1; i <= 5; i++)
        withdraw(trust_accounts, 1000);
}
} // namespace udemy1
