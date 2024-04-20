#include <string>
#include <iostream>
using namespace std;

string getReplacedString(string src, string from, string to)
{
    size_t pos;
    pos = src.find(from);

    while (pos != src.npos) {
        src.replace(pos, from.length(), to);
        pos += from.length();

        pos = src.find(from, pos);
    }
    return src;
}

int main()
{
    string haystack, needle, reple;
    cin >> haystack >> needle >> reple;

    string newStr = getReplacedString(haystack, needle, reple);
    cout << newStr;
    return 0;
}