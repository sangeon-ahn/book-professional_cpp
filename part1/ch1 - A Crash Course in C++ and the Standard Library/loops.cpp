#include <iostream>
#include <initializer_list>
#include <string>
using namespace std;

int makeSum(initializer_list<int> values)
{
    int result { 0 };
    for (int value : values) {
        result += value;
    }
    return result;
}

int main()
{
    int i { 0 };
    while (i < 5) {
        cout << "i is " << i << endl;
        ++i;
    }

    int j { 100 };
    do {
        cout << "This is bad.." << endl;
        ++j;
    } while (i < 5);

    int sum1 = makeSum({ 1, 2, 3 });
    int sum2 = makeSum({ 4, 5, 6 });

    cout << "sum1: " << sum1 << ", sum2: " << sum2 << endl;

    string myString { "Hello World!" };
    cout << myString << endl;
}