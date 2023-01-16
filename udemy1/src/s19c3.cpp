/**
 * Copyright © 2023 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : s19c3.cpp
 * Desc : Section 19: Stream manipulator challenge 3
 *
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2023-01-07
 *
 */

#include "udemy1.hpp"

#include <fstream>
#include <iostream>
#include <string>

/**
 * @brief Challenge 19.3
 *
 * Challenge 3
 * Word finder
 *
 * Ask the user to enter a word
 * Process the Romeo and Juliet file and determine how many total words there are
 * and how many times the word the user entered appears as a substring of a word in the play.
 *
 * For example.
 * If the user enters: love
 * Then the words love, lovely, and beloved will all be considered matches.
 * You decide whether you want to be case sensitive or not. My solution is case sensitive
 *
 * Sample are some sample runs:
 *
 * Enter the substring to search for: love
 * 25919 words were searched...
 * The substring love was found 171 times
 *
 * Enter the substring to search for: Romeo
 * 25919 words were searched...
 * The substring Romeo was found 132 times
 *
 * Enter the substring to search for: Juliet
 * 25919 words were searched...
 * The substring Juliet was found 49 times
 *
 * Enter the substring to search for: Frank
 * 25919 words were searched...
 * The substring Frank was found 0 times
 *
 */
namespace udemy1::s19c3
{

bool find_substring(const std::string& word, const std::string& target)
{
    return (word.find(target) == std::string::npos) ? false : true;
}

int find_word_count(std::string file_name, std::string target_word)
{
    int match_count{0};
    std::ifstream ifs{file_name};
    if (!ifs)
        std::cerr << "File open error." << std::endl;
    else {
        int wc{0};
        std::string word_read{};
        while (ifs >> word_read) {
            ++wc;
            if (find_substring(word_read, target_word))
                ++match_count;
        }
        std::cout << wc << " words were searched..." << std::endl;
        ifs.close();
    }
    return match_count;
}

} // namespace udemy1::s19c3

void udemy1::s19c3_run(void)
{
    std::string file_name{"../../data/romeoandjuliet_unix.txt"};
    std::cout << "Enter the substring to search for: ";

    std::string word;
    std::cin >> word;
    int word_count{s19c3::find_word_count(file_name, word)};

    std::cout << "The substring " << word << " was found " << word_count << " times" << std::endl;
}
