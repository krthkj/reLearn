/**
 * Copyright © 2023 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : s19c1.cpp
 * Desc : Section 19: Stream manipulator challenge 1
 *
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2023-01-07
 *
 */

#include "udemy1.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

namespace udemy1
{

/**
 * @brief Challenge 19.1
 *
 * Formatting output
 * ===========================================================
 * I have provided you with the starter source code for this challenge.
 * In this challenge you are to display the provided data in a nicely formatted table.
 * Your table does not have to match mine, but practice with the format manipulators
 * so you become comfortable with them.
 *
 * There are 3 structures provided. Yes, these could also be classes with public data,
 * but it's common to use structures when we simply want to model only data and not
 * operations as we would with classes.
 *
 * The structures work together to create a Tours structure that will contain
 * information about Tours to South America.
 * The Tours include Countries, Cities within those countries along with population and cost data for
 * each city tour.
 * I know, population? Huh? I just wanted a big number so that you can format it, OK :)
 *
 * Please watch the Challenge video for the expected output. It won't look right if I put it in this
 * editor because of the font style.
 *
 * In the provided source code I'm giving you some code that displays the data from the structures
 * and the vectors within the structures. This code uses tabs to format the data and it looks pretty ugly.
 *
 */

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

void s19c1_run(void)
{
    Tours tours
    {"Tour Ticket Prices from Miami",
         {
             {"Colombia",{
                 {"Bogota", 8778000, 400.98},
                 {"Cali", 2401000, 424.12},
                 {"Medellin", 2464000, 350.98},
                 {"Cartagena", 972000, 345.34}},
             },
             {"Brazil",{
                 {"Rio De Janiero", 13500000, 567.45},
                 {"Sao Paulo", 11310000, 975.45},
                 {"Salvador", 18234000, 855.99}},
             },
             {"Chile",{
                 {"Valdivia", 260000, 569.12},
                 {"Santiago", 7040000, 520.00}},
             },
             {"Argentina",{
                 {"Buenos Aires", 3010000, 723.77}}
             },
         }
    };

    // Unformatted display so you can see how to access the vector elements
    std::string ruler{"1234567890123456789012345678901234567890123456789012345678901234567890"};

    int field1_width{0}, field2_width{0}, field3_width{0}, field4_width{0};

    field1_width = ruler.length() * 0.25;
    field2_width = ruler.length() * 0.3;
    field3_width = ruler.length() * 0.25;
    field4_width = ruler.length() * 0.20;

    int total_width{field1_width + field2_width + field3_width + field4_width};

    std::cout << ruler << std::endl;

    std::cout << std::endl;
    std::cout << std::setw((total_width + tours.title.length()) / 2) << std::right << tours.title << std::endl;
    std::cout << std::endl;

    std::cout << std::setw(field1_width) << std::left << "Country";
    std::cout << std::setw(field2_width) << std::left << "City";
    std::cout << std::setw(field3_width) << std::right << "Population";
    std::cout << std::setw(field4_width) << std::right << "Price" << std::endl;

    std::cout << std::setfill('-') << std::setw(total_width) << "" << std::endl;
    std::cout << std::setfill(' '); // reset fill
    std::cout << std::setprecision(2) << std::fixed;

    for (auto country : tours.countries) {                  // loop through the countries
        for (size_t i{0}; i < country.cities.size(); ++i) { // loop through cities
            std::cout << std::setw(field1_width) << std::left << ((i == 0) ? country.name : "");
            std::cout << std::setw(field2_width) << std::left << country.cities.at(i).name;
            std::cout << std::setw(field3_width) << std::right << country.cities.at(i).population;
            std::cout << std::setw(field4_width) << std::right << country.cities.at(i).cost << std::endl;
        }
    }
    std::cout << std::endl << std::endl;
}

} // namespace udemy1
