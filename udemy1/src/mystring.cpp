#include "mystring.hpp"

#include <cstring>

namespace udemy1::myclass
{

/**
 * @brief Mystring - Default constructor
 */
Mystring::Mystring()
    : str{nullptr}
{
    this->str  = new char[1];
    *this->str = '\0';
}

/**
 * @brief Mystring - Arg constructor
 * @param src
 */
Mystring::Mystring(const char* s)
    : str{nullptr}
{
    if (s == nullptr) {
        this->str  = new char[1];
        *this->str = '\0';
    } else {
        this->str = new char[std::strlen(s) + 1];
        std::strcpy(this->str, s);
    }
}

/**
 * @brief Mystring - Copy constructor
 * @param src
 */
Mystring::Mystring(const Mystring& src)
    : str{nullptr}
{
    this->str = new char[std::strlen(src.str) + 1];
    std::strcpy(this->str, src.str);
}

/**
 * @brief Mystring - Move constructor
 * @param src
 */
Mystring::Mystring(Mystring&& src) noexcept
    : str{nullptr}
{
    this->str = src.str;
    src.str   = nullptr;
}

/**
 * @brief Mystring destructor
 */
Mystring::~Mystring()
{
    delete[] str;
}

/**
 * @brief Mystring copy assignment operator overloading
 */
Mystring& Mystring::operator=(const Mystring& src)
{
    if (this == &src)
        return *this;

    delete[] this->str;

    this->str = new char[std::strlen(src.str) + 1];
    std::strcpy(this->str, src.str);

    return *this;
}

/**
 * @brief Mystring move assignment operator overloading
 */
Mystring& Mystring::operator=(Mystring&& src) noexcept
{
    if (this == &src)
        return *this;

    delete[] this->str;

    this->str = src.str;
    src.str   = nullptr;

    return *this;
}

/**
 * @brief Display function to print the object
 */
void Mystring::display(void)
{
    std::cout << this->str << ":" << getLength() << std::endl;
}

/**
 * @brief calculate the string length
 */
int Mystring::getLength() const
{
    return std::strlen(this->str);
}

/**
 * @brief getter method for 'str'
 */
const char* Mystring::getStr(void) const
{
    return this->str;
}

std::ostream& operator<<(std::ostream& os, const Mystring& rhs)
{
    os << rhs.str;
    return os;
}

/**
 * @brief Binary equals operator overloading
 * @param rhs
 */
bool Mystring::operator==(const Mystring& rhs) const
{
    return (std::strcmp(this->str, rhs.str) == 0);
}

/**
 * @brief Binary not equals operator overloading
 * @param rhs
 */
bool Mystring::operator!=(const Mystring& rhs) const
{
    return !(*this == rhs);
}

/**
 * @brief Binary less than operator overloading
 * @param rhs
 */
bool Mystring::operator<(const Mystring& rhs) const
{
    return (std::strcmp(this->str, rhs.str) < 0);
}

/**
 * @brief Binary greater than operator overloading
 * @param rhs
 */
bool Mystring::operator>(const Mystring& rhs) const
{
    return (std::strcmp(this->str, rhs.str) > 0);
}

/**
 * @brief Unary minus operator overloading
 */
Mystring Mystring::operator-() const
{
    Mystring tmp{this->str};
    size_t s = this->getLength();

    for (size_t i{0}; i < s; ++i)
        tmp.str[i] = std::tolower(tmp.str[i]);

    return tmp;
}

/**
 * @brief Binary plus operator overloading
 * @param rhs
 */
Mystring Mystring::operator+(const Mystring& rhs) const
{
    char* buff = new char[std::strlen(this->str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, this->str);
    std::strcat(buff, rhs.str);
    Mystring tmp{buff};
    delete[] buff;
    return tmp;
}

/**
 * @brief Binary multiply operator overloading
 * @param n
 */
Mystring Mystring::operator*(const int n) const
{
    Mystring tmp;
    for (int i{1}; i <= n; ++i)
        tmp = tmp + *this;
    return tmp;
}

/**
 * @brief Unary pre increment operator overloading
 */
Mystring& Mystring::operator++()
{
    size_t s = this->getLength();
    for (size_t i{0}; i < s; ++i)
        this->str[i] = std::toupper(this->str[i]);
    return *this;
}

/**
 * @brief Unary post increment operator overloading
 */
Mystring Mystring::operator++(int)
{
    Mystring temp(*this); // make a copy
    operator++();         // call pre-increment - make sure you call pre-increment!
    return temp;          // return the old value
}

/**
 * @brief Binary plus equaloperator overloading
 * @param rhs
 */
Mystring& Mystring::operator+=(const Mystring& rhs)
{
    *this = *this + rhs;
    return *this;
}

/**
 * @brief Binary multiply equal operator overloading
 * @param n
 */
Mystring& Mystring::operator*=(const int rhs)
{
    *this = *this * rhs;
    return *this;
}
} // namespace udemy1::myclass
