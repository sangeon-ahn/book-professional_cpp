#include <limits>
#include <exception>
#include <memory>
#include <iostream>
using namespace std;

class please_terminate_me : public bad_alloc {};

void myNewHandler()
{
    cerr << "newhandler: Unable to allocate memory." << endl;
    throw please_terminate_me {};
}

int main()
{
    int* ptr { nullptr };
    // size_t integerCnt { numeric_limits<size_t>::max()};

    // try {
    //     ptr = new int[integerCnt];
    // } catch (const bad_alloc& e) {
    //     cerr << "FILE: " << __FILE__ << "(" << __LINE__ << " line)\n: Unable to allocate memory: " << e.what() << endl;
    // }

    try {
        // set_new_handler는 새 핸들러 설정하고 이전 핸들러 반환한다.
        new_handler oldHandler { set_new_handler(myNewHandler)};

        size_t numInts { numeric_limits<size_t>::max()};
        ptr = new int[numInts];

        // 정상 할당됐으면 다시 이전 핸들러로 복구
        set_new_handler(oldHandler);
    } catch (const please_terminate_me&) {
        cerr << "FILE: " << __FILE__ << "(" << __LINE__ << " line)\n: Unable to allocate memory: " << endl;
        return 1;
    }
}