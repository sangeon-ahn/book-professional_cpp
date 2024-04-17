#include <optional>
#include <iostream>
using namespace std;

optional<int> giveDataIfTrue(bool giveIt) 
{
    if (giveIt) {
        return 42;
    }
    return nullopt;
}
int main()
{
    optional<int> data1 { giveDataIfTrue(true) };
    optional<int> data2 { giveDataIfTrue(false) };

    if (data1.has_value()) {
        cout << "data1: " << data1.value() << endl;
        cout << "dereferenced data1: " << *data1 << endl;
    }

    if (data2.has_value()) {
        cout << "data2: " << data2.value() << endl;
        cout << "dereferenced data2: " << *data2 << endl;
    }
    // cout << "data2: " << data2.value() << endl; : bad optional access

    return 0;
}