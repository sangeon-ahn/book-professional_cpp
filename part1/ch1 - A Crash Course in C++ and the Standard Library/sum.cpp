#include <iostream>
#include <format>

using namespace std;
// auto addNumbers(int a, int b)
// {
//     std::cout << "Entering Function: " << __func__;
//     std::cout << format("Entering Function: {}", __func__) << endl;
//     return a + b;
// }

int addNumbers(int a, int b)
{
    return a + b;
}

double addNumbers(double a, double b)
{
    return a + b;
}

[[nodiscard("hi")]] int func(int param1, [[maybe_unused]] int param2)
{
    return 43;
}


int main()
{
    double sum {addNumbers(3.0009, 5.3)};
    std::cout << sum << std::endl;
    func(1, 2);
}