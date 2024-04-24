#include "weatherPrediction.h"
#include <iostream>
using namespace std;

class MyWeatherPrediction : public WeatherPrediction
{
    public:
        virtual void setCurrentTempCelsius(int temp);
        virtual int getTomorrowTempCelsius() const;
        void showResult() const override;
    private:
        // helper methods
        static int convertCelsiusToFahrenheit(int celsius); 
        static int convertFahrenheitToCelsius(int fahrenheit);
};

void MyWeatherPrediction::showResult() const
{
    cout << "Tomorrow will be " << getTomorrowTempCelsius() << " degrees Celsius(" << getTomorrowTempFahrenheit() << " degrees Fahrenheit)" << endl;
    cout << "Chance of rain is " << getChanceOfRain() << "%." << endl;
    
    if (getChanceOfRain() > 0.5) {
        cout << "Bring an umbrella!" << endl;
    }
}

void MyWeatherPrediction::setCurrentTempCelsius(int temp)
{
    int fahrenheitTemp { convertCelsiusToFahrenheit(temp) };
    setCurrentTempFahrenheit(fahrenheitTemp);
}

int MyWeatherPrediction::getTomorrowTempCelsius() const
{
    int fahrenheitTemp { getTomorrowTempFahrenheit() };
    return convertFahrenheitToCelsius(fahrenheitTemp);
}

int MyWeatherPrediction::convertCelsiusToFahrenheit(int celsius)
{
    return int((9 * celsius) / 5) + 32;
}

int MyWeatherPrediction::convertFahrenheitToCelsius(int fahrenheit)
{
    return int((fahrenheit - 32) * (5 / 9));
}