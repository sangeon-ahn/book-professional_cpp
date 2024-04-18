#include <string>
using namespace std;

void ThirdPartyLibraryMethod(char* str);

void f(const char* str)
{
    ThirdPartyLibraryMethod(const_cast<char*>(str));
}

int main()
{
    string str { "C++" };
    const string& constStr { as_const(str) };
}