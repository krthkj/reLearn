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
 *
 *******************************************************************************
 *******************************************************************************
 *******************************************************************************
 *******************************************************************************
 */

#include "e20_class_template.hpp"
#include "udemy1.hpp"

#include <algorithm>
#include <cctype> // handling c-style functions
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
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

    for(const auto& v : vec)
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
    for(auto const& i : vec)
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
    while(it != nums.end())
        std::cout << *(it++) << std::endl;

    std::cout << std::endl;

    // Change all vector elements to 0
    it = nums.begin();
    while(it != nums.end()) {
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
    while(it != nums.end())
        std::cout << *(it++) << std::endl;

    std::cout << "\n==============================================================================" << std::endl;

    // Change all vector elements to 0
    it = nums.begin();
    while(it != nums.end()) {
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
    while(it1 != nums.rend())
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
    while(it3 != fav.end())
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

    while(start != finish)
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
    if(loc != std::end(vec))
        std::cout << "Found the number: " << *loc << "\tat position: " << loc - std::begin(vec) << std::endl;
    else
        std::cout << "Unable to find the number." << std::endl;

    std::list<Person> player{{"Larry", 45}, {"Moe", 32}, {"Sam", 25}, {"Joe", 70}};
    auto loc1 = std::find(std::begin(player), std::end(player), Person{"Sam", 25});
    if(loc1 != std::end(player)) {
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
    const int great_num = 5;
    num = std::count_if(vec.begin(), vec.end(), [great_num](int x) { return x > great_num; });
    std::cout << num << " numbers are greater than " << great_num << std::endl;
}

void run_algo_replace(void)
{
    std::cout << "\n=== Algo - replace ===========================================================" << std::endl;
    std::vector<int> vec{1, 2, 6, 2, 3, 2, 1, 8, 1, 12, 10, 8, 7, 2};

    // display vector elements
    for(auto& i : vec)
        std::cout << i << " ";
    std::cout << std::endl;

    // replace element
    std::replace(vec.begin(), vec.end(), 2, 20);

    // display vector elements
    for(auto& i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
}

void run_algo_allof(void)
{
    std::cout << "\n=== Algo - all_of ============================================================" << std::endl;
    std::vector<int> vec{1, 2, 6, 2, 3, 2, 1, 8, 1, 12, 10, 8, 7, 2};

    if(std::all_of(vec.begin(), vec.end(), [](int x) { return x > 10; }))
        std::cout << "All elements are > 10" << std::endl;
    else
        std::cout << "No All elements are > 10" << std::endl;

    if(std::all_of(vec.begin(), vec.end(), [](int x) { return x < 20; }))
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
    e20::algo::run_algo_transform();

    // e20::algo::array
}
