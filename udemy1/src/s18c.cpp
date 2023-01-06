/**
 * Copyright © 2023 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : s18c.cpp
 * Desc : Section 18: Exception handling
 *
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2023-01-06
 *
 */

#include "s18c_class.hpp"
#include "udemy1.hpp"

#include <iostream>
#include <memory>

namespace udemy1
{

/**
 * @brief Challenge 18
 *
 * For this challenge we want to integrate our own user-defined exception classes into the Account class
 * hierarchy.
 *
 * The account classes are provided for you.
 * Also, the IllegalBalanceException.h file contains the declaration for the IllegalBalanceException class.
 *
 * What I would like you to do is:
 * 1. Derive IllegalBalanceException from std::exception and implement the what() method to provide an exception
 * message. This exception object should be thrown from the Account class constructor if an account object is created
 * with a negative balance.
 *
 * 2. Derive InsufficentFundsException from std::exception and implement the what() method to provide an exception
 * message. This exception object should be thrown if a withdraw results in a negative balance. You should throw this
 * exception object from the Account withdraw method.
 *
 */

void s18c_run(void)
{
    std::unique_ptr<s18c::Account> moes_account;
    std::unique_ptr<s18c::Account> larrys_account;

    try {
        larrys_account = std::make_unique<s18c::Savings_Account>("Larry", -2000.0);
        std::cout << *larrys_account << std::endl;

    } catch(const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        //} catch(const s18c::IllegalBalanceException& ex) {
        //    std::cerr << ex.what() << std::endl;
    }

    try {
        moes_account = std::make_unique<s18c::Savings_Account>("Moes", 1000.0);
        std::cout << *moes_account << std::endl;

        moes_account->withdraw(500);
        std::cout << *moes_account << std::endl;

        moes_account->withdraw(1000);
        std::cout << *moes_account << std::endl;

    } catch(const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        //} catch(const s18c::InsufficentFundsException& ex) {
        //    std::cerr << ex.what() << std::endl;
        //} catch(const s18c::IllegalBalanceException& ex) {
        //    std::cerr << ex.what() << std::endl;
    }

    std::cout << "Program completed successfully" << std::endl;
}

} // namespace udemy1
