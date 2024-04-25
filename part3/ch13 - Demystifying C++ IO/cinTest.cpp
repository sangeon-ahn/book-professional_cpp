#include <iostream>
#include <string>
using namespace std;

string readName(istream& stream)
{
    string name;
    char next;
    while (stream.get(next)) {
        name += name;
    }
    return name;
}

int main()
{
    // cout << "Enter numbers on separate lines to add.\n" << "Use Control+D followed by Enter to finish.\n" << endl;
    // int sum { 0 };

    // if (!cin.good()) {
    //     cerr << "Standard input is in a bad state!" << endl;
    //     return 1;
    // }

    // while (!cin.bad()) {
    //     int number;
    //     cin >> number;
        
    //     if (cin.good()) {
    //         sum += number;
    //     } else if (cin.eof()) {
    //         break;
    //     } else if (cin.fail()) {
    //         cin.clear();
    //         string badToken;
    //         cin >> badToken;
    //         cerr << "WARNING: Bad input encountered: " << badToken << endl;
    //     }
    // }
    // cout << "The sum is " << sum << endl;

    // string name = readName(cin);
    // cout << name << endl;

    string myString;
    std::getline(cin, myString, '@');
    cout << myString << endl;
}