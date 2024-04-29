#include <cstddef>
#include <iostream>
#include <exception>
using namespace std;

template <typename T>
class Matrix
{
    public:
        Matrix(size_t width, size_t height);
        virtual ~Matrix();
    private:
        void cleanup();
        size_t m_width { 0 };
        size_t m_height { 0 };
        T** m_matrix { nullptr };
};

template <typename T>
Matrix<T>::Matrix(size_t width, size_t height)
{
    m_matrix = new T*[width] {}; // 포인터배열의 zero initialization: nullptr로 초기화 -> delete 해도 오류 안생김
    
    m_width = width;
    m_height = height;

    try {
        for (size_t i { 0 }; i < width; ++i) {
            m_matrix[i] = new T[height];
        }
    } catch (...) {
        cerr << "Exception caught in constructor, cleaning up..." << endl;
        cleanup();

        throw_with_nested(bad_alloc{});
    }
}

template <typename T>
void Matrix<T>::cleanup() {
    for (size_t i { 0 }; i < m_width; ++i) {
        delete[] m_matrix[i];
        cout << "deleted!" << endl;
    }
    delete[] m_matrix;
    m_matrix = nullptr;
    m_width = m_height = 0;
}


template <typename T>
Matrix<T>::~Matrix()
{
    cleanup();
}

class Element
{
    private:
        int m_value;
};

int main()
{
    Matrix<Element> mat { 10, 10 };
}