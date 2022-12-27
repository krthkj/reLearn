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
#include <numeric> // std::iota
#include <vector>

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

/*************************************************************************************/

void test_pass_value(int a)
{
    std::cout << "-------------------------" << std::endl << "pass by value" << std::endl;
    std::cout << "[param_addr] &a: " << &a << std::endl;
    a += 2;
    std::cout << "[param_val]   a: " << a << std::endl;
}

void test_pass_ptr(int* a)
{
    if(a == nullptr) {
        std::cout << "nullptr param success" << std::endl;
        return;
    }
    std::cout << "-------------------------" << std::endl << "pass by pointer" << std::endl;
    std::cout << "[param_addr] a        : " << a << std::endl;
    *a += 5;
    std::cout << "[param_val] *a        : " << *a << std::endl;

    a = new int{1000};
    std::cout << "[param_addr_mod] new a: " << a << std::endl;
    std::cout << "[param_val_mod] new *a: " << *a << std::endl;
}

void test_pass_ptr_const(const int* a)
{
    if(a == nullptr) {
        std::cout << "nullptr param success" << std::endl;
        return;
    }
    std::cout << "-------------------------" << std::endl << "pass by pointer to const" << std::endl;
    std::cout << "[param_addr] a        : " << a << std::endl;
    // *a += 10; // readonly
    std::cout << "[param_val] *a        : " << *a << std::endl;

    a = new int{1000};
    std::cout << "[param_addr_mod] new a: " << a << std::endl;
    std::cout << "[param_val_mod] new *a: " << *a << std::endl;
}

void test_pass_const_ptr(int* const a)
{
    if(a == nullptr) {
        std::cout << "nullptr param success" << std::endl;
        return;
    }
    std::cout << "-------------------------" << std::endl << "pass by const pointer" << std::endl;
    std::cout << "[param_addr] a        : " << a << std::endl;
    *a += 10;
    std::cout << "[param_val] *a        : " << *a << std::endl;

    // a = new int{1000}; //readonly
    std::cout << "[param_addr_mod] new a: " << a << std::endl;
    std::cout << "[param_val_mod] new *a: " << *a << std::endl;
}

void test_pass_const_ptr_const(const int* const a)
{
    if(a == nullptr) {
        std::cout << "nullptr param success" << std::endl;
        return;
    }
    std::cout << "-------------------------" << std::endl << "pass by const pointer to const" << std::endl;
    std::cout << "[param_addr] a        : " << a << std::endl;
    // *a += 10; // readonly
    std::cout << "[param_val] *a        : " << *a << std::endl;

    // a = new int{1000}; // readonly
    std::cout << "[param_addr_mod] new a: " << a << std::endl;
    std::cout << "[param_val_mod] new *a: " << *a << std::endl;
}

void test_pass_ref(int& a)
{
    std::cout << "-------------------------" << std::endl << "pass by reference" << std::endl;
    std::cout << "[param_addr] &a        : " << &a << std::endl;
    a += 10;
    std::cout << "[param_val] a          : " << a << std::endl;
}

void test_pass_const_ref(const int& a)
{
    std::cout << "-------------------------" << std::endl << "pass by const reference" << std::endl;
    std::cout << "[param_addr] &a        : " << &a << std::endl;
    // a += 10; // readonly
    std::cout << "[param_val] a          : " << a << std::endl;
}

void run_pass_by_expt(void)
{

    int test_val{100};
    std::cout << "&test_val: " << &test_val << std::endl;
    std::cout << "test_val : " << test_val << std::endl;
    std::cout << std::endl;

    int* test_ptr{nullptr};
    test_ptr = &test_val;
    std::cout << "test_ptr : " << test_ptr << std::endl;
    std::cout << "*test_ptr: " << *test_ptr << std::endl;
    std::cout << std::endl;

    test_ptr = &test_val;
    test_pass_value(test_val);
    std::cout << "&test_val: " << &test_val << std::endl;
    std::cout << "test_val : " << test_val << std::endl;
    std::cout << std::endl;

    test_ptr = &test_val;
    test_pass_ptr(test_ptr);
    std::cout << "test_ptr : " << test_ptr << std::endl;
    std::cout << "*test_ptr: " << *test_ptr << std::endl;
    test_pass_ptr(nullptr);
    std::cout << std::endl;

    test_ptr = &test_val;
    test_pass_ptr_const(test_ptr);
    std::cout << "test_ptr : " << test_ptr << std::endl;
    std::cout << "*test_ptr: " << *test_ptr << std::endl;
    test_pass_ptr_const(nullptr);
    std::cout << std::endl;

    test_ptr = &test_val;
    test_pass_const_ptr(test_ptr);
    std::cout << "test_ptr : " << test_ptr << std::endl;
    std::cout << "*test_ptr: " << *test_ptr << std::endl;
    test_pass_const_ptr(nullptr);
    std::cout << std::endl;

    test_ptr = &test_val;
    test_pass_const_ptr_const(test_ptr);
    std::cout << "test_ptr : " << test_ptr << std::endl;
    std::cout << "*test_ptr: " << *test_ptr << std::endl;
    test_pass_const_ptr_const(nullptr);
    std::cout << std::endl;

    int& test_ref = test_val;
    std::cout << "&test_val: " << &test_val << std::endl;
    std::cout << "&test_ref: " << &test_ref << std::endl;
    std::cout << "test_ref : " << test_ref << std::endl;

    test_pass_ref(test_ref);
    std::cout << "&test_ref: " << &test_ref << std::endl;
    std::cout << "test_ref : " << test_ref << std::endl;
    std::cout << std::endl;

    test_pass_const_ref(test_ref);
    std::cout << "&test_ref: " << &test_ref << std::endl;
    std::cout << "test_ref : " << test_ref << std::endl;
    std::cout << std::endl;

    //  test_ptr =nullptr;
    int& tr1 = *test_ptr;
    std::cout << "&test_ptr: " << &test_ptr << std::endl;
    tr1 = test_val * test_val; // readonly
    std::cout << "&tr1     : " << &tr1 << std::endl;
    std::cout << "tr1      : " << tr1 << std::endl;

    const int& tr2 = test_val;
    std::cout << "&test_ptr: " << &test_val << std::endl;
    // tr2 = test_val*test_val; // readonly
    std::cout << "&tr2     : " << &tr2 << std::endl;
    std::cout << "tr2      : " << tr2 << std::endl;
}

/*************************************************************************************/

void vector_play(void)
{
    std::vector<int> a;
    std::vector<float> b;
    std::cout << "size of a : " << sizeof(a) << std::endl;
    std::cout << "size of b : " << sizeof(b) << std::endl;
    for(int i{0}; i < 10; ++i)
        a.push_back(i + 1);

    std::cout << "size of a : " << sizeof(a) << std::endl;
    for(int i{0}; i < 10; ++i)
        std::cout << a.at(i) << ", ";
    std::cout << std::endl;
}

/*************************************************************************************/

const char* string_literal_lifetimes(void)
{
    return "string_literals";
}

void test_iota(void)
{
    int num[10]{};
    int st{100};
    const char* strr;
    strr = string_literal_lifetimes();
    std::cout << "Elemelnts are : ";
    std::iota(num, num + 10, st);
    for(auto i : num)
        std::cout << " " << i;
    std::cout << std::endl;
    std::cout << strr << std::endl;
}

void const_pointer_vs_pointer_to_const(void)
{
    using std::cout, std::endl;
    int x{100}, y{20};

    const int* ptr1 = &x; // pointer to const
    int const* ptr2 = &x; // pointer to const
    int* const ptr3 = &x; // cosntant pointer

    cout << *ptr1 << " " << *ptr2 << " " << *ptr3 << endl;

    //++(*ptr1);
    ptr1 = &y;
    // *ptr1 = 12;
    cout << *ptr1 << " " << *ptr2 << " " << *ptr3 << endl;

    //++(*ptr2);
    ptr2 = &y;
    //*ptr2 = 17;
    cout << *ptr1 << " " << *ptr2 << " " << *ptr3 << endl;

    ++(*ptr3);
    //ptr3 = &y;
    *ptr3 = *ptr2 + 12;

    cout << *ptr1 << " " << *ptr2 << " " << *ptr3 << endl;
}

/*************************************************************************************/

/**
 * @brief Testing area for code
 */
void testing_ground(void)
{
    // assignment_test();
    // run_pass_by_expt();
    // vector_play();
    // test_iota();
    const_pointer_vs_pointer_to_const();
}

} // namespace udemy1
