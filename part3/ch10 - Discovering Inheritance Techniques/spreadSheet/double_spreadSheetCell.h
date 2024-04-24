#ifndef SPREADSHEET_CELL
#define SPREADSHEET_CELL
#include "spreadSheetCell.h"
#endif

// #ifndef STRING_SPREADSHEET_CELL
// #define STRING_SPREADSHEET_CELL
// #include "string_spreadSheetCell.h"
// #endif

#include <string>
#include <string_view>
#include <optional>
#include <algorithm>
using namespace std;

class StringSpreadSheetCell;

class DoubleSpreadSheetCell : public SpreadSheetCell
{
    public:
        virtual void set(double value) { m_value = value; }
        void set(std::string_view value) override { m_value = stringToDouble(value); }
        std::string getString() const override {
            return (m_value.has_value() ? doubleToString(m_value.value()) : "");
        }
    private:
        static std::string doubleToString(double value) { return to_string(value);};
        static double stringToDouble(std::string_view value) { return stod(value.data());};
        std::optional<double> m_value;
};

