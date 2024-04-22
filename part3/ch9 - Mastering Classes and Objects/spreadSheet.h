#include <cstddef>
#include "spreadSheetCell.h"
#include <utility>

class SpreadSheet
{
    public:
        SpreadSheet(size_t width, size_t height);
        SpreadSheet(const SpreadSheet& src); // copy constructor
        ~SpreadSheet();
        
        SpreadSheet(SpreadSheet&& src) noexcept; // move constructor
        SpreadSheet& operator=(SpreadSheet&& rhs) noexcept; // move assignment operator

        SpreadSheet& operator=(const SpreadSheet& rhs); // copy assignment operator
        void swap(SpreadSheet& other) noexcept;

        void setCellAt(size_t x, size_t y, const SpreadSheetCell& cell);
        SpreadSheetCell& getCellAt(size_t x, size_t y) const;
    private:
        bool inRange(size_t value, size_t upper) const;
        void verifyCoordinate(size_t x, size_t y) const;

        void cleanup() noexcept;
        void moveFrom(SpreadSheet& src) noexcept;

        size_t m_width { 0 };
        size_t m_height { 0 };
        // string m_name {""};
        SpreadSheetCell** m_cells { nullptr };
};

// void swap(SpreadSheet& first, SpreadSheet& second) noexcept
// {
//     first.swap(second);
// }
void SpreadSheet::swap(SpreadSheet& other) noexcept
{
    std::swap(m_width, other.m_width);
    std::swap(m_height, other.m_height);
    std::swap(m_cells, other.m_cells);
}

// normal constructor
SpreadSheet::SpreadSheet(size_t width, size_t height) : m_width{width}, m_height{height}
{
    m_cells = new SpreadSheetCell*[m_width]; // m_width개의 SpreadSheetCell*을 원소로 갖는 배열 생성후 배열 시작점을 m_cells에 할당
    for (size_t i { 0 }; i < m_width; ++i) {
        for (size_t j { 0 }; j < m_height; ++j) {
            m_cells[i] = new SpreadSheetCell[m_height];
        }
    }

    cout << "normal constructor called." << endl;
}

// copy constructor
SpreadSheet::SpreadSheet(const SpreadSheet& src) : SpreadSheet{src.m_width, src.m_height} // 이 ctor-initialization을 통해 delegating constructor 호출되며 동적 메모리가 할당된다. 이후 {}에서 실제 셀데이터가 복사된다.
{
    for (size_t i { 0 }; i < m_width; ++i) {
        for (size_t j { 0 }; j < m_height; ++j) {
            m_cells[i][j] = src.m_cells[i][j];
        }
    }
}

// destructor
SpreadSheet::~SpreadSheet()
{
    for (int i { 0 }; i < m_width; ++i) {
        delete[] m_cells[i];
    }
    delete[] m_cells;
    m_cells = nullptr;
    
    cout << "SpreadSheet destructor construtor has been successfully completed." << endl;
}

// 버전1
// SpreadSheet& SpreadSheet::operator=(const SpreadSheet& rhs)
// {
//     if (this == &rhs) {
//         return *this;
//     }

//     // 메모리 해제 후 할당
//     for (int i { 0 }; i < m_width; ++i) {
//         delete[] m_cells[i];
//     }
//     delete[] m_cells;
//     m_cells = nullptr;

//     m_width = rhs.m_width;
//     m_height = rhs.m_height;

//     m_cells = new SpreadSheetCell*[m_width];
//     for (int i { 0 }; i < m_width; ++i) {
//         m_cells[i] = new SpreadSheetCell[m_height];
//     }

//     for (int i { 0 }; i < m_width; ++i) {
//         for (int j { 0 }; j < m_height; ++j) {
//             m_cells[i][j] = rhs.m_cells[i][j];
//         }
//     }

//     return *this;
// }

// copy assignment operator= 버전2
SpreadSheet& SpreadSheet::operator=(const SpreadSheet& rhs)
{
    SpreadSheet temp { rhs }; // copy constructor 호출. 복사중 문제 발생해도 this에는 문제 없음.
    swap(temp); // rhs 복사본인 temp를 this 와 스왑. noexcept라 예외 안던짐
    return *this;
    // 스코프 벗어나면 temp는 destructor constructor 호출되며 해제됨.
}

bool SpreadSheet::inRange(size_t x, size_t upper) const
{
    return x >= 0 && x < upper;
}

void SpreadSheet::verifyCoordinate(size_t x, size_t y) const
{
    if (!inRange(x, m_width)) {
        throw out_of_range { to_string(x) + "must be less than" + to_string(m_width)};
    }
    if (!inRange(y, m_height)) {
        throw out_of_range { to_string(y) + "must be less than" + to_string(m_height)};
    }
}
void SpreadSheet::setCellAt(size_t x, size_t y, const SpreadSheetCell& cell)
{
    verifyCoordinate(x, y);
    m_cells[x][y] = cell;
}

SpreadSheetCell& SpreadSheet::getCellAt(size_t x, size_t y) const
{
    verifyCoordinate(x, y);
    return m_cells[x][y];
}

// Move Semantics involved //

// 나의 기존 동적 메모리(데이터) 초기화
void SpreadSheet::cleanup() noexcept
{
    for (size_t i { 0 }; i < m_width; ++i) {
        delete[] m_cells[i];
    }
    delete[] m_cells;
    m_cells = nullptr;
    m_width = m_height = 0;
}

// 상대방 꺼 다 받아오기 & 상대방 초기화
// 구현 1
void SpreadSheet::moveFrom(SpreadSheet& src) noexcept
{
    // 얕은 복사
    m_width = src.m_width;
    m_height = src.m_height;
    m_cells = src.m_cells;

    // 원본쪽 원본 초기화
    src.m_width = 0;
    src.m_height = 0;
    src.m_cells = nullptr;

    // 구현방법 2
    // ehxcange(a, b): b를 a에 복사하고 반환값은 교환 전 a이다.
    m_width = exchange(src.m_width, 0);
    m_height = exchange(src.m_height, 0);
    m_cells = exchange(src.m_cells, nullptr);

    // primitive 말고 객체가 있을 때는 단순 대입하는것보다 해당 객체의 rvalue reference operator= 사용
    // m_name = std::move(src.m_name);
}

// 이건 새 객체 생성시에 이루어지는거라 이동만 하면 된다.
SpreadSheet::SpreadSheet(SpreadSheet&& src) noexcept
{
    swap(src);
    cout << "move constructor called." << endl;
    // moveFrom(src);
}

// 이건 생성 후에 이루어지는거라 기존꺼 삭제 작업이 추가된다. -> rhs는 임시객체라서 해당 라인 벗어날 때 호출되는 destructor로 처리
SpreadSheet& SpreadSheet::operator=(SpreadSheet&& rhs) noexcept
{
//   if (this == &rhs) {
//     return *this;
//   }  

//     // 도착 객체 메모리 해제 & 오너쉽 이전
//   cleanup(); // 나의 기존 메모리 해제
//   moveFrom(rhs); // 오너쉽 이전
    cout << "move assignment operator called." << endl;
    swap(rhs);
    return *this;
}