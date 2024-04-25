#include <stdlib.h>

template <typename T, size_t WIDTH = 10, size_t HEIGHT = 10>
class Grid
{
    public:
        Grid() = default;
        virtual ~Grid() = default;

        // destructor가 위해 user declared 되어 있어서 밑에처럼 두개는 default 명시해줘야 함.
        // copy constructor
        Grid(const Grid& src) = default;
        // assignment operator
        Grid& operator=(const Grid& rhs) = default;

        // 다른 타입을 위한 copy constructor
        template <typename E, size_t WIDTH2, size_t HEIGHT2>
        Grid(const Grid<E, WIDTH2, HEIGHT2>& src);

        // 다은 타입을 위한 assignment constructor
        template <typename E, size_t WIDTH2, size_t HEIGHT2>
        Grid& operator=(const Grid<E, WIDTH2, HEIGHT2>& rhs);

        void swap(Grid& other) noexcept;

        std::optional<T>& at(size_t x, size_t y);
        const std::optional<T>& at(size_t, size_t y) const;

        size_t getHeight() const { return WIDTH; }
        size_t getWidth() const { return HEIGHT; }
    private:
        void verifyCoordinate(size_t x, size_t y) const;
        std::optional<T> m_cells[WIDTH][HEIGHT];
};

template <typename T, size_t WIDTH, size_t HEIGHT>
template <typename E, size_t WIDTH2, size_t HEIGHT2>
Grid<T, WIDTH, HEIGHT>::Grid(const Grid<E, WIDTH2, HEIGHT2>& src)
{
    for (size_t i { 0 }; i < WIDTH; ++i) {
        for (size_t j { 0 }; j < HEIGHT; ++j) {
            if (i < WIDTH2 && j < HEIGHT2) {
                m_cells[i][j] = src.at(i, j);
            } else {
                m_cells[i][j].reset();
            }
        }
    }
}

template <typename T, size_t WIDTH, size_t HEIGHT>
void Grid<T, WIDTH, HEIGHT>::swap(Grid& other) noexcept
{
    std::swap(m_cells, other.m_cells);
}

template<typename T, size_t WIDTH, size_t HEIGHT>
template<typename E, size_t WIDTH2, size_t HEIGHT2>
Grid<T, WIDTH, HEIGHT>& Grid<T, WIDTH, HEIGHT>::operator=(
    const Grid<E, WIDTH2, HEIGHT2>& rhs)
{
    Grid<T, WIDTH, HEIGHT> temp { rhs }; // copy constructor
    swap(temp);
    return *this;
}

