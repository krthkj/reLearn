#ifndef E20_CLASS_TEMPLATE_HPP
#define E20_CLASS_TEMPLATE_HPP

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Namespace for examples for template functions
 */
namespace udemy1::e20::functions
{

/**
 * @brief Template for calculating minumin
 * @param a
 * @param b
 */
template <typename T> T min(T a, T b)
{
    return (a < b) ? a : b;
}

/**
 * @brief template function to print two variables
 * @param a
 * @param b
 */
template <typename T1, typename T2> void func(T1 a, T2 b)
{
    std::cout << a << " " << b << std::endl;
}

struct Person {
    std::string name;
    int age;

    /**
     * @brief operator'<' overloading funcion to help template function 'min'
     * @param rhs
     */
    bool operator<(const Person& rhs) const
    {
        return this->age < rhs.age;
    }
};

/**
 * @brief template function for swapping two vairables
 * @param a
 * @param b
 */
template <typename T> void my_swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}
} // namespace udemy1::e20::functions

/**
 * @brief Namespace for examples for template class
 */
namespace udemy1::e20::classes
{

template <typename T> class Item
{
    // friend std::ostream& operator<<(std::ostream& os, const Item<T>& obj);
  private:
    std::string name;
    T value;

  public:
    Item(std::string n, T v)
        : name{n}
        , value{v}
    {
    }
    std::string get_name() const
    {
        return name;
    }
    T get_value() const
    {
        return value;
    }
};

template <typename T> std::ostream& operator<<(std::ostream& os, const Item<T>& obj)
{
    os << obj.get_name() << " " << obj.get_value();
    return os;
}

template <typename T1, typename T2> struct My_Pair {
    T1 first;
    T2 second;
};

template <typename T1, typename T2> std::ostream& operator<<(std::ostream& os, const My_Pair<T1, T2>& obj)
{
    os << obj.first << ", " << obj.second;
    return os;
}

} // namespace udemy1::e20::classes

/**
 * @brief Namespace to implement a class template for array
 *        C++11 alreay has an implementations, we are simply learning how this is created
 */
namespace udemy1::e20::ArrayClass
{

/**
 * @class My_Array
 * @author Karthik Jain
 * @date 08/01/23
 * @file e20_class_template.hpp
 * @brief This is a template class for for arry with specific data type (int)
 */
template <int N> class My_Array
{
    friend std::ostream& operator<<(std::ostream& os, const My_Array& arr)
    {
        os << "[";
        for(const auto& a : arr.value)
            os << a << " ";
        os << "]" << std::endl;
        return os;
    }

  private:
    int size{N};  // TODO: how to get the value of N?
    int value[N]; // the N needs to know at compiler-time
  public:
    My_Array() = default;
    ~My_Array() = default;
    My_Array(int init_val)
    {
        for(auto& item : this->value)
            item = init_val;
    }
    void fill(int val)
    {
        for(auto& item : this->value)
            item = val;
    }
    int get_size() const
    {
        return size;
    }
    // overloaded subscript operator for easy use
    int& operator[](int idx)
    {
        return value[idx];
    }
};

/**
 * @class My_Array_Generic
 * @author Karthik Jain
 * @date 08/01/23
 * @file e20_class_template.hpp
 * @brief This is a generic template class for array
 */
template <typename T, int N> class My_Array_Generic
{
    friend std::ostream& operator<<(std::ostream& os, const My_Array_Generic<T, N>& arr)
    {
        os << "[";
        for(const auto& a : arr.value)
            os << a << " ";
        os << "]" << std::endl;
        return os;
    }

  private:
    int size{N}; // TODO: how to get the value of N?
    T value[N];  // the N needs to know at compiler-time
  public:
    My_Array_Generic() = default;
    ~My_Array_Generic() = default;
    My_Array_Generic(T init_val)
    {
        for(auto& item : this->value)
            item = init_val;
    }
    void fill(T val)
    {
        for(auto& item : this->value)
            item = val;
    }
    int get_size() const
    {
        return size;
    }
    // overloaded subscript operator for easy use
    T& operator[](int idx)
    {
        return value[idx];
    }
};
} // namespace udemy1::e20::ArrayClass

#endif // E20_CLASS_TEMPLATE_HPP
