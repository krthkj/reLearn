/**
 * Copyright © 2022 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : s7c.cpp
 * Desc : Section 7 Challenge from Udemy course "Beginning C++ Programming - From Beginner to Beyond"
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2022-11-30
 *
 */

#include "udemy1.hpp"

#include <iostream>
#include <vector>

namespace udemy1
{
/**
 * @brief  Section 7 Challenge: Working with vector
 * Declare 2 empty vectors of integers named vector1 and vector2, respectively.
 *
 * Add 10 and 20 to vector1 dynamically using the push_back
 * Display elements in vector1 using the at() method as well as the size using the size() method
 *
 * Add 100 and 200 to vector2 dynamically using the push_back
 * Display elements in vector2 using the at() method as well as the size using the size() method
 *
 * Declare an empty 2D vector called vector_2d.
 * Remember, the a 2D vector is a vector of vector<int>
 *
 * Add vector1 to vector_2d dynamically using push_back
 * Add vector2 to vector_2d dynamically using push_back
 *
 * Display the elements in vector_2d using the at() method
 *
 * Change vector1.at(0) to 1000.
 *
 * Display the elements in vector_2d again using the at() method
 *
 * Display the elements in vector1
 *
 * What did you expect?
 * Did you get what you expected?
 * What do your think happened?
 *
 */
void s7c_run(void)
{
    /**
     * @brief Declare 2 empty vectors of integers named vector1 and vector2.
     */
    std::vector<int> vector1{}, vector2{};

    /**
     * @brief Add 10 and 20 to vector1 dynamically using the push_back
     */
    vector1.push_back(10);
    vector1.push_back(20);

    /**
     * @brief Display elements in vector1 using the at() method as well as the size using the size() method
     */
    std::cout << "vector1: " << std::endl;
    std::cout << vector1.at(0) << std::endl;
    std::cout << vector1.at(1) << std::endl;
    std::cout << "vector1 contains " << vector1.size() << " elements " << std::endl << std::endl;

    /**
     * @brief Add 100 and 200 to vector2 dynamically using the push_back
     */
    vector2.push_back(100);
    vector2.push_back(200);

    /**
     * @brief Display elements in vector2 using the at() method as well as the size using the size() method
     */
    std::cout << "vector2: " << std::endl;
    std::cout << vector2.at(0) << std::endl;
    std::cout << vector2.at(1) << std::endl;
    std::cout << "vector2 contains " << vector2.size() << " elements " << std::endl << std::endl;

    /**
     * @brief Declare an empty 2D vector called vector_2d.
     * Remember, the a 2D vector is a vector of vector<int>
     */
    std::vector<std::vector<int>> vector_2d;

    /**
     * @brief Add vector1 to vector_2d dynamically using push_back,
     * Add vector2 to vector_2d dynamically using push_back
     */
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);

    /**
     * @brief Display elements in vector2 using the at() method as well as the size using the size() method
     */
    std::cout << "vector_2d: " << std::endl
              << vector_2d.at(0).at(0) << ", " << vector_2d.at(0).at(1) << std::endl
              << vector_2d.at(1).at(1) << ", " << vector_2d.at(1).at(1) << std::endl;
    std::cout << "vector_2d contains " << vector_2d.size() << " elements " << std::endl << std::endl;

    /**
     * @brief Change vector1.at(0) to 1000.
     */
    vector1.at(0) = 1000;
    std::cout << "vector1.at(0) = 1000" << std::endl << std::endl;

    /**
     * @brief Display the elements in vector_2d again using the at() method
     */
    std::cout << "vector_2d: " << std::endl
              << vector_2d.at(0).at(0) << ", " << vector_2d.at(0).at(1) << std::endl
              << vector_2d.at(1).at(1) << ", " << vector_2d.at(1).at(1) << std::endl
              << std::endl;

    /**
     * @brief Display the elements in vector1
     */
    std::cout << "vector1: " << std::endl;
    std::cout << vector1.at(0) << std::endl;
    std::cout << vector1.at(1) << std::endl;

    /**
     * @brief  What did you expect? Did you get what you expected? What do your think happened?
     */
}
} // namespace udemy1
