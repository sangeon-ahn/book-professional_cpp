#ifndef SPREADSHEET_CELL
#define SPREADSHEET_CELL
#include "spreadSheetCell.h"
#endif

#ifndef DOUBLE_SPREADSHEET_CELL
#define DOUBLE_SPREADSHEET_CELL
#include "double_spreadSheetCell.h"
#endif

#include <string>
#include <string_view>
#include <optional>

class StringSpreadSheetCell : public SpreadSheetCell
{
    public:
        StringSpreadSheetCell() = default;
        StringSpreadSheetCell(const DoubleSpreadSheetCell& cell) : m_value{cell.getString()} {}
        void set(std::string_view value) override;
        std::string getString() const override;
    private:
        std::optional<std::string> m_value;
};

void StringSpreadSheetCell::set(std::string_view value)
{
    m_value = value;
}

std::string StringSpreadSheetCell::getString() const
{
    return m_value.value_or("");
}
