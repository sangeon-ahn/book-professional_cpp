#include <iostream>
using namespace std;

class Something
{
    public:
        Something() { cout << "something constructed" << endl;}
        virtual ~Something() { cout << "something destructed" << endl;}
};

class Base
{
    public:
        Base() {cout << "Base constructed" << endl;}
        virtual ~Base() { cout << "Base destructed" << endl;}
};

class Derived : public Base
{
    public:
        Derived() { cout << "Derived constructed" << endl;}
        virtual ~Derived() { cout << "Derived destructed" << endl;}
    private:
        Something m_dataMember;
};

int main()
{
    // Derived derived;
    // cout << endl;
    Base* ptr { new Derived{}};
    cout << endl;
    delete ptr;
    cout << endl;
}