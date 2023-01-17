/**
 * Copyright © 2022 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : s12_test_debugger.cpp
 * Desc : Section 12: working with_debugger
 *        Challenge from Udemy course "Beginning C++ Programming - From Beginner to Beyond"
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2022-12-09
 *
 */

#include "udemy1.hpp"

#include <iostream>

namespace udemy1
{
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void s12_test_debugger(void)
{

    int i{5};
    while (i > 0) {
        std::cout << i << std::endl;
        i--;
    }

    int x{100}, y{200};
    std::cout << "\nx: " << x << std::endl;
    std::cout << "y: " << y << std::endl;

    swap(&x, &y);

    std::cout << "\nx: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << std::endl;
}
} // namespace udemy1
