/*
 * Copyright © 2022 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : s4c.cpp
 * Desc : Section 4 Challenge from Udemy course "Beginning C++ Programming - From Beginner to Beyond"
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2022-11-30
 */

/*
 * Section 4 Challenge
 * Create a c++ program that asks the user for their favourite
 * number between 1 and 100 then read this number from console
 *
 * Suppose the user enters 24
 * Then display the following on the console:
 *
 * Amazing!! That's my favourite number too!
 * no really!!, 24 is my favourite number!
 */

#include "udemy1.hpp"
#include <iostream>

namespace udemy1
{

void s4c_run(void)
{
    int fav_num;
    do {
        std::cout << "Enter your favourite number between 1 and 100: ";

        std::cin >> fav_num;
    } while(fav_num > 100 || fav_num < 1);
    std::cout << "Amazing!! That's my favourite number too!" << std::endl;
    std::cout << "no really!!, " << fav_num << " is my favourite number!" << std::endl;
}

} // namespace udemy1
