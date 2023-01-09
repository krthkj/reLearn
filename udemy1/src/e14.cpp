/**
 * Copyright © 2022 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : e14.cpp
 * Desc : Section 14: Operator Overloading
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2022-12-22
 *
 */

/*******************************************************************************
 * Operator Overloading
 * ====================
 * - traditional operator : +, =, *, etc
 * - Allows user defined types to behave similar to built-in types
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
 * - Precedence and associations cannot be changed
 * - 'arity'  cannot be changed (i.e, cannot make the division operator unary)
 * - cannot overload operators for primitive types
 * - cannot create new operators
 * - [], (), -> and assignment operator(=) must be declares as member methods
 * - Other operators can be declared as member methods or global functions
 *
 *******************************************************************************
 * Copy assignment operator (=) overloading
 * ----------------------------------------
 * - C++ provides a default assignment operator used for assigning ove object to another
 * - default is member wise assignment (shallow copy)
 *   - if member data doesn't contain raw pointers then default assignment operator overloading is good enough.
 *   - if member data has raw pointers the we need to explicitly create assignment operator overloading method.
 * Example:
 *   Type& Type::operator=(const Type& rhs);
 *
 *******************************************************************************
 * Move assignment operator (=) overloading
 * ----------------------------------------
 * - You can choose to overload the move assignment operator
 * - if we have raw pointer we should overload the move assignment operator for efficiency
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
 * implementing operator overloading usign non member functions or global func
 * - if implement as friend functions of class, can access class member data
 * - if implement as normal functions then we need to use getter methods for class data
 * - ideally written in .cpp file
 *
 * Example:
 *  class ClassName{
 *    friend ClassName operator-(const ClassName& src);                       // unary minus operator overloading
 *    friend ClassName operator+(const ClassName& lhs, const ClassName& rhs); // binary plus operator overloading
 *    bool ClassName operator==(const ClassName& lhs, const ClassName& rhs); // binary equal operator overloading
 *    private:
 *          < member data >
 *    public:
 *          < member functions >
 *  }
 *******************************************************************************
 * overloading stream operators: insertion(<<) & extraction (>>)
 * ==============================================================
 * This cannot be implemented as member functions
 * Reason: 1. left operand must be user-defined class
 *         2. no the way we normally use these operators
 *
 * Stream insertion operator (<<):
 * - return a reference to the ostream so we can keep inserting
 * - don't return ostream by value
 * Syntax:
 *    std::ostream& operator<< (std::ostream& os, const Type& objType){
 *      os << obj.member_data;       // if friend functions
 *      os << obj.get_member_data(); // if not friend functions
 *      return os;
 *    }
 *
 * Stream extraction operator (>>):
 * - return a reference to the istream so we can keep inserting
 * - update the object passed in
 * Syntax:
 *    std::istream& operator>> (std::istream& is, Type& objType){
 *      chat *buff = new char[1000];  // allocate large array of char
 *      is >> buff;
 *      obj = Type {buff}; // if your have copy or move assignment operators
 *      delete[] buff;
 *      return is;
 *    }
 *
 *******************************************************************************
 */

#include "udemy1.hpp"
#include <cstring>
#include <iostream>

/**
 * @brief Comprehensive example of all operator overloading as member functions
 */
namespace udemy1::ex1
{

class Mystring
{
  private:
    char* str; // c-style string
  public:
    Mystring();                        // default constructor
    Mystring(const char* s);           // arg constructor
    Mystring(const Mystring& src);     // copy constructor
    Mystring(Mystring&& src) noexcept; // move Constructor
    ~Mystring();                       // destructor

    // operator overloading
    Mystring& operator=(const Mystring& l_val_ref); // copy assignment operator overloading
    Mystring& operator=(Mystring&& r_val_ref);      // move assignment operator overloading

    // unary operator
    Mystring operator-() const; // unary negative operator

    // binay operator
    Mystring operator+(const Mystring& rhs) const; // binary plus operator
    bool operator==(const Mystring& rhs) const;    // binary equals operator
    bool operator!=(const Mystring& rhs) const;    // binary not equals operator
    bool operator<(const Mystring& rhs) const;     // binary less than operator
    bool operator>(const Mystring& rhs) const;     // binary greater than operator

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
Mystring::Mystring(const Mystring& source)
{
    std::cout << "Copy Constructor" << std::endl;
    // deep copy remaining data
    this->str = new char[std::strlen(source.str) + 1]; // create in heap
    std::strcpy(this->str, source.str);                // copy data
}

/**************************************************
 * Move constructor
 **************************************************/
Mystring::Mystring(Mystring&& source) noexcept
{
    std::cout << "Move Constructor" << std::endl;
    // steal pointers from srouce
    this->str = source.str;
    source.str = nullptr;
}

/**************************************************
 * Destructor
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

    // De-allocate storage for this->str for overwriting
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

    // de-allocate storage for this->str for overwriting
    delete[] this->str;

    // steal the pointer
    this->str = rhs.str;

    // null out the rhs object
    rhs.str = nullptr;

    // return pointer
    return *this;
}

/**************************************************
 * Unary operator overloading (-)
 **************************************************/
Mystring Mystring::operator-() const // unary minus operator
{
    std::cout << "Unary - " << std::endl;
    // we are making the string to lower case.
    char* buff = new char[std::strlen(str) + 1];
    for(size_t i{0}; i < std::strlen(buff); ++i)
        buff[i] = std::tolower(str[i]);

    // create new object and return it
    Mystring tmp{buff};
    delete[] buff; // remove buffer object used for calculation
    return tmp;
}

/**************************************************
 * Binary operator overloading (+)
 **************************************************/
Mystring Mystring::operator+(const Mystring& rhs) const // binary plus operator
{
    std::cout << "Binary + " << std::endl;
    // allocate buffer
    char* buffer = new char[(std::strlen(str) + std::strlen(str) + 1)];
    std::strcpy(buffer, str);
    std::strcat(buffer, rhs.str);

    // create new object to return
    Mystring tmp{buffer};
    delete[] buffer; // delete buffer object
    return tmp;
}

bool Mystring::operator==(const Mystring& rhs) const // binary equals operator
{
    std::cout << "Binary == " << std::endl;
    return (std::strcmp(str, rhs.str) == 0);
}

bool Mystring::operator!=(const Mystring& rhs) const // binary not equals operator
{
    std::cout << "Binary != " << std::endl;
    return !(rhs == *this);
}

bool Mystring::operator<(const Mystring& rhs) const // binary equals operator
{
    std::cout << "Binary <" << std::endl;
    return (std::strcmp(str, rhs.str) < 0);
}

bool Mystring::operator>(const Mystring& rhs) const // binary equals operator
{
    std::cout << "Binary >" << std::endl;
    return (std::strcmp(str, rhs.str) > 0);
}

/**************************************************
 * Other member functions
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
    {
        Mystring a{"Hello"};  // overloaded constructor
        Mystring b;           // no-args constructor
        Mystring c{a};        // copy constructor
        b = a;                // copy assignment: b.operator=(a)
        a = Mystring{"Hola"}; // move assignment operator-overloading: a.operator=("Holla")
        b = "This is a test"; // move assignment operator-overloading: b.operator=("This is a test")
    }
    {
        Mystring larry{"LaRRy"};
        Mystring moe{"Moe"};

        Mystring stooge = larry;
        larry.display();
        moe.display();

        std::cout << (larry == moe) << std::endl;    // false
        std::cout << (larry == stooge) << std::endl; // true

        larry.display();
        Mystring larry2 = -larry; // unary operator overloading
        larry2.display();         // lower case larry

        Mystring stooges = larry + "Moe"; // binary plus operator overloading - PASS
        stooges.display();

        // Mystring stooges_1 = "Larry" + moe; // binary plus operator overloading - ERROR

        Mystring stooges_2 = larry + " " + moe; // binary plus operator overloading - PASS
        stooges_2.display();

        Mystring stooges_3 = moe + " " + larry + " " + "Curly"; // binary plus operator overloading - PASS
        stooges_3.display();
    }
}
} // namespace udemy1::ex1

/********************************************************************************************************************/

/**
 * @brief example of all operator overloading as global/friend functions
 */
namespace udemy1::ex2
{
class Mystring
{
    friend Mystring operator-(const Mystring& src);                      // unary minus operator overloading
    friend Mystring operator+(const Mystring& lhs, const Mystring& rhs); // binary plus operator overloading
    friend bool operator==(const Mystring& lhs, const Mystring& rhs);    // binary equal operator overloading

    friend std::ostream& operator<<(std::ostream& os, const Mystring& rhs); // stream insertion overloading as friend

  private:
    char* str; // c-style string
  public:
    Mystring();                    // default constructor
    Mystring(const char* s);       // arg constructor
    Mystring(const Mystring& src); // copy constructor
    Mystring(Mystring&& src);      // move Constructor
    ~Mystring();                   // destructor

    // operator overloading
    Mystring& operator=(const Mystring& l_val_ref); // copy assignment operator overloading
    Mystring& operator=(Mystring&& r_val_ref);      // move assignment operator overloading

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
    // std::cout << "Default Constructor" << std::endl;
    this->str = new char[1]; // allocate on heap
    *this->str = '\0';       // EOL character
}

/**************************************************
 * arg constructor
 **************************************************/
Mystring::Mystring(const char* s)
    : str{nullptr} // set to null
{
    // std::cout << "Arg Constructor" << std::endl;
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
Mystring::Mystring(const Mystring& source)
{
    std::cout << "Copy Constructor" << std::endl;
    // deep copy remaining data
    this->str = new char[std::strlen(source.str) + 1]; // create in heap
    std::strcpy(this->str, source.str);                // copy data
}

/**************************************************
 * Move constructor
 **************************************************/
Mystring::Mystring(Mystring&& source)
{
    std::cout << "Move Constructor" << std::endl;
    // steal pointers from source
    this->str = source.str;
    source.str = nullptr;
}

/**************************************************
 * destructor
 **************************************************/
Mystring::~Mystring(void) // destructor
{
    // std::cout << "Destructor" << std::endl;
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

    // de-allocate storage for this->str for overwriting
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

    // de-allocate storage for this->str for overwriting
    delete[] this->str;

    // steal the pointer
    this->str = rhs.str;

    // null out the rhs object
    rhs.str = nullptr;

    // return pointer
    return *this;
}

/**************************************************
 * Other member functions
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
 * Getter and setter
 **************************************************/
const char* Mystring::getStr() const
{
    return this->str;
}
void Mystring::setStr(char* str)
{
    this->str = str;
}

/***************************************************************
 * Implement operator overloading functions
 *=========================================
 *
 * Binary equal operator overloading non-member functions
 ***************************************************************/
bool operator==(const Mystring& lhs, const Mystring& rhs)
{
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

/***************************************************************
 * Unary Minus operator overloading non-member functions
 ***************************************************************/
Mystring operator-(const Mystring& src)
{ // convert string to lower
    char* buff = new char[std::strlen(src.str) + 1];
    for(size_t i{0}; i < std::strlen(src.str); ++i)
        buff[i] = std::tolower(src.str[i]);
    Mystring tmp{buff};
    delete[] buff;
    return tmp;
}

/***************************************************************
 * Binary + operator overloading non-member functions
 ***************************************************************/
Mystring operator+(const Mystring& lhs, const Mystring& rhs)
{ // performing concat

    char* buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    Mystring tmp{buff};
    delete[] buff;
    return tmp;
}

void run_global_operator_overloading(void)
{
    Mystring larry{"LaRrY"};
    larry.display();

    larry = -larry;
    larry.display();

    std::cout << std::boolalpha << std::endl;
    Mystring moe{"Moe"};
    Mystring stooge = larry;

    std::cout << (larry == moe) << std::endl;
    std::cout << (larry == stooge) << std::endl;

    Mystring stooges = larry + "Moe";
    stooges.display();

    Mystring stooges_1 = "Larry" + moe; // Now works with non-member functions
    stooges_1.display();

    Mystring stooges_2 = moe + " " + "Larry";
    stooges_2.display();

    Mystring stooges_3 = moe + " " + larry + "Curly";
    stooges_3.display();
}

/********************************************************************************************************************/

/**
 * @brief example of stream operator overloading
 */

/***************************************************************
 * stream Insertion operator overloading as non friend function
 ***************************************************************/
std::ostream& operator<<(std::ostream& os, const Mystring& rhs)
{
    os << rhs.str;
    return os;
}

} // namespace udemy1::ex2

/***************************************************************
 * stream extraction operator overloading as non friend function
 ***************************************************************/
std::istream& operator>>(std::istream& is, udemy1::ex2::Mystring& rhs)
{
    /*
    // This block of code has trouble compiling with C++ 20 flag both on GCC and Clang char* buff = new char[1000];
    is >> buff;
    rhs = udemy1::ex2::Mystring{buff};
    delete[] buff;
    return is;
    */

    std::string buffer{};
    is >> buffer;
    rhs = udemy1::ex2::Mystring{buffer.c_str()};
    return is;
}

void run_stream_operator_overloading(void)
{
    udemy1::ex2::Mystring larry{"LarRY"};
    udemy1::ex2::Mystring moe{"Moe"};
    udemy1::ex2::Mystring curly;

    std::cout << "Enter the third stooge's first name: ";
    std::cin >> curly;

    std::cout << "The three stooges are " << larry << ", " << moe << ", " << curly << std::endl;

    std::cout << std::endl << "Enter the stooges names separated by space: ";
    std::cin >> larry >> moe >> curly;

    std::cout << "The three stooges are " << larry << ", " << moe << ", " << curly << std::endl;
}

/**
 * @brief main function to run all the underlying examples
 */
void udemy1::e14_run(void)
{
    // udemy1::ex1::run_operator_overloading();        // operator-overloading usign member func
    // udemy1::ex2::run_global_operator_overloading(); // operator-overloading using non member func
    run_stream_operator_overloading(); // operator-overloading for stream operators
}
