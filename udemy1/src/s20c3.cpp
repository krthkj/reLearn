/**
 * Copyright © 2023 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : s20c3.cpp
 * Desc : Section 20: STL challenge 3
 *
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2023-01-19
 *
 */

/**
 * @brief Challenge 20.3
 * Challenge 3 - word counter
 * Using std::set and std::map
 *
 * This challenge has 2 parts.
 * We will be reading words from a text file provided to you.
 * The text file is named 'words.txt' and contains the fist few
 * paragraphs from the book, "The Wonderful Wizard of Oz", by
 * L. Frank Baum.
 *
 * Part 1:
 *
 * For part 1 of this challenge, you are to display each unique word
 * in the file and immediately following each word display the number
 * of time it occurs in the text file.
 *
 * The words should be displayed in ascending order.
 *
 * Here is a sample listing of the first few words:
 *
 * Word         Count
 * ===================
 * Aunt          5
 * Dorothy       8
 * Dorothy's     1
 * Em            5
 * Even          1
 * From          1
 *
 * Please use a map with <string, int> Key/ Value pairs
 *
 * ============================================
 * Part 2:
 *
 * For part 2 of this challenge, you are to display each unique word
 * in the file and immediately following each word display the line numbers
 * in which that word appears.
 *
 * The words should be displayed in ascending order and the line numbers for
 * each word should also be displayed in ascending order.
 * If a word appears more than once on a line then the line number should
 * only appear once.
 *
 * Here is a sample listing of the first few words:
 *
 * Word       Occurrences
 * ============================
 * Aunt            [ 2 7 25 29 48 ]
 * Dorothy      [ 1 7 15 29 39 43 47 51 ]
 * Dorothy's   [ 31 ]
 * Em              [ 2 7 25 30 48 ]
 * Even           [ 19 ]
 * From          [ 50 ]
 *
 * Please use a map of <string,set<int>> Key/Value pairs
 *
 * Hint: consider using stringstream to process words
 * once you read in a line from the file.
 *
 * Note: I have provided the basic shell for your program.
 * I have also provided the functions that display the maps
 * as well as the function that cleans the words read.
 * You should call the clean_string function for every word
 * you read from the file.
 *
 *
 */

#include "udemy1.hpp"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>

namespace udemy1::s20c3
{
// Used for Part1
// Display the word and count from the
// std::map<std::string, int>

void display_words(const std::map<std::string, int>& words)
{
    std::cout << std::setw(12) << std::left << "\nWord" << std::setw(7) << std::right << "Count" << std::endl;
    std::cout << "===================" << std::endl;
    for (auto pair : words)
        std::cout << std::setw(12) << std::left << pair.first << std::setw(7) << std::right << pair.second << std::endl;
}

// Used for Part2
// Display the word and occurences from the
// std::map<std::string, std::set<int>>

void display_words(const std::map<std::string, std::set<int>>& words)
{
    std::cout << std::setw(12) << std::left << "\nWord"
              << "Occurrences" << std::endl;
    std::cout << "=====================================================================" << std::endl;
    for (auto pair : words) {
        std::cout << std::setw(12) << std::left << pair.first << std::left << "[ ";
        for (auto i : pair.second)
            std::cout << i << " ";
        std::cout << "]" << std::endl;
    }
}

// This function removes periods, commas, semicolons and colon in
// a string and returns the clean version
std::string clean_string(const std::string& s)
{
    std::string result;
    for (char c : s) {
        if (c == '.' || c == ',' || c == ';' || c == ':')
            continue;
        else
            result += c;
    }
    return result;
}

// Part1 process the file and builds a map of words and the
// number of times they occur in the file

void part1(std::string filename)
{
    std::ifstream in_file{filename};
    if (!in_file) {
        std::cerr << "Error opening input file" << std::endl;
        return;
    }

    std::map<std::string, int> words;
    std::string line;
    std::string word;

    while (in_file >> word)
        ++words[clean_string(word)];

    in_file.close();
    display_words(words);
}

// Part2 process the file and builds a map of words and a
// set of line numbers in which the word appears
void part2(std::string filename)
{
    std::map<std::string, std::set<int>> words;
    std::string line;
    std::string word;
    std::ifstream in_file{filename};
    std::stringstream ss;
    if (!in_file) {
        std::cerr << "Error opening input file" << std::endl;
        return;
    }

    unsigned int line_no{0};
    while (std::getline(in_file, line)) {
        ++line_no;
        ss.str(line);
        while (ss >> word)
            words[clean_string(word)].insert(line_no);
        ss.clear();
    }

    // You implement this code

    in_file.close();
    display_words(words);
}

} // namespace udemy1::s20c3

void udemy1::s20c3_run(void)
{
    std::string filename{"../../data/s20c3_words.txt"};

    // display each unique word and word count
    udemy1::s20c3::part1(filename);

    // display each unique word, displayed in ascending order and the line numbers
    udemy1::s20c3::part2(filename);
}
