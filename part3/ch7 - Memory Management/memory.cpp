#include <iostream>
using namespace std;

int main()
{
    int size;

    cin >> size;

    int* myArrayPtr { new int[size] };
    *myArrayPtr = 10;
    *(myArrayPtr + 1) = 100;
    cout << myArrayPtr[1] << endl;

    delete[] myArrayPtr;
    myArrayPtr = nullptr;
    // cout << myArrayPtr[0] << endl;
}