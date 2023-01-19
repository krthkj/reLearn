#ifndef MYSTRING_HPP
#define MYSTRING_HPP

#include <iostream>

namespace udemy1::myclass
{

class Mystring
{
    friend std::ostream& operator<<(std::ostream& os, const Mystring& rhs);
    friend std::ostream& operator>>(std::istream& is, Mystring& rhs);

  private:
    char* str; // pointer to a char[] that holds a C-style string
  public:
    Mystring();                        // default constructor
    Mystring(const char* s);           // arg constructor
    Mystring(const Mystring& src);     // copy constructor
    Mystring(Mystring&& src) noexcept; // move constructor
    ~Mystring();                       // destructor

    Mystring& operator=(const Mystring& src);     // copy assignment Op-Over...
    Mystring& operator=(Mystring&& src) noexcept; // move assignment Op-Over...

    void display(void);             // display string
    int getLength() const;          // get string length
    const char* getStr(void) const; // getstring

    Mystring operator-() const; // unary minus operator overloading
    Mystring& operator++();     // pre increment operator overloading
    Mystring operator++(int);   // post increment operator overloading

    bool operator==(const Mystring& rhs) const; // Binary equals operator overloading
    bool operator!=(const Mystring& rhs) const; // Binary not equals operator overloading
    bool operator<(const Mystring& rhs) const;  // Binary less than operator overloading
    bool operator>(const Mystring& rhs) const;  // Binary greater than operator overloading

    Mystring operator+(const Mystring& rhs) const; // Binary plus operator overloading
    Mystring operator*(const int rhs) const;       // Binary multiply operator overloading

    Mystring& operator+=(const Mystring& rhs); // Binary plus-equal operator overloading
    Mystring& operator*=(const int rhs);       // Binary multiply-equal operator overloading
};

} // namespace udemy1::myclass

#endif // MYSTRING_HPP
