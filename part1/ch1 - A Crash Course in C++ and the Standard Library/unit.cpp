#include <iostream>
using namespace std;

int main()
{
    int someInteger { 256 };
    short someShort;
    long someLong;
    float someFloat;
    double someDouble;


    someInteger++;
    someInteger *= 2;
    someShort = static_cast<short>(someInteger);
    someLong = someShort * 10'000;
    someFloat = someLong + 0.785f; // float은 정확도가 6번째자리까지만 100%이고, 그 이후는 반올림.
    someDouble = static_cast<double>(someFloat) / 100'000;
    
    cout << "someShort: " << someShort << endl; 
    cout << "someLong: " << someLong << endl;
    cout << "someFloat: " << someFloat << endl;
    cout << "someDouble: " << someDouble << endl;
}