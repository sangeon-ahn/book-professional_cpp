#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ofstream fout { "test.out" };
    if (!fout) {
        cerr << "Error opening test.out for writing" << endl;
        return 1;
    }
    
    fout << "54321";

    streampos curPos { fout.tellp() };
    // "54321"까지 읽고 다음 위치 가리키기 때문에 정상이라면 5
    if (curPos == 5) {
        cout << "test passed: currently at position 5" << endl;
    } else {
        cout << "Test failed: Not at posiiton 5" << endl;
    }

    fout.seekp(2, ios_base::beg); // manipulator beg(in), 덮어씌우기
    

    fout << 0;
    fout.close();
    
    ifstream fin { "test.out" };
    
    if (!fin) {
        cerr << "Error opening test.out for reading" << endl;
        return 1;
    }

    int testVal;
    fin >> testVal;
    
    if (!fin) {
        cerr << "Error reading from file" << endl;
        return 1;
    }

    const int expected { 54021 };
    if (testVal == expected) {
        cout << "Test passed: Value is " << expected << endl;
    } else {
        cout << "Test failed: Value is not " << expected << "(it was " << testVal << ")" << endl;
    }
}