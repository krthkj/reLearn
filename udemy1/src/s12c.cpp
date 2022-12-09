/**
 * Copyright © 2022 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : s11c.cpp
 * Desc : Section 11: Pointers and references
 *        Challenge from Udemy course "Beginning C++ Programming - From Beginner to Beyond"
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2022-12-08
 *
 */

#include "udemy1.hpp"
#include <iostream>

namespace udemy1
{

/**
 * Write a C++ function named apply_all that expects two arrays of integers and their sizes and
 * dynamically allocates a new array of integers whose size is the product of the 2 array sizes
 *
 * The function should loop through the second array and multiplies each element across each element of array 1 and
 * store the product in the newly created array.
 *
 * The function should return a pointer to the newly allocated array.
 * You can also write a print function that expects a pointer to an array of integers and its size and display the
 * elements in the array.
 *
 * For example,
 *
 * Below is the output from the following code which would be in main:
 *
 * int array1[] {1,2,3,4,5};
 * int array2[] {10,20,30};
 *
 * cout << "Array 1: " ;
 * print(array1,5);
 *
 * cout << "Array 2: " ;
 * print(array2,3);
 *
 * int *results = apply_all(array1, 5, array2, 3);
 * cout << "Result: " ;
 * print(results,15);
 *
 * Output
 * ---------------------
 * Array 1: [ 1 2 3 4 5 ]
 * Array 2: [ 10 20 30 ]
 * Result: [ 10 20 30 40 50 20 40 60 80 100 30 60 90 120 150 ]
 *
 */

int* apply_all(const int* const, const size_t, const int* const, const size_t);
void print(const int* const, const size_t);

void s12c_run(void)
{
    const size_t array1_size{5};
    const size_t array2_size{3};

    int array1[]{1, 2, 3, 4, 5};
    int array2[]{10, 20, 30};

    std::cout << "Array 1: ";
    print(array1, array1_size);

    std::cout << "Array 2: ";
    print(array2, array2_size);

    int* results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size{array1_size * array2_size};

    std::cout << "Result: ";
    print(results, results_size);

    std::cout << std::endl;
    if(results != nullptr)
        delete results;
}

int* apply_all(const int* const a1, const size_t s1, const int* const a2, const size_t s2)
{
    int* res{nullptr};
    res = new int[s1 * s2];

    if(res != nullptr)
        for(size_t i{0}; i < s1; ++i)
            for(size_t j{0}; j < s2; ++j)
                res[(j * s1 + i)] = a2[j] * a1[i];
    return res;
}

void print(const int* const a, const size_t s)
{
    std::cout << "[ ";
    for(size_t i{0}; i < s; ++i)
        std::cout << a[i] << " ";
    std::cout << "]" << std::endl;
}

} // namespace udemy1
