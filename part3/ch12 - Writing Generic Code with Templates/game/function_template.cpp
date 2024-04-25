#include <stdlib.h>
#include <iostream>
#include <memory>
#include <string>
#include "spreadSheetCell.h"
using namespace std;

static const size_t NOT_FOUND { static_cast<size_t>(-1)};

template <typename T>
size_t Find(const T& value, const T* arr, size_t size)
{
    for (size_t i { 0 }; i < size; ++i) {
        if (arr[i] == value) {
            return i;
        }
    }

    return NOT_FOUND;
}

// function template specialization
size_t Find(const char* value, const char** arr, size_t size)
{
    for (size_t i { 0 }; i < size; ++i) {
        if (strcmp(arr[i], value) == 0) {
            return i;
        }
    }
    return NOT_FOUND;
}

const string message { "Test" };
const string& getString() { return message;}

// auto는 &와 const를 없애버린다.
template <typename T1, typename T2>
auto add(const T1& t1, const T2& t2) -> decltype(t1 + t2)
{ return t1 + t2; }

template <typename T>
constexpr T pi { T {3.1415925358}};

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8};
    int result = Find(8, arr, size(arr));
    cout << result << endl;

    SpreadSheetCell cell1 { 10 };
    SpreadSheetCell cells[] {SpreadSheetCell { 4 }, SpreadSheetCell { 10 } };
    const size_t sizeCells {size(cells)};

    result = Find(cell1, cells, sizeCells);
    cout << result << endl;

    const char* target { "guys"};
    const char* arr2[] {"hello", "world", "guys"};

    result = Find(target, arr2, size(arr2));
    cout << result << endl;

    cout << add(1, 2) << endl;

    auto s1 { getString() };
    const auto& s2 { getString() };

    decltype(getString()) s3 { getString() };
    decltype(auto) s4 { getString() };

    cout << s1 << s2 << s3 << s4 << endl;

    float piFloat { pi<float> };
    auto piDouble { pi<long double> };
    cout << piFloat << endl << piDouble << endl;
}