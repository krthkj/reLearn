/**
 * Copyright © 2022 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : e15.cpp
 * Desc : Section 15: Inheritance
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2022-12-27
 *
 */

/*******************************************************************************
 * Inheritance
 * ==========
 * - provides a method for creating new classes from existing class
 * - the new class contain the data and behaviours of existing class
 * - allow for reuse of existing class
 * - allow focus on the common attributes among common classes
 * - allow new calls to modify behaviour of existing classes to make unique(without modifying the original class)
 *
 *******************************************************************************
 * Terms
 * -----
 * Inheritance: reuse mechanism
 * - Single inheritance (created from another single class)
 * - Multiple inheritance (created from two or more other classes)
 *
 * Base class: Parent class or super class (class being extended or inherited from)
 * Derived class: child class or sub class (will inherit attributes and operations from base class)
 *
 * "Is-A" relationship:
 * - public inheritance
 * - Derived class are sub-typed of their base class
 * - can use a derived class object whenever we use a base class object
 *
 * Generalization
 * - combining similar class into a single, more general class based of common attributes
 *
 * Specialization
 * - creating new classes from existing classes proving more specialized attributes or operations
 *
 * Inheritance or class hierarchies
 *
 *******************************************************************************
 * +================================+============================+
 * | public inheritance             |     Composition            |
 * +================================+============================+
 * | reuse existing class           | reuse existing class       |
 * +--------------------------------+----------------------------+
 * | "is-a" relationship            | "has-a" relationship       |
 * +--------------------------------+----------------------------+
 * |Ex:                             |Ex:                         |
 * |- Employee is-a person          |Person has-a account        |
 * |- Circle is-a shape             |Circle has-a location       |
 * |- Checking account is-a account |Player has-a special attach |
 * +================================+============================+
 *
 * some topics to research: Aggregation, Association Composition
 *******************************************************************************
 * Syntax:
 *   class Base{
 *     // base class members . . .
 *   };
 *
 *   class Derived : access-specifier Base {
 *     // base class members . . .
 *   };
 *
 * Access-specifier: public, private or protected
 *
 * Public:
 * - most common
 * - "is-a" relationship between derived and base class
 *
 * Private and protected
 * - derived class 'has-a' base class relationship
 * - "is implimented in terms of" relationship
 * - different from composition
 *
 *******************************************************************************
 * Protected Members and class access
 * - Accessible from base class itself
 * - accessible from classes derived from base class
 * - not accessible by objects of base or derived
 *
 *
 *
 *
 *
 *
 *
 * Example:
 *   class Base {
 *     public:
 *       int a; // public base class member
 *     protected:
 *       int b; // protected base class member
 *     private:
 *       int c; // private base class member
 *   };
 *
 *   class Derived_public : public Base {    // "is-a" inheritance
 *     // public : a
 *     // protected : b
 *     // c : no-access
 *   };
 *
 *   class Derived_protected : public Base { // not "is-a" inheritance
 *     // protected : a
 *     // protected : b
 *     // c : no-access
 *   };
 *
 *   class Derived_private : public Base {   // not "is-a" inheritance
 *     // private : a
 *     // private : b
 *     // c : no-access
 *   };
 *
 *******************************************************************************
 */

#include "accounts.hpp"
#include "basederived.hpp"
#include "udemy1.hpp"
#include <iostream>

/**
 * @brief Example of inheritance
 */

namespace udemy1::e15::ex1
{
void run_class_inhertance(void)
{
    using std::cout, std::endl;
    using udemy::e15::Account, udemy::e15::Savings_Account;

    // using account class
    cout << "=== Account ====================================" << endl;
    Account acc{};
    acc.deposit(2000.0);
    acc.withdraw(500.0);

    cout << endl;

    Account* p_acc{nullptr};
    p_acc = new Account();
    p_acc->deposit(1000.0);
    p_acc->withdraw(500.0);
    delete p_acc;

    cout << endl;

    // using account class
    cout << "=== Savings Account ============================" << endl;
    Savings_Account sav_acc{};
    sav_acc.deposit(2000.0);
    sav_acc.withdraw(500.0);

    cout << endl;

    Savings_Account* p_sav_acc{nullptr};
    p_sav_acc = new Savings_Account();
    p_sav_acc->deposit(1000.0);
    p_sav_acc->withdraw(500.0);
    delete p_acc;

    cout << endl;

    cout << "================================================" << endl;
}

} // namespace udemy1::e15::ex1

/**
 * @brief Example of Public, private , protected access specifier
 */
namespace udemy1::e15::ex2
{

void run_access_specifier(void)
{
    using std::cout, std::endl;
    using udemy::e15::Base, udemy::e15::Derived_Public;

    cout << "=== Base member access from base objects =========================" << endl;
    Base base;
    base.a = 100 ; // Okay
    // base.b = 100 ; // compilet error - protected member
    // base.c = 100 ; // compiler error - private member
    base.display();

    cout << "=== Base member access from derived objects ======================" << endl;
    Derived_Public derived_1;
    derived_1.a = 1000 ; // Okay
    // derived_1.b = 2000 ; // Compiler error - protected member
    // derived_1.c = 3000 ; // Compiler error - private member
    derived_1.access_base_member();
}

} // namespace udemy1::e15::ex2

/**
 * @brief main function to run all the underlying examples
 */
void udemy1::e15_run(void)
{
    //udemy1::e15::ex1::run_class_inhertance();
    udemy1::e15::ex2::run_access_specifier();
}
