#ifndef BASEDERIVED_HPP
#define BASEDERIVED_HPP

/**
 * @brief Example of Public, private , protected access specifier
 */
namespace udemy::e15
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

} // namespace udemy::e15

#endif // BASEDERIVED_HPP
