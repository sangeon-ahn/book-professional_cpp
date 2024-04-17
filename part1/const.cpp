#include <iostream>
#include <string>
using namespace std;

void changeConstVar(const string* str)
{
    *str = "HI man!"; // const라서 할당 안됨.
}

void changeConstPrimitive(const int a)
{
    a = 10; // const
}

int main()
{
    // const int* ip;
    // ip = new int[10];
    // ip[0] = 10; // error
    // delete[] ip;

    // int const* ip2;
    // ip2 = new int[5];
    // ip2[0] = 100;
    // delete[] ip2;

    // int* const ip3 { nullptr };
    // ip3 = new int[8];
    // ip3[0] = 1;
    // delete[] ip3;

    int* const ip4 { new int[9] };
    ip4[0] = 10;
    std::cout << ip4[0] << std::endl;
    delete[] ip4;

    string str { "Hello World" };
    changeConstVar(&str);

    changeConstPrimitive(100);
}