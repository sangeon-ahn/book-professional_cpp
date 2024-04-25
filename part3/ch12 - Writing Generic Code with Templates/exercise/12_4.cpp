#include <string>
#include <iostream>
using namespace std;

template <typename T1, typename T2>
string concat(T1 t1, T2 t2)
{
    return to_string(t1) + to_string(t2);
}

int main()
{
    string s = concat(1221, 12.11);
    cout << s << endl;
}