/*
 * Copyright © 2022 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the projeat.
 *
 * File  : main file
 * Author: Karthik Jain
 * Date  : 2022-Nov-28
 */

#include "relearn_dl.hpp"
#include "relearn_sl.hpp"
#include "udemy1.hpp"

#include <iostream>

/**
 * @brief Main function call to generate the target executable.
 */
int main()
{
    std::cout << "[relearn] <func> relearn::main" << std::endl;
    relearn_dl::printlib();
    relearn_sl::printlib();
    udemy1::printlib();
    // udemy1::test_run_udemy1();
    return 0;
}
