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

        void setValue(double value);
        double getValue() const;

        void setString(std::string_view value);
        std::string getString() const;
    private:
        std::string doubleToString(double value) const;
        double stringToDouble(std::string_view value) const;

        double m_value { 0 };
};

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

double SpreadSheetCell::getValue() const {
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
    return doubleToString(m_value);
}

string SpreadSheetCell::doubleToString(double value) const
{
    return to_string(value);
} 

double SpreadSheetCell::stringToDouble(string_view value) const
{
    return stod(value.data());
}

