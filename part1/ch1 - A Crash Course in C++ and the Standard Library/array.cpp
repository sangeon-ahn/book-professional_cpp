#include <iostream>
#include <array>
#include <vector>
using namespace std;

int main()
{
    int myArray[3] = {};
    // cout << myArray[0] << myArray[1] << myArray[2];    

    int myArray2[39] = {2};
    // for (auto item : myArray2) {
    //     cout << item;
    // }

    size_t arraySize { sizeof(myArray2) / sizeof(myArray2[0])};

    cout << arraySize;

    array arr {9, 8, 7};
    vector vec {1, 2, 3};

    return 0;
}