#include <iostream>
#include <string>
using namespace std;

string getString() {
    return "Hello World";
}

class MyClass
{
    public:
        MyClass(int& ref) : m_ref { ref } {}
        int& getRef() {
            return m_ref;
        }
    private:
        int& m_ref;
};

int main()
{
    int x { 3 }, y { 4 };
    int& xRef { x };
    int& yRef { y };

    xRef = y; // x와 xRef가 가리키던 원시값이 4로 교체됨.
    y = 100;
    // cout << xRef; // 그래서 y를 바꿨음에도 xRef는 4가 나옴.

    // int& unnamedRef1 { 5 }; // 안되는 이유: const인 literal variable 5를 바꿀 수 있다는 소리이므로.
    const int& unnamedRef2 { 5 }; // const를 붙인다면 가능.

    // string& str1 {getString()}; // 임시객체라서 안된다. 임시객체는 평가된 후 사라지기 때문.
    const string& str2 {getString()}; // const를 붙여주면 임시객체 수명이 늘어나서 참조할 수 있다.
    // cout << str2;

    int xx { 3 };
    int& xRef2 { xx };
    int* xPtr2 { &xRef2 };
    *xPtr2 = 1000;
    cout << xx << xRef2 << endl;

    pair myPair {"sangeon", 42};
    auto [name, age] { myPair }; // 복사해서 주는 것.
    auto& [name2, age2] { myPair }; // 참조
    const auto& [name3, age3] { myPair }; // const 참조.   

    cout << name << age << endl;
    cout << name2 << age2 << endl;
    cout << name3 << age3 << endl;

    name2 = "hosu";
    age2 = 100;

    cout << name << name3 << endl;

    int a = 10;
    MyClass mycls(a);
    int& b = mycls.getRef();
    b = 100;
    
    cout << b << a << endl;
}