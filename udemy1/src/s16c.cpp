/**
 * Copyright © 2022 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : s16c.cpp
 * Desc : Section 16: Polymorphism
 *        Testing operator overloading
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2022-12-30
 *
 */

/*
 * Section 16 Challenge Polymorphism
 *
 * You are provided with a completed Account class hierarchy that was completed in Section 15.
 * The provided class hierarchy does not use dynamic polymorphism (it has no virtual functions!)
 *
 * Your challenge is the following:
 *
 * 1.  Modify the Account class so that it is now an Abstract class by adding the following pure virtual functions:
 *         virtual bool deposit(double amount) = 0;
 *         virtual bool withdraw(double amount) = 0;
 *
 *         Hint: you can implement these functions in the Account class if it makes sense
 *
 * 2. Create an I_Printable class interface as we did in the course and provide functionality so
 *     all accounts are printable to an ostream using the overloaded insertion operator.
 *
 *         class I_Printable
 *         {
 *             friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
 *         public:
 *             virtual void print(std::ostream &os) const = 0;
 *             virtual ~I_Printable() = default;
 *         };
 *
 * 3. Modify the functions in the Account_Util files so we only have one version of each. For example,
 *
 *         void display(const std::vector<Account *> &accounts);
 *         void deposit(std::vector<Account *> &accounts, double amount);
 *         void withdraw(std::vector<Account *> &accounts, double amount);
 *
 *         Note that the vector is a vector of pointers to Account objects <Account *>
 *         This is what we need for dynamic polymorphism.
 *
 * 4. Test your code with base class pointers as well as local objects.
 *     I provided a simple main driver that will get you started
 *
 * Hints:
 *     - Reuse existing functionality!!
 *     - If your class has a virtual function then be sure to implement a virtual destructor.
 *        You can have the C++ generate a default destructor for you with:
 *            virtual ~Class_Name() = default;
 *     - Take it one step at a time.
 *     - Start by making the Account class abstract by adding the pure virtual functions.
 *
 */

#include "s16c_class.hpp"
#include "udemy1.hpp"
#include <iostream>
#include <vector>

namespace udemy1
{
void s16c_run(void)
{
    using s16c::Account;
    using s16c::Checking;
    using s16c::Savings;
    using s16c::Trust;
    using std::cout, std::endl;
    cout << "#################################################################################################" << endl;
    // Part 1
    {
        // Account frank{"Frank", 5000}; // should not compile
        // cout << frank << endl;

        Checking frank{"Frank", 5000};
        cout << frank << endl;

        Account* trust = new Trust("James");
        cout << *trust << endl;

        Account* p1 = new Checking("Larry", 10000);
        Account* p2 = new Savings("Moe", 1000);
        Account* p3 = new Trust("Curly");

        std::vector<Account*> accounts{p1, p2, p3};

        display(accounts);
        deposit(accounts, 1000);
        withdraw(accounts, 2000);

        display(accounts);

        delete p1;
        delete p2;
        delete p3;
    }
    cout << "#################################################################################################" << endl;
    // Part 2
    {
        Checking c;
        cout << c << endl;

        Savings s{"Frank", 5000, 2.6};
        cout << s << endl;
        s.deposit(10000);
        cout << s << endl;
        s.withdraw(10000);
        cout << s << endl;
    }
    cout << "#################################################################################################" << endl;
    // Part 3
    {
        Account* ptr = new Trust("Leo", 10000, 2.6);
        cout << *ptr << endl;
    }
}
} // namespace udemy1
