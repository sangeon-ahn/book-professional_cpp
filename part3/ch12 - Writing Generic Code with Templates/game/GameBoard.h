#include <memory>
#include <vector>
#include "GamePiece.h"
using namespace std;

#ifndef GAMEBOARD
#define GAMEBOARD
class GameBoard
{
    public:
        explicit GameBoard(size_t width = DefaultWidth, size_t height = DefaultHeight);
        GameBoard(const GameBoard& src); // copy constructor
        virtual ~GameBoard() = default; // virtual 붙여야 자식클래스 파괴시 자식의 destructor 실행됨.
        GameBoard& operator=(const GameBoard& rhs); // copy assignment operator

        GameBoard(GameBoard&& src) = default;
        GameBoard& operator=(GameBoard&& src) = default;

        unique_ptr<GamePiece>& at(size_t x, size_t y);        
        const unique_ptr<GamePiece>& at(size_t x, size_t y) const;

        size_t getHeight() const { return m_height; }
        size_t getWidth() const { return m_width; }

        static const size_t DefaultWidth { 10 };
        static const size_t DefaultHeight { 10 };

        void swap(GameBoard& other) noexcept;
    private:
        void verifyCoordinate(size_t x, size_t y) const;
        vector<vector<unique_ptr<GamePiece>>> m_cells;
        size_t m_width { 0 }, m_height { 0 };        
};

// normal constructor
GameBoard::GameBoard(size_t width, size_t height) : m_width{width}, m_height{height}
{
    m_cells.resize(m_width);
    for (auto& colum : m_cells) {
        colum.resize(m_height);
    }
}

// copy constructor
GameBoard::GameBoard(const GameBoard& src) : GameBoard{src.m_width, src.m_height}
{
    for (size_t i { 0 }; i < m_width; ++i) {
        for (size_t j { 0 }; j < m_height; ++j) {
            if (src.m_cells[i][j]) {
                m_cells[i][j] = src.m_cells[i][j]->clone();
            }
        }
    }
}

void GameBoard::verifyCoordinate(size_t x, size_t y) const
{
    if (x >= m_width) {
        throw out_of_range{"x must be less than m_width"};
    }
    if (y >= m_height) {
        throw out_of_range{"y must be less than m_height"};
    }
}

void GameBoard::swap(GameBoard& other) noexcept
{
    std::swap(m_width, other.m_width);
    std::swap(m_height, other.m_height);
    std::swap(m_cells, other.m_cells);
}

void swap(GameBoard& first, GameBoard& second) noexcept
{
    first.swap(second);
}

// assign operator
GameBoard& GameBoard::operator=(const GameBoard& rhs)
{
    GameBoard temp { rhs };
    swap(temp);
    return *this;
}

const unique_ptr<GamePiece>& GameBoard::at(size_t x, size_t y) const
{
    verifyCoordinate(x, y);
    return m_cells[x][y];
}

// const가 아닌 GamePiece가 at을 호출할 땐 as_const로 const화한 후 const at 메서드를 호출해서 해당 위치의 const cell unique_ptr을 구한 후, const_cast로 const를 없애준다.
unique_ptr<GamePiece>& GameBoard::at(size_t x, size_t y)
{
    return const_cast<unique_ptr<GamePiece>&>(as_const(*this).at(x, y));
}
#endif