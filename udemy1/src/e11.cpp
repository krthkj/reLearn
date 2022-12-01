/**
 * Copyright © 2022 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : e11.cpp
 * Desc : Section 11 Challenge from Udemy course "Beginning C++ Programming - From Beginner to Beyond"
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2022-12-01
 *
 */

#include "udemy1.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

namespace udemy1
{

/**
 * @brief Random numbers Example
 */
void random_nums(void)
{

    int random_number{};
    size_t count{10}; // number of random numbers to generate
    int min{1};       // lower bound (inclusive)
    int max{6};       // upper bound (inclusive)

    // seed the random number generator
    // If you don't seed the generator you will get the same requence random numbers every run

    std::cout << "RAND_MAX on my system is: " << RAND_MAX << std::endl;

    // use current time as seed for random generator
    // std::time needs <ctime>
    // std::srand needs <cstdlib>
    std::srand(std::time(nullptr));

    for(size_t i{1}; i <= count; ++i) {
        random_number = std::rand() % max + min; // generate a random number [min, max]
        std::cout << random_number << std::endl;
    }

    std::cout << std::endl;
}

/**
 * @brief aggregate of all the functions in the section
 */
void e11_run(void)
{
    //    random_nums();
}

} // namespace udemy1
