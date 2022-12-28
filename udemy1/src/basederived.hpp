#ifndef BASEDERIVED_HPP
#define BASEDERIVED_HPP

/**
 * @brief Example of Public, private , protected access specifier
 */
namespace udemy::e15::ex2
{

class Base
{
    // Note friend of base class have access to all
  public:
    int a{0};
    void display();

  protected:
    int b{0};

  private:
    int c{0};
};

class Derived_Public : public Base
{
    // Note friend of Derived class have access to only what Derived has access to
    // a will be public
    // b will be protected
    // c will not be accessible

  public:
    void access_base_member();
};

} // namespace udemy::e15::ex2

/**
 * @brief Example of constructor and destructors with inheritance
 */
namespace udemy::e15::ex3
{

class Base
{
  private:
    int value;

  public:
    Base();
    Base(int val);
    ~Base();

    void display(void); // simply defined to prevent compiler warning for unused varialble 'value'
};

class Derived_Public : public Base
{
    // Note: using Base::Base;
    // will inherit non-special constructors
    // but in will perform base class initialization, but ignore derived class initialization

    // using Base::Base;
    int doubled_value;

  public:
    Derived_Public();
    Derived_Public(int value);
    ~Derived_Public();

    void display(void); // simply defined to prevent compiler warning for unused varialble 'doubled_value'
};

} // namespace udemy::e15::ex3

/**
 * @brief Example of passing arg to base class constructors
 *        Example of Copy and move constructor
 */
namespace udemy::e15::ex4
{

class Base
{
  private:
    int value;

  public:
    Base();        // default no arg constructor
    Base(int val); // arg constructor
    ~Base();       // destructor

    Base(const Base& src);            // copy constructor example
    Base& operator=(const Base& src); // assignment operator example
};

class Derived_Public : public Base
{
    int doubled_value;

  public:
    Derived_Public();          // default no arg constructor
    Derived_Public(int value); // arg constructor
    ~Derived_Public();         // destructor

    Derived_Public(const Derived_Public& src);            // copy constructor example
    Derived_Public& operator=(const Derived_Public& src); // assignment operator example
};

} // namespace udemy::e15::ex4

#endif // BASEDERIVED_HPP
