
/**
 * Copyright © 2023 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : s20c1.cpp
 * Desc : Section 20: STL challenge 1
 *
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2023-01-17
 *
 */

#include "udemy1.hpp"

#include <cctype>
#include <deque>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Challenge 20.1
 * Challenge 1 - Palindrome using deque
 *
 * A Palindrome is a string that reads the same backwards or forwards.
 * Simple examples are:
 * madam
 * bob
 * toot
 * radar
 *
 * An entire phrase can also be a palindome, for example:
 * A Toyota's a toyota
 * A Santa at NASA
 * A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!
 *
 * For the purposes of this assignment we will only consider alpha characters and omit all other characters.
 * We will also not be considering case.
 * So,
 * A Santa at Nasa, will be processed as:
 * ASANTAATNASA
 *
 * A common method to solve this problem is to compare the string to its reverse and
 * if the are equal then it must be a palindrome. But we will use a deque.
 *
 * I am providing the main driver for you which will automatically run several test cases.
 * You challenge is to write the following function:
 *
 * bool is_palindrome(const std::string &s) {
 *
 * This function will expect a string and it must determine if that string is a palindrome and return true if it is, or
 * false if it is not.
 *
 * So,
 *
 * is_palindrome("A Santa at Nasa");   will return true
 * is_palindrome("Hello");   will return false
 *
 */
namespace udemy1::s20c1
{
bool is_palindrome(const std::string& s)
{
    if (s.empty())
        return false;

    if (s.size() == 1)
        return true;

    std::deque<char> p{};

    // convert to lower and feed to deque
    for (char c : s)
        if (std::isalnum(c))
            p.push_back(std::toupper(c));

    char l{}, r{};
    while (p.size() > 1) {
        l = p.front();
        p.pop_front();
        r = p.back();
        p.pop_back();
        if (l != r)
            return false;
    }

    return true;
}
} // namespace udemy1::s20c1

void udemy1::s20c1_run(void)
{
    std::vector<std::string> test_strings{"a",
                                          "aa",
                                          "aba",
                                          "abba",
                                          "abbcbba",
                                          "ab",
                                          "abc",
                                          "radar",
                                          "bob",
                                          "ana",
                                          "avid diva",
                                          "Amore, Roma",
                                          "A Toyota's a toyota",
                                          "A Santa at NASA",
                                          "C++",
                                          "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!",
                                          "This is a palindrome",
                                          "palindrome"};

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result"
              << "String" << std::endl;
    for (const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << udemy1::s20c1::is_palindrome(s) << s << std::endl;
    }
    std::cout << std::endl;
}
