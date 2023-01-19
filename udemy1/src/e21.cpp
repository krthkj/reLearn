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
 * C++ lambda expressions (C++11 onwards)
 *
 * structure of lambda: [](){}
 * Types : stateless and stateful
 *******************************************************************************
 * Why lambda was created?
 *
 * Prior to C++11
 * - function object
 * - function pointer
 * - we often write many short func that control algorithms
 * - These func would be encapsulated in small class to produce func objects
 * - many times the classes and functions are far away from when they were used leading to modification, maintenance and
 *   testing issues
 * - compiler cannot effectively inline these functions for efficiency
 *
 *******************************************************************************
 * function object (prior to C++11)
 * --------------------------------
 *
 * Example 1:
 * class Multiplier {
 * private:
 *      int num{};
 * public:
 *      Multiplier (int n) : num {n} {}
 *      int operator()(int n) const { return num*n; }
 * }
 *
 * std::vector<int> vec {1,2,3,4};
 * Multiplier mult{10}l
 * std::transform(vec.begin(), vec.end(), vec.begin() Multiplier(10));
 * display(vec);  // vec now contains {10,20,30,40}
 *
 *
 * Example 2:
 * template <typename T>
 * struct Displayer {
 *    void operator()(const T &data) { std::cout << data << " "; }
 * }
 *
 * Displayer<int> d1;
 * Displayer<std::string> d2;
 * d1(100);       // d.operator(100);
 *                // displays 100
 * d2("Frank");   // d.operator("Frank");
 *                // displays Frank
 *
 * std::vector<int> vec1 {1,2,3,4,5};
 * std::vector<std::String> vec2 {"Larry", "Moe", "Curly", "Frank"};
 *
 * std::for_each (vec1.begin(), vec1.end(), Displayer<int>()); // anonymously
 * std::for_each (vec1.begin(), vec1.end(), d1);
 * std::for_each (vec2.begin(), vec2.end(), d2);
 *
 *
 * Example using Lambda:
 * std::vector<int> vec1 {1,2,3,4,5};
 * std::vector<std::String> vec2 {"Larry", "Moe", "Curly", "Frank"};
 *
 * std::for_each (vec1.begin(), vec1.end(), [](int x){ std::cout << x << " ";});
 * std::for_each (vec2.begin(), vec2.end(), [](std::string s){ std::cout << s << " ";});
 *
 *
 * only short function objects should be replaced by lambda
 *
 *******************************************************************************
 * Structure for Lambda expression
 *
 * [ ] ( ) -> return_type specifiers { } ;
 *  ^   ^           ^         ^       ^
 *  |   |           |         |       +---> Body, your code
 *  |   |           |         +-----------> optional specifier, mutable and constexpr
 *  |   |           +---------------------> return type, can be omitted and the complier will try to deduce it
 *  |   +---------------------------------> Parameter list, comma separated list of parameters
 *  +-------------------------------------> capture list, defines the start of the lambda
 *
 *
 * example:
 * [](){ std::cout << "Hello" ;}   ();  // Displays Hello
 *                                  \
 *                                   ---> this is function call that calls the lambda
 *
 * [] (int x) { std::cout << x ;};  // x is passed to the lambda like a parameter
 * [] (int x, int y) { std::cout << x+y ;};
 *
 * auto l = [] () {std::cout<<"Hi";};
 * l(); // Displays Hi
 *
 * [] (int x) {std::cout<<x;}(1000);  // displays 1000
 * auto l = [] (int x) {std::cout<<x;};
 * l(10);   // displays 10
 * l(100);  // displays 100
 *
 * auto l = [] (int x, int y) -> int {return x+y;};  // Actual lambda expression
 * auto l = [] (int x, int y) {return x+y;};         // compiler deduced the return type automatically
 *
 *
 *******************************************************************************
 * Stateless lambda express - empty capture list
 * Stateful lambda express - capture list contains variables
 *******************************************************************************
 * Stateless lambda.
 * ----------------
 *
 * Example:
 * [] () {std::cout<<"Hi";}();       // Displays Hi
 * int x {10};
 * [] (int x) {std::cout<<x;}(100);  // displays 100, local variable x is not the same as lambda variable x
 *
 * example:
 * const int n {3};
 * int nums[n] {10,20,30};
 * auto sum = [] (int nums[], int n){
 *               int sum{0};
 *               for(int i{0}; i<n;++i) sum+= num[i];
 *               return sum;
 *            }
 * std::cout << sum(nums, 3);  // displays 60
 *
 * example:
 * int y;
 * auto y = [](int x) { return x * x; };   // Passing by value,
 * x = y(x);
 *
 * auto l1 = [] (int& x) { x*=x; };        // passing by reference, no need to return
 * l1(y);
 *
 * auto l2 = [] (int* x) { (*x)*=(*x); }    // passing by pointers, no need to return
 * l2(&y);
 *
 * Example:
 * int num1{10};
 * float num2{15.5};
 * auto l = [] (auto x) {std::cout << x ;};
 * l(num1);  // valid for int
 * l(num2);  // valid for float
 *
 *******************************************************************************
 * lambda express as func parameters
 *
 * #include <functional> // for std::function
 *
 * void foo (std::function < void (int) > l ){   // C++14, here 'void' is return type, 'int' is parameter type
 *      l(10);
 * }
 *
 * or
 *
 * void foo (void (*l) (int)) {    // C++14, here 'void' is return type, 'int' is parameter type
 *      l(10);
 * }
 *
 * or
 *
 * void foo (auto l){              // C++20, here using auto, compiler deduces the return and parameter types
 *      l(10);
 * }
 *
 *******************************************************************************
 * #include <functional> // for std::function
 *
 * void foo (std::function < void (int) > l ){
 *      return [] (int x) {std::cout << x;};
 * }
 *
 * or
 *
 * void (*foo ()) (int) {       // Old style C syntax for backward compatibility
 *      return [] (int x) {std::cout << x;};
 * }
 *
 * or
 *
 * auto foo (){
 *      return [] (int x) {std::cout << x;};
 * }
 *
 * all the above version can be used the same way
 * auto l = foo();
 * l(10);   // displays 10
 *
 *******************************************************************************
 * foo( [] (int x) {std::cout << x;});
 * or
 * auto l = [] (int x) {std::cout << x;};
 * foo(l);
 *
 *******************************************************************************
 * predicate lambda
 *
 * void print_if(std::vector<int> num, bool (*predicate) int){
 *     for(int i : nums)
 *         if (predicate (i)) std::cout << i;
 * }
 *
 * int main (){
 *     std::vector <int> nums {1,2,3};
 *     print_if(nums, [] (auto x) {return x%2 == 0;});   // Displays evens
 *     print_if(nums, [] (auto x) {return x%2 != 0;});   // Displays odds
 *     return 0;
 * }
 *******************************************************************************
 * Statefull Lambda
 * ----------------
 * - Non-empty capture list, defines what information /variable show be captures
 *
 * [ captured_variables] () -> return_type specifiers { };
 *
 * example:
 * int x{100};
 * [x](){std::cout << x;}();     // displays 100 - by default x will be captured using a const lambda operator()
 *
 * [x]() mutable {               // tells the lambda operator to be non-const function
 *       x+=1;
 *       std::cout << x;         // displays 200
 * }();
 * std::cout << x ;              // displays 100
 *
 * [x](){x+=100;}();             // Pass by reference,
 * std::cout << x ;              // displays 200
 *
 *******************************************************************************
 * Default captures
 *
 * [=]    - default capture by value
 * [&]    - default capture by reference
 * [this] - default capture this object by reference
 *
 * Combination of default and explicit captures
 * [=, &x]    // default capture by value but capture x by reference
 * [&, y]     // default capture by reference but capture y by value
 * [this, z]  // default capture this by reference but capture z by value
 *
 * Note: default capture (=, & , this) should be the placed first
 *******************************************************************************
 *******************************************************************************
 *******************************************************************************
 *******************************************************************************
 *
 *
 *
###############################################################################
Stateless Lambda definition
-----------------------------
auto l = [] (int x) {std::cout << x+y;};

Compiler-generated closure
---------------------------
class CompilerGeneratedName{
  public:
    CompilerGeneratedName();
    void operator()(int x) { std::cout << x; }
};

###############################################################################
Stateful Lambda definition
---------------------------
int y{10};
auto l = [y] (int x) {std::cout << x+y;};

Compiler-generated closure
---------------------------
class CompilerGeneratedName{
  private:
    int y;
  public:
    CompilerGeneratedName(int y): y{y} {}
    void operator()(int x) const { std::cout << x + y; }
};

###############################################################################
Stateful Lambda definition mutable
---------------------------
int y{10};
auto l = [y] (int x) mutable {std::cout << x+y;};

Compiler-generated closure
---------------------------
class CompilerGeneratedName{
  private:
    int y;
  public:
    CompilerGeneratedName(int y): y{y} {}
    void operator()(int x) { std::cout << x + y; }
};

###############################################################################
 */

#include "udemy1.hpp"

#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric> // for std::iota
#include <vector>

int global_x{1000};

namespace udemy1::e21
{

struct Square_Functor {
    void operator()(int x)
    {
        std::cout << x * x << " ";
    }
};

template <typename T>
struct Displayer {
    void operator()(const T& data)
    {
        std::cout << data << " ";
    }
};

class Multiplier
{
  private:
    int num{};

  public:
    Multiplier(int n)
        : num{n}
    {
    }

    int operator()(int n) const
    {
        return n * num;
    }
};

void run_lambda_test_1(void)
{
    std::cout << "\nTest1 =========================" << std::endl;
    Square_Functor square;
    square(4); // square.operator()(4)          displays 16

    Displayer<int> d1;
    Displayer<std::string> d2;
    d1(100);     // Displays 100
    d2("Frank"); // displays Frank
    std::cout << std::endl;

    std::cout << "\nTest2 =========================" << std::endl;
    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<std::string> vec2{"Larry", "Moe", "Curly", "Frank"};

    std::for_each(vec1.begin(), vec1.end(), square); // 1 4 9 16 25
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), Displayer<int>()); // 1 2 3 4 5
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), d1); // 1 2 3 4 5
    std::cout << std::endl;

    std::for_each(vec2.begin(), vec2.end(), Displayer<std::string>()); // Larry Moe Curly Frank
    std::cout << std::endl;

    std::for_each(vec2.begin(), vec2.end(), d2); // Larry Moe Curly Frank
    std::cout << std::endl;

    std::cout << "\nTest3 =========================" << std::endl;
    std::for_each(vec1.begin(), vec1.end(), [](int x) { std::cout << x * x << " "; }); // 1 4 9 16 25
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), [](int x) { std::cout << x * 10 << " "; }); // 10 20 30 40 50
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), [](int x) { std::cout << x << " "; }); // 1 2 3 4 5
    std::cout << std::endl;

    std::for_each(vec2.begin(), vec2.end(), [](std::string s) { std::cout << s << " "; }); // Larry Moe Curly Frank
    std::cout << std::endl;

    std::cout << "\nTest3 =========================" << std::endl;
    Multiplier mult{100};
    vec1 = {1, 2, 3, 4};

    // transform changes the vector
    std::transform(vec1.begin(), vec1.end(), vec1.begin(), mult);
    std::for_each(vec1.begin(), vec1.end(), d1);
    std::cout << std::endl;

    vec1 = {1, 2, 3, 4};
    std::transform(vec1.begin(), vec1.end(), vec1.begin(), [](int x) { return x * 100; });
    std::for_each(vec1.begin(), vec1.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;
}

class Person
{
    friend std::ostream& operator<<(std::ostream& os, const Person& rhs);

  private:
    std::string name;
    int age;

  public:
    Person(std::string name, int age)
        : name{name}
        , age{age} {};

    Person(const Person& p)
        : name{p.name}
        , age{p.age}
    {
    }

    ~Person() = default;

    std::string get_name() const
    {
        return name;
    }

    void set_name(std::string name)
    {
        this->name = name;
    };

    int get_age() const
    {
        return age;
    }

    void set_age(int age)
    {
        this->age = age;
    }
};

std::ostream& operator<<(std::ostream& os, const Person& rhs)
{
    os << "[Person: " << rhs.name << " : " << rhs.age << "]";
    return os;
}

/**
 * @brief Stateless lambda expression examples
 */
void run_lambda_stateless_1(void)
{
    std::cout << "\nStateless lambda Test1 =========================" << std::endl;

    []() { std::cout << "Hi" << std::endl; }();

    [](int x) { std::cout << x << std::endl; }(100);

    [](int x, int y) { std::cout << y + x << std::endl; }(100, 200);
}

void run_lambda_stateless_2(void)
{
    std::cout << "\nStateless lambda Test2 =========================" << std::endl;
    auto l1 = []() { std::cout << "Hi" << std::endl; };
    l1();

    int num1{100};
    int num2{200};

    auto l2 = [](int x, int y) { std::cout << y + x << std::endl; };
    l2(10, 20);
    l2(num1, num2);

    auto l3 = [](int& x, int y) {
        std::cout << "x: " << x << " y: " << y << std::endl;
        x = 1000;
        y = 2000;
    };
    l3(num1, num2);
    std::cout << "num1: " << num1 << " num2: " << num2 << std::endl;
}

void run_lambda_stateless_3(void)
{
    std::cout << "\nStateless lambda Test3 =========================" << std::endl;
    Person stooge{"Larry", 18};
    std::cout << stooge << std::endl;

    auto l4 = [](Person p) { std::cout << p << std::endl; }; // pass by value
    l4(stooge);

    auto l5 = [](const Person& p) { std::cout << p << std::endl; }; // pass by reference
    l5(stooge);

    auto l6 = [](Person& p) { // pass by reference
        p.set_age(25);
        p.set_name("Frank");
        std::cout << p << std::endl;
    };
    l6(stooge);

    auto l7 = [](Person* p) { // pass by pointer
        p->set_age(80);
        p->set_name("Moe");
        std::cout << *p << std::endl;
    };
    l7(&stooge);
}

// used for run_lambda_test_3()
// std::function as a parameter in C++14 and greater
// or
// auto as parameter type in C++20
void filter_vector(const std::vector<int>& vec, auto func) // C++20 format
// void filter_vector(const std::vector<int>& vec, std::function<bool(int)> func) // C++14 onwards
// here <bool(int)> func - is predicate lambda
{
    std::cout << "[";
    for (int i : vec)
        if (func(i))
            std::cout << i << " ";
    std::cout << "]" << std::endl;
}

void run_lambda_stateless_4(void)
{
    std::cout << "\nStateless lambda Test4 ===== predicate lambda ==" << std::endl;

    std::vector<int> nums{10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    filter_vector(nums, [](int x) { return x > 50; });

    filter_vector(nums, [](int x) { return x < 50; });

    filter_vector(nums, [](int x) { return x >= 30 && x <= 60; });
}

auto make_lambda()
{
    return []() { std::cout << "This lambda was made using the make_lambda function!" << std::endl; };
}

void run_lambda_stateless_5(void)
{
    std::cout << "\nStateless lambda Test5 ===== func return lambda ==" << std::endl;
    auto l5 = make_lambda();
    l5();
}

void run_lambda_stateless_6(void)
{
    std::cout << "\nStateless lambda Test3 =========================" << std::endl;
    auto l6 = [](auto x, auto y) { std::cout << "x: " << x << " y: " << y << std::endl; };

    l6(10, 20);
    l6(100.3, 200);
    l6(102.5, 15.48);

    l6(Person("Larry", 18), Person("Curly", 50));
}

void run_lambda_stateless_7(void)
{
    std::cout << "\n---Test7 --------------------------" << std::endl;

    std::vector<Person> stooges{{"Larry", 18}, {"Moe", 30}, {"Curly", 25}};

    std::sort(begin(stooges), end(stooges), // begin(stooges) === stooges.being()
              [](const Person& p1, const Person p2) { return p1.get_name() < p2.get_name(); });
    std::for_each(begin(stooges), end(stooges), [](const Person& p) { std::cout << p << std::endl; });

    std::cout << std::endl;

    std::sort(begin(stooges), end(stooges),
              [](const Person& p1, const Person p2) -> bool { return p1.get_age() < p2.get_age(); });
    std::for_each(begin(stooges), end(stooges), [](const Person& p) -> void { std::cout << p << std::endl; });
}

// Capture by value
// The global variable global_x cannot be captured because it is not
// within the reaching scope of the lambda. It can however still be accessed
// from within the lambda using normal name lookup rules.
void run_lambda_stateful_1(void)
{
    std::cout << "\n---Test1 --------------------------" << std::endl;
    int local_x{100};
    auto l = [local_x]() {                  // capture by value, variable captured by copy in a non-mutable lambda
        std::cout << local_x << std::endl;  // local copy of local_x
        std::cout << global_x << std::endl; // its going to find the global because of scope rules
    };
    l();
}

// Capture by value - mutable
// The captured variable x can only be modified within the lambda by
// using the mutable keyword. Note that this modifiability only pertains to
// the captured variable within the lambda body and not the actual variable.
void run_lambda_stateful_2(void)
{
    std::cout << "\n---Test2 --------------------------" << std::endl;
    int x{100};
    auto l = [x]() mutable { // capture by value, variable captured by copy in a mutable lambda
                             // here the constructor is called , refer the Compiler-generated closure,
                             // the constructor is called only once.
        x += 100;            // able to modify because of mutable specifier
        std::cout << x << std::endl;
    };
    l(); // operator() is called, nothing is captured here
    std::cout << x << std::endl;

    l(); // calling this lambda executes, we dont capture again, we reuse the already captured x, which value is 200
         // here the operator() is called not the lambda constructor
    std::cout << x << std::endl;
}

// Capture by reference
// Any changes made to the captured reference variable within the lambda body
// will change the actual variable.
void run_lambda_stateful_3(void)
{
    std::cout << "\n---Test3 --------------------------" << std::endl;
    int x{100};
    auto l = [&x]() mutable { // capture by reference, variable captured by copy in a mutable lambda
        x += 100;
        std::cout << x << std::endl;
    };
    l();
    std::cout << x << std::endl;
}

// Default capture by value - mutable
// Only variables used within the lambda body are captured by value.
// The variable z is not captured by the lambda.
void run_lambda_stateful_4(void)
{
    std::cout << "\n---Test4 --------------------------" << std::endl;
    int x{100};
    int y{200};
    int z{300};

    auto l = [=]() mutable {
        x += 100;
        y += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
    };

    l();
    std::cout << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

// Default capture by reference
// This time because all three variables - x,y,z are used within
// the lambda body, all three of them will be captured by reference.
void run_lambda_stateful_5(void)
{
    std::cout << "\n---Test5 --------------------------" << std::endl;
    int x{100};
    int y{200};
    int z{300};

    auto l = [&]() mutable {
        x += 100;
        y += 100;
        z += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };

    l();
    std::cout << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

// Default capture by value, capture y by reference
void run_lambda_stateful_6(void)
{
    std::cout << "\n---Test6 --------------------------" << std::endl;
    int x{100};
    int y{200};
    int z{300};

    auto l = [=, &y]() mutable {
        x += 100;
        y += 100;
        z += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };

    l();
    std::cout << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

// Default capture by reference, capture x and z by value
// Equivalent to test6
void run_lambda_stateful_7(void)
{
    std::cout << "\n---Test7 --------------------------" << std::endl;
    int x{100};
    int y{200};
    int z{300};

    auto l = [&, x, z]() mutable {
        x += 100;
        y += 100;
        z += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };

    l();
    std::cout << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

// Used for run_lambda_stateful_8
class Person_2
{
    friend std::ostream& operator<<(std::ostream& os, const Person_2& rhs);

  private:
    std::string name;
    int age;

  public:
    Person_2() = default;
    Person_2(const Person_2& p) = default;
    ~Person_2() = default;

    Person_2(std::string name, int age)
        : name{name}
        , age{age}
    {
    }

    std::string get_name() const
    {
        return name;
    }

    void set_name(std::string name)
    {
        this->name = name;
    };

    int get_age() const
    {
        return age;
    }

    void set_age(int age)
    {
        this->age = age;
    }

    auto change_person1()
    {                                                      // always you [this] going forward
        return [this](std::string new_name, int new_age) { // recommended
            name = new_name;
            age = new_age;
        };
    }

    auto change_person2()
    { // [=] is deprecated in C++20, try avoid using this syntax
        return [=](std::string new_name, int new_age) {
            name = new_name;
            age = new_age;
        };
    }

    auto change_person3()
    {
        return [&](std::string new_name, int new_age) {
            name = new_name;
            age = new_age;
        };
    }
};

std::ostream& operator<<(std::ostream& os, const Person_2& rhs)
{
    os << "[Person_2: " << rhs.name << " : " << rhs.age << "]";
    return os;
}

// Default capture by reference of the current object using [this]
// [=], [&], and [this] are equivalent when capturing an object's member variables - all are captured by reference
// Notre that capturing this with [=] has been deprecated in C++20
// Also, C++20 allows [*this], which captures by value!
void run_lambda_stateful_8(void)
{
    std::cout << "\n---Test8 --------------------------" << std::endl;
    Person_2 person("Larry", 15);
    std::cout << person << std::endl;

    // default capture [this]
    auto change_person1 = person.change_person1();
    change_person1("Moe", 30);
    std::cout << person << std::endl;

    // default capture [=]
    auto change_person2 = person.change_person2();
    change_person2("Peter", 20);
    std::cout << person << std::endl;

    // default capture [&]
    auto change_person3 = person.change_person3();
    change_person3("Sam", 80);
    std::cout << person << std::endl;
}

// Used for run_lambda_stateful_9
class Lambda
{
  private:
    int y;

  public:
    Lambda(int y)
        : y{y} {};

    void operator()(int x) const
    {
        std::cout << x + y << std::endl;
    };
};

// Lambda class equivalence example
void run_lambda_stateful_9(void)
{
    std::cout << "\n---Test9 --------------------------" << std::endl;

    int y{100};
    Lambda lambda1(y);
    auto lambda2 = [y](int x) { std::cout << x + y << std::endl; };

    lambda1(200);
    lambda2(200);
}

// Class used in the test10() example
class People
{
    std::vector<Person_2> people;
    int max_people;

  public:
    People(const People& p) = default;

    People(int max = 10)
        : max_people(max)
    {
    }

    void add(std::string name, int age)
    {
        people.emplace_back(name, age);
    }

    void set_max_people(int max)
    {
        max_people = max;
    }

    int get_max_people() const
    {
        return max_people;
    }

    // This method returns a vector of Person_2 objects in
    // people whose age > max_age AND it limits the number of
    // persons returned to be <= the member variable max_people.
    // Note that the lambda in this example captures this, by reference, and by value
    std::vector<Person_2> get_people(int max_age)
    {
        std::vector<Person_2> result;
        int count{0};
        std::copy_if(
            people.begin(), people.end(), std::back_inserter(result),
            [this, &count, max_age](const Person_2& p) { return p.get_age() > max_age && ++count <= max_people; });
        return result;
    }
};

void run_lambda_stateful_10(void)
{
    std::cout << "\n---Test9 --------------------------" << std::endl;
    People friends;
    friends.add("Larry", 18);
    friends.add("Curly", 25);
    friends.add("Moe", 35);
    friends.add("Frank", 28);
    friends.add("James", 65);

    auto result = friends.get_people(17);
    for (const auto& p : result)
        std::cout << p << std::endl;
    std::cout << std::endl;

    friends.set_max_people(3);

    result = friends.get_people(17);
    for (const auto& p : result)
        std::cout << p << std::endl;
    std::cout << std::endl;
}

// See cppreference.com for documentation
// for the STL algorithms

// for_each - Non-modifying sequence operation
// Displays each element of nums.
void run_lambda_stl_1(void)
{
    std::cout << "\n---Test1 --------------------------" << std::endl;
    std::vector<int> nums{10, 20, 30, 40, 50, 60};
    // no capture, just one parameters, simple example
    std::for_each(nums.begin(), nums.end(), [](int num) { std::cout << num << " "; });
    std::cout << std::endl;
}

// is_permutation - Non-modifying sequence operation
// Tests whether two triangles are equivalent.
// Triangles are defined by a vector of three points in any order.
// Regardless of the order of points, if two triangles contain the
// same three points then they are equivalent.
// This is determined by testing whether one sequence of points is a
// permutation of another using a predicate lambda to compare points.
void run_lambda_stl_2(void)
{
    std::cout << "\n---Test2 --------------------------" << std::endl;

    struct Point {
        int x;
        int y;
    };

    Point pt1{1, 2};
    Point pt2{4, 3};
    Point pt3{3, 5};
    Point pt4{3, 1};

    std::vector<Point> triangle1{pt1, pt2, pt3};
    std::vector<Point> triangle2{pt2, pt3, pt1};
    std::vector<Point> triangle3{pt1, pt2, pt4};

    // using predicate lambda

    // Test whether triangle1 and triangle2 are equivalent
    if (std::is_permutation(triangle1.begin(), triangle1.end(), triangle2.begin(), triangle2.end(),
                            [](Point lhs, Point rhs) { return lhs.x == rhs.x && lhs.y == rhs.y; }))
        std::cout << "Triangle1 and Triangle2 are equivalent!" << std::endl;
    else
        std::cout << "Triangle1 and Triangle2 are not equivalent!" << std::endl;

    // Test whether triangle1 and triangle3 are equivalent
    if (std::is_permutation(triangle1.begin(), triangle1.end(), triangle3.begin(), triangle3.end(),
                            [](Point lhs, Point rhs) { return lhs.x == rhs.x && lhs.y == rhs.y; }))
        std::cout << "Triangle1 and triangle3 are equivalent!" << std::endl;
    else
        std::cout << "Triangle1 and triangle3 are not equivalent!" << std::endl;
}

void run_lambda_stl_3(void)
{
    std::cout << "\n---Test3 --------------------------" << std::endl;
    std::vector<int> test_scores{93, 88, 75, 86, 69};
    int bonus_points{5};
    std::transform(test_scores.begin(), test_scores.end(), test_scores.begin(),
                   [bonus_points](int score) { return score += bonus_points; });
    std::for_each(test_scores.begin(), test_scores.end(), [](int x) { std::cout << x << " "; });
}

// remove_if - Modifying sequence operation
// This example is what's known as an erase-remove idiom and is one of
// the most common uses of lambdas with the standard template library.
// The remove_if function removes all elements for which the predicate
// lambda returns true. The way in which it does this is by replacing
// each element for which the predicate returns true with the next element
// for which the predicate returns false. The function then returns an
// iterator to the new end of the sequence.
// The size of the sequence is not altered, only the position of its
// elements and its end iterator.
// Used in conjunction with the vector member function "erase", the
// removed elements can be erased from the vector so that it only contains
// the elements for which the predicate returned false.
// In this case, the erase-remove idiom is used to remove all even numbers from nums.
void run_lambda_stl_4(void)
{
    std::cout << "\n---Test4 --------------------------" << std::endl;
    std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    nums.erase(std::remove_if(nums.begin(), nums.end(), [](int n) { return n % 2 == 0; }), nums.end());
    std::for_each(nums.begin(), nums.end(), [](int n) { std::cout << n << " "; });
}

// sort - Sorting
// Sorts elements in the sequence according to the predicate lambda.
// In this example, a vector of people is first sorted by name in ascending order
// and then by age in descending order.
void run_lambda_stl_5(void)
{
    std::cout << "\n---Test5 --------------------------" << std::endl;

    Person person1("Larry", 18);
    Person person2("Moe", 30);
    Person person3("Curly", 25);
    std::vector<Person> people{person1, person2, person3};

    // sort people by name ascending order
    std::sort(people.begin(), people.end(), [](Person lhs, Person rhs) { return lhs.get_name() < rhs.get_name(); });
    std::for_each(people.begin(), people.end(), [](Person p) { std::cout << p << std::endl; });
}

// in_between is used for test6
// all_of - Non-modifying sequence operation
// Tests whether all elements contained within the sequence satisfy the
// condition defined by the passed predicate lambda.
bool in_between(const std::vector<int>& nums, int start_value, int end_value)
{
    bool result{false};
    result = std::all_of(nums.begin(), nums.end(),
                         [start_value, end_value](int value) { return value >= start_value && value <= end_value; });
    return result;
}

void run_lambda_stl_6(void)
{
    std::cout << "\n---Test6 --------------------------" << std::endl;
    std::cout << std::boolalpha;

    std::vector<int> nums(10); // create vector of 10 elements

    std::iota(nums.begin(), nums.end(), 1);

    for (int num : nums)
        std::cout << num << " ";

    std::cout << std::endl;

    std::cout << in_between(nums, 50, 60) << std::endl;
    std::cout << in_between(nums, 1, 10) << std::endl;
    std::cout << in_between(nums, 5, 7) << std::endl;
}

// The following classes are used for run_lambda_stl_7
class Password_Validator1
{
  private:
    char restricted_symbol{'$'};

  public:
    bool is_valid(std::string password)
    {
        return std::all_of(password.begin(), password.end(),
                           [this](char character) { return character != restricted_symbol; });
    }
};

class Password_Validator2
{
  private:
    std::vector<char> restricted_symbols{'!', '$', '+'};

  public:
    bool is_valid(std::string pwd)
    {
        return std::all_of(pwd.begin(), pwd.end(), [this](char ch) {
            return std::none_of(restricted_symbols.begin(), restricted_symbols.end(),
                                [ch](char rs) { return ch == rs; });
        });
    }
};

// all_of - Non-modifying sequence operation
// Tests whether all elements contained within the sequence satisfy the
// condition defined by the passed predicate lambda.
// In this case, the all_of function is contained within the class
// Password_Validator which determines whether a password contains
// a restricted symbol and thus is valid or not.
// The same can be accomplished by using the stl function "none_of" and
// changing the conditional contained within the passed lambda.
void run_lambda_stl_7(void)
{
    std::cout << "\n---Test7 --------------------------" << std::endl;

    // Password_Validator1 --------------------------------------------------
    std::string password{"holywood1$"};
    Password_Validator1 pv1;

    // Test whether password is valid
    if (pv1.is_valid(password))
        std::cout << "The password " << password << " is valid!" << std::endl;
    else
        std::cout << "The password " << password << " is not valid!" << std::endl;

    // Test whether new password is valid
    password = "hollywood1";
    if (pv1.is_valid(password))
        std::cout << "The password " << password << " is valid!" << std::endl;
    else
        std::cout << "The password " << password << " is not valid!" << std::endl;

    std::cout << "\n";

    // Password_Validator2 --------------------------------------------------
    password = "C++Rocks!";
    Password_Validator2 pv2;

    // Test whether password is valid
    if (pv2.is_valid(password))
        std::cout << "The password " << password << " is valid!" << std::endl;
    else
        std::cout << "The password " << password << " is not valid!" << std::endl;

    // Test whether new password is valid
    password = "CPlusPlusRocks!";
    if (pv2.is_valid(password))
        std::cout << "The password " << password << " is valid!" << std::endl;
    else
        std::cout << "The password " << password << " is not valid!" << std::endl;

    // Test whether new password is valid
    password = "CPlusPlusRocks";
    if (pv2.is_valid(password))
        std::cout << "The password " << password << " is valid!" << std::endl;
    else
        std::cout << "The password " << password << " is not valid!" << std::endl;
}

} // namespace udemy1::e21

void udemy1::e21_run(void)
{
    // udemy1::e21::run_lambda_test_1();
    // udemy1::e21::run_lambda_stateless_1();
    // udemy1::e21::run_lambda_stateless_2();
    // udemy1::e21::run_lambda_stateless_3();
    // udemy1::e21::run_lambda_stateless_4();
    // udemy1::e21::run_lambda_stateless_5();
    // udemy1::e21::run_lambda_stateless_6();

    // udemy1::e21::run_lambda_stateful_1();
    // udemy1::e21::run_lambda_stateful_2();
    // udemy1::e21::run_lambda_stateful_3();
    // udemy1::e21::run_lambda_stateful_4();
    // udemy1::e21::run_lambda_stateful_5();
    // udemy1::e21::run_lambda_stateful_6();
    // udemy1::e21::run_lambda_stateful_7();
    // udemy1::e21::run_lambda_stateful_8();
    // udemy1::e21::run_lambda_stateful_9();
    // udemy1::e21::run_lambda_stateful_10();

    udemy1::e21::run_lambda_stl_1();
    udemy1::e21::run_lambda_stl_2();
    udemy1::e21::run_lambda_stl_3();
    udemy1::e21::run_lambda_stl_4();
    udemy1::e21::run_lambda_stl_5();
    udemy1::e21::run_lambda_stl_6();
    udemy1::e21::run_lambda_stl_7();
}
