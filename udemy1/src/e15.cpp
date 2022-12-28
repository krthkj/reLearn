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
 * Understanding access modifiers
 * ------------------------------
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
 * Constructor and destructor with inheritance
 * ===========================================
 * - Derived class inherits from its base class
 * - Base class parts must be initialized before the derived class is initialized
 * - when derived object is created, base class constructor executs first and then derived class constructor executes
 *
 * Note:
 * 1. Derived class doent inherit
 *    - Base class constructor
 *    - Base class destructor
 *    - Base class overloaded assignment operator
 *    - Base class friend functions
 * 2. Derived class constructors, destructors and overloaded assignement operators can be invoke the base-class versions
 * 3. C++11 allows explicit inheritance of base 'non-special' constructors with
 *    - `using Base::Base;` anywhere in the derived class decleration
 *    - lots of rules involved, often better to deifne constructors yourself
 *
 * Syntax:
 *   class Base {
 *   public:
 *     Base();
 *     Base(int x);
 *   };
 *   Derived::Derived(int x) : Base (x), <optional initializers for derived> {
 *   }
 *******************************************************************************
 * Copy & move constructors with inheritance
 * =========================================
 * - Not inherited from base class
 * - you may not need to provide your own, copmiler provided version may be just fine
 * - we can explicitly invoke the base class version fron the derived class
 *
 * Copy constructor:
 * - can invoke base copy constructor explicitely,
 * - derived object 'other' will be sliced. (see below example)
 *
 * Derived;:Derived (const Derived& other) : Base(other), <derived initialization list> {
 *   // code
 * }
 *
 * Copy/Move constructor and overloaded operator=
 * ----------------------------------------------
 * - Often you do not need to provide your own
 * - If you dont define them in derived, then compiler will created ans automatically call the base class version
 * - if you do provide derived versions, them you must invoke the base version explicitly.
 * - Be careful with raw pointers.
 *   1. especially if Base and derived have raw pointers
 *   2. provide them with deep copy semantics
 *
 *******************************************************************************
 * override and redefinig base class methods
 * - derived class can directly invoke base class methods
 * - derived class can override or redefine base class methods
 * - very powerful in the contect of polymorphism
 *
 *******************************************************************************
 * Static binding of method calls
 * - Default binding for C++ is static
 * - derived class object will use derived-class methods
 * - we can explicitly involke base-class methods from derived-class methods
 * - not useful in all cases, reason we have other mechanism knowns as runtime binding
 *
 *******************************************************************************
 * Multiple inheritance
 * - Derived class inherits from two or more base class at the same time
 * - base classs may belong to unrelated class hierarchies
 *
 * Note:
 * - Can be very complex
 * - Easily misused
 *
 * Syntax:
 *   class Derived: public Base_A, public Base_B {
 *     // members and methods
 *   }
 *******************************************************************************
 */

#include "accounts.hpp"
#include "basederived.hpp"
#include "udemy1.hpp"
#include <iostream>

using std::cout, std::endl;
/**
 * @brief Example of inheritance
 */

namespace udemy1::e15::ex1
{
void run_class_inhertance(void)
{
    using udemy::e15::ex1::Account, udemy::e15::ex1::Savings_Account;

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
    using udemy::e15::ex2::Base, udemy::e15::ex2::Derived_Public;

    cout << "=== Base member access from base objects =========================" << endl;
    Base base;
    base.a = 100; // Okay
    // base.b = 100 ; // compilet error - protected member
    // base.c = 100 ; // compiler error - private member
    base.display();

    cout << "=== Base member access from derived objects ======================" << endl;
    Derived_Public derived_1;
    derived_1.a = 1000; // Okay
    // derived_1.b = 2000 ; // Compiler error - protected member
    // derived_1.c = 3000 ; // Compiler error - private member
    derived_1.access_base_member();
}

} // namespace udemy1::e15::ex2

/**
 * @brief Example of constructor and destructors with inheritance
 */
namespace udemy1::e15::ex3
{

void run_const_dest(void)
{
    using udemy::e15::ex3::Base, udemy::e15::ex3::Derived_Public;
    {
        cout << "=== Base object ======================= " << endl;
        Base base;
        cout << endl;
    }
    cout << endl;
    {
        cout << "=== Base object ======================= " << endl;
        Base b{100};
        cout << endl;
    }
    cout << endl;
    {
        cout << "=== Derived Object ==================== " << endl;
        Derived_Public derived;
        cout << endl;
    }
    cout << endl;
    {
        cout << "=== Derived Object ==================== " << endl;
        Derived_Public derived{1000};
        cout << endl;
    }
    cout << endl;
}

} // namespace udemy1::e15::ex3

/**
 * @brief Example of passing arg to base class constructors
 */
namespace udemy1::e15::ex4
{

void run_passing_args(void)
{
    using udemy::e15::ex4::Base, udemy::e15::ex4::Derived_Public;
    {
        cout << "=== Derived Object ==================== " << endl;
        Derived_Public derived;
        cout << endl;
    }
    cout << endl;
    {
        cout << "=== Derived Object ==================== " << endl;
        Derived_Public derived{1000};
        cout << endl;
    }
    cout << endl;
}

} // namespace udemy1::e15::ex4

/**
 * @brief Example of Copy and Move constructors
 */
namespace udemy1::e15::ex5
{

void run_copy_move_const(void)
{
    using udemy::e15::ex4::Base, udemy::e15::ex4::Derived_Public;
    {
        cout << "=== Base object ======================= " << endl;
        Base base_1{100};    // default constructor called
        Base base_2{base_1}; // copy constructor called

        Base base_3;
        base_3 = base_1; // Assigmnemt operator overloading called

        cout << endl;
    }
    cout << endl;
    {
        cout << "=== Derived Object ==================== " << endl;
        Derived_Public derived_1{1000};      // default constructor called
        Derived_Public derived_2{derived_1}; // copy constructor called

        Derived_Public derived_3;
        derived_3 = derived_1; // Assigmnemt operator overloading called
        cout << endl;
    }
    cout << endl;
}

} // namespace udemy1::e15::ex5

/**
 * @brief Example of redefinig base class methods
 *        Example of static binding
 */
namespace udemy1::e15::ex6
{

void run_redef_static(void)
{
    using udemy::e15::ex6::Account, udemy::e15::ex6::Savings_Account;

    cout << "=== Account ====================================" << endl;
    Account a1{1000.0};
    cout << a1 << endl; // Account balance: 1000

    a1.deposit(500.0);  // 500 deposited
    cout << a1 << endl; // Account balance: 1500

    a1.withdraw(1000.0); // 1000 withdrawn
    cout << a1 << endl;  // Account balance: 500

    a1.withdraw(5000.0); // Insufficient funds
    cout << a1 << endl;  // Account balance: 500

    cout << "\n=== Savings Account ============================" << endl;

    Savings_Account s1{1000.0, 5.0};
    cout << s1 << endl; // Savings Account Balance: 1000 Interest rate: 5

    s1.deposit(1000.0); // 1050 Deposited
    cout << s1 << endl; // Savings Account Balance: 2050 Interest rate: 5

    s1.withdraw(2000.0); // 2000 withdrawn
    cout << s1 << endl;  // Savings Account Balance: 50 Interest rate: 5

    s1.withdraw(5000.0); // Insufficient funds
    cout << s1 << endl;  // Savings Account Balance: 50 Interest rate: 5
}

} // namespace udemy1::e15::ex6

/**
 * @brief main function to run all the underlying examples
 */
void udemy1::e15_run(void)
{
    // udemy1::e15::ex1::run_class_inhertance();
    // udemy1::e15::ex2::run_access_specifier();
    // udemy1::e15::ex3::run_const_dest();
    // udemy1::e15::ex4::run_passing_args();
    // udemy1::e15::ex5::run_copy_move_const();
    // udemy1::e15::ex6::run_redef_static();
}
