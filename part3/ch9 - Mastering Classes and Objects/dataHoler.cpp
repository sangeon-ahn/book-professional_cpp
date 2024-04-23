#include <vector>
class DataHoler
{
    public:
        void setData(const std::vector<int>&& data) { m_data = std::move(data);}

        // lvalue면 복사 -> 이동
        // rvalue reference면 이동->이동
        void setData2(std::vector<int> data) { m_data = std::move(data);}
    private:
        std::vector<int> m_data;
};
