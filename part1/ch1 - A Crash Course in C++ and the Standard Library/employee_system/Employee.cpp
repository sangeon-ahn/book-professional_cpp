#include "Employee.h"
#include <iostream>
using namespace std;

namespace HR {
    Employee::Employee(const string& firstName, const string& lastName) : m_firstName { firstName }, m_lastName { lastName } {}
    void Employee::promote(int raiseAmount)
    {
        setSelary(getSalary() + raiseAmount);
    }
    void Employee::demote(int demeritAmount) 
    {
        setSelary(getSalary() - demeritAmount);
    }
    void Employee::hire() { m_hired = true; }
    void Employee::fire() { m_hired = false; }
    void Employee::display() const
    {
        cout << "Employee: " << getLastName() << ", " << getFirstName() << endl; 
        cout << "-------------------------" << endl;
        cout << "Title: " << static_cast<int>(getTitle()) << endl;
        cout << (isHired() ? "Current Employee" : "Former Employee") << endl;
        cout << "Employee Number: " <<  getEmployeeNumber() << endl;
        cout << "Salary: $" << getSalary() << endl;
        cout << endl;
    }
    void Employee::setFirstName(const string& firstName)
    {
        m_firstName = firstName;
    }
    void Employee::setLastName(const string& lastName)
    {
        m_lastName = lastName;
    }
    void Employee::setEmployeeNumber(int employeeNumber)
    {
        m_employeeNumber = employeeNumber;
    }
    void Employee::setSelary(int newSalary) {
        m_salary = newSalary;
    }

    const std::string& Employee::getFirstName() const {
        return m_firstName;
    }
    const std::string& Employee::getLastName() const {
        return m_lastName;
    }
    int Employee::getEmployeeNumber() const {
        return m_employeeNumber;
    }
    int Employee::getSalary() const {
        return m_salary;
    }

    bool Employee::isHired() const {
        return m_hired;
    }

    Title Employee::getTitle() const {
        return m_title;
    }

    void Employee::setTitle(Title title) {
        m_title = title;
    }
}
