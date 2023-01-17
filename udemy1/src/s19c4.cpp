/**
 * Copyright © 2023 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : s19c4.cpp
 * Desc : Section 19: Stream manipulator challenge 4
 *
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2023-01-07
 *
 */

#include "udemy1.hpp"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

/**
 * @brief Challenge 20.1
 *
 * Challenge 1
 * Palindrome
 *
 * This challenge should be pretty easy.
 * I have provided the text to Romeo and Juliet in a file named romeoandjuliet.txt
 *
 * For this challenge you have to make copy of the Romeo and Juliet file and save it to another file.
 * This new copy should have line numbers at the beginning of each line in the play.
 * Please format the numbers nicely so everything lines up.
 *
 * Feel free to extend this challenge in any way you like.
 * For example, you may want to provide line numbers only for lines that actually have text
 *
 */

namespace udemy1::s19c4
{

void copy_file_with_lineno(std::string src, std::string dest, bool empty_line_number)
{
    std::ifstream ifs{src};
    std::ofstream ofs{dest};
    if (!ifs) {
        std::cerr << " Error opening file" << std::endl;
        return;
    }
    if (!ifs) {
        std::cerr << " Error creating file" << std::endl;
        ifs.close();
        return;
    }

    std::string line{""};
    unsigned int line_number{0};

    while (std::getline(ifs, line)) {
        if ((line == "\r")     // mac and dos
            || (line == "")) { // unix
            if (empty_line_number)
                ofs << std::setw(7) << std::left << ++line_number;
            ofs << std::endl;
        } else
            ofs << std::setw(7) << std::left << ++line_number << line << std::endl;
    }
    ifs.close();
    ofs.close();
    std::cout << "File copied with line nubmers." << std::endl;
}

bool process_choice(std::string choice)
{
    if (choice.length() == 0)
        return false;

    bool retVal{true};
    char c{choice.at(0)};
    switch (c) {
    case 'Y':
    case 'y': retVal = true; break;
    default: retVal = false; break;
    }

    return retVal;
}

} // namespace udemy1::s19c4

void udemy1::s19c4_run(void)
{
    std::string source_file{"../../data/romeoandjuliet_unix.txt"};
    std::string destination_file{"../../data/romeoandjuliet_lineno.txt"};
    std::string choice{"Y"};
    std::cout << "Do you wish to empty line numbers? (y/N)";
    std::cin >> choice;
    s19c4::copy_file_with_lineno(source_file, destination_file, s19c4::process_choice(choice));
}
