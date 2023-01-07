/**
 * Copyright © 2023 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : s19c2.cpp
 * Desc : Section 19: Stream manipulator challenge 2
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
#include <memory>
#include <vector>

/**
 * @brief Challenge 19.2
 *
 * Challenge 2
 * Automated Grader
 *
 * Write a program that reads a file named 'responses.txt" that contains the answer key for a quiz
 * as well as student responses for the quiz.
 *
 * The answer key is the first item in the file.
 * Student1 name
 * Student1 responses
 * Student2 name
 * Student2 responses
 * . . .
 *
 * Here is a sample file.
 *
 * ABCDE
 * Frank
 * ABCDE
 * Larry
 * ABCAC
 * Moe
 * BBCDE
 * Curly
 * BBAAE
 * Michael
 * BBCDE
 *
 * You should read the file and display:
 * Each student's name and score (#correct out of 5)
 * At the end, the class average should be displayed
 * You may assume that the data in the file is properly formatted
 *
 * Program should output to the console the following:
 * Student                Score
 * ----------------------------
 * Frank                      5
 * Larry                      3
 * Moe                        4
 * Curly                      2
 * Michael                    4
 * ----------------------------
 * Average score            3.6
 *
 */

namespace udemy1::s19c2
{

void header(void)
{
    std::cout << std::setw(15) << std::left << "Student";
    std::cout << std::setw(5) << std::right << "Score" << std::endl;
    std::cout << std::setw(20) << std::setfill('-') << "" << std::setfill(' ') << std::endl;
}

void footer(double average)
{
    // Footer
    std::cout << std::setw(20) << std::setfill('-') << "" << std::setfill(' ') << std::endl;
    std::cout << std::setw(15) << std::left << "Average score";
    std::cout << std::setw(5) << std::right << std::setprecision(1) << std::fixed << average << std::endl;
    std::cout << std::setprecision(6);
    std::cout.unsetf(std::ios::fixed);
}

int auto_grader(std::string ans_key, std::string resp)
{
    int val{0};
    if((ans_key.length() != resp.length()) || resp.length() == 0 || ans_key.length() == 0)
        return val;
    for(size_t i{0}; i < ans_key.length(); ++i)
        if(ans_key.at(i) == resp.at(i))
            ++val;
    // std::cout << ans_key << " == " << resp << " Score:" << val << std::endl;
    return val;
}

namespace style1
{
struct StudentData {
    std::string name;
    int score;

    StudentData(std::string n, int s)
        : name{n}
        , score{s}
    {
    }
};

// prototype
void process_file(std::string file_name);

void display_grade(std::vector<std::shared_ptr<StudentData>> vec);
double average_grade(std::vector<std::shared_ptr<StudentData>> vec);

// implimentation
void process_file(std::string file_name)
{
    std::ifstream ifs{file_name};
    if(!ifs)
        std::cerr << "File Open Error" << std::endl;
    else {
        header(); // Header
        std::string name{};
        std::string grade{};
        std::string answer_key{};
        auto s_data = std::make_unique<std::vector<std::shared_ptr<StudentData>>>();
        ifs >> answer_key;
        while(ifs >> name >> grade)
            (*s_data).push_back(std::make_shared<StudentData>(name, auto_grader(answer_key, grade)));
        display_grade(*s_data);
        footer(average_grade(*s_data)); // footer
        std::cout << std::endl;
        ifs.close();
    }
}

void display_grade(std::vector<std::shared_ptr<StudentData>> vec)
{
    for(const auto& v : vec) {
        std::cout << std::setw(15) << std::left << (*v).name;
        std::cout << std::setw(5) << std::right << std::setprecision(1) << std::fixed << (*v).score << std::endl;
    }
}
double average_grade(std::vector<std::shared_ptr<StudentData>> vec)
{
    double val{0.0};
    if(vec.size() == 0)
        return 0;
    for(const auto& v : vec)
        val += (*v).score;
    return val / vec.size();
}

} // namespace style1

namespace style2
{

void display_grade(std::string name, int score)
{
    std::cout << std::setw(15) << std::left << name;
    std::cout << std::setw(5) << std::right << std::setprecision(1) << std::fixed << score << std::endl;
    std::cout << std::setprecision(6);
    std::cout.unsetf(std::ios::fixed);
}

void process_file(std::string file_name)
{
    std::ifstream ifs{file_name};
    if(!ifs)
        std::cerr << "File Open Error" << std::endl;
    else {
        header(); // Header
        std::string name{};
        std::string grade{};
        std::string answer_key{};
        int students{0}, sum_score{0};
        ifs >> answer_key;
        while(ifs >> name >> grade) {
            int score{auto_grader(answer_key, grade)};
            display_grade(name, score);
            sum_score += score;
            ++students;
        }
        if(students != 0)
            footer(static_cast<double>(sum_score) / students); // footer
        std::cout << std::endl;
        ifs.close();
    }
}

} // namespace style2

} // namespace udemy1::s19c2

void udemy1::s19c2_run(void)
{
    std::string response_file{"../../data/s19c2_responses.txt"};
    udemy1::s19c2::style1::process_file(response_file);
    std::cout << std::endl;
    udemy1::s19c2::style2::process_file(response_file);
}
