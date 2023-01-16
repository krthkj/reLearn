/**
 * Copyright © 2023 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : s17c.cpp
 * Desc : Section 17: Smart pointer
 *
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2023-01-06
 *
 */

#include "udemy1.hpp"

#include <iostream>
#include <memory>
#include <vector>

namespace udemy1
{

/*
 * Create a program that has the following:
 *
 * 1. a function named make that creates and returns a unique_ptr to a vector of shared_ptrs to Test objects.
 *
 * 2. a function named fill that expects a vector of shared pointers to Test objects and a int
 *    representing the number of Test objects to create dynamically and add to the vector.
 *
 *    This function will prompt the user to enter an integer, create a shared_ptr to a Test object
 *    initialized to the entered integer and add that shared pointer to the vector.
 *
 * 3. a function named display that expects a vector of shared_ptrs to Test object and displays the
 *    data in each Test object
 *
 * 4. The main driver should look as follows
 *
 *     int main() {
 *         std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
 *         vec_ptr = make();
 *         std::cout << "How many data points do you want to enter: ";
 *         int num;
 *         std::cin >> num;
 *         fill(*vec_ptr, num);
 *         display(*vec_ptr);
 *         return 0;
 *     }
 *
 * Below is a sample run for the user entering 3 at the console:
 *
 * How many data points do you want to enter: 3
 * Enter data point [1] : 10
 *         Test constructor (10)
 * Enter data point [2] : 20
 *         Test constructor (20)
 * Enter data point [3] : 30
 *         Test constructor (30)
 * Displaying vector data
 * =======================
 * 10
 * 20
 * 30
 * =======================
 *         Test destructor (10)
 *         Test destructor (20)
 *         Test destructor (30)
 *
 */

class Test
{
  private:
    int data;

  public:
    Test(int x = 0);
    ~Test();

    int get_data() const;
};

auto make()
{
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>>& vec, int num)
{
    int tmp;
    for (int i{0}; i < num;) {
        std::cout << "Enter data point [" << ++i << "] : ";
        std::cin >> tmp;
        vec.push_back(std::make_shared<Test>(tmp));
    }
}

void display(const std::vector<std::shared_ptr<Test>>& vec)
{
    std::cout << "Displaying vector data" << std::endl << "=======================" << std::endl;
    for (const auto& v : vec) {
        std::cout << v->get_data() << std::endl;
        // std::cout << "Use count: " << v.use_count() << std::endl;
    }
    std::cout << "=======================" << std::endl;
}

void s17c_run(void)
{

    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
}

Test::Test(int x)
    : data{x}
{
    std::cout << "\tTest Constructor (" << data << ")" << std::endl;
}

Test::~Test()
{
    std::cout << "\tTest Destructor (" << data << ")" << std::endl;
}

int Test::get_data() const
{
    return data;
}

} // namespace udemy1
