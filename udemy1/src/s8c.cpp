/**
 * Copyright © 2022 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : s7c.cpp
 * Desc : Section 7 Challenge from Udemy course "Beginning C++ Programming
 *        - From Beginner to Beyond"
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2022-11-30
 *
 */

#include "udemy1.hpp"
#include <iostream>

namespace udemy1
{
/**
 * @brief Section 8 Challenge
 * For this program, I'm going to be using US dollars and cents
 *
 * Write a program that asks the user to enter the following:
 * An integer representing the number of cents
 *
 * You can assume that the number of cents entered is greater than or equal to zero.
 *
 * The program then displays how to provide that change to the user.
 *
 * In the U.S:
 *     1 dollar = 100 cents
 *     1 quarter = 25 cents
 *     1 dime = 10 cents
 *     1 nickel = 5 cents
 *     1 penny = 1 cent
 *
 * Example
 * Enter an amount in cents: 92
 *
 * You can provide this change as follows:
 * dollars  : 0
 * quarters : 3
 * dime     : 1
 * nickel   : 1
 * pennies  : 2
 *
 */
void s8c_run(void)
{
    int cents{0};
    bool loop_val = false;
    do {
        std::cout << "Enter an amount in cents: ";
        std::cin >> cents;
        if(cents < 0)
            loop_val = true;
        else
            loop_val = false;
    } while(loop_val);

    int n_dollar{cents / 100};
    cents = cents % 100;

    int n_quarters{cents / 25};
    cents = cents % 25;

    int n_dime{cents / 10};
    cents = cents % 10;

    int n_nickel{cents / 5};
    cents = cents % 5;

    std::cout << "You can provide this change as follows:" << std::endl;
    std::cout << "dollars  : " << n_dollar << std::endl;
    std::cout << "quarters : " << n_quarters % 100 << std::endl;
    std::cout << "dime     : " << n_dime % 100 << std::endl;
    std::cout << "nickel   : " << n_nickel % 100 << std::endl;
    std::cout << "pennies  : " << cents % 100 << std::endl;
}
} // namespace udemy1
