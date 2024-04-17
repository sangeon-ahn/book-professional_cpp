#include <iostream>
using namespace std;

class Demo
{
    public:
        int get() { return 10; }
};

int get()
{
    return 50;
}

namespace NS{
    int get() { return 100; }
}

int main()
{
    
    int get1 = ::get(); // 

    Demo dm;
    int get2 = dm.get();
    int get3 = NS::get();

    cout << get1 << get2 << get3 << endl;
}
