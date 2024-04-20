#include <string>
#include <iostream>
using namespace std;

const string message { "Test" };
const string& foo() { return message;}

int main()
{
    const auto& str { foo() };

    str = "HO"; // error

    const int a = 10;
    const int& b { a };

    b = 100; // error

    cout << message << str << endl;
    return 0;

    int num { 123 };
    auto* p { &num };
    const auto* p2 {&num };
    auto* const p3 { &num };

    *p = 1000; // OK
    p2 = &b; // OK
    p3 = &b; // error

    const auto* const p4 { &num }; // 포인터와 객체 둘 다 const

    int x { 123 };
    decltype(x) y { 12334 };

    decltype(foo()) str2 { foo() };
    str2 = "aaa"; // error
}