/**
 * Copyright © 2022 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : e11.cpp
 * Desc : Section 11 Challenge from Udemy course "Beginning C++ Programming - From Beginner to Beyond"
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2022-12-01
 *
 */

#include "udemy1.hpp"

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>

namespace udemy1
{

/******************************************************************************/

/**
 * @brief Random numbers Example
 */
void random_nums(void)
{

    int random_number{};
    size_t count{10}; // number of random numbers to generate
    int min{1};       // lower bound (inclusive)
    int max{6};       // upper bound (inclusive)

    // seed the random number generator
    // If you don't seed the generator you will get the same requence random numbers every run

    std::cout << "RAND_MAX on my system is: " << RAND_MAX << std::endl;

    // use current time as seed for random generator
    // std::time needs <ctime>
    // std::srand needs <cstdlib>
    std::srand(std::time(nullptr));

    for (size_t i{1}; i <= count; ++i) {
        random_number = std::rand() % max + min; // generate a random number [min, max]
        std::cout << random_number << std::endl;
    }

    std::cout << std::endl;
}

/******************************************************************************/

/**
 * @brief Default arguments prototype
 */
double calc_cost(double base = 100, double tax = 0.06, double ship = 3.5);

/**
 * @brief arguments prototype Example
 */
double calc_cost(double base_cost, double tax_rate, double shipping)
{
    return base_cost += (base_cost * tax_rate) + shipping;
}

void run_default_args(void)
{
    std::cout << " Default arguments Ex1: " << calc_cost(100, 0.06, 3.5) << std::endl;
    std::cout << " Default arguments Ex2: " << calc_cost(100, 0.06) << std::endl;
    std::cout << " Default arguments Ex3: " << calc_cost(100) << std::endl;
    std::cout << " Default arguments Ex3: " << calc_cost() << std::endl;
}

/******************************************************************************/
/**
 * @brief function overloading example
 */
void print(int);
void print(double);
void print(std::string);
void print(std::string, std::string);
void print(std::vector<std::string>);

void print(int num)
{
    std::cout << "Printing int: " << num << std::endl;
}

void print(double num)
{
    std::cout << "Printing double: " << num << std::endl;
}

void print(std::string s)
{
    std::cout << "Printing string: " << s << std::endl;
}

void print(std::string s, std::string t)
{
    std::cout << "Printing 2 strings: " << s << " and " << t << std::endl;
}

void print(std::vector<std::string> v)
{
    std::cout << "Printing vector of strings: ";
    for (auto s : v)
        std::cout << s + " ";
    std::cout << std::endl;
}

void run_func_overloading()
{
    print(100); // int
    print('A'); //  character is always promoted to int should print 65 ASCII ('A')

    print(123.5);  // double
    print(123.3F); // Float is promoted to double

    print("C-style string"); // C-style string is converted to a C++ string

    std::string s{"C++ string"};
    print(s); // C++ string

    print("C-style string", s); // First argument is converted to a C++ string

    std::vector<std::string> three_stooges{"Larry", "Moe", "Curly"};
    print(three_stooges);

    std::cout << std::endl;
}

/******************************************************************************/

/**
 * @brief Example of passing array to functions
 */

void print_array(const int arr[], size_t size);
void set_array(int arr[], size_t size, int value);

void print_array(const int arr[], size_t size) // const
{

    for (size_t i{0}; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    //     arr[0] = 50000; // bug
}

// set each array element to value
void set_array(int arr[], size_t size, int value)
{
    for (size_t i{0}; i < size; ++i)
        arr[i] = value;
}

void run_array_to_func(void)
{
    int my_scores[]{100, 98, 90, 86, 84};

    print_array(my_scores, 5);
    set_array(my_scores, 5, 100);
    print_array(my_scores, 5);
    print_array(my_scores, 5);

    std::cout << std::endl;
}

/******************************************************************************/

/**
 * @brief Passing Arrays to Functions - Print a Guest List
 */

std::string print_guest_list(const std::string[], size_t);
void clear_guest_list(std::string[], size_t);

void event_guest_list(void)
{

    std::string guest_list[]{"Larry", "Moe", "Curly"};
    size_t guest_list_size{3};

    print_guest_list(guest_list, guest_list_size);
    clear_guest_list(guest_list, guest_list_size);
    print_guest_list(guest_list, guest_list_size);
}

std::string print_guest_list(const std::string guest_list[], size_t guest_list_size)
{

    for (size_t i{0}; i < guest_list_size; ++i)
        std::cout << guest_list[i] << std::endl;

    return typeid(guest_list).name();
}

void clear_guest_list(std::string guest_list[], size_t value)
{
    for (size_t i{0}; i < value; ++i)
        guest_list[i] = " ";
}

/******************************************************************************/

/**
 * @brief Pass by reference examples
 */
void pass_by_ref1(int& num);
void pass_by_ref2(std::string& s);
void pass_by_ref3(std::vector<std::string>& v);
void print_vector(const std::vector<std::string>& v); // const

void pass_by_ref1(int& num)
{
    num = 1000;
}

void pass_by_ref2(std::string& s)
{
    s = "Changed";
}

void pass_by_ref3(std::vector<std::string>& v)
{
    v.clear(); // delete all std::vector elements
}

void print_vector(const std::vector<std::string>& v)
{
    for (auto s : v)
        std::cout << s << " ";
    std::cout << std::endl;
}

void run_pass_by_ref(void)
{
    int num{10};
    int another_num{20};

    std::cout << "num before calling pass_by_ref1: " << num << std::endl;
    pass_by_ref1(num);
    std::cout << "num after calling pass_by_ref1: " << num << std::endl;

    std::cout << std::endl << "another_num before calling pass_by_ref1 : " << another_num << std::endl;
    pass_by_ref1(another_num);
    std::cout << "another_num after calling pass_by_ref1: " << another_num << std::endl;

    std::string name{"Frank"};
    std::cout << std::endl << "name before calling pass_by_ref2: " << name << std::endl;
    pass_by_ref2(name);
    std::cout << "name after calling pass_by_ref2: " << name << std::endl;

    std::vector<std::string> stooges{"Larry", "Moe", "Curly"};
    std::cout << std::endl << "stooges before calling pass_by_ref3: ";
    print_vector(stooges);
    pass_by_ref3(stooges);
    std::cout << "stooges after calling pass_by_ref3: ";
    print_vector(stooges);

    std::cout << std::endl;
}

/******************************************************************************/

/**
 * @brief C++ scope variables
 */
void local_example();
void global_example();
void static_local_example();

int num{300}; // Global variable - declared outside any class or function

void global_example()
{
    std::cout << std::endl << "Global num is: " << num << " in global_example - start" << std::endl;
    num *= 2;
    std::cout << "Global num is: " << num << " in global_example - end" << std::endl;
}

void local_example(int x)
{
    int num{1000}; // local to local_example
    std::cout << std::endl << "Local num is: " << num << " in local_example - start" << std::endl;
    num = x;
    std::cout << "Local num is: " << num << " in local_example - end" << std::endl;
    // num1 in main is not within scope - so it can't be used here.
}

void static_local_example()
{
    /**
     * @brief static variable are initialized only once, when they are frist called. in this fucntion, num is only
     * initialized to '5000' when the function is first called variable, subsequent calls to the function will not
     * reinitialize the value to '5000', instead it retains the previous value and behaves like a global variable     *
     */

    static int num{5000}; // local to static_local_example static - retains it value between calls
    std::cout << std::endl << "Local static  num is: " << num << " in static_local_example - start" << std::endl;
    num += 1000;
    std::cout << "Local static  num is: " << num << " in static_local_example - end" << std::endl;
}

void run_scope_variables(void)
{

    int num{100};  // Local to main
    int num1{500}; // Local to main

    std::cout << "Local num is : " << num << " in main" << std::endl;

    {                 // creates a new level of scope
        int num{200}; // local to this inner block
        std::cout << "Local num is: " << num << " in inner block in main" << std::endl;
        std::cout << "Inner block in main can see out - num1 is: " << num1 << std::endl;
    }

    std::cout << "Local num is : " << num << " in main" << std::endl;

    local_example(10);
    local_example(20);

    global_example();
    global_example();

    static_local_example();
    //    static_local_example();
    //    static_local_example();

    std::cout << std::endl;
}

/******************************************************************************/

/**
 * @brief Example of function call
 *
 * How memory is layed out
 *
 * +-------------------------------+
 * |                               |
 * |             heap              |
 * |         (free store)          |
 * |                               |
 * +-------------------------------+
 * |                               |  }
 * |       Stack                   |  } This area is where funtion call stack stored
 * |  (function calls &            |  }
 * |     local variabes)           |  }
 * |                               |  }
 * +-------------------------------+
 * |                               |
 * |      static/Global            |
 * |        variables              |
 * |                               |
 * +-------------------------------+
 * |                               |
 * |     code area                 |
 * |                               |
 * +-------------------------------+
 *
 * Video: https://youtu.be/_8-ht2AKyH4
 * Note:
 * - Size of stack frame and local variables is defined at compile time.
 * - Allocation of memory for stack frame and local variables occur during runtime.
 *
 *
 * What typically happens when main calls func1 (or any function calls another) ?
 * There are other ways to acheive the same results :)
 *
 *  main:
 *      push space for the return value
 *      push space for the parameters
 *      push the return address
 *      transfer control to func1 (jmp)
 *  func1:
 *      push the address of the previous activation record
 *      push any register values that will need to be restored before returning to the caller
 *      perform the code in func1
 *      restore the register values
 *      restore the previous activation record (move the stack pointer)
 *      store any function result
 *      transfer control to the return address (jmp)
 *  main:
 *      pop the parameters
 *      pop the return value
 *
 *
 *
 */

void func2(int& x, int y, int z)
{
    x += y + z;
}

int func1(int a, int b)
{
    int result{};
    result = a + b;
    func2(result, a, b);
    return result;
}

void run_func_stack(void)
{
    int x{10};
    int y{20};
    int z{};
    z = func1(x, y);
    std::cout << z << std::endl;
}

/******************************************************************************/
/**
 * @brief Example of Inline function
 * - Modern compilers automatically optimize functions using 'inline' without users suggestion.
 * - declared in header or .h files
 */
inline int add_num(int a, int b)
{
    return a + b;
}

/******************************************************************************/
/**
 * @brief Example of recursive function
 *
 */

unsigned long long my_factorial(unsigned long long n)
{
    if (n == 0)
        return 1;
    return n * my_factorial(n - 1);
}

unsigned long long my_fibonacci(unsigned long long n)
{
    if (n <= 1)
        return n;
    return my_fibonacci(n - 1) + my_fibonacci(n - 2);
}

void run_recursive(void)
{
    std::cout << "factorial(3): " << my_factorial(3) << std::endl;
    std::cout << "factorial(8): " << my_factorial(8) << std::endl;
    std::cout << "factorial(12): " << my_factorial(12) << std::endl;
    std::cout << "factorial(20): " << my_factorial(20) << std::endl;
    std::cout << "factorial(40): " << my_factorial(40) << std::endl;

    std::cout << "fibonacci(5): " << my_fibonacci(5) << std::endl;
    std::cout << "fibonacci(30): " << my_fibonacci(30) << std::endl;
    std::cout << "fibonacci(40): " << my_fibonacci(40) << std::endl;
    //    std::cout << "fibonacci(80): " << my_fibonacci(80) << std::endl;
}

/******************************************************************************/
/**
 * @brief Implementing a Recursive Function - Save a Penny
 */
int function_activation_count{0};

double a_penny_doubled_everyday(int, double amount = 0.01);

void run_amount_accumulated(void)
{
    double total_amount = a_penny_doubled_everyday(25);
    // header <iomanip> is required for std::setprecision()
    std::cout << "If I start with a penny and doubled it every day for 25 days, I will have $" << std::setprecision(10)
              << total_amount << std::endl;
}

double a_penny_doubled_everyday(int n, double amount)
{
    function_activation_count++;
    if (n <= 1)
        return amount;
    return a_penny_doubled_everyday(--n, amount * 2);
}

int test_function_activation_count()
{
    return function_activation_count;
}

/******************************************************************************/

/**
 * @brief aggregate of all the functions in the section
 */
void e11_run(void)
{
    // random_nums();
    // run_default_args();
    // run_func_overloading();
    // run_array_to_func();
    // run_pass_by_ref();
    // run_scope_variables();
    // run_func_stack();
    // run_recursive();
    // run_amount_accumulated();
}

} // namespace udemy1
