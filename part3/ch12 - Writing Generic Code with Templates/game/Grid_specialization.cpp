#include <stdlib.h>
#include <vector>
#include <optional>
template <>
class Grid<const char*>
{
    public:
        explicit Grid(size_t width = DefaultWidth, size_t height = DefaultHeight);  
        virtual ~Grid() = default;

        Grid<const Grid& src) = default;
        Grid& operator=(const Grid& rhs) = default;

        Grid(Grid&& src) = default;
        Grid& operator=(Grid&& rhs) = default;

        std::optional<std::string>& at(size_t x, size_t y);
        const std::optional<std::string>& at(size_t x, size_t y) const;

        size_t getHeight() const { return m_height; }
        size_t getWidth() const { return m_width; }

        static const size_t DefaultWidth { 10 };
        static const size_t DefaultHeight { 10 };
    private:
        void verifyCoordinate(size_t x, size_t y) const;

        std::vector<std::vector<std::optional<std::string>>> m_cells;
        size_t m_width { 0 }, m_height { 0 };
};

Grid<const char*>::Grid(size_t width, size_t height) : m_width{width}, m_height{height}
{
    m_cells.resize(m_width);
    for (auto& column : m_cells) {
        column.resize(m_height);
    }
}

// verifyCoordinate

// const at

// at
