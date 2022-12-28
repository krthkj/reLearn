#include "basederived.hpp"
#include <iostream>

using std::cout, std::endl;

/**
 * @brief Example of Public, private , protected access specifier
 */
namespace udemy1::e15::ex2
{
void Base::display()
{
    cout << a << ", ";
    cout << b << ", ";
    cout << c << endl;
}

void Derived_Public::access_base_member()
{
    a = 100; // Okay
    b = 200; // Okay
    // c = 300; // Compiler error - private member

    cout << a << ", ";
    cout << b << ", ";
    // cout << c; // Compiler error - private member
    cout << endl;
}
} // namespace udemy1::e15::ex2

/**
 * @brief Example of constructor and destructors with inheritance
 */
namespace udemy1::e15::ex3
{
Base::Base()
    : value{0}
{
    cout << "Base no-args Constructor" << endl;
}
Base::~Base()
{
    cout << "Base Destructor" << endl;
}
Base::Base(int val)
    : value{val}
{
    cout << "Base (int) overloaded Constructor" << endl;
}

Derived_Public::Derived_Public()
    : doubled_value{0}
{
    cout << "Derived_Public no-args Constructor" << endl;
}
Derived_Public::~Derived_Public()
{
    cout << "Derived_Public Destructor" << endl;
}
Derived_Public::Derived_Public(int x)
    : doubled_value{x * 2}
{
    cout << "Derived_Public (int) overloaded Constructor" << endl;
}

void Base::display(void) // simply defined to prevent compiler warning
{
    cout << value << endl;
}
void Derived_Public::display(void) // simply defined to prevent compiler warning
{
    cout << doubled_value << endl;
}

} // namespace udemy1::e15::ex3

/**
 * @brief Example of passing arg to base class constructors
 */
namespace udemy1::e15::ex4
{
Base::Base()
    : value{0}
{
    cout << "Base no-args Constructor" << endl;
}
Base::~Base()
{
    cout << "Base Destructor" << endl;
}
Base::Base(int val)
    : value{val}
{
    cout << "Base (int) overloaded Constructor" << endl;
}

Derived_Public::Derived_Public()
    : Base{}
    , doubled_value{0}
{
    cout << "Derived_Public no-args Constructor" << endl;
}
Derived_Public::~Derived_Public()
{
    cout << "Derived_Public Destructor" << endl;
}
Derived_Public::Derived_Public(int x)
    : Base{x}
    , doubled_value{x * 2}
{
    cout << "Derived_Public (int) overloaded Constructor" << endl;
}

} // namespace udemy1::e15::ex4

/**
 * @brief Example of Copy and Move constructors
 */
namespace udemy1::e15::ex4
{
Base::Base(const Base& src)
    : value{src.value}
{
    cout << "Base Copy constructor" << endl;
}
Base& Base::operator=(const Base& src)
{
    if(this != &src)
        value = src.value; // Assign Base part
    return *this;
}

Derived_Public::Derived_Public(const Derived_Public& src)
    : Base{src}
    , doubled_value{src.doubled_value}
{
    cout << "Derived_Public Copy constructor" << endl;
}
Derived_Public& Derived_Public::operator=(const Derived_Public& src)
{
    if(this != &src) {
        Base::operator=(src);              // Assign Base part
        doubled_value = src.doubled_value; // Assign Derived part
    }
    return *this;
}

} // namespace udemy1::e15::ex4
