/**
 * Copyright © 2022 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : e16.cpp
 * Desc : Section 16: Polymorphism
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2022-12-29
 *
 */

/*******************************************************************************
 * Polymorphism
 * ============
 * - Fundamental to Object Oriented Programming
 * - Types of polymorphism
 *    1. compile-time / early binding / static binding
 *    2. Runn-time / late binding / dynamic binding
 *
 * - Runntime polymorphism: Being able to assign different meaning to the same function at run-time
 * - Allows to program more abstract
 *    >> Thinking general vs specific
 *    >> let C++ figure out which function to call at runtime
 *
 * - Not the default in C++, run-time polymorphism
 *   1. Inheritance
 *   2. base class pointer or reference
 *   3. virtual functions
 *
 *******************************************************************************
 * Polymorphism --------> Compile-time ------>  Function Overloading
 *                \                      \
 *                 \                      --->  Operator Overloading
 *                  \
 *                   ---> Run-time ---------->  Function Overriding  (virtual functions)
 *
 * Note:
 * - redefined functions are bounded statically
 * - Overridden functions are bounded dynamically
 *******************************************************************************
 * Virtual keywords and functions
 * - bounded dynamically
 * - they are overridden functions
 * - allow us to treat all objects generally as objects of base class
 *
 * Declaring virtual function
 * - declare the functino you eant to override as virtual in base-class
 * - virtual function are virtual all the way down the hierarchy from this point
 * - Dynamic polumorphism only via bass-class pointer or reference.
 * - override the function if derived-class
 * - function signature and return type must match Exactly.
 * - in derived-class virtual keywork is not required but is used as best practice.
 * - if no overriden version is provided, then inherited version from base-class is used.
 *
 * class Account{
 * public:
 *   virtual void withdraw (double amount);
 * };
 * class Checking: public Account{
 * public:
 *   virtual void withdraw (double amount);
 * };
 *
 *
 * Virtual destructors
 * - Problem can happen when we destroy polymorphic objects
 * - if a derived-class is destroyed by deleting tis storeage via the base class pointer and the class a non-virtual
 *   destructor. Then the behaviour is undefined in the C++ standard.
 * - Derived objects must be destroyed in the correct order starting at the correct destructor
 * - can help Prevent memory leak
 *
 * class Account{
 * public:
 *   virtual void withdraw (double amount);
 *   virtual ~Account();
 * };
 * class Checking: public Account{
 * public:
 *   virtual void withdraw (double amount);
 *   virtual ~Checking();
 * };
 *
 * Note: Virtual constructors are dont exisit, and dont make sense
 *******************************************************************************
 * C++11 Overrride specifier
 * - used when method signature dont match, instead of dynamic binding, it becomes static binding.
 * - using override' keyword will throw compiler error preventing unnecessary static binding.
 *
 * class Base{
 * public:
 *   virtual void say_hello() const ;
 * };
 * class Derived{
 * public:
 *   virtual void say_hello() override ; //
 * };
 *******************************************************************************
 * The 'final' specifier (C++11)
 * - used for better compiler optimization
 * - used at class level: prevents a class from being derived
 * - used at method level: prevents method from being overridden in derived class
 *
 * class A final{
 * public:
 *   virtual void do_something();
 * };
 * class B : public A{  // compiler error - cant be derived
 * public:
 *   virtual void do_something();
 * };
 *
 * class C{
 * public:
 *   virtual void do_something() final;
 * };
 * class D: public C{
 * public:
 *   virtual void do_something(); // compiler error - cant overrider
 * };
 *******************************************************************************
 * using base class references
 *******************************************************************************
 * Abstract classes and pure virtual functions
 *
 * +==============================================+==============================================+
 * |    Abstract Class                            |      Concrete Class                          |
 * +==============================================+==============================================+
 * | 1. Cannot instantiate objects                | 1. used to instantiate objects from          |
 * | 2. These classes are used as base-classes in | 2. All their member functions are defined    |
 * |    inhertance hierarchies                    |                                              |
 * | 3. Often referred to as Abstract base classes|                                              |
 * | 4. must have at least one pure virtual func  |                                              |
 * +----------------------------------------------+----------------------------------------------+
 * | class Base{                                  | class Base {                                 |
 * |   virtual void func1() = 0;                  |   //members                                  |
 * | };                                           |  virtual void function1();                   |
 * | class Derived: public Base {                 |  void function2();                           |
 * |   void func1(){}                             | };                                           |
 * | };                                           |                                              |
 * |Pure virtual func:                            |                                              |
 * | virtual void function () = 0;                |                                              |
 * +----------------------------------------------+----------------------------------------------+
 *
 *******************************************************************************
 * Abstract classes as interfaces
 * - Abstract class that has only pure virtual funcs
 * - these funcs provide a general set of services to the user of the classes
 * - provided as public
 * - each subclass if free to implement these services as needed
 * - every service (methos) must be implemented
 * - service type information is strictly enforced
 *
 * Note: classes with "I_" tends to be used for interface classes, for example "I_Shape"
 *
 * Example:
 *   class Printable{
 *     friend ostream& operator<<(ostream&, const Printable &obj);
 *   public:
 *     virtual void print(ostream& os) const = 0;
 *     virtual ~Printable();
 *   };
 *   ostream& operator<<(ostream&, const Printable &obj){
 *     obj.print(os);
 *     return os;
 *   }
 *   class Any_Class: public Printable{
 *   public:
 *     virtual void print(ostream& os) override { os << "Hi from ANy_Class"; }
 *   };
 *
 *
 *******************************************************************************
 */

#include "e16_classes.hpp"
#include "udemy1.hpp"
#include <iostream>
#include <memory>
#include <vector>

/**
 * @brief Example of polymorphism -  Static binding
 */
namespace udemy1::e16::ex1
{
class Base
{
  public:
    void say_hello() const
    {
        std::cout << "Hello - I'm Base class object" << std::endl;
    }
};

class Derived : public Base
{
  public:
    void say_hello() const
    {
        std::cout << "Hello - I'm Derived class object" << std::endl;
    }
};

void greetings(const Base& obj)
{
    std::cout << "Greetings: ";
    obj.say_hello();
}

void run_static_binding(void)
{
    Base b;
    b.say_hello(); // No pointer, hence, Static binding

    Derived d;
    d.say_hello(); // No pointer, hence, Static binding

    greetings(b); // using Base-class, passing Base-class Object, static-binding to base-class
    greetings(d); // using Base-class, passing Derived-class Object, static-binding to base-class

    Base* ptr = new Derived(); // can be created, but pts can only access base-class members/methods
    ptr->say_hello();          // static binding to Base-class section

    std::unique_ptr<Base> ptr1 =
        std::make_unique<Derived>(); // create smart pointer to for derived object with base-class pointer
    ptr1->say_hello();               // static binding to Base-class section

    delete(ptr); // remove raw pointer
    // smart pointer get removed automatically
}

} // namespace udemy1::e16::ex1

/**
 * @brief Example of polymorphism -  Dynamic binding using pointer
 */
namespace udemy1::e16::ex2
{
void run_base_ptr(void)
{
    std::cout << "\n=== Pointers ===========" << std::endl;
    Account* p1 = new Account();
    Account* p2 = new Savings();
    Account* p3 = new Checking();
    Account* p4 = new Trust();

    p1->withdraw(1000);
    p2->withdraw(1000);
    p3->withdraw(1000);
    p4->withdraw(1000);

    Account* array[] = {p1, p2, p3, p4};

    std::cout << "\n=== Array ==============" << std::endl;
    for(auto i{0}; i < 4; ++i)
        array[i]->withdraw(1000);

    std::cout << "\n=== Array - for each ===" << std::endl;
    array[0] = p4;
    for(const auto& a : array)
        a->withdraw(1000);

    std::vector<Account*> accounts{p1, p2, p3, p4};
    std::cout << "\n=== Vector =============" << std::endl;
    for(const auto& pAcc : accounts)
        pAcc->withdraw(1000);

    accounts.push_back(p4);
    accounts.push_back(p4);
    accounts.push_back(p4);
    std::cout << "\n=== Vector =============" << std::endl;
    for(const auto& pAcc : accounts)
        pAcc->withdraw(1000);

    std::cout << "\n=== Clean-up ===========" << std::endl;
    delete p1;
    std::cout << std::endl;
    delete p2;
    std::cout << std::endl;
    delete p3;
    std::cout << std::endl;
    delete p4;
}
} // namespace udemy1::e16::ex2

/**
 * @brief Example of Virtual functions and virtual destructors
 */
namespace udemy1::e16::ex3
{
void run_virtual_func_dest(void)
{
    std::cout << "\n=== Pointers ===========" << std::endl;
    Account* p1 = new Account();
    Account* p2 = new Savings();
    Account* p3 = new Checking();
    Account* p4 = new Trust();

    p1->withdraw(1000);
    p2->withdraw(1000);
    p3->withdraw(1000);
    p4->withdraw(1000);

    Account* array[] = {p1, p2, p3, p4};

    std::cout << "\n=== Array ==============" << std::endl;
    for(const auto& a : array)
        a->withdraw(1000);

    std::vector<Account*> accounts{p1, p2, p3, p4};
    std::cout << "\n=== Vector =============" << std::endl;
    for(const auto& pAcc : accounts)
        pAcc->withdraw(1000);

    std::cout << "\n=== Clean-up ===========" << std::endl;
    delete p1;
    std::cout << std::endl;
    delete p2;
    std::cout << std::endl;
    delete p3;
    std::cout << std::endl;
    delete p4;
}
} // namespace udemy1::e16::ex3

/**
 * @brief Example of 'override' keyword
 */
namespace udemy1::e16::ex4
{
class Base
{
  public:
    virtual void say_hello(void) const
    {
        std::cout << "Hello - I'm Base class" << std::endl;
    }
    virtual ~Base()
    {
    }
};
class Derived : public Base
{
  public:
    // virtual void say_hello(void) const;      // Ideal way of writing func overriding
    // virtual void say_hello(void);            // This will cause func redefine
    // virtual void say_hello(void) override;   // This will throw compiler error forcing you to match func signature.
    virtual void say_hello(void) const override // using 'override' prevents unnecessary error leading to static-binding
    {
        std::cout << "Hello - I'm Derived class" << std::endl;
    }
    virtual ~Derived()
    {
    }
};

void run_virtual_override(void)
{
    Base* p1 = new Base();
    p1->say_hello();

    Derived* p2 = new Derived();
    p2->say_hello();

    Base* p3 = new Derived();
    p3->say_hello();
}
} // namespace udemy1::e16::ex4

/**
 * @brief Example of dynamic binding using reference
 */
namespace udemy1::e16::ex5
{

void do_withdraw(ex2::Account& account, double amt)
{
    account.withdraw(amt); // dynamic binding
}
void run_base_ref(void)
{
    ex2::Account a;
    ex2::Account& ref = a;
    ref.withdraw(1000);

    std::cout << std::endl;

    ex2::Trust t;
    ex2::Account& ref1 = t;
    ref1.withdraw(1000);

    std::cout << std::endl;

    ex2::Account a1;
    ex2::Savings a2;
    ex2::Checking a3;
    ex2::Trust a4;

    do_withdraw(a1, 1000);
    do_withdraw(a2, 1000);
    do_withdraw(a3, 1000);
    do_withdraw(a4, 1000);

    std::cout << std::endl;
}
} // namespace udemy1::e16::ex5

/**
 * @brief Example of Pure virtual function and abstract class
 */
namespace udemy1::e16::ex6
{

void screen_refresh(const std::vector<Shape*>& shapes)
{
    std::cout << "Refreshing" << std::endl;
    for(const auto& p : shapes)
        p->draw();
}

void run_pure_virtual_abstract(void)
{
    // Shape s;                // ERROR: cant have objects for abstract class
    // Shape* p = new Shape(); // ERROR: cant have objects for abstract class

    Circle c;
    c.draw();
    std::cout << std::endl;

    Shape* ptr = new Circle();
    ptr->draw();
    ptr->rotate();
    std::cout << std::endl;

    Shape* s1 = new Circle();
    Shape* s2 = new Line();
    Shape* s3 = new Square();

    std::vector<Shape*> shapes{s1, s2, s3};
    // for(const auto& s : shapes)
    //     s->draw();
    screen_refresh(shapes);
    std::cout << std::endl;

    delete ptr;
    delete s1;
    delete s2;
    delete s3;
}
} // namespace udemy1::e16::ex6

/**
 * @brief Example of abstract class as interfaces
 */
namespace udemy1::e16::ex7
{

void print(const ex7_2::I_Printable& obj)
{
    std::cout << obj << std::endl;
}

void run_abstract_interface(void)
{
    {
        // Static binding
        ex7_1::Account a{"John"};
        std::cout << a << std::endl; // Account display: John

        ex7_1::Checking c{"Sam"};
        std::cout << c << std::endl; // Checking display: Sam

        ex7_1::Savings s{"Peter"};
        std::cout << s << std::endl; // Savings display: Peter

        ex7_1::Trust t{"James"};
        std::cout << t << std::endl; // Trust display: James

        std::cout << std::endl;
    }
    {
        // Dymanic binding - works but incorrect result
        // Reason why interfaces is needed
        ex7_1::Account* p1 = new ex7_1::Account("Anna");
        std::cout << *p1 << std::endl; // INCORRECT - Account display: Anna

        ex7_1::Account* p2 = new ex7_1::Checking("Nikki");
        std::cout << *p2 << std::endl; // INCORRECT - Account display: Nikki
        std::cout << std::endl;
    }
    {
        // Dymanic binding - works and expected result
        // Properly implimented using interface
        ex7_2::Account* p1 = new ex7_2::Account("Anna");
        std::cout << *p1 << std::endl; // Account display: Anna
        print(*p1);                    // Account display: Anna

        ex7_2::Account* p2 = new ex7_2::Checking("Nikki");
        std::cout << *p2 << std::endl; // Correct: display: Nikki
        print(*p2);                    // Correct: display: Nikki

        std::cout << std::endl;

        ex7_2::Dog* dog = new ex7_2::Dog("Rocky");
        std::cout << *dog << std::endl; // Woof woof: Rocky
        print(*dog);                    // Woof woof: Rocky
    }
}
} // namespace udemy1::e16::ex7

/**
 * @brief main function to run all the underlying examples
 */
void udemy1::e16_run(void)
{
    // udemy1::e16::ex1::run_static_binding();
    // udemy1::e16::ex2::run_base_ptr();
    // udemy1::e16::ex3::run_virtual_func_dest();
    // udemy1::e16::ex4::run_virtual_override();
    // udemy1::e16::ex5::run_base_ref();
    // udemy1::e16::ex6::run_pure_virtual_abstract();
    udemy1::e16::ex7::run_abstract_interface();
}
