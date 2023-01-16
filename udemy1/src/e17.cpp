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
 * Unique pointers:  (Introduced in C++11)
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
 * Shared pointers:  (Introduced in C++11)
 * - Provides shared ownership of heap objects
 * - shared_ptr<T>
 *    - Points to an object of the type T on the heap
 *    - it is not unique - there can many shared_ptr<T> pointing to the same object on the heap
 *    - Established shared ownership relatopship
 *    - CAN be assigned or copied
 *    - CAN be moved
 *    - desn't support managing array by default
 *    - When the use count is zero, the managed object on the heap is deatroyed
 *    - increment or decrement reference use count to keep track of the shared ownerships
 * make_shared - introduced in C++11
 * deleteing shared pointer, by keeping count of
 *******************************************************************************
 * Weak pointers: (Introduced in C++11)
 * - Provides a non-owning "weak" reference
 * - weak_ptr<T>
 *    - Points to an object of the type T on the heap
 *    - Doesnt participate in owning relatopship (no ownership)
 *    - Always created from shared_ptr (reference to an object manages by shared_ptr)
 *    - Does NOT increment or decrement reference use count
 *    - Used to prevent strong reference cycles which could prevent objects from being deleted
 *******************************************************************************
 * Problem with shared_ptr:
 * - A refers to B
 * - B refers to A
 * - Shared strong ownership prevents heap deallocation
 *
 * Solution using weak_ptr:
 * - make one of the pointers non-owning or 'weak'
 * - now heap storage is deallocated properly
 *******************************************************************************
 * custom deleters
 * - Sometimes when we destroy a smart pointer we need more than to just destory the object on the heap
 * - These are special use-case
 * - C++ smart pointer allow you to provide custom deleters
 * - lots of ways to achieve this
 *    - Functions
 *    - Lambdas
 *    - Others
 *
 * Example using functions:
 *   void my_deleter( Some_Class* raw_pointer){
 *     // your custom deleter code
 *     delete raw_pointer;
 *   }
 *   shared_ptr<Some_Class> ptr{new Some_Class{}, my_deleter};
 *
 *
 *
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
        auto t2                  = std::make_unique<Test>(2000);

        std::unique_ptr<Test> t3;
        if (!t1)
            std::cout << "T1 is nullptr" << std::endl;
        if (!t3)
            std::cout << "T3 is nullptr" << std::endl;

        std::cout << "### Performing move on smart pointer" << std::endl;
        // t3 = t1; // ERROR - Copy/Assigment Not defined
        t3 = std::move(t1);
        if (!t1)
            std::cout << "T1 is nullptr" << std::endl;
        if (!t3)
            std::cout << "T3 is nullptr" << std::endl;
    }
}
} // namespace udemy1::e17::ex1

/**
 * @brief Example of Unique pointer
 */
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
    for (const auto& acc : accounts)
        std::cout << *acc << std::endl;
}

} // namespace udemy1::e17::ex2

/**
 * @brief Example of Shared pointer
 */
namespace udemy1::e17::ex3
{
void func(std::shared_ptr<udemy1::e17::ex1::Test> p)
{
    std::cout << "Use count: " << p.use_count() << std::endl;
}

void run_shared_ptr(void)
{
    {
        std::cout << "\n==========================================" << std::endl;
        std::shared_ptr<int> ptr1{new int{100}};
        std::cout << "ptr1 Created" << std::endl;
        std::cout << "ptr1 Use count: " << ptr1.use_count() << std::endl;

        std::shared_ptr<int> ptr2{ptr1};
        std::cout << "ptr2{ptr1} Created" << std::endl;
        std::cout << "ptr1 Use count: " << ptr1.use_count() << std::endl;
        std::cout << "ptr2 Use count: " << ptr2.use_count() << std::endl;

        ptr1.reset();
        std::cout << "ptr1.reset()" << std::endl;
        std::cout << "ptr1 Use count: " << ptr1.use_count() << std::endl;
        std::cout << "ptr2 Use count: " << ptr2.use_count() << std::endl;
    }
    {
        std::cout << "\n==========================================" << std::endl;
        using udemy1::e17::ex1::Test;
        std::shared_ptr<Test> ptr = std::make_shared<Test>(100);
        func(ptr);
        std::cout << "ptr Use count: " << ptr.use_count() << std::endl;

        {
            std::shared_ptr<Test> ptr1 = ptr;
            std::cout << "ptr Use count: " << ptr.use_count() << std::endl;
            {
                std::shared_ptr<Test> ptr2 = ptr;
                std::cout << "ptr Use count: " << ptr.use_count() << std::endl;
                ptr.reset();
            }
            std::cout << "ptr Use count: " << ptr.use_count() << std::endl;
        }
        std::cout << "ptr Use count: " << ptr.use_count() << std::endl;
    }
    {
        using udemy1::e17::ex2::Account;
        using udemy1::e17::ex2::Checking_Account;
        using udemy1::e17::ex2::Savings_Account;
        using udemy1::e17::ex2::Trust_Account;
        std::cout << "\n==========================================" << std::endl;
        std::vector<std::shared_ptr<Account>> accounts;
        {

            std::shared_ptr<Account> acc1 = std::make_shared<Trust_Account>("Larry", 10000, 3.1);
            std::shared_ptr<Account> acc2 = std::make_shared<Checking_Account>("Moe", 5000);
            std::shared_ptr<Account> acc3 = std::make_shared<Savings_Account>("Curly", 6000);

            // std::vector<std::shared_ptr<Account>> accounts;
            accounts.push_back(acc1);
            accounts.push_back(acc2);
            accounts.push_back(acc3);

            for (const auto& acc : accounts) {
                std::cout << *acc << std::endl;
                std::cout << "Use count: " << acc.use_count() << std::endl;
            }
            std::cout << "==========================================" << std::endl;
        }

        for (const auto& acc : accounts) {
            std::cout << *acc << std::endl;
            std::cout << "Use count: " << acc.use_count() << std::endl;
        }
        std::cout << "==========================================" << std::endl;
    }
}
} // namespace udemy1::e17::ex3

/**
 * @brief Example of Weak pointer
 */
namespace udemy1::e17::ex4
{

struct Person;

struct Team {
    std::shared_ptr<Person> goalKeeper; // Team.goalKeeper is an owner, hence increments shared_ptr.count()

    Team()
    {
        std::cout << "Team Created." << std::endl;
    }

    ~Team()
    {
        std::cout << "Team destructed." << std::endl;
    }
};

struct Person {
    std::weak_ptr<Team> team; // Person.team is an observer and has no ownership, doesnt increments shared_ptr.count()

    Person()
    {
        std::cout << "Person Created." << std::endl;
    }

    ~Person()
    {
        std::cout << "Person destructed." << std::endl;
    }
};

void run_weak_ptr_cyclic_dep_2(void)
{
    auto Barca        = std::make_shared<Team>();
    auto Valdes       = std::make_shared<Person>();
    Barca->goalKeeper = Valdes;
    Valdes->team      = Barca;
}

void run_weak_ptr_cyclic_dep()
{
    std::cout << "==========================================" << std::endl;
    std::cout << "Problem: Strong cirular reference" << std::endl;
    {
        // This Block will create (strong) circular reference
        // this can not be deallocated
        std::shared_ptr<A> a = std::make_shared<A>();
        std::shared_ptr<B> b = std::make_shared<B>();
        a->set_B(b);
        b->set_A(a);
        std::cout << "Results: Memory leak, no destructor called " << std::endl;
    }
    std::cout << "==========================================" << std::endl;
    std::cout << "Solution: Weak cirular reference" << std::endl;
    {
        // This Block will create (weak) circular reference
        // this can not be deallocated
        std::shared_ptr<A_weak> a = std::make_shared<A_weak>();
        std::shared_ptr<B_weak> b = std::make_shared<B_weak>();
        a->set_B(b);
        b->set_A(a);
        std::cout << "Results: No Memory leak, destructor are called for cleanup" << std::endl;
    }
}

//---------------------------------------------------------------------

std::weak_ptr<int> gw;
std::shared_ptr<int> gw_2;

void observe()
{
    std::cout << "gw.use_count() == " << gw.use_count() << "; ";
    // we have to make a copy of shared pointer before usage:
    if (std::shared_ptr<int> spt = gw.lock()) {
        std::cout << "*spt == " << *spt << '\n';
    } else {
        std::cout << "gw is expired\n";
    }
}

void observe_2()
{
    std::cout << "gw_2.use_count() == " << gw_2.use_count() << "; ";
    // we have to make a copy of shared pointer before usage:
    if (std::shared_ptr<int> spt = gw_2) {
        std::cout << "*spt == " << *spt << '\n';
    } else {
        std::cout << "gw_2 is expired\n";
    }
}

void run_weak_ptr_2(void)
{
    {
        {
            auto sp = std::make_shared<int>(42);
            std::cout << "sp.use_count() == " << sp.use_count() << "; " << std::endl;
            gw = sp;
            observe();
        }
        observe();
    }
    {
        {
            auto sp = std::make_shared<int>(42);
            gw_2    = sp;
            observe_2();
        }
        observe_2();
    }
}

//---------------------------------------------------------------------

// std::shared_ptr<int> myfunc(void)
//{
//
// }

void run_weak_ptr_3(void)
{

    {
        auto shared_Ptr = std::make_shared<int>(100);
        std::cout << "shared_Ptr.use_count() == " << shared_Ptr.use_count() << "; " << std::endl;
        std::cout << std::endl;

        std::weak_ptr<int> weak_ptr_1(shared_Ptr);
        std::cout << "shared_Ptr.use_count() == " << shared_Ptr.use_count() << "; " << std::endl;
        std::cout << "weak_ptr_1.use_count() == " << weak_ptr_1.use_count() << "; " << std::endl;
        std::cout << "weak_ptr_1.expired()   == " << weak_ptr_1.expired() << "; " << std::endl;
        std::cout << std::endl;

        std::weak_ptr<int> weak_ptr_2 = shared_Ptr;
        std::cout << "shared_Ptr.use_count() == " << shared_Ptr.use_count() << "; " << std::endl;
        std::cout << "weak_ptr_2.use_count() == " << weak_ptr_2.use_count() << "; " << std::endl;
        std::cout << "weak_ptr_2.expired()   == " << weak_ptr_2.expired() << "; " << std::endl;

        std::cout << std::endl;
        std::shared_ptr<int> shared_ptr_2 = shared_Ptr;
        std::cout << "shared_Ptr.use_count() == " << shared_Ptr.use_count() << "; " << std::endl;
        std::cout << "shared_ptr_2.use_count() == " << shared_ptr_2.use_count() << "; " << std::endl;
        std::cout << "weak_ptr_2.use_count() == " << weak_ptr_2.use_count() << "; " << std::endl;
        std::cout << "weak_ptr_2.expired()   == " << weak_ptr_2.expired() << "; " << std::endl;

        std::cout << std::endl;
        if (std::shared_ptr<int> sp = weak_ptr_1.lock()) {

            std::cout << "*sp = " << *sp << "; " << std::endl;
            std::cout << "sp.use_count() == " << sp.use_count() << "; " << std::endl;
        } else
            std::cout << "Didnt get the resource " << std::endl;
        std::cout << std::endl;

        std::cout << "Before weak_ptr_2.reset();" << std::endl;
        std::cout << "shared_Ptr.use_count() == " << shared_Ptr.use_count() << "; " << std::endl;
        std::cout << "weak_ptr_2.use_count() == " << weak_ptr_2.use_count() << "; " << std::endl;
        std::cout << "weak_ptr_2.expired()   == " << weak_ptr_2.expired() << "; " << std::endl;
        weak_ptr_2.reset();
        std::cout << "after weak_ptr_2.reset();" << std::endl;
        std::cout << "shared_Ptr.use_count() == " << shared_Ptr.use_count() << "; " << std::endl;
        std::cout << "weak_ptr_2.use_count() == " << weak_ptr_2.use_count() << "; " << std::endl;
        std::cout << "weak_ptr_2.expired()   == " << weak_ptr_2.expired() << "; " << std::endl;

        std::cout << std::endl;
        if (std::shared_ptr<int> sp = weak_ptr_1.lock()) {

            std::cout << "*sp = " << *sp << "; " << std::endl;
            std::cout << "sp.use_count() == " << sp.use_count() << "; " << std::endl;
        } else
            std::cout << "Didnt get the resource " << std::endl;
    }
}

} // namespace udemy1::e17::ex4

/**
 * @brief Example of Weak pointer
 */
namespace udemy1::e17::ex4
{

void my_deleter(udemy1::e17::ex1::Test* ptr)
{
    std::cout << "In my custom deleter: " << (*ptr).get_data() << std::endl;
    delete ptr;
}

void run_custom_deleter(void)
{
    // custom delete using function
    using udemy1::e17::ex1::Test;

    // custom deleter for unique pointer
    std::unique_ptr<Test, decltype(&my_deleter)> ptr_u{new Test{12}, &my_deleter};

    // custom deleter for shared pointer
    std::shared_ptr<Test> ptr_s{new Test{100}, &my_deleter};

    // custom lamda deleter for shared pointer
    std::shared_ptr<Test> ptr_s_lamds{new Test{200}, [](Test* ptr) {
                                          std::cout << "\tUsing custom deleter lamda " << (*ptr).get_data()
                                                    << std::endl;
                                          delete ptr;
                                      }};
}
}; // namespace udemy1::e17::ex4

/**
 * @brief main function to run all the underlying examples
 */
void udemy1::e17_run(void)
{
    // e17::ex1::run_unique_ptr_test();
    // e17::ex2::run_unique_ptr_account();
    // e17::ex3::run_shared_ptr();
    // e17::ex4::run_weak_ptr_cyclic_dep();
    e17::ex4::run_weak_ptr_cyclic_dep_2();
    // e17::ex4::run_weak_ptr_2();
    // e17::ex4::run_weak_ptr_3();
    // e17::ex4::run_custom_deleter();
}
