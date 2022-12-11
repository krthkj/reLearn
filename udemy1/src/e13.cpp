/**
 * Copyright © 2022 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : e13.cpp
 * Desc : Section 13: OOP - Class and objects
 *        Challenge from Udemy course "Beginning C++ Programming - From Beginner to Beyond"
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2022-12-11
 *
 */

#include "account.hpp"
#include "udemy1.hpp"
#include <iostream>
#include <vector>

namespace udemy1
{

/*
 ***********************************************************************************************
 * Object-Oriented Programming
 ***********************************************************************************************
 * Class and object
 * - Focus is on class and model real-world domain entities
 * - allows to hink at a higher level of abstraction
 * - used succeffully un very large programs.
 ***********************************************************************************************
 * Concepts:
 * - Encapsulation:
 *   - Objects contain data and operations that work on that data
 *   - Abstract Data Type (ADT)
 * - Information hiding
 *   - implementation specific login can be hidden
 *   - users of class code to the interface since they dont need to know the implementations
 *   - more abstraction.
 *   - easier to test, debug, maintain and extend.
 * - Reusability
 *   - easier to reuse class in the applicaitons
 *   - faster development
 *   - higher quality
 * - Inheritance
 *   - create new class in terms of existing class
 *   - reusability
 *   - polymorphic class
 * - Polymorphism and more..
 *   - Overloading
 *   - Overriding
 ***********************************************************************************************
 * Classes:
 * - bluprint of object
 * - has attributes (data)
 * - has methods (functions)
 * - userdefined data-type
 * - can hide data and methods
 * - provide a public interface
 * - Syntax: class Class_Name{
 *           // declerations
 *           };
 *
 * Object:
 * - created from class
 * - represent a specific instance of a class
 * - can create many ojects
 * - each has it own identity
 * - each can use the defined class methods
 * - Syntax: Class_Name object_name;
 ***********************************************************************************************
 * Access class member
 * - using dot operator
 * - using -> (member of pointer or arrow) operator
 * Example:
 * {
 *   Account *frank_account = new Account ();
 *
 *   // dereference the pointer and use dot operator
 *   *frank_account.balance;
 *   *frank_account.deposit(100);
 *
 *   // use -> directly on the pointer.
 *   frank_account->balance;
 *   frank_account->deposit(100);
 *
 * }
 *
 ***********************************************************************************************
 * Class member access modifiers
 * - public    : accessible everywhere
 * - private   : accessible only by members or friends of the class
 * - protected : using with inheritance
 * - friends   : ????????????
 ***********************************************************************************************
 * Implementing member methods:
 * - can be implemented inside the class decleration ( implicitly inline )
 * - can be implemented outside the class decleration ( use '::' scope resolution operator )
 * - Can seperate specificaiton for impelementation
 *   - .h for class decleration
 *   - .cpp for class implementation
 ***********************************************************************************************
 * Include Guards:
 * Ideal method:
 *      #ifndef _FILENAME_H_
 *      #define _FILENAME_H_
 *      // class decleration
 *      #endif // _FILENAME_H_
 *
 * Alternative method: (may not work on some compilers)
 *      #pragma once
 ***********************************************************************************************
 *
 */
//-----------------------------------------------------------------------------------------
namespace ex1
{

class Player
{
  public:
    // attributes
    std::string name{"Player"};
    int health{100};
    int xp{3};

    // methods
    void talk(std::string test_to_say)
    {
        std::cout << name << " says " << test_to_say << std::endl;
    }

    bool is_dead(void)
    {
        if(health > 0)
            return true;
        return false;
    }
};

class Account
{
  public:
    std::string name{"Account"};
    double balance{0.0};

    void deposit(double amt)
    {
        balance += amt;
        std::cout << "in deposit" << std::endl;
    }
    void withdraw(double amt)
    {
        balance -= amt;
        std::cout << "in withdraw" << std::endl;
    }
};

} // namespace ex1

//-----------------------------------------------------------------------------------------

namespace ex2
{

class Player
{
  private:
    std::string name{"Player"};
    int health{100};
    int xp{3};

  public:
    // implementing member method inside class
    void talk(std::string test_to_say)
    {
        std::cout << name << " says " << test_to_say << std::endl;
    }

    bool is_dead(void)
    {
        if(health > 0)
            return true;
        return false;
    }
};

class Account
{
  private:
    double balance{0.0};

  public:
    std::string name{"Account"};

    // implementing methods declerationd
    void SetBalance(double);
    double GetBalance();

    // implementing member method inside class
    void deposit(double amt)
    {
        balance += amt;
        std::cout << "in deposit" << std::endl;
    }

    void withdraw(double amt)
    {
        balance -= amt;
        std::cout << "in withdraw" << std::endl;
    }
};

// implementing method outside the class
void Account::SetBalance(double bal)
{
    balance = bal;
}
double Account::GetBalance()
{
    return balance;
}

} // namespace ex2

//-----------------------------------------------------------------------------------------

namespace ex3
{

class Account
{
  private:
    std::string name{"Account"};
    double balance{0.0};

  public:
    void set_balance(double);
    double get_balance();

    void set_name(std::string);
    std::string get_name();

    bool deposit(double);
    bool withdraw(double);
};

void Account::set_name(std::string n)
{
    name = n;
}
std::string Account::get_name()
{
    return name;
}

void Account::set_balance(double bal)
{
    balance = bal;
}
double Account::get_balance()
{
    return balance;
}

bool Account::deposit(double amt)
{
    balance += amt;
    return true;
}

bool Account::withdraw(double amt)
{
    if(balance - amt >= 0) {
        balance -= amt;
        return true;
    }
    return false;
}

} // namespace ex3

//-----------------------------------------------------------------------------------------

void run_class_example(void)
{
    // objects
    ex1::Player frank;
    ex1::Player hero;

    frank.name = "Frank";
    frank.health = 80;
    frank.xp = 15;
    frank.talk("Hi there..!");

    ex1::Player player[]{frank, hero};
    std::vector<ex1::Player> player_vec{frank};
    player_vec.push_back(hero);

    ex1::Player* enemy{nullptr};
    enemy = new ex1::Player();

    (*enemy).name = "Enemy";
    (*enemy).health = 200;
    enemy->xp = 20;

    enemy->talk("I will destroy you!!");
    delete enemy;

    //----------------------------------------
    ex1::Account frank_account;

    frank_account.name = "Frank's account";
    frank_account.balance = 5000;

    frank_account.deposit(1000);
    frank_account.withdraw(1000);
}

//-----------------------------------------------------------------------------------------

void run_class_access(void)
{
    // objects
    ex2::Player frank;
    ex2::Player hero;

    // frank.name = "Frank"; // Error access is private
    // frank.health = 80;    // Error access is private
    // frank.xp = 15;        // Error access is private
    frank.talk("Hi there..!");

    //----------------------------------------
    ex2::Account frank_account;

    frank_account.name = "Frank's account"; // PASS access is public
    // frank_account.balance = 5000;           // Error access is private

    frank_account.deposit(1000);
    frank_account.withdraw(1000);
}

//-----------------------------------------------------------------------------------------

void run_test_class(void)
{
    ex3::Account frank_account;
    frank_account.set_name("Frank's account");
    frank_account.set_balance(1000.0);

    if(frank_account.deposit(200.0))
        std::cout << "Deposit OK" << std::endl;
    else
        std::cout << "Deposit not allowed" << std::endl;

    if(frank_account.withdraw(200.0))
        std::cout << "Withdraw OK" << std::endl;
    else
        std::cout << "Insufficient funds" << std::endl;

    if(frank_account.withdraw(1500.0))
        std::cout << "Withdraw OK" << std::endl;
    else
        std::cout << "Insufficient funds" << std::endl;
}

void run_test_classfile(void)
{
    myclass::Account frank_account;
    frank_account.set_name("Frank's account");
    frank_account.set_balance(1000.0);

    if(frank_account.deposit(200.0))
        std::cout << "Deposit OK" << std::endl;
    else
        std::cout << "Deposit not allowed" << std::endl;

    if(frank_account.withdraw(200.0))
        std::cout << "Withdraw OK" << std::endl;
    else
        std::cout << "Insufficient funds" << std::endl;

    if(frank_account.withdraw(1500.0))
        std::cout << "Withdraw OK" << std::endl;
    else
        std::cout << "Insufficient funds" << std::endl;
}

void e13_run(void)
{
    // run_class_example();
    // run_class_access();
    // run_test_class();
    run_test_classfile();
}

} // namespace udemy1
