#include <iostream>
using namespace std;

class Rect
{
    public:
        Rect(size_t width, size_t height) {
            m_width = width;
            m_height = height;
        }
        int getArea() {
            return m_width * m_height;
        }
    private:
        size_t m_width { 0 };
        size_t m_height { 0 };
};

int getArrSize()
{
    return 42;
}

int main()
{

    Rect rec1(10, 50); 
    int myArr[rec1.getArea()];
    myArr[0] = 100;
    cout << myArr[0];

}