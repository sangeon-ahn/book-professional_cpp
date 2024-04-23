#include <string>
#include <string_view>
#include <charconv>
#include <iostream>
using namespace std;

class SpreadSheetCell
{
    public:
        explicit SpreadSheetCell(double initialValue);
        explicit SpreadSheetCell(string_view initialValue);
        explicit SpreadSheetCell() = default;
        ~SpreadSheetCell();
        
        SpreadSheetCell& operator=(const SpreadSheetCell& rhs);
        SpreadSheetCell operator+(double rhs) const;
        SpreadSheetCell operator+(const SpreadSheetCell& cell) const;
        void setValue(double value);
        double getValue() const;

        void setString(std::string_view value);
        std::string getString() const;

        enum class Color { Red = 1, Green, Blue, Yellow };
        void setColor(Color color);
        Color getColor() const;

        SpreadSheetCell add(const SpreadSheetCell& cell) const;
    private:
        static std::string doubleToString(double value);
        static double stringToDouble(std::string_view value);

        double m_value { 0 };
        mutable size_t m_numAccesses { 0 };
        Color m_color { Color::Red };
};

SpreadSheetCell SpreadSheetCell::operator+(double rhs) const
{
    return SpreadSheetCell { getValue() + rhs };
}

SpreadSheetCell SpreadSheetCell::operator+(const SpreadSheetCell& cell) const
{
    return SpreadSheetCell { getValue() + cell.getValue() };
}

SpreadSheetCell SpreadSheetCell::add(const SpreadSheetCell& cell) const
{
    // getValue()는 const 메서드라 호출 가능, normal constructor 호출해서 Cell 생성 후 리턴. RVO
    return SpreadSheetCell { getValue() + cell.getValue() };
}

void SpreadSheetCell::setColor(Color color)
{
    m_color = color;
}

SpreadSheetCell::Color SpreadSheetCell::getColor() const
{
    return m_color;
}

SpreadSheetCell::SpreadSheetCell(double initialValue)
{
    setValue(initialValue);
}

// 1번
// SpreadSheetCell::SpreadSheetCell(string_view initialValue)
// {
//     setString(initialValue);
// }

// 2번
SpreadSheetCell::SpreadSheetCell(string_view initialValue) : SpreadSheetCell{stringToDouble(initialValue)} {}

SpreadSheetCell::~SpreadSheetCell()
{
    // cout << "Destructor called." << endl;
}

SpreadSheetCell& SpreadSheetCell::operator=(const SpreadSheetCell& rhs)
{
    // self assignment 예외처리
    if (this == &rhs) {
        return *this;
    }
    m_value = rhs.m_value;
    return *this;
}

void SpreadSheetCell::setValue(double value) {
    m_value = value;
}

inline double SpreadSheetCell::getValue() const {
    ++m_numAccesses;
    return m_value;
}
void printCell(const SpreadSheetCell& cell)
{
    cout << cell.getString() << endl;
}
void SpreadSheetCell::setString(string_view value)
{
    m_value = stringToDouble(value);
    printCell(*this);
}

string SpreadSheetCell::getString() const
{
    ++m_numAccesses;
    return doubleToString(m_value);
}

string SpreadSheetCell::doubleToString(double value)
{
    return to_string(value);
} 

double SpreadSheetCell::stringToDouble(string_view value)
{
    return stod(value.data());
}

