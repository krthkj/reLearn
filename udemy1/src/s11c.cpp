/**
 * Copyright © 2022 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : s11c.cpp
 * Desc : Section 11 Challenge from Udemy course "Beginning C++ Programming - From Beginner to Beyond"
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2022-12-08
 *
 */

#include "udemy1.hpp"
#include <iostream>
#include <vector>

namespace udemy1
{
/**
 * @brief Section 11 Challenge
 * Rewrite secoin 9 challenge using functions.
 *
 * This challenge is about using a collection (list) of integers and allowing the user
 * to select options from a menu to perform operation on teh list.
 *
 * Your program should display a menu options to the user as follows:
 * P - Print numbers
 * A - Add numbers
 * M - Display mean of the numbers
 * S - Display the smallest number
 * L - Display the largest number
 * Q - Quit
 *
 * Enter your choice:
 *
 * Upon Selecting Q, should display "Goodbye" and terminate.
 *
 * list messages to be display if the list is empty,
 * "Unable to calculate the mean - no data"
 * "Unable to determint the smallest number - list is empty"
 * "[] - the list is empty"
 * "<value> added"
 * "The smallest number is <val>"
 * "The largest number is <val>"
 * "Goodbye"
 *
 * This program though only accept valid choices from teh user, both upper and lower-case selection should be allowed.
 * if an illegal choice is made, you should display, "Unknown selection , please try again." and menu options should be
 * displayed again.
 *
 * Additional feature:
 * - Search for a number in the list, if found display the number of times it occurs.
 * - clearing out makes an empty list
 * - Dont allow duplicate entries
 * - add your own ideas
 */

// Menu related
void display_menu(void);
char get_selection(void);

// Handle functions for menu options
void handle_display(const std::vector<int>&);
void handle_add(std::vector<int>&);
void handle_clear(std::vector<int>&);
void handle_mean(const std::vector<int>&);
void handle_smallest(const std::vector<int>&);
void handle_largest(const std::vector<int>&);
void handle_quit(void);
void handle_unknown(void);
void handle_find(const std::vector<int>&);

// operations
void display_list(const std::vector<int>&);
double calc_mean(const std::vector<int>&);
int get_smallest(const std::vector<int>&);
int get_largest(const std::vector<int>&);
bool find(const std::vector<int>&, int);

void s11c_run(void)
{
    std::vector<int> mylist{};
    char selection{};
    do {
        display_menu();
        selection = get_selection();
        switch(selection) {
        case 'p':
            handle_display(mylist);
            break;
        case 'a':
            handle_add(mylist);
            break;
        case 'c':
            handle_clear(mylist);
            break;
        case 'm':
            handle_mean(mylist);
            break;
        case 's':
            handle_smallest(mylist);
            break;
        case 'f':
            handle_find(mylist);
            break;
        case 'l':
            handle_largest(mylist);
            break;
        case 'q':
            handle_quit();
            break;
        default:
            handle_unknown();
            break;
        }
    } while(selection != 'q');
}

void display_menu(void)
{
    std::cout << std::endl
              << "P - Print numbers" << std::endl
              << "A - Add numbers" << std::endl
              << "M - Display mean of the numbers" << std::endl
              << "S - Display the smallest number" << std::endl
              << "L - Display the largest number" << std::endl
              << "F - Find a number" << std::endl
              << "C - Clear the list" << std::endl
              << "Q - Quit" << std::endl
              << std::endl
              << "Enter your choice: ";
}

char get_selection(void)
{
    char choice{};
    std::cin >> choice;
    std::cout << std::endl;
    return std::tolower(choice);
}

void handle_mean(const std::vector<int>& v)
{
    if(v.empty())
        std::cout << "Unable to calculate the mean - no data" << std::endl;
    else
        std::cout << "The mean is " << calc_mean(v) << std::endl;
}

void handle_smallest(const std::vector<int>& v)
{
    if(v.empty())
        std::cout << "Unable to determint the smallest number - list is empty" << std::endl;
    else
        std::cout << "The smallest number is " << get_smallest(v) << std::endl;
}

void handle_largest(const std::vector<int>& v)
{
    if(v.empty())
        std::cout << "Unable to determint the largest number - list is empty" << std::endl;
    else
        std::cout << "The largest number is " << get_largest(v) << std::endl;
}

void handle_unknown(void)
{
    std::cout << "Unknown selection , please try again." << std::endl;
}

void handle_quit(void)
{
    std::cout << "Goodbye..." << std::endl;
}

void handle_display(const std::vector<int>& v)
{
    if(v.empty())
        std::cout << "[] - the list is empty" << std::endl;
    else
        display_list(v);
}

void handle_add(std::vector<int>& v)
{
    int n{};
    std::cout << "Enter an integer to add to the list: ";
    std::cin >> n;
    if(!v.empty()) {
        int count{0};
        for(auto i : v) {
            if(n == i)
                count++;
        }
        if(count > 0)
            std::cout << n << " is a duplicate entry, it occurs " << count << " times" << std::endl;
    }
    v.push_back(n);
    std::cout << n << " added" << std::endl;
}

void handle_find(const std::vector<int>& v)
{
    int target{0};
    std::cout << "Enter the number to find: ";
    std::cin >> target;
    if(find(v, target))
        std::cout << target << " was found" << std::endl;
    else
        std::cout << target << " was not found" << std::endl;
}

void handle_clear(std::vector<int>& v)
{
    if(v.empty())
        std::cout << "[] - the list is already empty" << std::endl;
    else {
        v.clear();
        std::cout << "List cleared" << std::endl;
    }
}

void display_list(const std::vector<int>& v)
{
    std::cout << "[ ";
    for(auto i : v)
        std::cout << i << " ";
    std::cout << "]" << std::endl;
}

double calc_mean(const std::vector<int>& v)
{
    int val{0};
    for(auto i : v)
        val += i;
    return static_cast<double>(val) / v.size();
}

int get_smallest(const std::vector<int>& v)
{
    int val{v.at(0)};
    for(auto i : v)
        val = (i < val) ? i : val;
    return val;
}

int get_largest(const std::vector<int>& v)
{
    int val{v.at(0)};
    for(auto i : v)
        val = (i > val) ? i : val;
    return val;
}

bool find(const std::vector<int>& v, int t)
{
    for(auto i : v)
        if(i == t)
            return true;
    return false;
}

} // namespace udemy1
