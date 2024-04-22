#include <iostream>
using namespace std;
class Point3D
{
    public:
        Point3D(int x, int y, int z) : m_x(x), m_y(y), m_z(z) {}
        int getX() { return m_x; }
        int getY() { return m_y; }
        int getZ() { return m_z; }
    private:
        int m_x;
        int m_y;
        int m_z;
};

int main()
{
    Point3D* p1 = new Point3D{1, 2, 3};
    cout << p1->getX() << p1->getY() << p1->getZ() << endl;

    return 0;
}