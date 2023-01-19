#include "e20_class_template.hpp"

namespace udemy1::e20::containers
{
std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os << p.name << ":" << p.age;
    return os;
}

Person::Person(std::string name, int age)
    : name{name}
    , age{age}
{
}

Person::Person()
    : name{"Unknown"}
    , age{0}
{
}

bool Person::operator<(const Person& rhs) const
{
    return this->age < rhs.age;
    // return this->name < rhs.name;
}

bool Person::operator>(const Person& rhs) const
{
    return this->age > rhs.age;
}

bool Person::operator==(const Person& rhs) const
{
    return (this->name == rhs.name && this->age == rhs.age);
}
} // namespace udemy1::e20::containers
