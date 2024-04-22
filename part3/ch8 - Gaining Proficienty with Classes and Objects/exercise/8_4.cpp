#include <string>
#include <memory>
#include <iostream>
using namespace std;

// ch9에서 move semantic에 대해 배우면 문자열 할당을 더 최적화할 수 있다.
class Person
{
    public:
        explicit Person(const string& first, const string& last) : Person(first, last, string(1, first[0]) + last[0]) {}

        explicit Person(const string& first, const string& last, const string& initials) : m_firstName{first}, m_lastName{last}, m_initials{initials} {}
        explicit Person() = default;

        const string& getFirstName() const;
        const string& getLastName() const;
        const string& getInitials() const;

        void setFirstName(const string& firstName);
        void setLastName(const string& lastName);
        void setInitials(const string& initials);
    private:
        string m_firstName; 
        string m_lastName;
        string m_initials;
};

const string& Person::getFirstName() const {
    return m_firstName;
}

const string& Person::getLastName() const {
    return m_lastName;
}

const string& Person::getInitials() const {
    return m_initials;
}

void Person::setFirstName(const string& firstName) {
    m_firstName = firstName;
}

void Person::setLastName(const string& lastName) {
    m_lastName = lastName;
}

void Person::setInitials(const string& initials) {
    m_initials = initials;
}

int main()
{
    Person person1{"sangeon", "ahn"};
    auto person2 { make_unique<Person>("sangeon", "ahn") };

    cout << "person1: " << person1.getFirstName() << " " << person1.getLastName() << endl;
    cout << "person2: " << person2->getFirstName() << " " << person2->getLastName() << endl;

    Person phoneBook[3];

    Person copied { person1 };

    cout << copied.getFirstName() << copied.getLastName() << copied.getInitials() << endl;

    Person assigned {"Jane", "Street"};
    copied = assigned;

    cout << copied.getFirstName() << copied.getLastName() << copied.getInitials() << endl;
}