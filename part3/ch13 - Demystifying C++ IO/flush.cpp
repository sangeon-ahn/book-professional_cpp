#include <iostream>
using namespace std;

int main()
{
    cout << "abc";
    cout.flush();

    if (cout.good()) {
        cout << "cout is good" << endl;
    }

    cout.exceptions(ios::failbit | ios::badbit | ios::eofbit);
    try {
        cout.clear();
        cout << "hello world." << endl;
    } catch(const ios_base::failure& ex) {
        cerr << "caught exception: " << ex.what() << ", error code = " << ex.code() << endl;
    }
}