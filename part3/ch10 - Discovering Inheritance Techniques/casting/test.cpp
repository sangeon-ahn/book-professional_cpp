#include <memory>
#include <iostream>

using namespace std;

class Base
{
    public:
        virtual ~Base() = default;
};

class Derived : public Base
{
    public:
        virtual ~Derived() = default;
};


int main()
{
    int i { 3 };
    int j { 10 };
    double result { static_cast<double>(i) / j};
    cout << result << endl;

    Base* b { nullptr };
    Derived* d { nullptr };
    b = d;
    d = static_cast<Derived*>(b);

    Base base;
    Derived derived;
    Base& br {derived};
    Derived& dr {static_cast<Derived&>(base)};

    // base = static_cast<Base>(derived);
    derived = static_cast<Derived>(base);
}