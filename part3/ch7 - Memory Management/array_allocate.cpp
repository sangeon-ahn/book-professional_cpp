#include <iostream>
#include <array>
using namespace std;

void doubleInts(int* theArray, size_t size);
void doubleInts(int theArray[], size_t size);
void doubleInts(int theArray[2], size_t size);

void doubleInts(int theArray[], size_t size)
{
    for (int i { 0 }; i < size; ++i) {
        theArray[i] *= 2;
    }
}

char** allocateCharacterBoard(size_t x, size_t y)
{
    char** myArray { new char*[x] };
    for (size_t i { 0 }; i < x; ++i) {
        myArray[i] = new char[y];
    }
    return myArray;
}

void releaseCharacterBoard(char**& myArray, size_t x)
{
    for (int i { 0 }; i < x; ++i) {
        delete[] myArray[i];
        myArray[i] = nullptr;
    }
    delete[] myArray;
    myArray = nullptr;
}

class Simple
{
    public:
        Simple() { cout << "simple constructor called!" << endl;}
        ~Simple() { cout << "simple destructor called!" << endl;}
};

int main()
{
    Simple* arr { new Simple[3] };
    delete[] arr;
    arr = nullptr;

    const size_t size { 4 };
    Simple** mySimplePtrArray { new Simple*[size] };

    for (size_t i { 0 }; i < size; ++i) { mySimplePtrArray[i] = new Simple{}; }

    // mySimplePtrArray 사용

    for (size_t i { 0 }; i < size; ++i) {
        delete mySimplePtrArray[i];
        mySimplePtrArray[i] = nullptr;
    }
    delete[] mySimplePtrArray;
    mySimplePtrArray = nullptr;

    char board[3][3] {};
    board[0][0] = 'X';
    board[2][1] = 'O';

    // not good idea to implement twoDArray -> 메모리상에 흩어져 있기 때문에 캐시 이용 불가.
    char** twoDArray = allocateCharacterBoard(2, 2);
    for (int i { 0 }; i < 2; ++i) {
        for (int j { 0 }; j < 2; ++j) {
            twoDArray[i][j] = 'a';
        }
    }

    for (int i { 0 }; i < 2; ++i) {
        for (int j { 0 }; j < 2; ++j) {
            cout << twoDArray[i][j];
        }
        cout << endl;
        delete[] twoDArray[i];
        twoDArray[i] = nullptr;
    }
    delete[] twoDArray;
    twoDArray = nullptr;

    // one big 1D array is better.
    char* oneDArray = new char[4];

    // use

    delete[] oneDArray;  

    int myIntArray[10] {};
    int* myIntPtr { myIntArray };
    myIntPtr[0] = 10;

    int intArray[] {1, 2, 3, 4, 5};
    size_t arrSize = std::size(intArray);
    doubleInts(intArray, arrSize);

    for (int i { 0 }; i < arrSize; ++i) {
        cout << intArray[i] << endl;
    }
}