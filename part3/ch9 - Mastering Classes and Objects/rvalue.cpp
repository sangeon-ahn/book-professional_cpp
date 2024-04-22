#include <string>
#include <iostream>
using namespace std;

// void handleMessage(string& message)
// {
//     cout << message << 1 << endl;
// }

void helper(string&& str)
{
    cout << str << "helper" << endl;
}
void handleMessage(string&& message)
{
    cout << message << 2 << endl;
    helper(std::move(message));
    // helper(message);
}

int main()
{
    string s { "Hello World" };
    handleMessage(std::move(s));
    handleMessage(s + "Helll");
}