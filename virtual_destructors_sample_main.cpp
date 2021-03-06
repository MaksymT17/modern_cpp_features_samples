
#include <iostream>
#include <memory>

// MV NOTE [IMPORTANT]: Deleting an object through pointer to base invokes undefined behavior unless the destructor in the base class is virtual
// https://en.cppreference.com/w/cpp/language/destructor
// This file shows an possible output with gcc compiler
//compile: g++ virtual_destructors_sample_main.cpp

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

    virtual ~Derived()
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

    Base *bs = new SuperClass();
    delete bs; //dtors called: Base. UNSAFE
    std::cout << "______________" << std::endl;

    Derived *ds = new SuperClass();
    delete ds; //dtors called: SuperClass Derived(v) Base.
    std::cout << "______________" << std::endl;

    SuperClass sc; //dtors called: SuperClass Derived Base
    return 0;
}
