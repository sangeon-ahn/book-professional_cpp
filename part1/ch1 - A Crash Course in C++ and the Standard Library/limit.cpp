#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

int main()
{
    cout << "int:\n";
    cout << "Max int value: " << std::numeric_limits<int>::max() << '\n';
    cout << "Min int value: " << std::numeric_limits<int>::min() << '\n';
    cout << "Min int value: " << std::numeric_limits<int>::lowest() << '\n';

    // floating point 타입인 경우 좀 다름.
    cout << "double:\n";
    cout << "Max double value: " << std::numeric_limits<double>::max() << '\n';
    cout << "Min double value: " << std::numeric_limits<double>::min() << '\n'; // 양의 실수 중 가장 작은 것.
    cout << "Min double value: " << std::numeric_limits<double>::lowest() << '\n'; // 음수 중 가장 작은.

    cout << std::isnan(0.0/0.0); // not a number -> 1
    cout << std::isnan(1.0/0.0); // is inf -> 0
    cout << std::isinf(1.0/0.0); // is inf -> 1

    cout << std::numeric_limits<double>::infinity(); // inf
}

