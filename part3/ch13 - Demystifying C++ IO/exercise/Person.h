#include <string>
#include <compare>
#include <string>
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>

using namespace std;

class Person
{
public:
	// Two-parameter constructor automatically creates initials and
	// delegates the work to the three-parameter constructor.
	// Person(std::string firstName, std::string lastName) : Person{ std::move(firstName), std::move(lastName), std::string(firstName.substr(0, 1)) + lastName.substr(0, 1) } {}

	Person(std::string firstName, std::string lastName) : Person(firstName, lastName, std::string(1, firstName.front()) + std::string(1, lastName.front())) {};

	Person() = default;

	Person(const std::string& firstName, const std::string& lastName, const std::string& initials)
		: m_firstName{ std::move(firstName) }
		, m_lastName{ std::move(lastName) }
		, m_initials{ std::move(initials) }
	{
	}

	const std::string& getFirstName() const { return m_firstName; }
	void setFirstName(std::string firstName) { m_firstName = std::move(firstName); }

	const std::string& getLastName() const { return m_lastName; }
	void setLastName(std::string lastName) { m_lastName = std::move(lastName); }

	const std::string& getInitials() const { return m_initials; }
	void setInitials(std::string initials) { m_initials = std::move(initials); }
	void output(ostream& ost) const {
		ost << "firstName: " << m_firstName << ". lastName: " << m_lastName << ". initials: " << m_initials << std::endl; 
	}
private:
	std::string m_firstName;
	std::string m_lastName;
	std::string m_initials;
};