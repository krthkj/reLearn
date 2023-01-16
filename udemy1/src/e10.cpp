/**
 * Copyright © 2022 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : e10.cpp
 * Desc : Section 10 Challenge from Udemy course "Beginning C++ Programming - From Beginner to Beyond"
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2022-11-30
 *
 */

#include "udemy1.hpp"

#include <cctype> // for character-based functions
#include <cstdlib>
#include <cstring> // for c-style string functions
#include <iomanip>
#include <iostream>
#include <string>

namespace udemy1
{

/**
 * @brief Understanding C-Style strings
 */
void c_style_string()
{
    /*
    char my_name_1[]{"Frank"};
    my_name_1[5] = 'y'; // works but this causes runtime problem because we over write the '\0'
    std::cout << my_name_1 << std::endl;

    char my_name_2[8]{"Frank"};
    my_name_2[5] = 'y'; // works without any issues.
    std::cout << my_name_2 << std::endl;

    char my_name_3[8];
    // my_name_3 = "Frank";        // Error
    strcpy(my_name_3, "Frank"); // Works, using <cstring>

    std::cout << my_name_3 << std::endl;
    */

    char first_name[20]{};
    char last_name[20]{};
    char full_name[50]{};
    char temp[50]{};

    {
        std::cout << first_name; // Will likely display garbage!

        std::cout << "Please enter your first name: ";
        std::cin >> first_name;

        std::cout << "Please enter your last name: ";
        std::cin >> last_name;
        std::cout << "-------------------------------" << std::endl;

        std::cout << "Hello, " << first_name << " your first name has " << strlen(first_name) << " characters"
                  << std::endl;
        std::cout << "and your last name, " << last_name << " has " << strlen(last_name) << " characters" << std::endl;

        strcpy(full_name, first_name); // copy first_name to full_name
        strcat(full_name, " ");        // concatenate full_name and a space
        strcat(full_name, last_name);  // concatenate last_name to full_name
        std::cout << "Your full name is " << full_name << std::endl;
    }
    {
        std::cout << "-------------------------------" << std::endl;
        std::cout << "Enter your full name: ";
        std::cin >> full_name;

        std::cout << "Your full name is " << full_name << std::endl;
    }
    {
        std::cout << "Enter your full name: ";
        std::cin.getline(full_name, 50);
        std::cout << "Your full name is " << full_name << std::endl;
    }
    {
        std::cout << "-------------------------------" << std::endl;
        strcpy(temp, full_name);
        if (strcmp(temp, full_name) == 0)
            std::cout << temp << " and " << full_name << " are the same" << std::endl;
        else
            std::cout << temp << " and " << full_name << " are different" << std::endl;

        std::cout << "-------------------------------" << std::endl;
    }
    {
        for (size_t i{0}; i < strlen(full_name); ++i) {
            if (isalpha(full_name[i]))
                full_name[i] = toupper(full_name[i]);
        }
        std::cout << "Your full name is " << full_name << std::endl;
    }
    {
        std::cout << "-------------------------------" << std::endl;

        if (strcmp(temp, full_name) == 0)
            std::cout << temp << " and " << full_name << " are the same" << std::endl;
        else
            std::cout << temp << " and " << full_name << " are different" << std::endl;

        std::cout << "-------------------------------" << std::endl;
        std::cout << "Result of comparing " << temp << " and " << full_name << ": " << strcmp(temp, full_name)
                  << std::endl;
        std::cout << "Result of comparing " << full_name << " and " << temp << ": " << strcmp(full_name, temp)
                  << std::endl;
    }
    std::cout << std::endl;
}

/**
 * @brief Coding Exercise 18: using C-Style Sting
 * In this exercise you will create a program that determines the length of a first name and last name
 * individually and then the length of the entire name through the use of the C-style string functions strlen, strcpy,
 * and strcat.
 *
 * Begin by declaring and initializing the C-style string variable first_name to contain "Bjarne".
 * Now, declare and initialize a second C-style string variable last_name to contain "Stroustrup".
 * You must also declare a third C-style string variable whole_name but do not initialize it yet. Remember that the
 * variable whole_name must be large enough to contain the first and last name with no whitespaces.
 *
 * Now, by using the C-style string function strlen, declare and initialize the variable first_name_length to contain
 * the length of the first_name string and the variable last_name_length to contain the length of the last_name string.
 *
 *
 * Using the C-style string function strcpy, copy the first_name string into the whole_name string variable.
 * Now, by using the C-style string function strcat, concatenate the last_name string at the end of the whole_name
 * string. Finally, by using the C-style string function strlen, declare and initialize the variable whole_name_length
 * to contain the length of the whole_name string.
 *
 */
void strings_and_functions()
{

    //----WRITE YOUR CODE BELOW THIS LINE----
    char first_name[10]{"Bjarne"};
    char last_name[12]{"Stroustrup"};
    char whole_name[22]{};

    size_t first_name_length = strlen(first_name);
    size_t last_name_length  = strlen(last_name);

    strcpy(whole_name, first_name);
    // strcat(whole_name," ");
    strcat(whole_name, last_name);

    size_t whole_name_length = strlen(whole_name);

    //----WRITE YOUR CODE ABOVE THIS LINE----
    //----DO NOT MODIFY THE CODE BELOW THIS LINE----

    std::cout << "The length of the first name, " << first_name << ", is " << first_name_length
              << " letters long and the length of the last name, " << last_name << ", is " << last_name_length
              << " letters long. This means that the length of the whole name must be " << whole_name_length
              << " letters long.";
}

/**
 * @brief Understanding C++ strings
 */
void cpp_string()
{

    std::string s1;             // Empty
    std::string s2{"Frank"};    // Frank
    std::string s3{s2};         // Frank
    std::string s4{"Frank", 3}; // Fra
    std::string s5{s3, 0, 2};   // Fr
    std::string s6(3, 'x');
    std::cout << "s1: " << s1 << std::endl
              << "s2: " << s2 << std::endl
              << "s3: " << s3 << std::endl
              << "s4: " << s4 << std::endl
              << "s5: " << s5 << std::endl
              << "s6: " << s6 << std::endl;

    s1 = "C++ Rocks!";
    std::cout << "s1: " << s1 << "   s2: " << s2 << std::endl;
    s2 = s1;
    std::cout << "s1: " << s1 << "   s2: " << s2 << std::endl;

    std::string part1{"C++"};
    std::string part2{"is a powerful"};

    std::string sentence;

    sentence = part1 + " " + part2 + " language"; // C++ is a powerful language
    std::cout << sentence << std::endl;
    // sentence = "C++ " + " is powerful " + " language"; // Illegal operation

    std::cout << "s3[0]: " << s3[0] << std::endl;
    std::cout << "s3.at(0): " << s3.at(0) << std::endl;

    s3[0] = 'p';
    std::cout << "s3[0] = 'p' output: " << s3 << std::endl;
    s3.at(1) = 'y';
    std::cout << "s3.at(1) = 'y' output: " << s3 << std::endl;

    std::cout << std::endl << "ASCII code for the strings literals" << std::endl;
    for (int c : s1)
        std::cout << c << std::endl;

    // reading Strings
    std::string str1;

    std::cout << "Enter a sentence: ";
    getline(std::cin, str1); // reads the whole line until '\n'
    std::cout << "getline(std::cin, str1) result: " << str1 << std::endl;

    std::cout << "Enter a sentence: ";
    getline(std::cin, str1, 'x');                                              // waits for 'x' as a delimiter
    std::cout << "getline(std::cin, str1, 'x') result: " << str1 << std::endl; // this is

    std::cout << "Enter a sentence: ";
    std::cin >> str1; // only accepts up to the first space
    std::cout << "std::cin >> result: " << str1 << std::endl;
}

/**
 * @brief working with C++ string
 */
void working_with_cpp_string(void)
{

    std::string s0;
    std::string s1{"Apple"};
    std::string s2{"Banana"};
    std::string s3{"Kiwi"};
    std::string s4{"apple"};
    std::string s5{s1};       // Apple
    std::string s6{s1, 0, 3}; // App
    std::string s7(10, 'X');  // XXXXXXXXXX

    std::cout << "s0 is :" << s0 << std::endl;               // No garbage
    std::cout << "s0 length = " << s0.length() << std::endl; // empty string

    // Initialization
    std::cout << std::endl
              << "Initialization" << std::endl
              << "------------------------------------------" << std::endl
              << "s1 is initialized to: " << s1 << std::endl
              << "s2 is initialized to: " << s2 << std::endl
              << "s3 is initialized to: " << s3 << std::endl
              << "s4 is initialized to: " << s4 << std::endl
              << "s5 is initialized to: " << s5 << std::endl
              << "s6 is initialized to: " << s6 << std::endl
              << "s7 is initialized to: " << s7 << std::endl;

    // Comparison
    std::cout << std::endl
              << "Comparison" << std::endl
              << "------------------------------------------" << std::endl
              << std::boolalpha << s1 << " == " << s5 << ": " << (s1 == s5) << std::endl // True    Apple == Apple
              << s1 << " == " << s2 << ": " << (s1 == s2) << std::endl                   // False   Apple != Banana
              << s1 << " != " << s2 << ": " << (s1 != s2) << std::endl                   // True    Apple != Banana
              << s1 << " < " << s2 << ": " << (s1 < s2) << std::endl                     // True         Apple < Banana
              << s2 << " > " << s1 << ": " << (s2 > s1) << std::endl                     // True         Banana > Apple
              << s4 << " < " << s5 << ": " << (s4 < s5) << std::endl                     // False        apple >Apple
              << s1 << " == "
              << "Apple"
              << ": " << (s1 == "Apple") << std::endl; // True Apple == Apple

    // Assignment
    std::cout << std::endl << "Assignment" << std::endl << "------------------------------------------" << std::endl;

    s1 = "Watermelon";
    std::cout << "s1 is now: " << s1 << std::endl; // Watermelon
    s2 = s1;
    std::cout << "s2 is now: " << s2 << std::endl; // Watermelon

    s3 = "Frank";
    std::cout << "s3 is now: " << s3 << std::endl; // Frank

    s3[0] = 'C';                                                       // Crank
    std::cout << "s3 change first letter to 'C': " << s3 << std::endl; // Crank
    s3.at(0) = 'P';
    std::cout << "s3 change first letter to 'P': " << s3 << std::endl; // Prank

    // Concatenation

    s3 = "Watermelon";
    std::cout << std::endl << "Concatenation" << std::endl << "------------------------------------------" << std::endl;

    s3 = s5 + " and " + s2 + " juice";             // Apple and Banana juice
    std::cout << "s3 is now: " << s3 << std::endl; // Apple and Banana Juice

    // s3 = "nice " + " cold " + s5 + "juice"; // Compiler error

    //  for loop
    std::cout << std::endl << "Looping" << std::endl << "------------------------------------------" << std::endl;

    s1 = "Apple";
    for (size_t i{0}; i < s1.length(); ++i)
        std::cout << s1.at(i); //  or s1[i]    Apple
    std::cout << std::endl;

    //// Range-based for loop
    for (char c : s1)
        std::cout << c; // Apple
    std::cout << std::endl;

    // Substring
    std::cout << std::endl << "Substring" << std::endl << "------------------------------------------" << std::endl;
    s1 = "This is a test";

    std::cout << s1.substr(0, 4) << std::endl   // This
              << s1.substr(5, 2) << std::endl   // is
              << s1.substr(10, 4) << std::endl; // test

    // Erase
    std::cout << std::endl << "Erase" << std::endl << "------------------------------------------" << std::endl;

    s1 = "This is a test";
    s1.erase(0, 5);                                // Erase This from s1 results in "is a test"
    std::cout << "s1 is now: " << s1 << std::endl; // is a test

    // getline
    std::cout << std::endl << "getline" << std::endl << "------------------------------------------" << std::endl;

    std::string full_name{};

    std::cout << "Enter your full name: ";
    getline(std::cin, full_name);

    std::cout << "Your full name is: " << full_name << std::endl;

    // Find
    std::cout << std::endl << "find" << std::endl << "------------------------------------------" << std::endl;

    s1 = "The secret word is Boo";
    std::string word{};

    std::cout << "Enter the word to find: ";
    std::cin >> word;

    size_t position = s1.find(word);
    if (position != std::string::npos)
        std::cout << "Found " << word << " at position: " << position << std::endl;
    else
        std::cout << "Sorry, " << word << " not found" << std::endl;

    std::cout << std::endl;
}

/**
 * @brief aggregate of all the functions in the section
 */
void e10_run(void)
{
    // c_style_string();
    // strings_and_functions();
    // cpp_string();
    // working_with_cpp_string();
}
} // namespace udemy1
