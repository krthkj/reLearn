/**
 * Copyright © 2022 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : e17.cpp
 * Desc : Section 17: Smart pointer
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2022-12-29
 *
 */

/*******************************************************************************
 * RAII: Resource Acquisition Is Initialization
 * --------------------------------------------
 * - Common Idion or pattern used in software design based on container object lifetime
 * - RAII object are allocated on the stack
 * - Resource ALlocation: 1. Open a file
 *                        2. Allocate memory
 *                        3. Acquire a lock
 * - is initialized: the resource is acquired in a constructor
 * - Resource relinquishing:
 *   Happend in the destructor: 1. Close the file
 *                              2. dellocate the memory
 *                              3. release the lock
 *
 *******************************************************************************
 * Smart Pointer
 * ==============
 *
 * Issues with RAW pointers
 * - C++ provides absolute flexibility with memory management
 *   - Allocation
 *   - Deallocation
 *   - Lifetime management
 * - Some potential serious problems
 *   - Uninitialized (wild) Pointers
 *   - Memory Leaks
 *   - Dandling pointers
 *   - Not exception safe
 * - Ownership?
 *   - WHo owns the pointer?
 *   - when should a pointer be deleted?
 *
 *******************************************************************************
 * Whar are smart pointers?
 * - Objects
 * - can only point to heap-allocated memory
 * - automatically call delete when no longer needed
 * - Adhere to RAII principles
 * - C++ Smart pointers
 *   --> Unique pointers (unique_ptr)
 *   --> Shared pointers (shared_ptr)
 *   --> Weak pointers (weak_ptr)
 *   --> Auto pointers (auto_ptr) DEPRECATED as of C++11
 *
 * What are they?
 * - #include <memory>
 * - Defined by class template
 *   - wrapper around a raw pointer
 *   - Overloaded operators
 *      - Dereference (*)
 *      - Member selection (->)
 *      - Pointer arithmetic not supported (++,-- etc.)
 *   - can have custom deleters
 *
 * Example:
 *   {
 *     std::smart_pointer<Some_Class> ptr= ......
 *     ptr->method();
 *     cout << (*ptr) << endl;
 *   }
 * // Pointer will be destroyed automatically when no longer needed
 *******************************************************************************
 * Unique pointers:
 * - simple smart pointer - very effecient
 * - uniqe_ptr<T>
 *    - Points to an object of the type T on the heap
 *    - it is unique - there can only be one unique_ptr<T> pointing to the heap
 *    - owns what it points to
 *    - CANNOT be assigned or copied
 *    - CAN be moved
 *    - when the pointer is destroyed, what it points is automatically destroyed
 *
 * make_unique - introduced in C++14
 *******************************************************************************
 * Shared pointers:
 * - Provides shared ownership of heap objects
 * - shared_ptr<T>
 *    - Points to an object of the type T on the heap
 *    - it is not unique - there can many shared_ptr<T> pointing to the same object on the heap
 *    - Established shared ownership relatopship
 *    - CAN be assigned or copied
 *    - CAN be moved
 *    - desn't support managing array by default
 *    - When the use count is zero, the managed object on the heap is deatroyed
 * make_unique - introduced in C++11
 *******************************************************************************
 */

#include "e16_classes.hpp"
#include "e17_class.hpp"
#include "udemy1.hpp"

#include <iostream>
#include <memory>

/**
 * @brief Example of Smart pointer
 */
namespace udemy1::e17::ex1
{
void run_unique_ptr_test(void)
{
    {
        std::cout << "### local variable on stack" << std::endl;
        Test t1{1000};
    }
    {
        std::cout << "### pointer variable on Heap" << std::endl;
        Test* t2 = new Test{1000};
        delete t2;
    }
    {
        std::cout << "### smart pointer variable on Heap using new" << std::endl;
        std::unique_ptr<Test> t3{new Test{100}};
    }
    {
        std::cout << "### smart pointer variable on Heap using make_ptr" << std::endl;
        std::unique_ptr<Test> t1 = std::make_unique<Test>(1000);
        auto t2 = std::make_unique<Test>(2000);

        std::unique_ptr<Test> t3;
        if(!t1)
            std::cout << "T1 is nullptr" << std::endl;
        if(!t3)
            std::cout << "T3 is nullptr" << std::endl;

        std::cout << "### Performing move on smart pointer" << std::endl;
        // t3 = t1; // ERROR - Copy/Assigment Not defined
        t3 = std::move(t1);
        if(!t1)
            std::cout << "T1 is nullptr" << std::endl;
        if(!t3)
            std::cout << "T3 is nullptr" << std::endl;
    }
}
} // namespace udemy1::e17::ex1

namespace udemy1::e17::ex2
{
void run_unique_ptr_account(void)
{
    std::unique_ptr<Account> a1 = std::make_unique<Checking_Account>("Moe", 5000);
    std::cout << *a1 << std::endl;
    a1->deposit(5000);
    std::cout << *a1 << std::endl;

    std::vector<std::unique_ptr<Account>> accounts;
    accounts.push_back(std::make_unique<Checking_Account>("James", 1000));
    accounts.push_back(std::make_unique<Savings_Account>("Billy", 4000, 5.2));
    accounts.push_back(std::make_unique<Trust_Account>("Boby", 5000, 4.5));

    // for(auto acc : accounts) // ERROR: call to deleted constructor of 'std::unique_ptr<>'
    for(const auto& acc : accounts)
        std::cout << *acc << std::endl;
}

} // namespace udemy1::e17::ex2

namespace udemy1::e17::ex3
{
void run_shared_ptr(void)
{
}
} // namespace udemy1::e17::ex3

/**
 * @brief main function to run all the underlying examples
 */
void udemy1::e17_run(void)
{
    // e17::ex1::run_unique_ptr_test();
    // e17::ex2::run_unique_ptr_account();
    e17::ex3::run_shared_ptr();
}
