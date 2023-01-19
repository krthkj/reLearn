/**
 * Copyright © 2023 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : s20c4.cpp
 * Desc : Section 20: STL challenge 4
 *
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2023-01-19
 *
 */

/**
 * @brief Challenge 20.4
 * Challenge 4 - Stack and Queue Challenge
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
 * Please use a stack and a queue to solve the problem.
 *
 *
 */

#include "udemy1.hpp"

#include <cctype>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <string>

namespace udemy1::s20c4
{
bool is_palindrome_2(const std::string& s)
{
    std::stack<char> tmp_s{};
    std::queue<char> tmp_q{};
    for (char c : s)
        if (std::isalpha(c)) {
            c = std::toupper(c);
            tmp_q.push(c); // string going forward
            tmp_s.push(c); // string gets reversed when popped
        }

    // reduce time by half by stopping comparison at mid
    int mid = tmp_s.size() / 2;
    while (mid > 0) {
        if (tmp_s.top() != tmp_q.front())
            return false;
        tmp_s.pop();
        tmp_q.pop();
        --mid;
    }
    return true;
}

bool is_palindrome(const std::string& s)
{
    std::stack<char> tmp_s{};
    std::queue<char> tmp_q{};
    for (char c : s)
        if (std::isalpha(c)) {
            c = std::toupper(c);
            tmp_q.push(c); // string going forward
            tmp_s.push(c); // string gets reversed when popped
        }

    while (!tmp_s.empty()) {
        if (tmp_s.top() != tmp_q.front())
            return false;
        tmp_s.pop();
        tmp_q.pop();
    }
    return true;
}
} // namespace udemy1::s20c4

void udemy1::s20c4_run(void)
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
    std::cout << std::setw(8) << std::left << "Result1" << std::setw(8) << std::left << "Result2"
              << "String" << std::endl;
    for (const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << udemy1::s20c4::is_palindrome(s) << std::setw(8) << std::left
                  << udemy1::s20c4::is_palindrome_2(s) << s << std::endl;
    }
    std::cout << std::endl;
}
