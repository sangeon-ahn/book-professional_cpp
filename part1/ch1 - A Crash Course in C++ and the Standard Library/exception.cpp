#include <iostream>
#include <stdexcept>
using namespace std;

double divideNumbers(double numerator, double denominator)
{
    if (denominator == 0) {
        throw invalid_argument { "Denominator cannot be 0"};
    }
    return numerator / denominator;
}

int main()
{
    try {
        double res = divideNumbers(100, 0);
        cout << res << endl;
    } catch(const exception& e) {
        cerr << e.what() << '\n';
    }
    
    return 0;
}
