#include <iostream>
#include <vector>
using namespace std;

class Base
{
    public:
        Base() = default;
        virtual ~Base() = default;
        Base(int val) {m_privateInt = val;}
        Base(const Base& src) {}

        Base& Base::operator+(const Base& rhs);

        virtual void someMethod(double d);
        int getVal() const { return m_privateInt; }
    protected:
        int m_protectedInt { 0 };
    private:
        int m_privateInt { 0 };
};
Base& Base::operator+(const Base& rhs)
{
    if (this == &rhs) {
        return *this;
    }

    m_protectedInt = rhs.m_protectedInt;
    m_privateInt = rhs.m_privateInt;

    return *this;
}

class Derived : public Base
{
    public:
        // Derived() = default;
        using Base::Base; // Base의 생성자 사용 가능해짐.
        Derived(int a) : Base{a} {};
        Derived(const Derived& src) : Base{src} {}



        using Base::someMethod; // Base꺼 사용 가능
        void someMethod(double d) override final;
        virtual void someOtherMethod();
};

Derived& Derived::operator=(const Derived& rhs) noexcept
{
    if (this == &rhs) {
        return *this;
    }

    Base::operator=(rhs);
    return *this;
}

void Base::someMethod(double d)
{
    cout << "This is Base's version of someMethod" << endl;
}

void Derived::someMethod(double d)
{
    cout << "This is Derived version of someMethod" << endl;
}

void Derived::someOtherMethod()
{
    cout << "doSomethingMethod" << endl;    
    cout << "protected Base data member: " << m_protectedInt << endl;
    // cout << "private Base data member: " << m_privateInt << endl; // 부모의 private엔 접근 불가.
}
class Foo final {};

int main()
{
    Base myBase;
    Derived myDerived;

    myBase.someMethod(1.1); // base call
    myDerived.someMethod(1.2); // derived call

    Base& ref { myDerived };

    ref.someMethod(1.3); // derived call
    // ref.someOtherMethod(); // error

    Base assignedObj { myDerived };
    assignedObj.someMethod(1.4);

    Derived myDerived2 {20};
    
    cout << myDerived2.getVal() << endl;
}