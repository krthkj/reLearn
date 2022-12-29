#include "e16_classes.hpp"

namespace udemy1::e16::ex2
{
void Account::withdraw(double amount)
{
    balance -= amount;
    std::cout << "In Account::withdraw" << std::endl;
}
void Account::deposit(double amount)
{
    balance += amount;
    std::cout << "In Account::deposit" << std::endl;
}

Account::Account()
    : balance{0}
{
}
Account::~Account()
{
    std::cout << "Account::destructor" << std::endl;
}
void Checking::withdraw(double amount)
{
    balance -= amount;
    std::cout << "In Checking::withdraw" << std::endl;
}
void Checking::deposit(double amount)
{
    balance += amount;
    std::cout << "In Checking::deposit" << std::endl;
}

Checking::Checking()
    : Account{}
{
}
Checking::~Checking()
{
    std::cout << "Checking::destructor" << std::endl;
}
void Savings::withdraw(double amount)
{
    balance -= amount;
    std::cout << "In Savings::withdraw" << std::endl;
}
void Savings::deposit(double amount)
{
    balance += amount;
    std::cout << "In Savings::deposit" << std::endl;
}

Savings::Savings()
    : Account{}
{
}
Savings::~Savings()
{
    std::cout << "Savings::destructor" << std::endl;
}
void Trust::deposit(double amount)
{
    balance += amount;
    std::cout << "In Trust::deposit" << std::endl;
}

void Trust::withdraw(double amount)
{
    balance -= amount;
    std::cout << "In Trust::withdraw" << std::endl;
}
Trust::Trust()
    : Account{}
{
}
Trust::~Trust()
{
    std::cout << "Trust::destructor" << std::endl;
}

} // namespace udemy1::e16::ex2

namespace udemy1::e16::ex3
{
Account::~Account()
{
    std::cout << "Account::destructor" << std::endl;
}
Checking::~Checking()
{
    std::cout << "Checking::destructor" << std::endl;
}
Savings::~Savings()
{
    std::cout << "Savings::destructor" << std::endl;
}
Trust::~Trust()
{
    std::cout << "Trust::destructor" << std::endl;
}

void Account::withdraw(double amount)
{
    std::cout << "In Account::withdraw " << amount << std::endl;
}
void Checking::withdraw(double amount)
{
    std::cout << "In Checking::withdraw " << amount << std::endl;
}
void Savings::withdraw(double amount)
{
    std::cout << "In Savings::withdraw " << amount << std::endl;
}
void Trust::withdraw(double amount)
{
    std::cout << "In Trust::withdraw " << amount << std::endl;
}

} // namespace udemy1::e16::ex3

namespace udemy1::e16::ex6
{
// concrete classes related
void Square::draw()
{
    std::cout << "Drawing a Square" << std::endl;
}
void Square::rotate()
{
    std::cout << "Rotating a Square" << std::endl;
}
void Circle::draw()
{
    std::cout << "Drawing a Circle" << std::endl;
}
void Circle::rotate()
{
    std::cout << "Rotating a Circle" << std::endl;
}
void Line::draw()
{
    std::cout << "Drawing a Line" << std::endl;
}
void Line::rotate()
{
    std::cout << "Rotating a Line" << std::endl;
}

} // namespace udemy1::e16::ex6

namespace udemy1::e16::ex7_1
{
void Account::withdraw(double amount)
{
    std::cout << "In Account::withdraw " << amount << std::endl;
}
void Checking::withdraw(double amount)
{
    std::cout << "In Checking::withdraw " << amount << std::endl;
}
void Savings::withdraw(double amount)
{
    std::cout << "In Savings::withdraw " << amount << std::endl;
}
void Trust::withdraw(double amount)
{
    std::cout << "In Trust::withdraw " << amount << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Account& acc)
{
    os << "Account display: " << acc.name;
    return os;
}
std::ostream& operator<<(std::ostream& os, const Checking& acc)
{
    os << "Checking display: " << acc.name;
    return os;
}
std::ostream& operator<<(std::ostream& os, const Savings& acc)
{
    os << "Savings display: " << acc.name;
    return os;
}
std::ostream& operator<<(std::ostream& os, const Trust& acc)
{
    os << "Trust display: " << acc.name;
    return os;
}

Account::Account(std::string n)
    : name{n}
{
}

Checking::Checking(std::string n)
    : Account{n}
{
}

Savings::Savings(std::string n)
    : Account{n}
{
}

Trust::Trust(std::string n)
    : Account{n}
{
}

} // namespace udemy1::e16::ex7_1

namespace udemy1::e16::ex7_2
{
Account::Account(std::string n)
    : name{n}
{
}

Checking::Checking(std::string n)
    : Account{n}
{
}

Savings::Savings(std::string n)
    : Account{n}
{
}

Trust::Trust(std::string n)
    : Account{n}
{
}

Dog::Dog(std::string n)
    : name{n}
{
}

void Account::withdraw(double amount)
{
    std::cout << "In Account::withdraw " << amount << std::endl;
}
void Checking::withdraw(double amount)
{
    std::cout << "In Checking::withdraw " << amount << std::endl;
}
void Savings::withdraw(double amount)
{
    std::cout << "In Savings::withdraw " << amount << std::endl;
}
void Trust::withdraw(double amount)
{
    std::cout << "In Trust::withdraw " << amount << std::endl;
}

void Account::print(std::ostream& os) const
{
    os << "Account display: " << this->name;
}

void Checking::print(std::ostream& os) const
{
    os << "Checking display: " << this->name;
}

void Savings::print(std::ostream& os) const
{
    os << "Savings display: " << this->name;
}

void Trust::print(std::ostream& os) const
{
    os << "Trust display: " << this->name;
}

void Dog::print(std::ostream& os) const
{
    os << "Woof woof: " << this->name;
}

std::ostream& operator<<(std::ostream& os, const I_Printable& obj)
{
    obj.print(os);
    return os;
}
} // namespace udemy1::e16::ex7_2
