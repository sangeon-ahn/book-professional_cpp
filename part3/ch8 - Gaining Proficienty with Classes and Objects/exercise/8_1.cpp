#include <string>
#include <memory>
#include <iostream>
using namespace std;

// ch9에서 move semantic에 대해 배우면 문자열 할당을 더 최적화할 수 있다.
class Person
{
    public:
        explicit Person(const string& first, const string& last) : m_firstName{first}, m_lastName{last} {}
        explicit Person() = default;
        // copy constructor
        Person(const Person& copied); 

        // assignment operator
        Person& operator=(const Person& rhs);

        // destructor
        ~Person();

        const string& getFirstName() const;
        const string& getLastName() const;

        void setFirstName(const string& firstName);
        void setLastName(const string& lastName);
    private:
        string m_firstName; 
        string m_lastName;
};

Person::Person(const Person& copied) : m_firstName{copied.getFirstName()}, m_lastName{copied.getLastName()} {
    cout << "Person copy constructor called." << endl;
}

Person& Person::operator=(const Person& rhs)
{
    // 이거 잊음.
    if (this != &rhs) {
        m_firstName = rhs.getFirstName();
        m_lastName = rhs.getLastName();        
    }
    return *this;
}
Person::~Person()
{
    cout << "destructor constructor is Executing now." << endl;
}

const string& Person::getFirstName() const {
    return m_firstName;
}

const string& Person::getLastName() const {
    return m_lastName;
}

void Person::setFirstName(const string& firstName) {
    m_firstName = firstName;
}

void Person::setLastName(const string& lastName) {
    m_lastName = lastName;
}
int main()
{
    Person person1{"sangeon", "ahn"};
    auto person2 { make_unique<Person>("sangeon", "ahn") };

    cout << "person1: " << person1.getFirstName() << " " << person1.getLastName() << endl;
    cout << "person2: " << person2->getFirstName() << " " << person2->getLastName() << endl;

    // Person phoneBook[3];
}