#include <iostream>
#include "Employee.h"
using namespace std;
using namespace HR;

int main()
{
    cout << "Testing the Employee class." << endl;
    Employee emp { "Jane", "Doe" };
    
    emp.setFirstName("John");
    emp.setLastName("Doe");
    emp.setTitle(Title::Manager);
    emp.setEmployeeNumber(71);
    emp.setSelary(50'000);
    emp.promote();
    emp.promote(50);
    emp.hire();
    
    emp.display();
}