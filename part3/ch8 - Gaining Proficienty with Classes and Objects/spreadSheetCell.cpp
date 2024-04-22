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
    cout << "Destructor called." << endl;
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


int main()
{
    // objects in stack
    SpreadSheetCell cell, anotherCell;
    cell.setValue(6);
    anotherCell.setString("3.2");
    cout << "cell 1: " << cell.getValue() << endl;
    cout << "cell 2: " << anotherCell.getValue() << endl;

    // objects in free store(heap)
    SpreadSheetCell* myCell { new SpreadSheetCell{}};
    myCell->setValue(56.3);
    cout << "cell 3: " << myCell->getValue() << endl;
    delete myCell;
    myCell = nullptr;

    // objects in free store using smart pointer(more recommended)
    auto myCell2 { make_unique<SpreadSheetCell>()};
    myCell2->setValue(100.1);
    cout << "cell 4: " << myCell2->getValue() << myCell2->getString() << endl;

    // 생성자 함수 사용하기
    // 1. 스택
    SpreadSheetCell c1(5); // or c1 { 5 }
    cout << "cell 5: " << c1.getValue() << endl;

    // 2. 힙
    auto c2 { make_unique<SpreadSheetCell>(6) };
    auto c3 { make_unique<SpreadSheetCell>("133.23")};
    cout << c3->getValue() << endl;

    SpreadSheetCell c4 { 5 };
    string s2 = c4.getString(); // getString에서 반환string 만들려고 string copy constructor 한번, s2 생성할 때 string copy constructor 1번 해서 총 2번 copy 일어남.
    // move constructor 쓰면 1번만에 가능
}