#include <iostream>
#include <cstddef>
#include <limits>

using namespace std;

int main() {
    int uninit; // 초기화 안하는 경우 -> 쓰레기값(당시 메모리에 존재했던 값)
    int init = 7;

    cout << init;    
    
    std::byte b { 42 };

    return 0;
}