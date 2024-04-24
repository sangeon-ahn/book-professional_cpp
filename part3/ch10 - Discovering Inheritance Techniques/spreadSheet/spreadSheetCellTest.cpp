#include <vector>
#include <memory>
#include <iostream>

#ifndef SPREADSHEET_CELL
#define SPREADSHEET_CELL
#include "spreadSheetCell.h"
#endif

#ifndef STRING_SPREADSHEET_CELL
#define STRING_SPREADSHEET_CELL
#include "string_spreadSheetCell.h"
#endif

#ifndef DOUBLE_SPREADSHEET_CELL
#define DOUBLE_SPREADSHEET_CELL
#include "double_spreadSheetCell.h"
#endif

using namespace std;
StringSpreadSheetCell operator+(const DoubleSpreadSheetCell& lhs, const DoubleSpreadSheetCell& rhs)
{
    StringSpreadSheetCell cell;
    cell.set(lhs.getString() + rhs.getString());
    return cell;
}



int main()
{
    vector<unique_ptr<SpreadSheetCell>> cells;
    cells.push_back(make_unique<StringSpreadSheetCell>());
    cells.push_back(make_unique<StringSpreadSheetCell>());
    cells.push_back(make_unique<DoubleSpreadSheetCell>());

    cells[0]->set("hello world");
    cells[1]->set("Bye Bye");
    cells[2]->set("100.3");
    
    for (const auto& cell: cells) {
        cout << cell->getString() << endl;
    }

    DoubleSpreadSheetCell myDoubleCell;
    myDoubleCell.set(8.4);
    StringSpreadSheetCell result { myDoubleCell + myDoubleCell};
    cout << result.getString() << endl;
}