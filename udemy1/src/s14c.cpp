/**
 * Copyright © 2022 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : s14c.cpp
 * Desc : Section 14: Operator overloading
 *        Testing operator overloading
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2022-12-23
 *
 */

/*
 * Overload the following operators in the provided Mystring class.
 *
 * To gain experience overloading operators, you should do this challenge twice.
 * First, overload the operators using member functions and then in another project overload the same operators
 * again using non-member functions.
 *
 * Please do it once using member methods and then again using non-member functions.
 *
 * Here is a list of some of the operators that you can overload for this class:
 *
 * -       - unary minus. Returns the lowercase version of the object's string
 *            -s1
 * ==    - returns true if the two strings are equal
 *            (s1 == s2)
 * !=     - returns true if the two strings are not equal
 *            (s1 != s2)
 * <      - returns true if the lhs string is lexically less than the rhs string
 *            (s1 < s2)
 * >      - returns true if the lhs string is lexically greater than the rhs string
 *           (s1 > s2)
 * +       - concatenation. Returns an object that concatenates the lhs and rhs
 *            s1 + s2
 * +=    - concatenate the rhs string to the lhs string and store the result in lhs object
 *           s1 += s2;      equivalent to s1 = s1 + s2;
 * *        - repeat -  results in a string that is copied n times
 *           s2 * 3;          ex). s2 = "abc";
 *                                    s1 = s2 * 3;
 *                                    s1 will result in "abcabcabc"
 * *=      - repeat the string on the lhs n times and store the result back in the lhs object
 *             s1 = "abc";
 *             s1 *= 4;        s1 = s1 will result in "abcabcabcabc"
 *
 * If you wish to overlod the ++ and -- operators remember that they have pre and post versions.
 *
 * The semantics should be as follows (this shows the member method version):
 *
 * Mystring &operator++()   {  // pre-increment
 *    // do what ever you want increment do to - maybe make all characters uppercase?
 *    return *this;
 * }
 *
 * // Note that post-increment returns a Mystring by value not by reference
 * Mystring operator++(int) {   // post-increment
 *    Mystring temp (*this);       // make a copy
 *    operator++();                    // call pre-increment - make sure you call pre-increment!
 *    return temp;                     // return the old value
 * }
 *
 *
 * Have fun! Think of some other operators that might be useful!
 * Don't worry if they all don't make sense -- this is an exercise about learning how
 * to overload operators.
 *
 * Hints:
 * 1. take advantage of the std::strcmp function for the equality operators!
 * 2. the += and *= operators should return a Mystring &
 * 3. rather than duplicate code in the += and *= functions, use the + and * operators which you have already
 * overloaded!
 *
 */

#include "mystring.hpp"
#include "udemy1.hpp"
#include <iostream>

namespace udemy1
{

/**
 * @brief Testing operator overloading
 */
void s14c_run(void)
{
    std::cout << "## Operator overloading challenge ##" << std::endl;
    std::cout << std::boolalpha << std::endl;
    udemy1::myclass::Mystring a{"frank"};
    udemy1::myclass::Mystring b{"frank"};

    std::cout << (a == b) << std::endl; // true
    std::cout << (a != b) << std::endl; // false

    b = "george";
    std::cout << (a == b) << std::endl; // false
    std::cout << (a != b) << std::endl; // true
    std::cout << (a < b) << std::endl;  // true
    std::cout << (a > b) << std::endl;  // false

    udemy1::myclass::Mystring s1{"FRANK"};
    s1 = -s1;
    std::cout << s1 << std::endl; // frank

    s1 = s1 + "*****";
    std::cout << s1 << std::endl; // frank*****

    s1 += "-----"; // frank*****-----
    std::cout << s1 << std::endl;

    udemy1::myclass::Mystring s2{"12345"};
    s1 = s2 * 3;
    std::cout << s1 << std::endl; // 123451234512345

    udemy1::myclass::Mystring s3{"abcdef"}; // arg constructor
    s3 *= 5;                                // *= operator overloading
    std::cout << s3 << std::endl;           // abcdefabcdefabcdefabcdefabcdef

    udemy1::myclass::Mystring s = "Frank"; // move assignment
    ++s;                                   //    pre increment
    std::cout << s << std::endl;           // FRANK

    s = -s;                      // minus operator
    std::cout << s << std::endl; // frank

    udemy1::myclass::Mystring result;
    result = ++s;                     // Pre-increment
    std::cout << s << std::endl;      // FRANK
    std::cout << result << std::endl; // FRANK

    s = "Frank";
    s++;                         // post increment
    std::cout << s << std::endl; // FRANK

    s = -s;
    std::cout << s << std::endl;      // frank
    result = s++;                     // post increment
    std::cout << s << std::endl;      // FRANK
    std::cout << result << std::endl; // frank
}

} // namespace udemy1
