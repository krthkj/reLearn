/**
 * Copyright © 2022 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : e14.cpp
 * Desc : Section 14: Ooperator Overloading
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2022-12-22
 *
 */

/*******************************************************************************
 * Operator Overloading
 * ====================
 * - traditional operator : +, =, *, etc
 * - Allows user defined tpyes to behave similar to built-in types
 * - can make code more readable and writable
 * - not done automatically ( except for assignment operator)
 *
 * Example:
 *  - using functions:
 *      Number result = multiply (add (a,b) , divide (c,d));
 *  - using member meathods:
 *      Number result = (a.add(b)).multiply(c.divide(d));
 *  - using overloading operator:
 *      Number result = (a+b)*(c/d);
 *
 * +--------------------------+--------------------------+
 * | Operator available       |   Operator cannot        |
 * |     to overload          |     be to overload       |
 * +--------------------------+--------------------------+
 * | (Copy, Move)   =         |         ::               |
 * | (unary)  ++, --, -, !    |         :?               |
 * |                          |         .*               |
 * |                          |         .                |
 * |                          |        sizeof            |
 * |                          |                          |
 * |                          |                          |
 * |                          |                          |
 * +--------------------------+--------------------------+
 *
 * Rules:
 * ======
 * - Precedence and associativity cannot be changed
 * - 'arity'  cannot be changed (i.e, cannt make the divion operator unary)
 * - cannt overload operators for primitive types
 * - cannot create new operators
 * - [], (), -> and assignment operator(=) must be declares as member methods
 * - Other operatos can be declared as member mehtods or global functions
 *
 *******************************************************************************
 * Copy assignment operator (=) overloading
 * ----------------------------------------
 * - C++ provides adefault assignment operator used for assinging ove object to another
 * - default is member wise assignment (shallow copy)
 *   - if member data doesnt contain raw pointers then default assignment operator overloading is good enough.
 *   - if member data has raw pointers the we need to explicitely create assignment operator overloading method.
 * Example:
 *   Type& Type::operator=(const Type& rhs);
 *
 *******************************************************************************
 * Move assignment operator (=) overloading
 * ----------------------------------------
 * - You can choose to overload the move assignment operator
 * - if we have raw pointer we shuld overload the move assignment operator for effeciency
 * Example:
 *   Type& Type::operator=(Type &&lhs);
 *
 *******************************************************************************
 * unary operator (++, --, -, !) overloading
 * ------------------------------------------
 * - work on one operands
 *
 * Example:
 *   Type Type::operator++();          // pre-increment
 *   Type Type::operator++(int) const; // post-increment
 *   Type Type::operator--();          // pre-decrement
 *   Type Type::operator--(int) const; // post-decrement
 *   Type Type::operator-() const;     // negative number
 *   bool Type::operator!() const;     // logical not operator
 *
 *******************************************************************************
 * Binary operator (+, -, ==, !=, <, >, etc) overloading
 * -----------------------------------------------------
 * - work on one operands
 *
 * Example:
 *   Type Type::operator+(const Type& rhs) const;  // add
 *   Type Type::operator-(const Type& rhs) const;  // subtract
 *   bool Type::operator==(const Type& rhs) const; //
 *   bool Type::operator!=(const Type& rhs) const;
 *   bool Type::operator<(const Type& rhs) const;
 *   bool Type::operator>(const Type& rhs) const;
 *
 *******************************************************************************
 */

#include "udemy1.hpp"
#include <cstring>
#include <iostream>

/**
 * @brief Comprenshive example of all operator overloading
 */
namespace udemy1::ex1
{

class Mystring
{
  private:
    char* str; // c-style string
  public:
    Mystring();                    // default constructor
    Mystring(const char* s);       // arg constructor
    Mystring(const Mystring& src); // copy constructor
    ~Mystring();                   // destructor

    // operator overloading
    Mystring& operator=(const Mystring& l_val_ref); // copy assignment operator overloading
    Mystring& operator=(Mystring&& r_val_ref);      // move assignment operator overloading

    // unary operator
    Mystring operator-() const; // negative

    // binay operator
    Mystring operator+(const Mystring& rhs) const;
    bool operator==(const Mystring& rhs) const;
    bool operator!=(const Mystring& rhs) const;
    bool operator<(const Mystring& rhs) const;
    bool operator>(const Mystring& rhs) const;

    // other func
    void display() const;
    size_t get_length() const;

    // getter and setter
    void setStr(char* str);
    const char* getStr() const;
};

/**************************************************
 * default constructor
 **************************************************/
Mystring::Mystring(void)
    : str{nullptr} // set pointer to null
{
    std::cout << "Default Constructor" << std::endl;
    this->str = new char[1]; // allocate on heap
    *this->str = '\0';       // EOL character
}

/**************************************************
 * arg constructor
 **************************************************/
Mystring::Mystring(const char* s)
    : str{nullptr} // set to null
{
    std::cout << "Arg Constructor" << std::endl;
    if(s == nullptr) {           // if arg is nullptr
        this->str = new char[1]; // allocate on heap
        *this->str = '\0';       // EOL character
    } else {
        this->str = new char[std::strlen(s) + 1]; // create in heap
        std::strcpy(this->str, s);                // copy arg to member data
    }
}

/**************************************************
 * Copy constructor
 **************************************************/
Mystring::Mystring(const Mystring& src) // copy constructor
    : str{nullptr}                      // set to null
{
    std::cout << "Copy Constructor" << std::endl;
    this->str = new char[std::strlen(src.str) + 1]; // create in heap
    std::strcpy(this->str, src.str);                // copy data
}

/**************************************************
 * destructor
 **************************************************/
Mystring::~Mystring(void) // destructor
{
    std::cout << "Destructor" << std::endl;
    delete[] this->str;
}

/**************************************************
 * copy assignment operator overloading
 **************************************************/
Mystring& Mystring::operator=(const Mystring& rhs)
{
    std::cout << "Copy assignment" << std::endl;
    // check for self assignment
    if(this == &rhs)
        return *this;

    // deallocate storage for this->str for overwriting
    delete[] this->str;

    // allocate storage and deep copy
    this->str = new char[std::strlen(rhs.str) + 1]; // create in heap
    std::strcpy(this->str, rhs.str);                // copy arg to member data

    // return pointer
    return *this;
}

/**************************************************
 * Move assignment operator overloading
 **************************************************/
Mystring& Mystring::operator=(Mystring&& rhs)
{
    std::cout << "Move assignment" << std::endl;
    // check for self assignment
    if(this == &rhs)
        return *this;

    // deallocate storage for this->str for overwriting
    delete[] this->str;

    // steal the pointer
    this->str = rhs.str;

    // null out the rhs object
    rhs.str = nullptr;

    // return pointer
    return *this;
}

/**************************************************
 * Unary oprator overloading (-)
 **************************************************/

/**************************************************
 * Other member finctions
 **************************************************/
void Mystring::display() const
{
    std::cout << this->str << ":" << get_length() << std::endl;
}
size_t Mystring::get_length() const
{
    return std::strlen(this->str);
}

/**************************************************
 * Getter setters
 **************************************************/
void Mystring::setStr(char* str)
{
    this->str = str;
}
const char* Mystring::getStr() const
{
    return this->str;
}

void run_operator_overloading(void)
{
    Mystring a{"Hello"};  // overloaded constructor
    Mystring b;           // no-args contructor
    Mystring c{a};        // copy constructor
    b = a;                // copy assignment: b.operator=(a)
    a = Mystring{"Hola"}; // move assignment operator-overloading: a.operator=("Holla")
    b = "This is a test"; // move assignment operator-overloading: b.operator=("This is a test")
}

} // namespace udemy1::ex1

/********************************************************************************************************************/

namespace udemy1::ex2
{
void run_memfunc_operator_overloading(void)
{
}
} // namespace udemy1::ex2

/**
 * @brief main function to run all the underlying examples
 */
void udemy1::e14_run(void)
{
    udemy1::ex1::run_operator_overloading();         // operator-overloading
    udemy1::ex2::run_memfunc_operator_overloading(); // operator-overloading
}
