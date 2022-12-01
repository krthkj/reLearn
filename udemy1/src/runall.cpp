/*
 * Copyright © 2022 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File  : runall.cpp
 * Desc  : run all the functions
 *
 * Author : Karthik Jain
 * Date : 2022-11-30
 *
 */

#include "udemy1.hpp"
#include <iostream>

namespace udemy1
{

void test_run_udemy1(void)
{

    /**
     * @brief Running Section challenges
     */
    s4c_run();
    s6c_run();
    s7c_run();
    s8c_run();
    s9c_run();
    s10c_run();

    /**
     * @brief Running Section exercises
     */
    e10_run();
    e11_run();

    /**
     * @brief Running Section Assignments
     */
    assignment_pyramid();

    /**
     * @brief running test codes
     */
    testing_ground();
}

} // namespace udemy1
