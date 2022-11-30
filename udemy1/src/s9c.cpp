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
#include <vector>
#include <string>
#include <boost/algorithm/string/erase.hpp>

namespace udemy1
{

/**
 * @brief Section 9 Challenge
 * This challenge is about using a collection (list) of integers and allowing the user
 * to select options from a menu to perform operation on teh list.
 *
 * Your program should display a menu options to the user as follows:
 * P - Print numbers
 * A - Add numbers
 * M - Display mean of the numbers
 * S - Display the smallest number
 * L - Display the largest number
 * Q - Quit
 *
 * Enter your choice:
 *
 * Upon Selecting Q, should display "Goodbye" and terminate.
 *
 * list messages to be display if the list is empty,
 * "Unable to calculate the mean - no data"
 * "Unable to determint the smallest number - list is empty"
 * "[] - the list is empty"
 * "<value> added"
 * "The smallest number is <val>"
 * "The largest number is <val>"
 * "Goodbye"
 *
 * This program though only accept valid choices from teh user, both upper and lower-case selection should be allowed.
 * if an illegal choice is made, you should display, "Unknown selection , please try again." and menu options should be
 * displayed again.
 *
 * Additional feature:
 * - Search for a number in the list, if found display the number of times it occurs.
 * - clearing out makes an empty list
 * - Dont allow duplicate entries
 * - add your own ideas
 */
void s9c_run(void)
{
    std::vector<int> mylist{};
    bool loop_val = true;
    std::string choice;
    while(loop_val) {
        std::cout << std::endl
                  << "P - Print numbers" << std::endl
                  << "A - Add numbers" << std::endl
                  << "M - Display mean of the numbers" << std::endl
                  << "S - Display the smallest number" << std::endl
                  << "L - Display the largest number" << std::endl
                  << "Q - Quit" << std::endl
                  << std::endl
                  << "Enter your choice: ";
        std::cin >> choice;
        std::cout << std::endl;

        boost::algorithm::erase_all(choice, " ");
        
        switch((char)choice.at(0)) {

        case 'P':
        case 'p':
            std::cout << "[] - the list is empty" << std::endl;
            break;
        case 'A':
        case 'a':
            std::cout << "<val> added" << std::endl;
            std::cout << "invalid value, please try again." << std::endl;
            break;
        case 'M':
        case 'm':
            std::cout << "The mean is <val>" << std::endl;
            std::cout << "Unable to calculate the mean - no data" << std::endl;
            break;
        case 'S':
        case 's':
            std::cout << "The smallest number is <val>" << std::endl;
            std::cout << "Unable to determint the smallest number - list is empty" << std::endl;
            break;
        case 'L':
        case 'l':
            std::cout << "The largest number is <val>" << std::endl;
            std::cout << "Unable to determint the smallest number - list is empty" << std::endl;
            break;
        case 'Q':
        case 'q':
            std::cout << "Goodbye" << std::endl;
            loop_val = false;
            break;
        default:
            std::cout << "Unknown selection , please try again." << std::endl;
            break;
        }
    }
}
} // namespace udemy1
