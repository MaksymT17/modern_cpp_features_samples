
#include <iostream>
#include <memory>

class Base
{
public:
    Base() = default;

    ~Base()
    {
        std::cout << "dtor Base" << std::endl;
    }
};

class Derived : public Base
{
public:
    Derived() = default;

    ~Derived()
    {
        std::cout << "dtor Derived" << std::endl;
    }
};

class SuperClass : public Derived
{
public:
    SuperClass() = default;

    ~SuperClass()
    {
        std::cout << "dtor SuperClass" << std::endl;
    }
};

int main()
{
    Base *bd = new Derived();
    delete bd; //dtors called: Base

    std::cout << "______________" << std::endl;

    Derived *bs = new SuperClass();
    delete bs; //dtors called: Derived Base.   Derived dtor marked as non virtual
    std::cout << "______________" << std::endl;

    SuperClass sc; //dtors called: SuperClass Derived Base
    return 0;
}