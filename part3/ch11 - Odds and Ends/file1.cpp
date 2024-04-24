#include <iostream>
void fo();

extern int x; // x를 사용하기 위해 x 선언이 필요하다.


int main()
{
    std::cout << x << std::endl;
}
