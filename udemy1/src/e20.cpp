/**
 * Copyright © 2023 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT license, refer the license file supplied with the project.
 *
 * File : s20c.cpp
 * Desc : Section 20: Standard Template library
 *
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2023-01-08
 *
 */

/*******************************************************************************
 * STL - Standard template library
 *******************************************************************************
 * Generic/Meta programming
 * STL Container
 * STL Iterators
 * STL Algorithms
 *
 *******************************************************************************
 * What is STL?
 * - powerful, reusable, adaptable, generic classes and functions
 * - implemented using c++ template
 * - implements common data structures and algorithms
 * - huge class library
 *
 *******************************************************************************
 * Why use STL?
 * - assortment of commonly used containers
 * - known time and size complexity
 * - tried and tested - re-usability
 * - consistent, fast and type-safe
 * - extensible
 *
 *******************************************************************************
 * STL components
 * - Containers: containers of objects or primitive types
 *               (array, vector, deque, stack, set, map, etc..)
 * - Algorithms: Functions for processing sequence of elements from containers
 *               (find, max, count, accumulate, sort, etc..)
 * - Iterators: Generate sequences of elements from containers
 *               (forward, reverse, by value, by reference, constant, etc..)
 *
 *******************************************************************************
 * Containers typed
 * - Sequence container: array, vector, list, forward_list, deque
 * - Associative container: set, multi set, map, multi map
 * - Container Adapter: stack, queue, priority queue
 *
 *******************************************************************************
 * Iterators types
 * - input iterators: from the container to the program
 * - output iterators: from the program to the container
 * - forward iterators: navigate one item at a time in one direction
 * - Bi-directional iterators: navigate one item at a time both directions
 * - random access iterators: directly access a container item
 *
 *******************************************************************************
 * Algorithm types
 * - non-modifying type
 * - modifying type
 * There are about 60 algorithms in STL
 *
 *******************************************************************************
 * Generic Programming
 * - using Macros (*** dangerous ***)
 * - using function template
 * - using class template
 *
 *******************************************************************************
 * Generic Programming using Macros
 * - used extensively in legacy C++ code
 * - more extensively used in C-code.
 * - part of Pre-processor directives
 *
 *******************************************************************************
 * Macro (#define)
 * - C++ pre-processor directive
 * - No type information
 * - simple substitution by compiler
 * Example:
 *   #define MAX_SIZE 100         // no type associated with it
 *   #define PI 3.14159
 *   #define MAX(a,b) ((a>b)?a:b) // Macros with parameters
 *
 * Problems occurs, example:
 * #define SQUARE(a) a*a
 *
 * result = SQUARE(5);     // code written: expect 25
 * result = 5*5;           // after compiler substitutes: get 25
 *
 * result = 100/SQUARE(5); // code written: expect 4
 * result = 100/5*5;       // after compiler substitutes: got 100
 *
 * Solution to fix the problem: (wrap up arguments)
 * #define SQUARE(a) ((a)*(a)) //
 * result = 100/SQUARE(5);     // code written: expect 4
 * result = 100/((5)*(5));     // after compiler substitutes: got 4
 *
 *******************************************************************************
 * C++ Templates
 * - generic blueprint for function and class templates
 * - allows plugging-in any data type
 * - compiler generates the appropriate function/class from the blueprint
 * - Generic programming/meta-programming
 *
 * Note:
 * - C++ does it at compile time not at run-time, and helps with type-checking
 * - compiler writes actual function/classes
 * - concept is easy to understand, but templates can be very complex
 * - error messages provided by compiler can be difficult to understand
 * - code is not generated unless the user uses the specialized version of the template
 *
 *******************************************************************************
 * Function Template
 *
 * Example:
 * template <typename T>
 * T max (T a, T b) { return (a>b)?a:b; }
 *
 * template <typename T1,typename T2>
 * T max (T1 a, T2 b) { return (a>b)?a:b; }
 *
 * template <class T>
 * T max (T a, T b) { return (a>b)?a:b; }
 *
 * int a{10},b{25};
 * double c{2.45},d{12.3};
 * std::cout << max<int>(a,b);      // specialized version of max is generated for int
 * std::cout << max(a,b);           // Compiler determines the data-types automatically which id int
 * std::cout << max<double>(c,d);   // specialized version of max is generated for double
 * std::cout << max(c,d);           // Compiler determines the data-types automatically which is double
 * std::cout << max('A',100);       // used with two different template-type
 *
 *******************************************************************************
 * Class Template
 * - Similar to function template, but at the class level
 * - allow plugging-in any datatype
 * - compiler generates the appropriate class from blueprint
 * - can be very complex
 *
 * Note: Template classes are typically completely contained in header files.
 *
 *******************************************************************************
 * STL Containers
 * - Data structure can store object of almost any type: Template-based containers
 * - each container has member functions: some are specific to container and other are available to all containers
 * - each container has an associated header file : #include <container_type>
 *
 *******************************************************************************
 * +===============================================================================================+
 * |                                Common containers                                              |
 * +=============================+=================================================================+
 * | Function                    | Description                                                     |
 * +=============================+=================================================================+
 * | Default constructor         | initializes an empty container                                  |
 * | Overloaded constructor      | initializes containers with many options                        |
 * | Copy constructor            | Initializes a container as a copy of another container          |
 * | Move constructor            | Moves existing container to new container                       |
 * | Destructor                  | Destroys a container                                            |
 * | Copy assignment (operator=) | Copy one container to another                                   |
 * | Move assignment (operator=) | Move one container to another                                   |
 * | size                        | returns the number of elements in the container                 |
 * | empty                       | returns Boolean - is the container empty                        |
 * | insert                      | inserts an element into the container                           |
 * | operator< and operator<=    | returns Boolean - compare contents of 2 containers              |
 * | operator> and operator>=    | returns Boolean - compare contents of 2 containers              |
 * | operator== and operator!=   | returns Boolean - are the contents of 2 containers equal or not |
 * | swap                        | swap the elements of 2 containers                               |
 * | erase                       | remove element(s) from a container                              |
 * | clear                       | remove all elements from the container                          |
 * | begin and end               | returns iterators to first element or end                       |
 * | rbegin and rend             | returns reverse iterators to first element or end               |
 * | cbegin and cend             | returns constant iterators to first element or end              |
 * | crbegin and crend           | returns constant reverse iterators to first element or end      |
 * +=============================+=================================================================+
 *
 * Container elements **** Important Note ****
 * - A copy of the elements will be stored in the container: all primitives are okay
 * - elements should be: copy-able and assignable (copy constructor/copy assignment)
 *                       Movable for efficiency (move constructor/move assignment)
 * - Ordered associative containers must be able to compare elements : operator<, operator==
 *
 *******************************************************************************
 * STL Iterators
 * - Allows abstracting an arbitrary containers as a sequence of elements
 * - They are objects that work like pointers by design
 * - most container class can be traverses with iterators
 *
 * Declaring iterators: must be declared based on the container type they will iterate over
 *
 * Syntax:   container_type::iterator_type iterator_name
 *
 * Example:  std::vector<int>::iterator it1;
 *           std::list<std::string>::iterator it2;
 *           std::map<std::string, std::string>::iterator it3;
 *
 *******************************************************************************
 * Visual representation of iterator for vector
 *
 * std::vector<int> vec {1,2,3}; // vector definition
 *
 * std::vector<int>::iterator it = vec.begin(); // iterator definition
 *   or
 * auto it = vec.begin();                       // iterator definition using auto
 *
 *  +---+---+---+---+
 *  | 1 | 2 | 3 |   |
 *  +---+---+---+---+
 *    ^           ^
 *    |           |
 *    |           +----> vec.end()   - Location after last element
 *    +----------------> vec.begin() - Location on first element
 *
 *******************************************************************************
 * +===================================================================+
 * |                   Operators with iterators (it)                   |
 * +=====================+==========================+==================+
 * | Operator            | Description              | Type of iterator |
 * +=====================+==========================+==================+
 * | ++it                | Pre-Increment            | All              |
 * | it++                | Pre-Increment            | All              |
 * | it = it1            | Assignment               | All              |
 * | *it                 | Dereference              | Input and output |
 * | it->                | Arrow operator           | Input and output |
 * | it ==it1            | Comparison of equality   | input            |
 * | it !=it1            | Comparison of inequality | input            |
 * | --it                | Pre-decrement            | Bidirectional    |
 * | it--                | Post-decrement           | Bidirectional    |
 * | it + i, it += i     | Increment                | Random Access    |
 * | it - i, it -= i     | Decrement                | Random Access    |
 * | it < it1, it <= it1 | Comparison               | Random Access    |
 * | it > it1, it >= it1 | Comparison               | Random Access    |
 * +=====================+==========================+==================+
 *
 *******************************************************************************
 * Examples
 *   std::vector<int> vec {1,2,3}; // vector definition
 *   std::vector<int>::iterator it = vec.begin(); // iterator definition
 *
 *   while (it != vc.end()) {      // using while loop
 *       std::cout << *it << " ";
 *       ++it;
 *   }
 *
 *   for( auto it = vec.begin(); it != vec.end(); it++)  // range-based for loop
 *       std::cout << *it << " ";
 *
 *******************************************************************************
 * STL Algorithms
 * - work on sequences of container elements provided to them by an iterator
 * - many common and useful algorithms
 * - too many to list refer: https://en.cppreference.com/w/cpp/algorithm
 * - Many algorithms requires extra information in order to do their work:
 *     - Function (function objects)
 *     - Function pointers
 *     - Lambda expressions (C++11)
 *
 * Notes:
 * - Header: #include <algorithms>
 * - All STL algorithms expect iterators as arguments
 * - Different containers support different types of iterators
 *******************************************************************************
 * Iterator Invalidation
 * - Iterators point to container elements
 * - Its possible iterators become invalid during processing
 *
 * Suppose we are iterating over vector of 10 elements,
 * and we 'clear()' the vector while iterating. What happens?
 * Undefined behavior - our iterator are pointing to invalid locations
 *
 *******************************************************************************
 * std::find( begin, end, object )
 *  - Need to define operator== overloading
 *
 * std::for_each( begin, end, object)
 *
 *******************************************************************************
 * STL  Sequence containers
 * ========================
 * std::array
 * - Fixed size
 * - direct element access
 * - provides access to the underlying raw array
 * - use instead of raw array when possible
 * - all iterators available and don't invalidate
 *
 * methods provides by array
 * - .size()      - gets size of array
 * - .at()  or [] - access elements
 * - .front() back() - refers to element at front and back
 * - .empty()        - is the array empty ?
 * - .max_size()
 * - arr1.swap(arr2) - swap 2 arrays
 * - .data()         - get raw array address
 *
 * Example
 *   std::array<int, 5> arr1 {{1,2,3,4,5}}; // C++11 format
 *   std::array<int, 5> arr1 {1,2,3,4,5}; // C++14 format
 *
 *******************************************************************************
 * std::vector
 * - Dynamic size: handled automatically, contiguous memory like array
 * - direct access (constant time)
 * - rapid insertion and deletion at the back (constant time)
 * - inserting or removal of elements (linear time)
 * - all iterators available and may invalidate
 *
 *******************************************************************************
 * std::deque (double-ended queue)
 * - Dynamic size: not contiguous memory, handled automatically
 * - Direct element access (constant time)
 * - rapid insertion and deletion at the front and back (constant time)
 * - insertion and removal of elements (liner time)
 * - all iterators available and my invalidate
 *
 * example:
 *   std::deque<int> d1{1,2,3,4,5};
 *   std::deque<int> d2(10,100);  // then 100s
 *
 * methods:
 * size(), max_size()
 * front(), back()
 * push_front(), push_back()
 * pop_front(), pop_back()
 * emplace_front(), emplace_back()
 *******************************************************************************
 * std::list
 * - Dynamic: bidirectional, non-contiguous
 * - Fast random access is not supported. (linear time)
 * - Rapid insertion and deletion anywhere on the container (constant time)
 * - all iterators available and invalidate when corresponding element is deleted
 *
 * example:
 *  std::list<int> l1{1,2,3,4,5}
 *
 * Variations:
 * std::forward_list
 * - single direction, forward
 * - size(), back(), push_back(), pop_back() is not defined
 * - insert_after(), emplace_after(), erase_after(), resize()
 *
 *******************************************************************************
 *******************************************************************************
 *******************************************************************************
 *******************************************************************************
 *******************************************************************************
 *******************************************************************************
 *******************************************************************************
 *******************************************************************************
 */

#include "e20_class_template.hpp"
#include "udemy1.hpp"

#include <algorithm>
#include <array>
#include <cctype> // handling c-style functions
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator> // for std::advance
#include <list>
#include <map>
#include <numeric>
#include <string>
#include <vector>

/**
 * @brief Namespace for examples for template functions
 */
namespace udemy1::e20::functions
{

/**
 * @brief First template example functions
 */
void run_template_functions(void)
{
    std::cout << min<int>(2, 3) << std::endl;             // 2
    std::cout << min(2, 3) << std::endl;                  // 2
    std::cout << min('A', 'B') << std::endl;              // A
    std::cout << min(5.4, 31.5) << std::endl;             // 5.4
    std::cout << min(2 / 2 + 5, 7 + 34 * 2) << std::endl; // 6

    Person p1{"Mark", 32};
    Person p2{"Zack", 23};

    Person p3 = min(p1, p2); // Compiler error: operator '<' has no match for Person data-type
                             // Solution: writer operator '<' overloading function
    std::cout << p3.name << " is younger" << std::endl;

    func<int, int>(10, 20);           // 10 20
    func(10, 20);                     // 10 20
    func<double, char>(10.250, 'B');  // 10.25 B
    func('A', 25.69);                 // A 25.69
    func(1000, "Testing");            // 1000 Testing
    func(1500, std::string{"Frank"}); // 1500 Frank

    func(p1.name, p2.name); // Compiler error: operator << not overloaded for struct Person
                            // Solution: write  operator'<<' overloading function for struct Person

    int x{100}, y{200};
    std::cout << x << "," << y << std::endl; // 100,200
    my_swap(x, y);
    std::cout << x << "," << y << std::endl; // 200,100
}

} // namespace udemy1::e20::functions

/**
 * @brief Namespace for examples for template class
 */
namespace udemy1::e20::classes
{

void run_template_class(void)
{
    Item<int> item1{"Frank", 10};
    // std::cout << item1.get_name() << " " << item1.get_value() << std::endl;
    std::cout << item1 << std::endl;

    Item<std::string> item2{"Frank", "Professor"};
    // std::cout << item2.get_name() << " " << item2.get_value() << std::endl;
    std::cout << item2 << std::endl;

    Item<Item<std::string>> item3{"Frank", {"C++", "Professor"}};
    // std::cout << item3.get_name() << " " << item3.get_value().get_name() << " " << item3.get_value().get_value()
    //           << std::endl;
    std::cout << item3 << std::endl;

    std::cout << "\n--------------------------------------------------------" << std::endl;
    std::vector<Item<double>> vec{};

    vec.push_back(Item<double>("Mark", 200.0));
    vec.push_back(Item<double>("Sam", 100.0));
    vec.push_back(Item("Joe", 800.0));
    vec.push_back(Item("Larry", 900.0));
    vec.push_back(Item("Moe", 400.0));

    for (const auto& v : vec)
        std::cout << v << std::endl;

    std::cout << "\n--------------------------------------------------------" << std::endl;
    My_Pair<std::string, int> p1{"Frank", 100};
    My_Pair<int, double> p2{23, 12.34};

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
}

} // namespace udemy1::e20::classes

/**
 * @brief Namespace to implement a class template for array
 *        C++11 already has an implementations, we are simply learning how this is created
 *        use std::array instead of raw arrays whenever possible
 */
namespace udemy1::e20::ArrayClass
{

void run_template_class_array_int(void)
{
    My_Array<5> nums;
    std::cout << "The size of nums is: " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;

    nums.fill(0);
    std::cout << "The size of nums is: " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;

    nums.fill(10);
    std::cout << "The size of nums is: " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;

    nums[0] = 1000;
    nums[3] = 2000;
    std::cout << nums << std::endl;

    My_Array<100> nums2{1};
    std::cout << "The size of nums2 is: " << nums2.get_size() << std::endl;
    std::cout << nums2 << std::endl;
}

void run_template_class_array_generic(void)
{
    My_Array_Generic<int, 5> nums;
    std::cout << "The size of nums is: " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;

    nums.fill(0);
    std::cout << "The size of nums is: " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;

    nums.fill(10);
    std::cout << "The size of nums is: " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;

    nums[0] = 1000;
    nums[3] = 2000;
    std::cout << nums << std::endl;

    My_Array_Generic<int, 100> nums2{1};
    std::cout << "The size of nums2 is: " << nums2.get_size() << std::endl;
    std::cout << nums2 << std::endl;

    My_Array_Generic<std::string, 100> nums3{"Frank"};
    std::cout << "The size of nums2 is: " << nums3.get_size() << std::endl;
    std::cout << nums3 << std::endl;

    nums3[0] = std::string{"Larry"};
    nums3[3] = std::string{"Mark"};
    std::cout << nums3 << std::endl;

    nums3.fill(std::string{"xXx"});
    std::cout << nums3 << std::endl;
}

} // namespace udemy1::e20::ArrayClass

/**
 * @brief Namespace for examples for STL Iterator
 */
namespace udemy1::e20::itr
{

void display(const std::vector<int>& vec)
{
    std::cout << "[";
    for (auto const& i : vec)
        std::cout << i << " ";
    std::cout << "]" << std::endl;
}

void run_iterators_test_1(void)
{
    std::cout << "\n==============================================================================" << std::endl;

    std::vector<int> nums{1, 2, 3, 4, 5};
    display(nums);
    auto it = nums.begin(); // points to 1
    std::cout << std::setw(25) << std::left << "auto it = nums.begin();";
    std::cout << "// Iterator points to: " << *it << std::endl;

    it++; // points to 2
    std::cout << std::setw(25) << std::left << "it++;";
    std::cout << "// Iterator points to: " << *it << std::endl;

    it += 2;
    std::cout << std::setw(25) << std::left << "it += 2;";
    std::cout << "// Iterator points to: " << *it << std::endl;

    it -= 2;
    std::cout << std::setw(25) << std::left << "it -= 2;";
    std::cout << "// Iterator points to: " << *it << std::endl;

    it = nums.end() - 1;
    std::cout << std::setw(25) << std::left << "it = nums.end() - 1;";
    std::cout << "// Iterator points to: " << *it << std::endl;
}

void run_iterators_test_2(void)
{
    std::cout << "\n==============================================================================" << std::endl;

    std::vector<int> nums{1, 2, 3, 4, 5};
    display(nums);

    // display all elements using iterators
    std::vector<int>::iterator it = nums.begin();
    while (it != nums.end())
        std::cout << *(it++) << std::endl;

    std::cout << std::endl;

    // Change all vector elements to 0
    it = nums.begin();
    while (it != nums.end()) {
        *it = 0;
        ++it;
    }
    display(nums);
}

void run_iterators_test_3(void)
{
    std::cout << "\n== Constant iterators ========================================================" << std::endl;

    std::vector<int> nums{1, 2, 3, 4, 5};
    display(nums);

    std::vector<int>::const_iterator it = nums.begin(); // OR: auto it = nums.cbegin();
    while (it != nums.end())
        std::cout << *(it++) << std::endl;

    std::cout << "\n==============================================================================" << std::endl;

    // Change all vector elements to 0
    it = nums.begin();
    while (it != nums.end()) {
        // *it = 0; // Compiler ERROR - read only
        ++it;
    }
    display(nums);
}

void run_iterators_test_4(void)
{
    std::cout << "\n== Reverse Iterators =========================================================" << std::endl;

    std::vector<int> nums{1, 2, 3, 4, 5};
    display(nums);

    // Reverse iterator over vector
    auto it1 = nums.rbegin();
    while (it1 != nums.rend())
        std::cout << *(it1++) << std::endl;

    std::cout << "\n== Constant Reverse Iterators ================================================" << std::endl;

    // constant reverse over a list
    std::list<std::string> names{"Larry", "Moe", "Curly", "Frank"};

    auto it2 = names.crbegin(); // Points to Frank
    std::cout << *it2 << std::endl;

    it2++; // points to Curly
    std::cout << *it2 << std::endl;

    std::cout << "\n== Display subset using Iterators ============================================" << std::endl;

    // iterator over map
    std::map<std::string, std::string> fav{
        {"Frank", "C++"}, {"Larry", "PHP"}, {"Moe", "Rust"}, {"Sam", "Ruby"}, {"James", "Haskell"}};
    auto it3 = fav.begin(); // iterator over map or string-string pair
    while (it3 != fav.end())
        std::cout << (*it3).first << " : " << (it3++)->second << std::endl;
}

void run_iterators_test_5(void)
{

    std::cout << "\n==============================================================================" << std::endl;
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(vec);

    // Iterator over subset of container
    auto start = vec.cbegin() + 2;
    auto finish = vec.cend() - 3;

    while (start != finish)
        std::cout << *start++ << std::endl;
}

} // namespace udemy1::e20::itr

/**
 * @brief Namespace with examples of STL algorithms
 */
namespace udemy1::e20::algo
{

class Person
{
    std::string name;
    unsigned age;

  public:
    Person() = default;

    Person(std::string s, unsigned a)
        : name{s}
        , age{a}
    {
    }

    bool operator<(const Person& rhs) const
    {
        return (this->age < rhs.age);
    }

    bool operator==(const Person& rhs) const
    {
        return (this->age == rhs.age && this->name == rhs.name);
    }
};

void run_algo_find(void)
{
    std::cout << "\n=== Algo - Find ==============================================================" << std::endl;

    std::vector<int> vec{1, 5, 6, 2, 3, 4, 7, 8};
    auto loc = std::find(std::begin(vec), std::end(vec), 3);
    if (loc != std::end(vec))
        std::cout << "Found the number: " << *loc << "\tat position: " << loc - std::begin(vec) << std::endl;
    else
        std::cout << "Unable to find the number." << std::endl;

    std::list<Person> player{{"Larry", 45}, {"Moe", 32}, {"Sam", 25}, {"Joe", 70}};
    auto loc1 = std::find(std::begin(player), std::end(player), Person{"Sam", 25});
    if (loc1 != std::end(player)) {
        std::cout << "Found Sam" << std::endl;
    } else
        std::cout << "Unable to find Sam." << std::endl;
}

void run_algo_count(void)
{
    std::cout << "\n=== Algo - Count =============================================================" << std::endl;
    std::vector<int> vec{1, 2, 6, 2, 3, 2, 1, 4, 1, 2};
    int num = std::count(vec.begin(), vec.end(), 2);
    std::cout << num << " occurrences found." << std::endl;
}

void run_algo_countif(void)
{
    std::cout << "\n=== Algo - count_if ==========================================================" << std::endl;
    std::vector<int> vec{1, 2, 6, 2, 3, 2, 1, 8, 1, 12, 10, 8, 7, 2};

    // count only if even
    int num = std::count_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
    std::cout << num << " even number found." << std::endl;

    // count only if odd
    num = std::count_if(vec.begin(), vec.end(), [](int x) { return x % 2 != 0; });
    std::cout << num << " odd number found." << std::endl;

    // count only value greater than 5
    int great_num = 5;
    num = std::count_if(vec.begin(), vec.end(), [great_num](int x) { return x > great_num; });
    std::cout << num << " numbers are greater than " << great_num << std::endl;
}

void run_algo_replace(void)
{
    std::cout << "\n=== Algo - replace ===========================================================" << std::endl;
    std::vector<int> vec{1, 2, 6, 2, 3, 2, 1, 8, 1, 12, 10, 8, 7, 2};

    // display vector elements
    for (auto& i : vec)
        std::cout << i << " ";
    std::cout << std::endl;

    // replace element
    std::replace(vec.begin(), vec.end(), 2, 20);

    // display vector elements
    for (auto& i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
}

void run_algo_allof(void)
{
    std::cout << "\n=== Algo - all_of ============================================================" << std::endl;
    std::vector<int> vec{1, 2, 6, 2, 3, 2, 1, 8, 1, 12, 10, 8, 7, 2};

    if (std::all_of(vec.begin(), vec.end(), [](int x) { return x > 10; }))
        std::cout << "All elements are > 10" << std::endl;
    else
        std::cout << "No All elements are > 10" << std::endl;

    if (std::all_of(vec.begin(), vec.end(), [](int x) { return x < 20; }))
        std::cout << "All elements are < 20" << std::endl;
    else
        std::cout << "Np All elements are < 20" << std::endl;
}

void run_algo_transform(void)
{
    std::cout << "\n=== Algo - string  transform =================================================" << std::endl;
    std::string str1{"This is a test case"};

    std::cout << "Before transform: " << str1 << std::endl;
    std::transform(str1.cbegin(), str1.cend(), str1.begin(), ::toupper);
    std::cout << "After transform: " << str1 << std::endl;

    // std::transform(str1.cbegin(),str1.cend(),str1.begin(),::toupper);
    // std::cout << "After 2nd transform: " << str2 << std::endl;
}

} // namespace udemy1::e20::algo

namespace udemy1::e20::containers
{

void run_array_test_1(void)
{
    std::cout << "\n=== Containers - Array test 1 ================================================" << std::endl;
    std::array<int, 5> arr1{1, 2, 3, 4, 5};
    std::array<int, 5> arr2;

    display(arr1);
    display(arr2); // Elements are not initialized, will have garbage

    arr2 = {10, 20, 30, 40, 50};

    display(arr1);
    display(arr2);

    std::cout << "Size of arr1 is: " << arr1.size() << std::endl;
    std::cout << "Size of arr2 is: " << arr2.size() << std::endl;

    arr1[2] = 1000;    // doesn't check for array out of range.
    arr1.at(4) = 2000; // check for array out of range, will throw out_of_range exception
    display(arr1);

    std::cout << "Front of arr2 is: " << arr2.front() << std::endl;
    std::cout << "back of arr2 is: " << arr2.back() << std::endl;
}

void run_array_test_2(void)
{
    std::cout << "\n=== Containers - Array test 2 - fill() =======================================" << std::endl;
    std::array<int, 5> arr1{1, 2, 3, 4, 5};
    std::array<int, 5> arr2{10, 20, 30, 40, 60};

    display(arr1);
    display(arr2);

    // fill array elements with single value
    arr1.fill(01);
    display(arr1);
    display(arr2);

    // swap arrays
    arr1.swap(arr2);
    display(arr1);
    display(arr2);
}

void run_array_test_3(void)
{
    std::cout << "\n=== Containers - Array test 3 - data() =======================================" << std::endl;
    std::array<int, 5> arr1{1, 2, 3, 4, 5};

    int* ptr = arr1.data();
    std::cout << "pointer value: " << ptr << std::endl;
    display(arr1);
    *ptr = 10000;
    display(arr1);
}

void run_array_test_4(void)
{
    std::cout << "\n=== Containers - Array test 4 - sort() =======================================" << std::endl;
    std::array<int, 5> arr1{1, 3, 4, 6, 2};
    display(arr1);

    std::sort(arr1.begin(), arr1.end());
    display(arr1);
}

void run_array_test_5(void)
{
    std::cout << "\n=== Containers - Array test 5 - min_element() ================================" << std::endl;
    std::array<int, 5> arr1{1, 3, 4, 6, 2};

    std::array<int, 5>::iterator min_num = std::min_element(arr1.begin(), arr1.end());
    auto max_num = std::max_element(arr1.begin(), arr1.end());
    display(arr1);
    std::cout << "Minimum element: " << *min_num << std::endl;
    std::cout << "Maximum element: " << *max_num << std::endl;
}

void run_array_test_6(void)
{
    std::cout << "\n=== Containers - Array test 6 - adjacent_find() ==============================" << std::endl;
    std::array<int, 5> arr1{1, 3, 4, 6, 2};
    std::array<int, 5> arr2{1, 3, 4, 4, 2};

    display(arr1);
    auto adjacent = std::adjacent_find(arr1.begin(), arr1.end());
    if (adjacent != arr1.end())
        std::cout << "Adjacent element found with value: " << *adjacent << std::endl;
    else
        std::cout << "No Adjacent element found" << std::endl;

    display(arr2);
    adjacent = std::adjacent_find(arr2.begin(), arr2.end());
    if (adjacent != arr2.end())
        std::cout << "Adjacent element found with value: " << *adjacent << std::endl;
    else
        std::cout << "No Adjacent element found" << std::endl;
}

void run_array_test_7(void)
{
    std::cout << "\n=== Containers - Array test 7 - accumulate() =================================" << std::endl;
    std::array<int, 5> arr1{1, 2, 3, 4, 5};
    display(arr1);

    // accumulate is from #include <numeric>
    int sum = std::accumulate(arr1.begin(), arr1.end(), 0);
    std::cout << "Sum of all elements of the array: " << sum << std::endl;
}

void run_array_test_8(void)
{
    std::cout << "\n=== Containers - Array test 8 - count() ======================================" << std::endl;
    std::array<int, 10> arr1{1, 3, 4, 3, 3, 3, 3, 6, 3, 3};
    display(arr1);

    auto count = std::count(arr1.begin(), arr1.end(), 3);
    std::cout << "Found 3: " << count << " times" << std::endl;
}

void run_array_test_9(void)
{
    std::cout << "\n=== Containers - Array test 9 - count_if() ===================================" << std::endl;
    std::array<int, 10> arr1{1, 2, 3, 50, 60, 70, 80, 200, 300, 400};
    display(arr1);

    // count numbers between 10 and 200
    int count = std::count_if(arr1.begin(), arr1.end(), [](int x) { return (x > 10 && x < 200); });
    std::cout << "Found " << count << " matches, between 10 and 200" << std::endl;
}

void run_vector_test_1()
{
    std::cout << "\nTest1 =========================" << std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5};
    display(vec);

    vec = {2, 4, 5, 6};
    display_using_lambda(vec);

    std::vector<int> vec1(10, 100); // ten 100s in the vector
    display(vec1);
}

void run_vector_test_2()
{
    std::cout << "\nTest2 =========================" << std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5};
    display(vec);
    std::cout << "\nvec size: " << vec.size() << std::endl;
    std::cout << "vec max size: " << vec.max_size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << std::endl;

    vec.push_back(6);
    display(vec);
    std::cout << "\nvec size: " << vec.size() << std::endl;
    std::cout << "vec max size: " << vec.max_size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << std::endl;

    vec.shrink_to_fit(); // C++11
    display(vec);
    std::cout << "\nvec size: " << vec.size() << std::endl;
    std::cout << "vec max size: " << vec.max_size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << std::endl;

    vec.reserve(100);
    display(vec);
    std::cout << "\nvec size: " << vec.size() << std::endl;
    std::cout << "vec max size: " << vec.max_size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << std::endl;
}

void run_vector_test_3()
{
    std::cout << "\nTest3 =========================" << std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5};
    display(vec);

    vec[0] = 100;
    vec.at(1) = 200;

    display(vec);
}

void run_vector_test_4()
{
    std::cout << "\nTest4 =========================" << std::endl;
    std::vector<Person> stooges;

    Person p1{"Larry", 18};
    display(stooges);

    stooges.push_back(p1);
    display(stooges);

    stooges.push_back(Person{"Moe", 25});
    display(stooges);

    stooges.emplace_back("Curly", 30); // Use emplace_back!!!
    display(stooges);
}

void run_vector_test_5()
{
    std::cout << "\nTest5 =========================" << std::endl;

    std::vector<Person> stooges{{"Larry", 18}, {"Moe", 25}, {"Curly", 30}};

    display(stooges);
    std::cout << "\nFront: " << stooges.front() << std::endl;
    std::cout << "Back: " << stooges.back() << std::endl;

    stooges.pop_back();
    display(stooges);
}

void run_vector_test_6()
{
    std::cout << "\nTest6 =========================" << std::endl;
    std::vector<int> vec{1, 2, 3, 4, 5};
    display(vec);

    vec.clear(); // remove all elements
    display(vec);

    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(vec);
    vec.erase(vec.begin(), vec.begin() + 2);
    display(vec);

    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // erase all even numbers
    auto it = vec.begin();
    while (it != vec.end()) {
        if (*it % 2 == 0)
            vec.erase(it);
        else
            it++; // only increment if not erased!
    }
    display(vec);
}

void run_vector_test_7()
{
    std::cout << "\nTest7 =========================" << std::endl;

    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<int> vec2{10, 20, 30, 40, 50};

    display(vec1);
    display(vec2);
    std::cout << std::endl;

    vec2.swap(vec1);
    display(vec1);
    display(vec2);
}

void run_vector_test_8()
{
    std::cout << "\nTest8  =========================" << std::endl;

    std::vector<int> vec1{1, 21, 3, 40, 12};

    display(vec1);
    std::sort(vec1.begin(), vec1.end());
    display(vec1);
}

void run_vector_test_9()
{
    // std::back_inserter contructs a back-insert iterator that inserts new elements
    // at the end of the container it applied to. It's a special output iterator
    // It's awesome!!!!   and  very efficient
    // There is also a front_inserter we can use with deques and lists
    // Copy one list to another using an iterator and back_inserter

    std::cout << "\nTest9  =========================" << std::endl;

    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<int> vec2{10, 20};

    display(vec1);
    display(vec2);
    std::cout << std::endl;

    std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));
    display(vec1);
    display(vec2);
    std::cout << std::endl;

    // Copy_if the element is even

    vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vec2 = {10, 20};

    display(vec1);
    display(vec2);
    std::cout << std::endl;

    std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2), [](int x) { return x % 2 == 0; });
    display(vec1);
    display(vec2);
}

void run_vector_test_10()
{
    std::cout << "\nTest10  =========================" << std::endl;
    // transform over 2 ranges

    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<int> vec2{10, 20, 30, 40, 50};
    std::vector<int> vec3;

    display(vec1);
    display(vec2);

    // 1*10, 2*20, 3*30, 4*40, 5*50 and store the results in vec3
    std::transform(vec1.begin(), vec1.end(), vec2.begin(), std::back_inserter(vec3),
                   [](int a, int b) { return a * b; });

    display(vec3);
}

// Insertion from another vector
// Insert vec2 into vec1 before the 5
void run_vector_test_11()
{
    std::cout << "\nTest11  =========================" << std::endl;
    std::vector<int> vec1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> vec2{100, 200, 300, 400};

    display(vec1);
    display(vec2);
    std::cout << std::endl;

    auto it = std::find(vec1.begin(), vec1.end(), 5);
    if (it != vec1.end()) {
        vec1.insert(it, vec2.begin(), vec2.end());
        std::cout << "inserting..." << std::endl;
    } else
        std::cout << "Sorry, 5 not found" << std::endl;

    display(vec1);
}

} // namespace udemy1::e20::containers

namespace udemy1::e20::containers
{

void run_deque_test_1(void)
{
    std::cout << "\n deque Test1  =========================" << std::endl;
    std::deque<int> d{1, 2, 3, 4, 5};
    display(d);

    d = {2, 4, 5, 6};
    display(d);

    std::deque<int> d1(10, 100);
    display(d1);

    d[0] = 100;
    d.at(2) = 200;
    display(d);
}

void run_deque_test_2(void)
{
    std::cout << "\n deque Test2  =========================" << std::endl;
    std::deque<int> d{1, 2, 3, 4, 5};
    display(d);

    d.push_back(100);
    d.push_front(200);
    display(d);

    std::cout << "Front: " << d.front() << std::endl;
    std::cout << "Back: " << d.back() << std::endl;
    std::cout << "Size: " << d.size() << std::endl;

    d.pop_back();
    d.pop_front();
    display(d);
    std::cout << "Front: " << d.front() << std::endl;
    std::cout << "Back: " << d.back() << std::endl;
    std::cout << "Size: " << d.size() << std::endl;

    d.pop_back();
    d.pop_front();
    display(d);
    std::cout << "Front: " << d.front() << std::endl;
    std::cout << "Back: " << d.back() << std::endl;
    std::cout << "Size: " << d.size() << std::endl;
}

void run_deque_test_3(void)
{
    // insert even to back of deque and odd to front
    std::cout << "\n deque Test3  =========================" << std::endl;
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> d{};
    display(vec);
    display(d);
    for (const auto& v : vec) {
        if (v % 2 == 0)
            d.push_back(v);
        else
            d.push_front(v);
    }
    display(d);
}

void run_deque_test_4(void)
{
    // push_front vs back_ordering
    std::cout << "\n deque Test4  =========================" << std::endl;
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> d{};
    display(vec);
    display(d);
    std::cout << "d.push_front() order: ";
    for (const auto& v : vec)
        d.push_front(v);
    display(d);
    d.clear();
    std::cout << "d.push_back() order: ";
    for (const auto& v : vec)
        d.push_back(v);
    display(d);
}

void run_deque_test_5(void)
{
    // push_front vs back_ordering
    std::cout << "\n deque Test5  =========================" << std::endl;
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> d{};
    display(vec);
    display(d);
    std::cout << "std::copy( front_inserter()) order: ";
    std::copy(vec.begin(), vec.end(), std::front_inserter(d));

    display(d);
    d.clear();
    std::cout << "std::copy( back_inserter()) order: ";
    std::copy(vec.begin(), vec.end(), std::back_inserter(d));
    display(d);
}

void run_list_test_1(void)
{
    std::cout << "\nTest1 =========================" << std::endl;

    std::list<int> l1{1, 2, 3, 4, 5};
    display(l1);

    std::list<std::string> l2;
    l2.push_back("Back");
    l2.push_front("Front");
    display(l2);

    std::list<int> l3;
    l3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(l3);

    std::list<int> l4(10, 100);
    display(l4);
}

void run_list_test_2(void)
{
    std::cout << "\nTest2 =========================" << std::endl;

    std::list<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(l);
    std::cout << "Size: " << l.size() << std::endl;

    std::cout << "Front : " << l.front() << std::endl;
    std::cout << "Back  : " << l.back() << std::endl;

    l.clear();
    display(l);
    std::cout << "Size: " << l.size() << std::endl;
}

void run_list_test_3(void)
{
    std::cout << "\nTest3 =========================" << std::endl;

    std::list<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(l);

    l.resize(5);
    display(l);

    l.resize(10);
    display(l);

    std::list<Person> persons;
    persons.resize(5); // uses the Person default constructor
    display(persons);
}

void run_list_test_4(void)
{
    std::cout << "\nTest4 =========================" << std::endl;

    std::list<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(l);

    auto it = std::find(l.begin(), l.end(), 5);
    if (it != l.end())
        l.insert(it, 100);

    display(l);
    std::cout << "it=" << *it << std::endl;

    std::list<int> l2{1000, 2000, 3000};
    l.insert(it, l2.begin(), l2.end());
    display(l);
    std::cout << "it=" << *it << std::endl;

    std::advance(it, -4); // pointing to 100
    std::cout << *it << std::endl;

    l.erase(it);
    // std::cout << *it << std::endl; // it is invalidated
    display(l);
}

void run_list_test_5(void)
{
    std::cout << "\nTest5 =========================" << std::endl;

    std::list<Person> stooges{{"Larry", 18}, {"Moe", 25}, {"Curly", 17}};

    display(stooges);
    std::string name;
    int age{};
    std::cout << "\nEnter the name of the next stooge: ";
    getline(std::cin, name);
    std::cout << "Enter their age: ";
    std::cin >> age;

    stooges.emplace_back(name, age);
    display(stooges);

    // Insert Frank before Moe
    auto it = std::find(stooges.begin(), stooges.end(), Person{"Moe", 25});
    if (it != stooges.end())
        stooges.emplace(it, "Frank", 18);
    display(stooges);
}

void run_list_test_6(void)
{
    std::cout << "\nTest6 =========================" << std::endl;

    std::list<Person> stooges{{"Larry", 18}, {"Moe", 25}, {"Curly", 17}};

    display(stooges);
    stooges.sort();
    display(stooges);
}

} // namespace udemy1::e20::containers

/**
 * @brief Run all examples of STL
 */
void udemy1::e20_run(void)
{
    // e20::functions::run_template_functions();
    // e20::classes::run_template_class();
    // e20::ArrayClass::run_template_class_array_int();
    // e20::ArrayClass::run_template_class_array_generic();

    // e20::itr::run_iterators_test_1();
    // e20::itr::run_iterators_test_2();
    // e20::itr::run_iterators_test_3();
    // e20::itr::run_iterators_test_4();
    // e20::itr::run_iterators_test_5();

    // e20::algo::run_algo_find();
    // e20::algo::run_algo_count();
    // e20::algo::run_algo_countif();
    // e20::algo::run_algo_replace();
    // e20::algo::run_algo_allof();
    // e20::algo::run_algo_transform();

    // e20::containers::run_array_test_1();
    // e20::containers::run_array_test_2();
    // e20::containers::run_array_test_3();
    // e20::containers::run_array_test_4();
    // e20::containers::run_array_test_5();
    // e20::containers::run_array_test_6();
    // e20::containers::run_array_test_7();
    // e20::containers::run_array_test_8();
    // e20::containers::run_array_test_9();

    // e20::containers::run_vector_test_1();
    // e20::containers::run_vector_test_2();
    // e20::containers::run_vector_test_3();
    // e20::containers::run_vector_test_4();
    // e20::containers::run_vector_test_5();
    // e20::containers::run_vector_test_6();
    // e20::containers::run_vector_test_7();
    // e20::containers::run_vector_test_8();
    // e20::containers::run_vector_test_9();
    // e20::containers::run_vector_test_10();
    // e20::containers::run_vector_test_11();

    // e20::containers::run_deque_test_1();
    // e20::containers::run_deque_test_2();
    // e20::containers::run_deque_test_3();
    // e20::containers::run_deque_test_4();
    // e20::containers::run_deque_test_5();

    // std::list
    // e20::containers::run_list_test_1();
    // e20::containers::run_list_test_2();
    // e20::containers::run_list_test_3();
    // e20::containers::run_list_test_4();
    // e20::containers::run_list_test_5();
    e20::containers::run_list_test_6();
}
