#include "spreadSheet.h"
#include <iostream>
#include <vector>
using namespace std;

void printSpreadSheet(SpreadSheet ss) // 복사 일어남.
{
    //
}

SpreadSheet createObject()
{
    return SpreadSheet { 3, 2 };
}

int main()
{
    // SpreadSheet ss1 {4, 3};
    
    // 어떤 생성자가 호출되는지 따라가며 파악하기.
    vector<SpreadSheet> vec;
    for (size_t i { 0 }; i < 2; ++i) {
        cout << "Iteration " << i << endl;
        vec.push_back(SpreadSheet { 100, 100 });
        cout << endl;
    }

    SpreadSheet s { 2, 3 };
    s = createObject(); // 임시객체의 = 연산 -> move assign operator
    
    SpreadSheet s2 { 5, 6 };
    s2 = s;
    
    // Iterattion 0
    // Normal constructor
    // Move constructor

    // Iteration 1
    // Normal constructor
    // Move constructor
    // Move constructor

    // Normal constructor
    // Normal constructor
    // move assignment constructor

    // Normal constructor
    // copy assignment constructor
    // Normal constructor
    // Copy constructor
}