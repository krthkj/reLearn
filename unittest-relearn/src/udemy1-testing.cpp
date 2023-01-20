//#include "udemy1-testing.hpp"
#include "udemy1.hpp"

#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

TEST(udemy_s4c, valid_values)
{
    std::stringstream ss_out;
    std::streambuf* orig_cout = std::cout.rdbuf(ss_out.rdbuf());

    std::stringstream ss_in;
    std::streambuf* orig_cin = std::cin.rdbuf(ss_in.rdbuf());

    ss_in << 10;
    udemy1::s4c_run();

    std::cin.rdbuf(orig_cin);
    std::cout.rdbuf(orig_cout);

    std::string result{"Enter your favourite number between 1 and 100: "};
    result += "Amazing!! That's my favourite number too!\n";
    result += "no really!!, 10 is my favourite number!\n";

    EXPECT_EQ(ss_out.str(), result);
}

TEST(udemy_s4c, lower_bound)
{
    std::stringstream ss_out;
    std::streambuf* orig_cout = std::cout.rdbuf(ss_out.rdbuf());

    std::stringstream ss_in;
    std::streambuf* orig_cin = std::cin.rdbuf(ss_in.rdbuf());

    ss_in << -10 << " " << 50;
    udemy1::s4c_run();

    std::cin.rdbuf(orig_cin);
    std::cout.rdbuf(orig_cout);

    std::string result{"Enter your favourite number between 1 and 100: "};
    result += "Enter your favourite number between 1 and 100: ";
    result += "Amazing!! That's my favourite number too!\n";
    result += "no really!!, 50 is my favourite number!\n";

    EXPECT_EQ(ss_out.str(), result);
}

TEST(udemy_s6c, valid)
{
    std::stringstream ss_out;
    std::streambuf* orig_cout = std::cout.rdbuf(ss_out.rdbuf());

    std::stringstream ss_in;
    std::streambuf* orig_cin = std::cin.rdbuf(ss_in.rdbuf());

    ss_in << 4 << " " << 8;
    udemy1::s6c_run();

    std::cin.rdbuf(orig_cin);
    std::cout.rdbuf(orig_cout);

    std::string result{"Hello, welcome to Frank's Carpet Cleaning Service\n"};
    result += "How many small rooms would you like cleaned? How many large rooms would you like cleaned? \n";
    result += "Estimate for carpet cleaning service\nNumber of small rooms: 4\n";
    result += "Number of large rooms: 8\n";
    result += "Price per small room: $25\n";
    result += "Price per large room: $35\n";
    result += "Cost: $380\n";
    result += "Tax: $22.8\n";
    result += "====================================\n";
    result += "Total estimate: $402.8\n";
    result += "This estimate is valid for 30 days\n";

    EXPECT_EQ(ss_out.str(), result);
}

TEST(udemy_s7c, valid_values)
{
    // capture cout
    std::stringstream ss_out;
    std::streambuf* orig_cout = std::cout.rdbuf(ss_out.rdbuf());

    // simulate user input to cin
    // std::stringstream ss_in;
    // std::streambuf* orig_cin = std::cin.rdbuf(ss_in.rdbuf());

    // ss_in << input_value_int_float_string;
    udemy1::s7c_run();

    // std::cin.rdbuf(orig_cin);
    std::cout.rdbuf(orig_cout);

    std::string result{"vector1: \n10\n20\n"};
    result += "vector1 contains 2 elements \n\n";
    result += "vector2: \n100\n200\n";
    result += "vector2 contains 2 elements \n\n";
    result += "vector_2d: \n10, 20\n200, 200\n";
    result += "vector_2d contains 2 elements \n\n";
    result += "vector1.at(0) = 1000\n\n";
    result += "vector_2d: \n10, 20\n200, 200\n\n";
    result += "vector1: \n1000\n20\n";

    EXPECT_EQ(ss_out.str(), result);
}

TEST(udemy_s8c, valid_values)
{
    // capture cout
    std::stringstream ss_out;
    std::streambuf* orig_cout = std::cout.rdbuf(ss_out.rdbuf());

    // simulate user input to cin
    std::stringstream ss_in;
    std::streambuf* orig_cin = std::cin.rdbuf(ss_in.rdbuf());

    ss_in << 141;
    udemy1::s8c_run();

    std::cin.rdbuf(orig_cin);
    std::cout.rdbuf(orig_cout);

    std::string result{"Enter an amount in cents: You can provide this change as follows:\ndollars  : 1\nquarters : "
                       "1\ndime     : 1\nnickel   : 1\npennies  : 1\n"};

    EXPECT_EQ(ss_out.str(), result);
}

/*
// Template
TEST(udemy_s4c, valid_values)
{
    // capture cout
    std::stringstream ss_out;
    std::streambuf* orig_cout = std::cout.rdbuf(ss_out.rdbuf());

    // simulate user input to cin
    std::stringstream ss_in;
    std::streambuf* orig_cin = std::cin.rdbuf(ss_in.rdbuf());

    ss_in << input_value_int_float_string;
    cin_cout_based_function_to_test();

    std::cin.rdbuf(orig_cin);
    std::cout.rdbuf(orig_cout);

    std::string result{"RESULT STRING GOES HERE"};

    EXPECT_EQ(ss_out.str(), result);
}
*/
