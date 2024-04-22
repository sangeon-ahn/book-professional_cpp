#include <memory>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    const size_t numberOfElements { 10 };
    vector<int> vec {1, numberOfElements};
    
    for (int index { 0 }; index < numberOfElements; ++index) {
        vec[index] = index;
    }

    vec[numberOfElements - 1] = 99;

    for (int index { 0 }; index < numberOfElements; ++index) {
        cout << vec[index] << " ";
    }
}