#include "basederived.hpp"
#include <iostream>

using std::cout, std::endl;

void udemy::e15::Base::display()
{
    cout << a << ", ";
    cout << b << ", ";
    cout << c << endl;
}

void udemy::e15::Derived_Public::access_base_member()
{
    a = 100; // Okay
    b = 200; // Okay
    // c = 300; // Compiler error - private member

    cout << a << ", ";
    cout << b << ", ";
    // cout << c; // Compiler error - private member
    cout << endl;
}
