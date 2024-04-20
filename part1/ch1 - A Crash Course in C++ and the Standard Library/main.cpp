#include <iostream>

// using namespace std;
namespace mycode {
    void foo()
    {
        std::cout << "foo() called in the mycode namespace" << std::endl;
    }
    namespace secretSpace {
        void foo()
        {
            std::cout << "This is secret foo function in secretSpace" << std::endl;
        }
    }
}

namespace inner = mycode::secretSpace;
int main() {
    std::cout << "hello world!\n";
    mycode::secretSpace::foo();
    inner::foo();
    int num = 100'000'000;
    std::cout << num << std::endl;
    return 0;
}
