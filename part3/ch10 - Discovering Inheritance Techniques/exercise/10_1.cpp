#include <string>
#include <iostream>
#include <vector>
#include <memory>
using namespace std;
namespace HR {
class Person
{
public:
	Person(std::string firstName, std::string lastName) //// Pass by value and move.
		: m_firstName{ std::move(firstName) }, m_lastName{ std::move(lastName) }
	{
	}

	Person() = default;

	// Copy constructor.
	Person(const Person& src)
		: m_firstName{ src.m_firstName }, m_lastName{ src.m_lastName }
	{
		std::cout << "Person copy constructor called." << std::endl;
	}

	// Assignment operator.
	//// Modified to use copy-and-swap to avoid code duplication.
	Person& operator=(const Person& rhs)
	{
		std::cout << "Person assignment operator called." << std::endl;

		auto temp{ rhs };
		swap(temp);
		return *this;
	}

	// Destructor.
	virtual ~Person()
	{
		std::cout << "Person destructor called." << std::endl;
	}

	// Move constructor.
	Person(Person&& src) noexcept
	{
		std::cout << "Person move constructor called." << std::endl;
		swap(src);
	}

	// Move assignment operator.
	Person& operator=(Person&& rhs) noexcept
	{
		std::cout << "Person move assignment operator called." << std::endl;
		swap(rhs);
		return *this;
	}

	// swap method.
	//// Added to avoid code duplication
	void swap(Person& other) noexcept
	{
		std::swap(m_firstName, other.m_firstName);
		std::swap(m_lastName, other.m_lastName);
	}

	virtual const std::string& getFirstName() const { return m_firstName; }
	virtual void setFirstName(std::string firstName) { m_firstName = std::move(firstName); } //// Pass by value and move.

	virtual const std::string& getLastName() const { return m_lastName; }
	virtual void setLastName(std::string lastName) { m_lastName = std::move(lastName); } //// Pass by value and move.

    virtual std::string toString() const {
        return "person:" + m_firstName + m_lastName + ".";
    }

private:
	std::string m_firstName;
	std::string m_lastName;
};

class Employee : public Person
{
    public:
        virtual ~Employee() {
            std::cout << "Employee destructor called." << std::endl;
        }
        Employee(std::string firstName, std::string lastName, int id) : Person(std::move(firstName), std::move(lastName)), m_employeeId{id} {} 

        int getId() const { return m_employeeId; }
        void setId(int id) { m_employeeId = id;}
        virtual std::string toString() const override {
            return Person::toString() + " role1: Employee";
        }

    private:
        int m_employeeId { 0 };
};

class Manager : public Employee
{
    public:
        using Employee::Employee;
        Manager(const Employee& src) : Employee{src} {}
        virtual ~Manager() {
            std::cout << "Manager desturctor called." << std::endl;
        }
        std::string toString() const override {
            return Employee::toString() + " role2: Manager.";
        }
        
};

class Director : public Employee
{
    public:
        using Employee::Employee;
        virtual ~Director() {
            std::cout << "Direct destructor called." << std::endl;
        }
        std::string toString() const override {
            return Employee::toString() + "role2: Director.";
        }
};
}

int main()
{
    // HR::Manager mg{"sangeon", "ahn", 123};
    // HR::Director dr{"nana", "Ji", 11};

    // std::cout << mg.toString() << std::endl;
    // std::cout << dr.toString() << std::endl;

    // std::vector<HR::Employee> emps;
    // HR::Employee{"sangeon", "ahn", 1};
    // emps.push_back(HR::Employee{"sangeon", "ahn", 1});
    // emps.push_back(HR::Manager{"sungmin", "jung", 2});
    // emps.push_back(HR::Director{"jibum", "park", 3});

    // for (const auto& emp: emps) {
    //     std::cout << emp.toString() << std::endl;
    // }

    vector<unique_ptr<HR::Person>> persons; 
    persons.push_back(make_unique<HR::Employee>(HR::Employee{"sangeon", "ahn", 1}));
    persons.push_back(make_unique<HR::Director>(HR::Director{"sanji", "park", 2}));

    for (const auto& person : persons) {
        cout << person->toString() << endl;
    }

    HR::Employee emp { "SMITH", "SAM", 190};
    HR::Manager manager { emp };

    cout << manager.toString() << endl;;
}