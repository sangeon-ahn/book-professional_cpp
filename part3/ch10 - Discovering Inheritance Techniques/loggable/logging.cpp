#include <string>
#include <iostream>
using namespace std;

class Loggable
{
    public:
    virtual ~Loggable() = default;
    virtual std::string getLogMessage() const = 0;
};

class Foo : public Loggable
{
    public:
        std::string getLogMessage() const override { return "Hello logger. "; }
};

void logObject(const Loggable& loggableObject)
{
    cout << typeid(loggableObject).name() << ": ";
    cout << loggableObject.getLogMessage() << endl;
}

int main()
{
    Foo foo;
    cout << "result: ";
    logObject(foo);
}