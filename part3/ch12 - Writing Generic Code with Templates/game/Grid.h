#include <memory>
#include <vector>
#include <optional>
#include <algorithm>
using namespace std;

#ifndef GRID
#define GRID

template <typename T> class Grid;
template <typename T>
Grid<T> operator+(const Grid<T>& lhs, const Grid<T>& rhs);

template <typename T>
class Grid
{
    public:
        friend Grid operator+<T>(const Grid& lhs, const Grid& rhs);
        explicit Grid<T>(size_t width = DefaultWidth, size_t height = DefaultHeight);
        virtual ~Grid() = default; // virtual 붙여야 자식클래스 파괴시 자식의 destructor 실행됨.
        // Grid& operator=(const Grid& rhs); // copy assignment operator

        template <typename E>
        Grid(const Grid<E>& src); // copy constructor

        template <typename E>
        Grid<T>& operator=(const Grid<E>& rhs); // assign operator

        Grid(Grid&& src) = default; // move constructor
        Grid<T>& operator=(Grid&& src) = default; // move operator
        
        optional<T>& at(size_t x, size_t y);        
        const optional<T>& at(size_t x, size_t y) const;

        size_t getHeight() const { return m_height; }
        size_t getWidth() const { return m_width; }

        static const size_t DefaultWidth { 10 };
        static const size_t DefaultHeight { 10 };

        void swap(Grid& other) noexcept;
    private:
        void verifyCoordinate(size_t x, size_t y) const;
        vector<vector<optional<T>>> m_cells;
        size_t m_width { 0 }, m_height { 0 };        
};

template <typename T>
Grid<T> operator+(const Grid<T>& lhs, const Grid<T>& rhs)
{
    size_t minWidth {min(lhs.getWidth(), rhs.getWidth())};
    size_t minHeight {min(lhs.getHeight(), rhs.getWidth())};
    
    Grid<T> result { minWidth, minHeight };

    for (size_t y { 0 }; y < minHeight; ++y) {
        for (size_t x { 0 }; x < minWidth; ++x) {
            const auto& leftElement { lhs.m_cells[x][y] };
            const auto& rightElement { rhs.m_cells[x][y] };

            if (leftElement.has_value() && rightElement.has_value()) {
                result.at(x, y) = leftElement.value() + rightElement.value();
            }
        }
    }
    return result;
}

// normal constructor
template <typename T>
Grid<T>::Grid(size_t width, size_t height) : m_width{width}, m_height{height}
{
    m_cells.resize(m_width);
    for (auto& colum : m_cells) {
        colum.resize(m_height);
    }
}

template <typename T>
template <typename E>
Grid<T>& Grid<T>::operator=(const Grid<E>& rhs)
{
    Grid<T> temp { rhs };
    swap(temp);
    return *this;
}

// copy constructor
template <typename T>
template <typename E>
Grid<T>::Grid(const Grid<E>& src) : Grid{src.m_width, src.m_height}
{
    for (size_t i { 0 }; i < m_width; ++i) {
        for (size_t j { 0 }; j < m_height; ++j) {
            m_cells[i][j] = src.at(i, j);
            // if (src.m_cells[i][j]) {
                // m_cells[i][j] = src.m_cells[i][j]->clone();
            // }
        }
    }
}

template <typename T>
void Grid<T>::verifyCoordinate(size_t x, size_t y) const
{
    if (x >= m_width) {
        throw out_of_range{"x must be less than m_width"};
    }
    if (y >= m_height) {
        throw out_of_range{"y must be less than m_height"};
    }
}

template <typename T>
void Grid<T>::swap(Grid& other) noexcept
{
    std::swap(m_width, other.m_width);
    std::swap(m_height, other.m_height);
    std::swap(m_cells, other.m_cells);
}

// void swap(Grid& first, Grid& second) noexcept
// {
//     first.swap(second);
// }

// // assign operator
// Grid& Grid::operator=(const Grid& rhs)
// {
//     Grid temp { rhs };
//     swap(temp);
//     return *this;
// }

template <typename T>
const optional<T>& Grid<T>::at(size_t x, size_t y) const
{
    verifyCoordinate(x, y);
    return m_cells[x][y];
}

// const가 아닌 GamePiece가 at을 호출할 땐 as_const로 const화한 후 const at 메서드를 호출해서 해당 위치의 const cell unique_ptr을 구한 후, const_cast로 const를 없애준다.
template <typename T>
optional<T>& Grid<T>::at(size_t x, size_t y)
{
    return const_cast<optional<T>&>(as_const(*this).at(x, y));
}
#endif