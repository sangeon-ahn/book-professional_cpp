#include <string>
#include <iostream>
using namespace std;

void fillWithM(string& text)
{
    for (int i { 0 }; i < text.length(); ++i) {
        text[i] = 'm';
    }
}

int main()
{
    string s = "abcde";
    fillWithM(s);
    cout << s << endl;
}