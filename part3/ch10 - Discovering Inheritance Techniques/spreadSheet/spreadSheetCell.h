#include <string>
#include <string_view>

class SpreadSheetCell
{
    public:
        virtual ~SpreadSheetCell() = default;
        virtual void set(std::string_view value) = 0;
        virtual std::string getString() const = 0;
};