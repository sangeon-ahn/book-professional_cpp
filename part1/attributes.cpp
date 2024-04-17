#include <cstdlib>
#include <iostream>
using namespace std;

[[noreturn]] void forceProgramTermination()
{
    std::exit(1);
}

[[deprecated("Unsafe method, please use xyz")]] bool isDongleAvailable()
{
    bool isAvailable { true };
    return isAvailable;
}

bool isFeatureLicensed(int featureId, [[maybe_unused]] int aux)
{
    if (!isDongleAvailable()) {
        forceProgramTermination();
    } else {
        bool isLicensed { featureId == 42 };
        return isLicensed;
    }
}

int main()
{
    bool isLicensed { isFeatureLicensed(42, 100) };

    int value { 8 };
    if (value > 11) [[unlikely]] {
        cout << value << endl;
    } else {
        cout << value << endl;
    }

    switch (value)
    {
        [[likely]] case 8:
        break;
        case 2:
        break;
        [[unlikely]] case 12:
        break;
    }

    return 0;
}