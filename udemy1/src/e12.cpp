/**
 * Copyright © 2022 by Karthik Jain <krthkj.public@gmail.com>
 * All Rights Reserved.
 * Using MIT licence, refer the license file supplied with the project.
 *
 * File : e12.cpp
 * Desc : Section 12: Pointers and references
 *        Challenge from Udemy course "Beginning C++ Programming - From Beginner to Beyond"
 *
 * Author : Karthik Jain <krthkj.public@gmail.com>
 * Date : 2022-12-09
 *
 */

#include "udemy1.hpp"

#include <iostream>
#include <vector>

namespace udemy1
{

/******************************************************************************
 * Pointer declaration
 * variable_type* pointer_name {nullptr};
 * or
 * variable_type *pointer_name {nullptr};
 *
 * before C++11 use 'zero', starting with C++11 use 'nullptr'
 ******************************************************************************/

void run_test_ptrs(void)
{
    int* p;
    std::cout << "Value of p is: " << p << std::endl;
    std::cout << "Address of p is: " << &p << std::endl;
    std::cout << "size of p is: " << sizeof p << std::endl;

    p = nullptr;
    std::cout << "reinitilaized Value of p is: " << p << std::endl << std::endl;
    if (p != nullptr)
        std::cout << "dereferenced Value of p is: " << *p << std::endl << std::endl;

    int q{0};
    std::cout << "Value of q is: " << q << std::endl;
    std::cout << "Address of q is: " << &q << std::endl;
    std::cout << "size of q is: " << sizeof(q) << std::endl;

    q = 100;
    std::cout << "reinitilaized Value of q is: " << q << std::endl << std::endl;

    p = &q;
    std::cout << "Value of p is: " << p << std::endl;
    std::cout << "Address of p is: " << &p << std::endl;
    if (p != nullptr)
        std::cout << "dereferenced Value of p is: " << *p << std::endl << std::endl;

    std::cout << "value of  'q'  is: " << q << std::endl;
    std::cout << "value of  '&q' is: " << &q << std::endl;
    std::cout << "value of '*&q' is: " << *&q << std::endl;

    int a;
    float b;
    long c;
    double d;
    char e;
    bool f;
    int* k{nullptr};
    float* l{nullptr};
    long* m{nullptr};
    double* n{nullptr};
    char* o{nullptr};
    bool* r{nullptr};
    void* y{nullptr};

    std::cout << std::endl;
    std::cout << "size of int     is: " << sizeof a;
    std::cout << "  size of int*    is: " << sizeof(k) << std::endl;
    std::cout << "size of float   is: " << sizeof b;
    std::cout << "  size of float*  is: " << sizeof l << std::endl;
    std::cout << "size of long    is: " << sizeof c;
    std::cout << "  size of long*   is: " << sizeof m << std::endl;
    std::cout << "size of double  is: " << sizeof d;
    std::cout << "  size of double* is: " << sizeof n << std::endl;
    std::cout << "size of char    is: " << sizeof e;
    std::cout << "  size of char*   is: " << sizeof o << std::endl;
    std::cout << "size of bool    is: " << sizeof f;
    std::cout << "  size of bool*   is: " << sizeof r << std::endl;
    std::cout << "                     ";
    std::cout << "  size of void*   is: " << sizeof y << std::endl << std::endl;

    std::vector<std::string> stooges{"Larry", "Moe", "Curly"};
    std::vector<std::string>* vector_ptr{nullptr};
    vector_ptr = &stooges;

    std::cout << "First stooges: " << (*vector_ptr).at(0) << std::endl;
    std::cout << "Stooges: ";
    for (auto stoogge : *vector_ptr)
        std::cout << stoogge << " ";
    std::cout << std::endl;
}

/******************************************************************************/

/**
 * @brief Examples for dynamic memory allocation
 * Memory is allocated from heap.
 */
void run_dynamic_mem(void)
{
    //--------------------------
    int* int_ptr{nullptr};
    int_ptr = new int; // allocate integer on heap

    std::cout << "Addr : " << int_ptr << std::endl;
    std::cout << "value: " << *int_ptr << std::endl;
    *int_ptr = 100;
    std::cout << "value: " << *int_ptr << std::endl;
    if (int_ptr != nullptr)
        delete int_ptr;

    //--------------------------
    int* array_ptr{nullptr};
    size_t size{0};

    std::cout << "How big do your want the array ? ";
    std::cin >> size;
    array_ptr = new int[size];
    for (size_t i{0}; i < size; ++i) {
        array_ptr[i] = i;
        std::cout << array_ptr[i] << " ";
    }
    if (array_ptr != nullptr)
        delete[] array_ptr;

    std::cout << std::endl;

    //--------------------------
    // This will lead to meamory leak
    // double* tmp_ptr{nullptr};
    // std::cout << "How many temps ? ";
    // std::cin >> size;
    // size_t count{0};
    //
    // while(true) {
    //     tmp_ptr = new double[size];
    //     std::cout << ++count << " " << std::endl;
    //     delete[] tmp_ptr;
    // }
}

/******************************************************************************/

void run_pointer_array(void)
{
    /**************************************
     * array and pointers
     * Notes:
     * int array_name[] {1,2,3,4,5};
     * int* ptr_name {array_name};
     * array_name[index]  === *(array_name + index)
     * ptr_name[index]    === *(ptr_name + index)
     *
     */
    int scores[]{100, 95, 89, 57, 35};
    size_t size = sizeof(scores) / sizeof(int);
    int* score_ptr{scores};
    std::cout << std::endl;

    std::cout << "Size of array: " << size << std::endl;

    std::cout << "Address of array: " << size << std::endl;
    for (size_t i{0}; i < size; ++i)
        std::cout << score_ptr + i << std::endl;
    std::cout << std::endl;

    std::cout << "Array subscript notation:   ";
    for (size_t i{0}; i < size; ++i)
        std::cout << scores[i] << " ";
    std::cout << std::endl;

    std::cout << "Pointer subscript notation: ";
    for (size_t i{0}; i < size; ++i)
        std::cout << score_ptr[i] << " ";
    std::cout << std::endl;

    std::cout << "Array offset notation:      ";
    for (size_t i{0}; i < size; ++i)
        std::cout << *(scores + i) << " ";
    std::cout << std::endl;

    std::cout << "Pointer offset notation:    ";
    for (size_t i{0}; i < size; ++i)
        std::cout << *(score_ptr + i) << " ";
    std::cout << std::endl;
}

/******************************************************************************/

void run_pointer_arithmetic(void)
{
    std::string s1{"Frank"};
    std::string s2{"Frank"};
    std::string s3{"James"};

    std::string* p1{&s1};
    std::string* p2{&s2};
    std::string* p3{&s1};

    //--------------------------
    std::cout << std::boolalpha;
    std::cout << p1 << "==" << p2 << ": " << (p1 == p2) << std::endl;     // false
    std::cout << p1 << "==" << p3 << ": " << (p1 == p3) << std::endl;     // true
    std::cout << *p1 << "==" << *p2 << ": " << (*p1 == *p2) << std::endl; // true
    std::cout << *p1 << "==" << *p3 << ": " << (*p1 == *p3) << std::endl; // true
    p3 = &s3;
    std::cout << *p1 << "==" << *p3 << ": " << (*p1 == *p3) << std::endl; // false
    std::cout << std::endl;

    //--------------------------
    char name[]{"Frank"};
    char* char_ptr_1{nullptr};
    char* char_ptr_2{nullptr};

    char_ptr_1 = &name[0];
    char_ptr_2 = &name[3];
    std::cout << "in the string " << name << ", " << *char_ptr_2 << " is " << char_ptr_2 - char_ptr_1
              << " characters away from " << *char_ptr_1 << std::endl;

    std::cout << std::endl;

    //--------------------------
    int scores[]{100, 98, 89, 68, -1};
    int* score_ptr{scores};

    while (*score_ptr != -1) {
        std::cout << *score_ptr << std::endl;
        score_ptr++;
    }
    std::cout << std::endl;

    score_ptr = scores;
    while (*score_ptr != -1)
        // *score_ptr++  === *(score_ptr++)
        // dereference pointer first and then increment pointer
        std::cout << *score_ptr++ << std::endl;
    std::cout << std::endl;
}

/******************************************************************************
 * Variations of using 'const' on pointers (used for passing pointers to functions)
 * pointers to constants
 * constant pointers
 * constant pointers to constants
 *
 ******************************************************************************
 * Pointers to constant:
 * - data pointed to by the pointer is constant and cannot be changed
 * - pointer itself can be changed
 *
 * Constant pointer:
 * - data pointed to by the pointer can be changed
 * - pointer itself cannot be changed and cant be pointed to anything else
 *
 * Constant pointer to constant:
 * - data pointed to by the pointer is constant and cannot be changed
 * - pointer itself cannot be changed and cant be pointed to anything else
 ******************************************************************************
 */
void run_const_pointer(void)
{
    int high_score{100};
    int low_score{65};

    // pointers to constants -------------------------
    const int* score_ptr_1{&high_score};
    // *score_ptr_1 = 86;     // error: assignment of read-only location '* score_ptr_1'
    score_ptr_1 = &low_score; // okay
    std::cout << *score_ptr_1 << std::endl;

    // Constant pointers -----------------------------
    int* const score_ptr_2{&high_score};
    *score_ptr_2 = 86; // okay
    // score_ptr_2 = &low_score; // error: assignment of read-only variable 'score_ptr_2'
    std::cout << *score_ptr_2 << std::endl;

    // Constant pointers to constant -----------------
    const int* const score_ptr_3{&high_score};
    // *score_ptr_3 = 86;        // error: assignment of read-only location '*(const int*)score_ptr_3'
    // score_ptr_3 = &low_score; // error: assignment of read-only variable 'score_ptr_3'
    std::cout << *score_ptr_3 << std::endl;
}

/******************************************************************************/

void double_data(int* int_ptr);
void my_swap(int*, int*);
void display1(std::vector<std::string>*);
void display2(const std::vector<std::string>*);
void display3(const std::vector<std::string>* const);
void display(int*, int);

void run_pointer_function(void)
{
    int value{10};
    int* int_ptr{nullptr};
    std::cout << "Value: " << value << std::endl;
    double_data(&value);
    std::cout << "Value: " << value << std::endl;
    std::cout << "--------------" << std::endl;

    int_ptr = &value;
    double_data(int_ptr);
    std::cout << "Value: " << value << std::endl;
    std::cout << std::endl;

    //-------------------------------------
    int x{10}, y{200};
    std::cout << "x: " << x << "\t"
              << "y: " << y << std::endl;
    my_swap(&x, &y);
    std::cout << "x: " << x << "\t"
              << "y: " << y << std::endl;
    std::cout << std::endl;

    //-------------------------------------
    std::vector<std::string> stooges{"larry", "moe", "Curly"};

    display1(&stooges);
    display2(&stooges);
    display3(&stooges);
    std::cout << std::endl;

    //-------------------------------------
    int scores[]{100, 95, 83, 64, 16, -1, 29};
    display(scores, -1);
}

void double_data(int* int_ptr)
{
    *int_ptr *= 2;
}

void my_swap(int* a, int* b)
{
    int tmp = *a;
    *a      = *b;
    *b      = tmp;
}

void display1(std::vector<std::string>* v)
{
    (*v).at(0) = "Funny"; // can modify const value
    for (auto str : *v)
        std::cout << str << " ";
    std::cout << std::endl;
    v = nullptr; // can modify const value
}

void display2(const std::vector<std::string>* v)
{
    // (*v).at(0) = "Funny"; // cant modify const value, read-only
    for (auto str : *v)
        std::cout << str << " ";
    std::cout << std::endl;
    v = nullptr;
}

void display3(const std::vector<std::string>* const v)
{
    // (*v).at(0) = "Funny"; // cant modify, read-only
    for (auto str : *v)
        std::cout << str << " ";
    std::cout << std::endl;
    // v = nullptr; // cannot modify pointer, read-only
}

void display(int* array, int sentinal)
{
    // Cannot use any kind of constant pointer in this function
    while (*array != sentinal)
        std::cout << *array++ << " ";
    std::cout << std::endl;
}

/******************************************************************************/

int* largest_int(int* int_ptr_1, int* int_ptr_2)
{
    if (*int_ptr_1 > *int_ptr_2)
        return int_ptr_1;
    else
        return int_ptr_2;
}

int* create_array(size_t size, int init_value = 0)
{
    int* new_storage{nullptr};
    new_storage = new int[size];
    for (size_t i{0}; i < size; ++i)
        *(new_storage + i) = init_value;
    return new_storage;
}

void display_array(const int* const array, size_t size)
{
    for (size_t i{0}; i < size; ++i)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

void run_ptr_ret_func(void)
{
    int a{0100}, b{200};
    int* largest_ptr{nullptr};
    largest_ptr = largest_int(&a, &b);
    std::cout << "Largest: " << *largest_ptr << std::endl;
    std::cout << std::endl;

    int* my_array;
    size_t size{};
    int init_val{};
    std::cout << "How many integers would you allocate? ";
    std::cin >> size;

    std::cout << "What value would you like them initialized to? ";
    std::cin >> init_val;

    my_array = create_array(size, init_val);
    display_array(my_array, size);
    delete[] my_array;
}

/******************************************************************************
 * Potential pitfalls in pointers (raw pointers)
 * - un-initialized pointer variable; resutls in corruption of data.
 * - Dangling pointers; results in program crash.
 * - DeReferencing null pointer OR not checking if new failed; results in program crash.
 * - meamory leak; results in orphan memory, loss of heap storage.
 *******************************************************************************/

/******************************************************************************/

void run_reference(void)
{
    std::vector<std::string> stooges{"Larry", "Moe", "Curly"};

    //----------------------------------------------------
    // references in range-based loop
    for (auto str : stooges) // 'str' is a copy
        str = "FUnny";       // changes the copy not the original value

    for (auto str : stooges)
        std::cout << str << " ";
    std::cout << std::endl;

    //----------------------------------------------------
    // Using a referenece as loop variable
    for (auto& str : stooges) // 'str' is an alias, reference to the 'stooges'
        str = "FUnny";        // changes the original value

    for (auto str : stooges) // here 'str' is creating copy, its unnecessary
        std::cout << str << " ";
    std::cout << std::endl;

    //----------------------------------------------------
    // Using a referenece as loop variable
    // for(auto const& str : stooges)
    //     str = "FUnny"; // compiler error

    // This range-based loop is space effecient, as it doesnt make copies.
    for (auto const& str : stooges) // 'str' is reference; 'const' makes it read-only
        std::cout << str << " ";    // no error
    std::cout << std::endl;
    std::cout << std::endl;

    //----------------------------------------------------
    int num{100};
    int& ref{num}; // creates alias, and doesnt not createoccumy additional memory

    std::cout << num << std::endl << ref << std::endl;

    num = 200;
    std::cout << num << std::endl << ref << std::endl;

    num = 300;
    std::cout << num << std::endl << ref << std::endl;
    std::cout << std::endl;

    //----------------------------------------------------
}

/******************************************************************************
 * L-Values:
 * - Values that have names and are addressable
 * - modifiable in they are not constants
 *
 * R-Values:
 * - non-assressable and non-assignable
 * - a value that is not l-value :
 *   - RHS of teh assignment expression,
 *   - a literal,
 *   - a temporary intemded to be non-modifiable
 *
 * r-values can be assigned to l-values explicitly.
 * l-values can apprear both on the left and right side of the assignment statement.
 *
 * l-value references:
 *******************************************************************************/
int square(int& n)
{
    return n * n;
}

void run_l_r_value(void)
{
    //---------------------------------
    int x{100};       // 100 is r-value
    x     = 1000;     // 'x' is l-value
    x     = 100 + 22; // 'x' is l-value
    int y = x + 200;  // '(x+200)' is an r-vaue

    std::string name; // 'name' is l-value
    name = "Frank";   // 'Frank' is r-value

    // 100 = x; // '100' an NOT an l-value
    // "Frank" = name; // 'Frank' an NOT an l-value

    int max_num = std::max(20, 30); // 'max(20,30)' is an r-value

    //---------------------------------
    int& ref1 = x; // ref1 is reference to l-value
    ref1      = 1000;
    // int &ref2=100; // compiler error: 100 is an r-value

    //---------------------------------
    int num{10};
    square(num);
    // square(5); // error: cant reference r-value '5' to l-value 'int&'
    // error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'

    std::cout << x << " " << y << " " << max_num << std::endl;
}

/******************************************************************************
 * SUMMARY of Pointer, Reference and related
 ******************************************************************************
 * pointer to constant : const int* var_1 = {&var_2};
 * - can change the var_1                 ; { *var_1 = 100 ; // ERROR }
 * - cannot change value pointed by var_1 ; { var_1 = var_3; // PASS }
 *
 * constant pointer : int* const var_1 = {&var_2};
 * - cannot change the var_1           ; { *var_1 = 100 ; // PASS }
 * - can change value pointed by var_1 ; { var_1 = var_3; // ERROR }
 *
 * constnat pointer to constant : const int* const var_1 = {&var_2};
 * - cannot change the var_1              ; { *var_1 = 100 ; // ERROR }
 * - cannot change value pointed by var_1 ; { var_1 = var_3; // ERROR }
 ******************************************************************************
 * Note: references can be considered as constant pointer (ref == const ptr )
 * references:
 * - alias for variable                  ; { int &ref_1 = var_1; }
 * - cannot be null                      ; {
 *                                           int* ptr_1{nullptr};
 *                                           int &ref_1 = ptr_1;  // Runtime Error;
 *                                         }
 * - must be initialized when declared   ; {
 *                                           int var_1;
 *                                           int &ref_1 = &var_1;  // PASS
 *                                           }
 *                                       ; {
 *                                           int var_1; int* ptr_1{nullptr};
 *                                           ptr_1=&var_1;
 *                                           int &ref_1 = ptr_1;  //PASS: ref_1 == var_1
 *                                         }
 * - cannot be modified after initialized; {
 *                                           int &ref_1 = var_1;
 *                                           ref_1 = var_2; // ERROR
 *                                         }
 * - reference values can be modified    ; {
 *                                           int &ref_1 = var_1;
 *                                           var_1 = 125;
 *                                           ref_1 = 100; // PASS
 *                                         }
 *
 * constant references:
 * - same as references
 * - cannot modify values ; {
 *                        ;   const int &ref_1 = var_1;
 *                        ;   var_1 = 125;
 *                        ;   ref_1 = 100; // ERROR
 *                        ; }
 ******************************************************************************
 * Pass-by-value:
 * Ex: void test_pass_value(int);
 * - C++ does by default.
 * - function never modify actual parameters.
 * - parameters are small and effecient to copy (like simple data types).
 *
 * Pass-by-reference using pointer:
 * Ex: void test_pass_ptr(int*);
 * - pointer can be nullptr
 * - parameters are expensive to copy.
 * - function modifies the actual parameters.
 * - function modifies the pointer itself
 *
 * Pass-by-reference using pointer to const:
 * Ex: void test_pass_ptr_const(const int*);
 * - pointer can be nullptr
 * - parameters are expensive to copy.
 * - function never modify actual parameters
 * - function modifies the pointer itself
 *
 ? Pass-by-reference using constant pointer: (is there any use of this type?)
 ? Ex: void test_pass_const_ptr(int* const);
 ? - pointer can be nullptr
 ? - parameters are expensive to copy.
 ? - function modifies actual parameters
 ? - function never modifies the pointer itself
 *
 * Pass-by-reference using const pointer to const:
 * Ex: void test_pass_const_ptr_const(const int* const);
 * - pointer can be nullptr
 * - parameters are expensive to copy.
 * - function never modify actual parameters
 * - function never modifies the pointer itself
 *
 * Pass-by-reference using a reference:
 * Ex: void test_pass_ref(int&);
 * - reference cannot be nullptr
 * - parameters are expensive to copy.
 * - function modifies actual parameters
 *
 * Pass-by-reference using a const reference:
 * Ex: void test_pass_const_ref(const int&);
 * - reference cannot be nullptr
 * - parameters are expensive to copy.
 * - function never modify actual parameters
 *
 *******************************************************************************
 +========================+=========+============+============+=======+
 | Function call          | Copy    | Mod actual | Mod ptr or |  null |
 | Pass by Type           |  Params |   params   | ref itself |  Ptr  |
 +========================+=========+============+============+=======+
 | value                  |   Yes   |     No     |   undef    | undef |
 |                        |Expensive|            |            |       |
 +------------------------+---------+------------+------------+-------+
 | Pointer                |   Yes   |     Yes    |     Yes    |  Yes  |
 | pointer to const       |   Yes   |     No     |     Yes    |  Yes  |
 | const pointer  ??????  |   Yes   |     Yes    |     No     |  Yes  | <<< Any use of this type??
 | const pointer to const |   Yes   |     No     |     No     |  Yes  |
 +------------------------+---------+------------+------------+-------+
 | reference              |    No   |     Yes    |   undef    | undef |
 | const reference        |    No   |     No     |   undef    | undef |
 +========================+=========+============+============+=======+
 *******************************************************************************
 */

/**
 * @brief Exercise to run pointers and references
 */
void e12_run(void)
{
    // run_test_ptrs();
    // run_dynamic_mem();
    // run_pointer_array();
    // run_pointer_arithmetic();
    // run_const_pointer();
    // run_pointer_function();
    // run_ptr_ret_func();
    // run_reference();
    // run_l_r_value();
}

} // namespace udemy1
