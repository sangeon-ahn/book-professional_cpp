#include <iostream>
using namespace std;

class Foo
{
    public:
        Foo(double value);
    private:
        double m_value { 0 };
};

Foo::Foo(double value) : m_value {value}
{
    cout << "Foo::m_value = " << m_value << endl;
}

class MyClass
{
    public:
        MyClass(double value);
    private:
        Foo m_foo;
        double m_value { 0 };
};
MyClass::MyClass(double value) : m_value{0}, m_foo{value}
{
    cout << "MyClass::m_value = " << m_value << endl;
}

int main()
{
    MyClass mcls{3.9};

    MyClass mcls2 { mcls };
}
