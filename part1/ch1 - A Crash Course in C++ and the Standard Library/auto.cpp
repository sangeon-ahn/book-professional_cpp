#include <array>
#include <iostream>
using namespace std;

int main()
{
    array values {1, 2, 3};
    auto [x, y, z] { values };
    
    // struct Point {
    //     double m_x;
    //     double m_y;
    //     double m_z;
    // };

    // Point p;
    // p.m_x = 1.0;
    // p.m_y = 2.0;
    // p.m_z = 3.0;

    // auto [a, b, c] = { p };

    pair myPair {"hello", 5};
    auto [str, integer] {myPair};
    cout << str << integer << endl;

    array myArr {1, 2, 3};

    for (auto& item : myArr) {
        cout << item << endl;
    }
}