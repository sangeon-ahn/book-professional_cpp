#include <iostream>

int func(int n)
{
    return n;
}

int main()
{
    int* intP { nullptr };
    intP = new int { 10 };

    *intP = 1000;
    // std::cout << *intP;

    delete intP;
    intP = nullptr;

    // std::cout << *intP;

    int arraySize = 8;
    int* myArray = { new int[arraySize] };

    *myArray = 10;
    *(myArray + 1) = 100;
    std::cout << myArray[0] << " " << myArray[1] << std::endl;

    delete[] myArray;
    myArray = nullptr;

    std::cout << myArray[0] << " " << myArray[1] << std::endl;
    
    func(nullptr);
}