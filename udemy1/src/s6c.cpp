/*
 * Copyright © 2022 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : s6c.cpp
 * Desc : Section 6 Challenge from Udemy course "Beginning C++ Programming - From Beginner to Beyond"
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2022-11-30
 */

/*
 * Section 6 Challenge
 * Franks carpet cleaning service
 * Charges:
 * $25 per small room
 * $35 per large room
 * Sales tax rate is 6%
 * Estimates are valid for 30 days
 *
 * Prompt the user for the number of small and large rooms they would like cleaned and provide an estimate such as:
 *
 * Estimate for carpet cleaning service
 * Number of small rooms: 3
 * Number of large rooms: 1
 * Price per small room: $25
 * Price per large room: $35
 * Cost: $110
 * Tax: $6.6
 * ====================================
 * Total estimate: $116.6
 * This estimate is valid for 30 days
 */

#include "udemy1.hpp"

#include <iostream>

namespace udemy1
{
void s6c_run(void)
{

    int room_s{0}, room_l{0};
    bool loop_val{false};

    std::cout << "Hello, welcome to Frank's Carpet Cleaning Service" << std::endl;
    do {
        std::cout << "How many small rooms would you like cleaned? ";
        std::cin >> room_s;
        if (room_s < 0)
            loop_val = true;
        else
            loop_val = false;
    } while (loop_val);

    do {
        std::cout << "How many large rooms would you like cleaned? ";
        std::cin >> room_l;
        if (room_l < 0)
            loop_val = true;
        else
            loop_val = false;
    } while (loop_val);

    float price_s{25}, price_l{35}, tax{6};
    int valid_days{30};

    std::cout << std::endl;
    std::cout << "Estimate for carpet cleaning service" << std::endl;
    std::cout << "Number of small rooms: " << room_s << std::endl;
    std::cout << "Number of large rooms: " << room_l << std::endl;
    std::cout << "Price per small room: $" << price_s << std::endl;
    std::cout << "Price per large room: $" << price_l << std::endl;
    std::cout << "Cost: $" << ((room_s * price_s) + (room_l * price_l)) << std::endl;
    std::cout << "Tax: $" << tax * ((room_s * price_s) + (room_l * price_l)) / 100 << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "Total estimate: $" << (1 + (tax / 100)) * (room_s * price_s + room_l * price_l) << std::endl;
    std::cout << "This estimate is valid for " << valid_days << " days" << std::endl;
}
} // namespace udemy1
