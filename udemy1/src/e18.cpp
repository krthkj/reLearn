/**
 * Copyright © 2023 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : e18.cpp
 * Desc : Section 18: Exception handling
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2023-01-06
 *
 */

/*******************************************************************************
 * Basic Concepts
 *
 * C++ Syntax:
 *    throw
 *      - throws exception
 *      - followed by an argument
 *
 *    try {}
 *      -
 *
 *    catch (Exception ex) { }
 *      - code that handled the exception
 *
 *******************************************************************************
 * Class-level exceptions:
 * Methods:
 *  - These woek same way as they do for functions
 * Constructor:
 *  - Constructors may fail
 *  - constructors do nore return any value
 *  - throw an exception in the Constructor if you cannt initiazlie object
 * Destructor:
 *  - Do NOT throw exceptions from destructors
 *
 *******************************************************************************
 */

#include "e18_class.hpp"
#include "udemy1.hpp"

#include <iostream>
#include <memory>

namespace udemy1::e18::ex1
{

/**
 * @brief Example of using if-else
 */
void run_div_by_zero(void)
{
    int miles{};
    int gallons{};
    double miles_per_gallon{};

    std::cout << "Enter in miles: ";
    std::cin >> miles;
    std::cout << "Enter in gallons: ";
    std::cin >> gallons;

    if (gallons != 0) {
        miles_per_gallon = static_cast<double>(miles) / gallons; // double division
        std::cout << "Result: " << miles_per_gallon << std::endl;
    } else
        std::cerr << "Sorry, cant divide by zero" << std::endl;
    std::cout << "Bye" << std::endl;
}

/*********************************************************************************/

/**
 * @brief Example of Exception handling
 */
void run_div_by_zero_exception(void)
{
    int miles{};
    int gallons{};
    double miles_per_gallon{};

    std::cout << "Enter in miles: ";
    std::cin >> miles;
    std::cout << "Enter in gallons: ";
    std::cin >> gallons;

    try {
        if (gallons == 0)
            throw 0;
        miles_per_gallon = static_cast<double>(miles) / gallons; // double division
        std::cout << "Result: " << miles_per_gallon << std::endl;
    } catch (int& ex) {
        std::cerr << "Sorry, cant divide by zero" << std::endl;
    }
    std::cout << "Bye" << std::endl;
}
} // namespace udemy1::e18::ex1

namespace udemy1::e18::ex3
{

/**
 * @brief Example of functions throwing exception
 */
double calc_mpg(int mile, int gallon)
{
    if (gallon == 0)
        throw 0;
    return static_cast<double>(mile) / gallon;
}

/**
 * @brief Example of Exception handling from a functions
 */
void run_func_except(void)
{
    int miles{};
    int gallons{};
    double miles_per_gallon{};

    std::cout << "Enter in miles: ";
    std::cin >> miles;
    std::cout << "Enter in gallons: ";
    std::cin >> gallons;

    try {
        miles_per_gallon = calc_mpg(miles, gallons);
        std::cout << "Result: " << miles_per_gallon << std::endl;
    } catch (int& ex) {
        std::cerr << "Sorry, cant divide by zero" << std::endl;
    }

    std::cout << "Bye" << std::endl;
}
} // namespace udemy1::e18::ex3

namespace udemy1::e18::ex4
{
/**
 * @brief Example of functions throwing multiple exception
 */
double calc_mpg(int mile, int gallon)
{
    if (gallon == 0)
        throw 0;
    if (mile < 0 || gallon < 0)
        throw std::string{"Negative value error"};
    return static_cast<double>(mile) / gallon;
}

/**
 * @brief Example of multiple Exception handling
 */
void run_multi_func_except(void)
{
    int miles{};
    int gallons{};
    double miles_per_gallon{};

    std::cout << "Enter in miles: ";
    std::cin >> miles;
    std::cout << "Enter in gallons: ";
    std::cin >> gallons;

    try {
        miles_per_gallon = calc_mpg(miles, gallons);
        std::cout << "Result: " << miles_per_gallon << std::endl;
    } catch (int& ex) { // catch int handler
        std::cerr << "Sorry, cant divide by zero" << std::endl;
    } catch (std::string& ex) { // catch string handler
        std::cerr << ex << std::endl;
    } catch (...) { // catch all handler
        std::cerr << " Unknown exception" << std::endl;
    }

    std::cout << "Bye" << std::endl;
}

} // namespace udemy1::e18::ex4

/**
 * @brief Example of Stack unwinding
 */
namespace udemy1::e18::ex5
{

void func_c()
{
    std::cout << "staring func_c" << std::endl;
    throw 100;
    std::cout << "ending func_c" << std::endl;
}

void func_b()
{
    std::cout << "staring func_b" << std::endl;
    try {
        func_c();
    } catch (int& ex) {
        std::cout << "Caught error in func_b" << std::endl;
    }
    std::cout << "ending func_b" << std::endl;
}

void func_a()
{
    std::cout << "staring func_a" << std::endl;
    func_b();
    std::cout << "ending func_a" << std::endl;
}

void run_stack_unwinding(void)
{
    std::cout << "staring main" << std::endl;
    try {
        func_a();
    } catch (int& ex) {
        std::cout << "Caught error in main" << std::endl;
    }
    std::cout << "ending main" << std::endl;
}

} // namespace udemy1::e18::ex5

/**
 * @brief Example of use-defined exception
 */
namespace udemy1::e18::ex6
{

// Class used for exceptions
class DivideByZeroException
{
};

class NegativeValueException
{
};

double calc_mpg(int mile, int gallon)
{
    if (gallon == 0)
        throw DivideByZeroException();
    if (mile < 0 || gallon < 0)
        throw NegativeValueException();
    return static_cast<double>(mile) / gallon;
}

void run_user_exception(void)
{
    int miles{};
    int gallons{};
    double miles_per_gallon{};

    std::cout << "Enter in miles: ";
    std::cin >> miles;
    std::cout << "Enter in gallons: ";
    std::cin >> gallons;

    try {
        miles_per_gallon = calc_mpg(miles, gallons);
        std::cout << "Result: " << miles_per_gallon << std::endl;
    } catch (const DivideByZeroException& ex) {
        std::cerr << "Sorry, cant divide by zero" << std::endl;
    } catch (const NegativeValueException& ex) {
        std::cerr << "Negative values not allowed" << std::endl;
    }

    std::cout << "Bye" << std::endl;
}

} // namespace udemy1::e18::ex6

/**
 * @brief Example of class level exception
 */
namespace udemy1::e18::ex7
{
class IllegalBalanceException
{
  public:
    IllegalBalanceException()  = default;
    ~IllegalBalanceException() = default;
};

Account::Account(std::string name, double balance)
    : name{name}
    , balance{balance}
{
    if (balance < 0.0)
        throw IllegalBalanceException();
}

void run_class_level_except(void)
{
    try {
        std::unique_ptr<Account> moes_account = std::make_unique<Checking_Account>("Moe", -10.0);
        std::cout << *moes_account << std::endl;
    } catch (const IllegalBalanceException& ex) {
        std::cerr << "Couldnt create account - negative balance" << std::endl;
    }
    std::cerr << "Program completed successfully" << std::endl;
}
} // namespace udemy1::e18::ex7

/**
 * @brief Example of class level exception using exception hierarchy
 */
namespace udemy1::e18::ex8
{

class IllegalBalanceException : public std::exception
{
  public:
    IllegalBalanceException() noexcept = default;
    ~IllegalBalanceException()         = default;

    virtual const char* what() const noexcept
    {
        return "Illegal Balance Exception";
    }
};

Account::Account(std::string name, double balance)
    : name{name}
    , balance{balance}
{
    if (balance < 0.0)
        throw IllegalBalanceException();
}

void run_class_except_hierarchy(void)
{
    try {
        std::unique_ptr<Account> moes_account = std::make_unique<Checking_Account>("Moe", -100.0);
        std::cout << *moes_account << std::endl;
    } catch (const IllegalBalanceException& ex) {
        std::cerr << ex.what() << std::endl;
    }
    std::cerr << "Program completed successfully" << std::endl;
}

} // namespace udemy1::e18::ex8

void udemy1::e18_run(void)
{
    // e18::ex1::run_div_by_zero();
    // e18::ex1::run_div_by_zero_exception();
    // e18::ex3::run_func_except();
    // e18::ex4::run_multi_func_except();
    // e18::ex5::run_stack_unwinding();
    // e18::ex6::run_user_exception();
    // e18::ex7::run_class_level_except();
    e18::ex8::run_class_except_hierarchy();
}
