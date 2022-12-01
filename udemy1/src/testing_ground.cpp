/**
 * Copyright © 2022 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : testing_ground.cpp
 * Desc : Section 7 Challenge from Udemy course "Beginning C++ Programming - From Beginner to Beyond"
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
 * @brief Examples of variables initializing with braces and benefits of using {} for initialization.
 * using {} to initialize helps reduce possible runtime errors.
 */
void assignment_test(void)
{
    float val = 7.9;
    int val2 = 15;

    int x2 = val; // if val==7.9, x2 becomes 7 (bad)
    std::cout << val << std::endl;
    std::cout << x2 << std::endl;

    char c2 = val2; // if val2==1025, c2 becomes 1 (bad)
    std::cout << val2 << std::endl;
    std::cout << c2 << std::endl;

/*
    // uncomment to see the compiler warning/error
    int x3{val}; // error: possible truncation (good)
    std::cout << val << std::endl;
    std::cout << x3 << std::endl;
*/

/*
    // uncomment to see the compiler warning/error
    char c3{val2}; // error: possible narrowing (good)
    std::cout << val2 << std::endl;
    std::cout << c3 << std::endl;
*/

    char c4{24}; // OK: 24 can be represented exactly as a char (good)
    std::cout << c4 << std::endl;

/*
    // uncomment to see the compiler warning/error
    char c5{264}; // error (assuming 8-bit chars): 264 cannot be
                  // represented as a char (good)
    std::cout << c6 << std::endl;
*/
}

/**
 * @brief Testing area for code
 */
void testing_ground(void)
{
}

} // namespace udemy1
