#include <iostream>

int func(int num)
{
    return num;
}

int main()
{
    // narrowing 발생시 -> warning
    int b = 3.14;

    // narrowing 발생시 -> error
    int a { 3.14 };

    // 마찬가지로 narrowing -> error
    // int res = ::func({3.14});
    // std::cout << res;

    int* myArray = new int[4] { 0, 1, 2, 3 };

    auto arr1 = { 11, 12 };
    auto arr2 { 11, 12 }; // error
}