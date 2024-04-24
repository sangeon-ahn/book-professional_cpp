#include <string>
class WeatherPrediction
{
    public:
        virtual ~WeatherPrediction();
        
        virtual void setCurrentTempFahrenheit(int temp);

        virtual void setPositionOfJupiter(int distanceFromMars);

        virtual int getTomorrowTempFahrenheit() const;

        virtual double getChanceOfRain() const;

        virtual void showResult() const;

        virtual std::string getTemperature() const;
    private:
        int m_currentTempFahrenheit { 0 };
        int m_distanceFromMars { 0 };
};
