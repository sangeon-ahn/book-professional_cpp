#include <iostream>
#include <string>
using namespace std;

// void addOne(int num)
// {
//     num++;
// }

void addOne(int& num)
{
    num++;
}

void swap(int& first, int& second)
{
    int temp { first };
    first = second;
    second = temp;
}

void printString(const string& str)
{
    cout << str << endl;
}

int main()
{
    int a { 10 };
    addOne(a);
    addOne(a);
    cout << a << endl;

    int b { 20 };
    swap(a, b);
    cout << a << b << endl;

    string str1 { "Hello World" };

    printString(str1);
    printString("Bye World"); // literal을 넘겨주지만, 파라미터에 const라고 되어 있기 때문에 가능.
}