#include <string>
#include <iostream>

class AirlineTicket
{
    public:
        AirlineTicket(); // constructor, 생성자. 객체 생성시 자동 호출됨.
        AirlineTicket(std::string, int, bool);
        ~AirlineTicket(); // destructor, 파괴자. 객체 파괴시 자동 호출됨.
        
        double calculatePriceInDollars() const;
        
        std::string getPassengerName() const;
        void setPassengerName(std::string name);

        int getNumberOfMiles() const;
        void setNumberOfMiles(int miles);

        bool hasEliteSuperRewardsStatus() const;
        void setHasEliteSuperRewardsStatus(bool status);

    private:
        std::string m_passengerName;
        int m_numberOfMiles;
        bool m_hasEliteSuperRewardsStatus;
};


// 생성자 정의 방법 : 1번 
// AirlineTicket::AirlineTicket()
// : m_passengerName { "Unknown Passenger" }, m_numberOfMiles { 0 }, m_hasEliteSuperRewardsStatus { false } {}

// 생성자 정의 방법 : 2번
AirlineTicket::AirlineTicket()
{
    m_passengerName = "Unknown Passenger";
    m_numberOfMiles = 0;
    m_hasEliteSuperRewardsStatus = false;
}

AirlineTicket::AirlineTicket(std::string name, int miles, bool status)
{
    m_passengerName = name;
    m_numberOfMiles = miles;
    m_hasEliteSuperRewardsStatus = status;
}

// 객체가 파괴될 때, 파일을 닫아야 한다거나, 메모리 해제 등이 필요하면 파괴자 내부에 구현함.
AirlineTicket::~AirlineTicket()
{

}

double AirlineTicket::calculatePriceInDollars() const
{
    if (hasEliteSuperRewardsStatus()) {
        return 0;
    }

    return getNumberOfMiles() * 0.1;
}

std::string AirlineTicket::getPassengerName() const
{
    return m_passengerName;
}

void AirlineTicket::setPassengerName(std::string name)
{
    m_passengerName = name;
}

int AirlineTicket::getNumberOfMiles() const
{
    return m_numberOfMiles;
}

void AirlineTicket::setNumberOfMiles(int miles)
{
    m_numberOfMiles = miles;
}

bool AirlineTicket::hasEliteSuperRewardsStatus() const
{
    return m_hasEliteSuperRewardsStatus;
}

void AirlineTicket::setHasEliteSuperRewardsStatus(bool flag)
{
    m_hasEliteSuperRewardsStatus = flag;
}